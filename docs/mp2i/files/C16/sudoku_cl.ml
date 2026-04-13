(* ============================================================
   Encodage d'un Sudoku en formule logique CNF (DIMACS)
   ============================================================
   Variable x[i][j][k] = la case (i,j) contient la valeur k
   Encodée comme entier : var(i,j,k) = 81*(i-1) + 9*(j-1) + k
   avec i,j,k dans {1..9}
   ============================================================ *)

(* --- Représentation --- *)

(* Grille : 0 = case vide, 1-9 = valeur fixée *)
type grid = int array array

(* Une clause = liste de littéraux (entier, négatif si nié) *)
type clause = int list

(* Formule CNF = liste de clauses *)
type cnf = clause list

(* --- Encodage des variables --- *)


let rec get_max lst =
  match lst with
  | [] -> failwith "Maximum liste vide "
  | h::[] -> abs(h)
  | h::t -> let mr = get_max t in if abs(h)> mr then h else mr;;

let maxvar fnc =
  get_max (List.map get_max fnc);;


let rec print_clause c = 
  match c with
  | [] ->  Printf.printf " () ";
  | n::[] -> if n>=0 then Printf.printf "p%d" n else  Printf.printf "¬p%d" n  
  | n::t -> if n>=0 then Printf.printf "p%d ∨ " n else Printf.printf "¬p%d ∨ " (-n); print_clause t ;;

let rec print_fnc f=
  match f with
  | [] -> ()
  | h::[] -> print_string " ( ";print_clause h;print_string " ) "
  | h::t -> print_string " ( ";print_clause h;print_string " ) "; Printf.printf " ∧ "; print_fnc t;;

let get_var fnc =
  match fnc with
  | [] -> failwith "fnc vide"
  | []::t -> failwith "clause vide"
  | h::t -> abs(List.hd h);;

let rec remove var lst =
  (*Supprimer un littéral d'une clause*)
  match lst with
  | [] -> []
  |h::t -> if (h=var || h=(-var)) then t else h::(remove var t);;

let satisfiable fnc = not (List.mem fnc []);;

let rec substitution fnc n v =
  match fnc with
  | [] -> []
  | h::t ->  (* Suppression entière de la clause si elle contient un litteral vrai *)
            if (v && List.mem n h) || (not v && List.mem (-n) h) then substitution t n v else
            (* Suppression du littéral de la clause si il est faux*)
            if ((v && List.mem (-n) h) || (not v && List.mem n h))then (remove n h)::substitution t n v else
                h::substitution t n v;;


let quine fnc =
  (* nombre de variables = plus grand numéro de variables *)
  let nbvar = maxvar fnc in
  let valuation = Array.make (nbvar+1) false in
  let rec aux_quine fl = 
  match fl with
  | [] -> (true, valuation)
  | []::t ->  (false, valuation)
  | h::t -> let p = get_var fl in
            valuation.(p) <- true;
            let nf1 = substitution fl p true  in
              if fst (aux_quine nf1) then (true, valuation) else 
                (valuation.(p) <- false;
                let nf2 = substitution fl p false in
              if fst (aux_quine nf2) then (true, valuation) else (false, valuation)) in
  aux_quine fnc;;



(** var i j k : numéro de la variable propositionnelle x[i][j][k]
    i = ligne, j = colonne, k = valeur (tous dans 1..9) *)
let var i j k =
  81 * (i - 1) + 9 * (j - 1) + k

(* --- Génération des contraintes --- *)

(** 1. Chaque case (i,j) contient AU MOINS une valeur *)
let at_least_one_value () : cnf =
  let clauses = ref [] in
  for i = 1 to 9 do
    for j = 1 to 9 do
      let clause = List.init 9 (fun k -> var i j (k + 1)) in
      clauses := clause :: !clauses
    done
  done;
  !clauses

(** 2. Chaque case (i,j) contient AU PLUS une valeur
    Pour chaque paire (k1, k2), on ne peut pas avoir les deux *)
let at_most_one_value () : cnf =
  let clauses = ref [] in
  for i = 1 to 9 do
    for j = 1 to 9 do
      for k1 = 1 to 9 do
        for k2 = k1 + 1 to 9 do
          clauses := [-(var i j k1); -(var i j k2)] :: !clauses
        done
      done
    done
  done;
  !clauses

(** 3. Chaque valeur k apparaît AU MOINS une fois dans chaque ligne i *)
let row_constraints () : cnf =
  let clauses = ref [] in
  for i = 1 to 9 do
    for k = 1 to 9 do
      let clause = List.init 9 (fun j -> var i (j + 1) k) in
      clauses := clause :: !clauses
    done
  done;
  !clauses

(** 4. Chaque valeur k apparaît AU MOINS une fois dans chaque colonne j *)
let col_constraints () : cnf =
  let clauses = ref [] in
  for j = 1 to 9 do
    for k = 1 to 9 do
      let clause = List.init 9 (fun i -> var (i + 1) j k) in
      clauses := clause :: !clauses
    done
  done;
  !clauses

(** 5. Chaque valeur k apparaît AU PLUS une fois dans chaque ligne *)
let row_unique_constraints () : cnf =
  let clauses = ref [] in
  for i = 1 to 9 do
    for k = 1 to 9 do
      for j1 = 1 to 9 do
        for j2 = j1 + 1 to 9 do
          clauses := [-(var i j1 k); -(var i j2 k)] :: !clauses
        done
      done
    done
  done;
  !clauses

(** 6. Chaque valeur k apparaît AU PLUS une fois dans chaque colonne *)
let col_unique_constraints () : cnf =
  let clauses = ref [] in
  for j = 1 to 9 do
    for k = 1 to 9 do
      for i1 = 1 to 9 do
        for i2 = i1 + 1 to 9 do
          clauses := [-(var i1 j k); -(var i2 j k)] :: !clauses
        done
      done
    done
  done;
  !clauses

(** 7. Contraintes de bloc 3×3 : AU MOINS une fois *)
let box_constraints () : cnf =
  let clauses = ref [] in
  for bi = 0 to 2 do
    for bj = 0 to 2 do
      for k = 1 to 9 do
        let clause = ref [] in
        for di = 1 to 3 do
          for dj = 1 to 3 do
            let i = 3 * bi + di in
            let j = 3 * bj + dj in
            clause := (var i j k) :: !clause
          done
        done;
        clauses := !clause :: !clauses
      done
    done
  done;
  !clauses

(** 8. Contraintes de bloc 3×3 : AU PLUS une fois *)
let box_unique_constraints () : cnf =
  let clauses = ref [] in
  for bi = 0 to 2 do
    for bj = 0 to 2 do
      for k = 1 to 9 do
        let cells = ref [] in
        for di = 1 to 3 do
          for dj = 1 to 3 do
            cells := (3 * bi + di, 3 * bj + dj) :: !cells
          done
        done;
        let cells = !cells in
        let rec pairs = function
          | [] -> []
          | (i1, j1) :: rest ->
            List.map (fun (i2, j2) ->
              [-(var i1 j1 k); -(var i2 j2 k)]
            ) rest @ pairs rest
        in
        clauses := (pairs cells) @ !clauses
      done
    done
  done;
  !clauses

(** 9. Cases préremplies : clauses unitaires *)
let given_constraints (grid : grid) : cnf =
  let clauses = ref [] in
  for i = 1 to 9 do
    for j = 1 to 9 do
      let v = grid.(i-1).(j-1) in
      if v <> 0 then
        clauses := [var i j v] :: !clauses
    done
  done;
  !clauses

(** Assemblage de toutes les clauses *)
let encode (grid : grid) : cnf =
  at_least_one_value ()
  @ at_most_one_value ()
  @ row_constraints ()
  @ col_constraints ()
  @ row_unique_constraints ()
  @ col_unique_constraints ()
  @ box_constraints ()
  @ box_unique_constraints ()
  @ given_constraints grid

(* --- Affichage --- *)

let print_grid (grid : grid) =
  Printf.printf "Grille Sudoku en entrée :\n";
  for i = 0 to 8 do
    if i mod 3 = 0 then Printf.printf "+-------+-------+-------+\n";
    for j = 0 to 8 do
      if j mod 3 = 0 then Printf.printf "| ";
      let v = grid.(i).(j) in
      if v = 0 then Printf.printf ". "
      else Printf.printf "%d " v
    done;
    Printf.printf "|\n"
  done;
  Printf.printf "+-------+-------+-------+\n\n"

let print_dimacs (cnf : cnf) =
  let nb_vars = 729 in
  let nb_clauses = List.length cnf in
  Printf.printf "c Encodage CNF d'un Sudoku\n";
  Printf.printf "c Variables : x[i][j][k] = var(i,j,k) = 81*(i-1)+9*(j-1)+k\n";
  Printf.printf "c %d variables, %d clauses\n" nb_vars nb_clauses;
  Printf.printf "p cnf %d %d\n" nb_vars nb_clauses;
  List.iter (fun clause ->
    List.iter (fun lit -> Printf.printf "%d " lit) clause;
    Printf.printf "0\n"
  ) cnf

let print_summary (cnf : cnf) (grid : grid) =
  let given = given_constraints grid in
  let structural =
    at_least_one_value ()
    @ at_most_one_value ()
    @ row_constraints ()
    @ col_constraints ()
    @ row_unique_constraints ()
    @ col_unique_constraints ()
    @ box_constraints ()
    @ box_unique_constraints ()
  in
  Printf.printf "=== Résumé de l'encodage CNF ===\n";
  Printf.printf "Variables propositionnelles : 729 (9×9×9)\n";
  Printf.printf "  x[i][j][k] = case (i,j) contient la valeur k\n\n";
  Printf.printf "Clauses structurelles       : %d\n" (List.length structural);
  Printf.printf "  - Au moins une valeur/case : 81\n";
  Printf.printf "  - Au plus une valeur/case  : %d\n" (List.length (at_most_one_value ()));
  Printf.printf "  - Unicité par ligne        : %d\n" (List.length (row_unique_constraints ()));
  Printf.printf "  - Unicité par colonne      : %d\n" (List.length (col_unique_constraints ()));
  Printf.printf "  - Unicité par bloc 3×3     : %d\n" (List.length (box_unique_constraints ()));
  Printf.printf "  - Couverture ligne         : 81\n";
  Printf.printf "  - Couverture colonne       : 81\n";
  Printf.printf "  - Couverture bloc          : 81\n\n";
  Printf.printf "Clauses des cases fixées    : %d\n" (List.length given);
  Printf.printf "─────────────────────────────────\n";
  Printf.printf "Total                       : %d clauses\n\n" (List.length cnf)

(* --- Parsing de la grille --- *)

let parse_grid (s : string) : grid =
  if String.length s < 81 then
    failwith "La chaîne doit contenir au moins 81 caractères";
  let grid = Array.make_matrix 9 9 0 in
  for i = 0 to 8 do
    for j = 0 to 8 do
      let c = s.[i * 9 + j] in
      grid.(i).(j) <- (match c with
        | '1'..'9' -> Char.code c - Char.code '0'
        | '0' | '.' -> 0
        | _ -> failwith (Printf.sprintf "Caractère invalide : '%c'" c))
    done
  done;
  grid

(* --- Programme principal --- *)

let () =
  let sudoku_str =
    "530070000" ^
    "603195000" ^
    "098000060" ^
    "800060003" ^
    "400803001" ^
    "700020006" ^
    "060000280" ^
    "000419005" ^
    "000080079" 
  in

  Printf.printf "=== Encodeur Sudoku → CNF (OCaml) ===\n\n";

  let grid = parse_grid sudoku_str in
  print_grid grid;

  let sudoku = encode grid in
  let ok, valuation = quine sudoku in
if ok then
for i = 0 to (Array.length valuation -1) do
  if valuation.(i) then Printf.printf "%i \n" i;
done
else
  Printf.printf "Non satisfiable ! \n";
;;