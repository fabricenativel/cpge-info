(* ============================================================
   Sudoku solver : encodage CNF + algorithme de Quine (DPLL)
   ============================================================
   Variables : x(i,j,v) avec i,j ∈ [0..8], v ∈ [1..9]
   Encodage  : var(i,j,v) = i*81 + j*9 + (v-1)   → entiers [0..728]
   Littéraux : positif = variable vraie, négatif = variable fausse
   ============================================================ *)

(* ---------- Encodage des variables ---------- *)

(* Les littéraux sont des entiers non nuls :
     lit > 0  →  variable (lit-1) vraie
     lit < 0  →  variable (-lit-1) fausse
   var i j v retourne le littéral positif correspondant à x(i,j,v),
   soit un entier dans [1..729]. *)
let var i j v = (i * 81) + (j * 9) + (v - 1) + 1
(* +1 pour que les littéraux démarrent à 1 (0 est réservé à "non affecté") *)

let nb_vars = 9 * 9 * 9   (* 729 variables, indices internes 0..728 *)

(* ---------- Construction des clauses CNF ---------- *)

(* Chaque clause est une liste de littéraux (entiers signés) *)

let clauses = ref []

let add_clause c = clauses := c :: !clauses

(* 1. Chaque case contient AU MOINS une valeur *)
let at_least_one () =
  for i = 0 to 8 do
    for j = 0 to 8 do
      let c = ref [] in
      for v = 1 to 9 do
        c := (var i j v) :: !c
      done;
      add_clause !c
    done
  done

(* 2. Chaque case contient AU PLUS une valeur (pour tout v1 < v2 : ¬x(i,j,v1) ∨ ¬x(i,j,v2)) *)
let at_most_one () =
  for i = 0 to 8 do
    for j = 0 to 8 do
      for v1 = 1 to 9 do
        for v2 = v1 + 1 to 9 do
          add_clause [-(var i j v1); -(var i j v2)]
        done
      done
    done
  done

(* 3. Chaque valeur apparaît AU MOINS une fois dans chaque ligne *)
let row_at_least () =
  for i = 0 to 8 do
    for v = 1 to 9 do
      let c = ref [] in
      for j = 0 to 8 do
        c := (var i j v) :: !c
      done;
      add_clause !c
    done
  done

(* 4. Chaque valeur apparaît AU PLUS une fois dans chaque ligne *)
let row_at_most () =
  for i = 0 to 8 do
    for v = 1 to 9 do
      for j1 = 0 to 8 do
        for j2 = j1 + 1 to 8 do
          add_clause [-(var i j1 v); -(var i j2 v)]
        done
      done
    done
  done

(* 5. Chaque valeur apparaît AU MOINS une fois dans chaque colonne *)
let col_at_least () =
  for j = 0 to 8 do
    for v = 1 to 9 do
      let c = ref [] in
      for i = 0 to 8 do
        c := (var i j v) :: !c
      done;
      add_clause !c
    done
  done

(* 6. Chaque valeur apparaît AU PLUS une fois dans chaque colonne *)
let col_at_most () =
  for j = 0 to 8 do
    for v = 1 to 9 do
      for i1 = 0 to 8 do
        for i2 = i1 + 1 to 8 do
          add_clause [-(var i1 j v); -(var i2 j v)]
        done
      done
    done
  done

(* 7. Chaque valeur apparaît AU MOINS une fois dans chaque bloc 3×3 *)
let box_at_least () =
  for bi = 0 to 2 do
    for bj = 0 to 2 do
      for v = 1 to 9 do
        let c = ref [] in
        for di = 0 to 2 do
          for dj = 0 to 2 do
            let i = bi * 3 + di and j = bj * 3 + dj in
            c := (var i j v) :: !c
          done
        done;
        add_clause !c
      done
    done
  done

(* 8. Chaque valeur apparaît AU PLUS une fois dans chaque bloc 3×3 *)
let box_at_most () =
  for bi = 0 to 2 do
    for bj = 0 to 2 do
      for v = 1 to 9 do
        (* liste des cases du bloc *)
        let cells = ref [] in
        for di = 0 to 2 do
          for dj = 0 to 2 do
            cells := (bi*3+di, bj*3+dj) :: !cells
          done
        done;
        let cells = !cells in
        let rec pairs = function
          | [] | [_] -> ()
          | (i1,j1) :: rest ->
            List.iter (fun (i2,j2) ->
              add_clause [-(var i1 j1 v); -(var i2 j2 v)]
            ) rest;
            pairs rest
        in
        pairs cells
      done
    done
  done

(* 9. Contraintes des cases préremplies *)
let add_givens grid =
  for i = 0 to 8 do
    for j = 0 to 8 do
      let v = grid.(i).(j) in
      if v <> 0 then
        add_clause [var i j v]   (* clause unitaire : x(i,j,v) = true *)
    done
  done

(* ---------- Construction complète de la CNF ---------- *)

let build_cnf grid =
  clauses := [];
  at_least_one ();
  at_most_one ();
  row_at_least ();
  row_at_most ();
  col_at_least ();
  col_at_most ();
  box_at_least ();
  box_at_most ();
  add_givens grid;
  !clauses

(* ---------- Algorithme de Quine (DPLL) ---------- *)

(* Représentation de l'état : tableau d'affectation
   assign.(k) = true  → variable k est vraie
   assign.(k) = false → variable k est fausse
   assigned.(k) = true → variable k est affectée *)

type state = {
  assign   : bool array;
  assigned : bool array;
}

let make_state () = {
  assign   = Array.make nb_vars false;
  assigned = Array.make nb_vars false;
}

let copy_state s = {
  assign   = Array.copy s.assign;
  assigned = Array.copy s.assigned;
}

(* Évaluation d'un littéral sous une affectation partielle :
   Some true  → satisfait
   Some false → falsifié
   None       → non déterminé *)
let eval_lit s lit =
  let v = abs lit - 1 in   (* les variables sont encodées à partir de 0 *)
  if not s.assigned.(v) then None
  else
    let b = s.assign.(v) in
    Some (if lit > 0 then b else not b)

(* Évaluation d'une clause :
   Some true  → au moins un littéral vrai → satisfaite
   Some false → tous les littéraux faux   → insatisfaisable
   None       → indéterminée *)
let eval_clause s clause =
  let has_none = ref false in
  let rec loop = function
    | [] -> if !has_none then None else Some false
    | lit :: rest ->
      (match eval_lit s lit with
       | Some true  -> Some true
       | Some false -> loop rest
       | None -> has_none := true; loop rest)
  in
  loop clause

(* Évaluation de la formule entière :
   Some true  → toutes les clauses satisfaites
   Some false → au moins une clause insatisfaisable
   None       → indéterminée *)
let eval_formula s formula =
  List.fold_left (fun acc clause ->
    match acc with
    | Some false -> Some false
    | _ ->
      match eval_clause s clause with
      | Some false -> Some false
      | Some true  -> acc
      | None       -> None
  ) (Some true) formula

(* Propagation unitaire : si une clause est unitaire (un seul littéral
   non affecté, les autres falsifiés), on force ce littéral à vrai.
   Retourne false si un conflit est détecté. *)
let unit_propagate s formula =
  let changed = ref true in
  let conflict = ref false in
  while !changed && not !conflict do
    changed := false;
    List.iter (fun clause ->
      if not !conflict then begin
        (* Cherche les littéraux non falsifiés dans la clause *)
        let unset = ref [] in
        let satisfied = ref false in
        List.iter (fun lit ->
          match eval_lit s lit with
          | Some true  -> satisfied := true
          | Some false -> ()
          | None       -> unset := lit :: !unset
        ) clause;
        if not !satisfied then begin
          match !unset with
          | [] ->
            (* Clause vide → conflit *)
            conflict := true
          | [lit] ->
            (* Clause unitaire → propagation *)
            let v = abs lit - 1 in
            if not s.assigned.(v) then begin
              s.assigned.(v) <- true;
              s.assign.(v)   <- (lit > 0);
              changed := true
            end
          | _ -> ()
        end
      end
    ) formula
  done;
  not !conflict

(* Choix d'une variable non affectée (heuristique : première trouvée) *)
let pick_unassigned s =
  let result = ref None in
  let i = ref 0 in
  while !i < nb_vars && !result = None do
    if not s.assigned.(!i) then result := Some !i;
    incr i
  done;
  !result

(* Algorithme de Quine / DPLL récursif *)
let rec dpll s formula =
  if not (unit_propagate s formula) then
    None  (* conflit après propagation *)
  else
    match eval_formula s formula with
    | Some true  -> Some s          (* solution trouvée *)
    | Some false -> None            (* insatisfaisable *)
    | None ->
      (* Choisir une variable non affectée et bifurquer *)
      match pick_unassigned s with
      | None -> None  (* ne devrait pas arriver *)
      | Some v ->
        (* Branche v = true *)
        let s1 = copy_state s in
        s1.assigned.(v) <- true;
        s1.assign.(v)   <- true;
        (match dpll s1 formula with
         | Some sol -> Some sol
         | None ->
           (* Branche v = false *)
           let s2 = copy_state s in
           s2.assigned.(v) <- true;
           s2.assign.(v)   <- false;
           dpll s2 formula)

(* ---------- Lecture et affichage ---------- *)

let parse_grid str =
  if String.length str <> 81 then
    failwith "La chaîne doit contenir exactement 81 caractères";
  let grid = Array.make_matrix 9 9 0 in
  for i = 0 to 8 do
    for j = 0 to 8 do
      let c = str.[i * 9 + j] in
      if c < '0' || c > '9' then
        failwith (Printf.sprintf "Caractère invalide '%c' à la position %d" c (i*9+j));
      grid.(i).(j) <- Char.code c - Char.code '0'
    done
  done;
  grid

let extract_solution s =
  let grid = Array.make_matrix 9 9 0 in
  for i = 0 to 8 do
    for j = 0 to 8 do
      let v = ref 0 in
      for k = 1 to 9 do
        let idx = var i j k - 1 in  (* conversion littéral → indice tableau *)
        if s.assigned.(idx) && s.assign.(idx) then
          v := k
      done;
      grid.(i).(j) <- !v
    done
  done;
  grid

let print_grid grid =
  for i = 0 to 8 do
    if i mod 3 = 0 && i <> 0 then
      print_string "+-------+-------+-------+\n";
    for j = 0 to 8 do
      if j mod 3 = 0 then print_string "| ";
      let v = grid.(i).(j) in
      if v = 0 then print_string ". "
      else Printf.printf "%d " v
    done;
    print_string "|\n"
  done

let print_grid_flat grid =
  for i = 0 to 8 do
    for j = 0 to 8 do
      print_char (Char.chr (grid.(i).(j) + Char.code '0'))
    done
  done;
  print_newline ()

(* ---------- Programme principal ---------- *)

let () =
  let input =
    if Array.length Sys.argv > 1 then
      Sys.argv.(1)
    else begin
      print_string "Entrez le sudoku (81 chiffres, 0 = vide) : ";
      flush stdout;
      input_line stdin
    end
  in

  Printf.printf "\n=== Sudoku en entrée ===\n";
  let grid = parse_grid input in
  print_string "+-------+-------+-------+\n";
  print_grid grid;
  print_string "+-------+-------+-------+\n\n";

  Printf.printf "=== Encodage CNF ===\n";
  let formula = build_cnf grid in
  Printf.printf "Nombre de variables : %d\n" nb_vars;
  Printf.printf "Nombre de clauses   : %d\n\n" (List.length formula);

  Printf.printf "=== Résolution par l'algorithme de Quine (DPLL) ===\n%!";
  let state = make_state () in
  (match dpll state formula with
   | None ->
     Printf.printf "Aucune solution trouvée (sudoku invalide ou sans solution).\n"
   | Some sol ->
     let result = extract_solution sol in
     Printf.printf "Solution trouvée !\n\n";
     Printf.printf "=== Sudoku résolu ===\n";
     print_string "+-------+-------+-------+\n";
     print_grid result;
     print_string "+-------+-------+-------+\n\n";
     Printf.printf "Représentation compacte :\n";
     print_grid_flat result)