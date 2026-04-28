

let choix_variable fnc =
  (*Si la fnc contient une clause ayant un littéral alors renvoie ce littéral sinon renvoie un des littéraux présent dans une des plus petites clauses*)
  let rec aux fnc cmin littmin =
    match fnc with
    | [] -> littmin
    | []::t -> failwith "Erreur, la fnc contient une clause vide !"
    | h::t -> let nblitt = List.length h in
      let un_litt = List.hd h in
      if nblitt=1 then un_litt else
      if nblitt<cmin then aux t nblitt un_litt
      else aux t cmin littmin 
  in
  aux fnc Int.max_int 0;;

let maxvar fnc =
  let aux cl =
    List.fold_left (fun a b -> if a>abs(b) then a else abs(b))  0 cl in
  aux (List.map aux fnc);;

let substitue_clause clause v b =
  if (List.mem v clause && b) || (List.mem (-v) clause && (not b)) then [0] 
  else List.filter (fun x -> x<>v && x<>(-v)) clause;;

let substitue fnc v b =
  List.filter (fun x -> x<>[0]) (List.map (fun cl -> substitue_clause cl v b) fnc);; 

let quine fnc = 
  let nbvar = maxvar fnc in
  let valuation = Array.make nbvar false in
  let rec aux fnc valuation = 
    if List.mem [] fnc then false else
    if fnc = [] then true
    else
      let cv = choix_variable fnc in
      let idx = abs(cv) - 1 in
      let old = valuation.(idx) in
      valuation.(idx) <- (cv > 0);
      let nouvelle_fnc1 = substitue fnc (abs(cv)) valuation.(idx) in
      if aux nouvelle_fnc1 valuation then true else
        let opposite = not (cv > 0) in
        valuation.(idx) <- opposite;
        let nouvelle_fnc2 = substitue fnc (abs(cv)) valuation.(idx) in
        if aux nouvelle_fnc2 valuation then true else
          (valuation.(idx) <- old; false)
  in
  let res = aux fnc valuation in
  res, valuation
;;



(** var i j k : numéro de la variable propositionnelle x[i][j][k]
    i = ligne, j = colonne, k = valeur (tous dans 1..9) *)
let var i j k =
  81 * i + 9 * j + k+1

(* --- Génération des contraintes --- *)

(** 1. Chaque case (i,j) contient AU MOINS une valeur *)
let at_least_one_value () =
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
let at_most_one_value () =
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
let row_constraints ()  =
  let clauses = ref [] in
  for i = 1 to 9 do
    for k = 1 to 9 do
      let clause = List.init 9 (fun j -> var i (j + 1) k) in
      clauses := clause :: !clauses
    done
  done;
  !clauses

(** 4. Chaque valeur k apparaît AU MOINS une fois dans chaque colonne j *)
let col_constraints ()  =
  let clauses = ref [] in
  for j = 1 to 9 do
    for k = 1 to 9 do
      let clause = List.init 9 (fun i -> var (i + 1) j k) in
      clauses := clause :: !clauses
    done
  done;
  !clauses

(** 5. Chaque valeur k apparaît AU PLUS une fois dans chaque ligne *)
let row_unique_constraints ()  =
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
let col_unique_constraints ()  =
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
let box_constraints ()  =
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
let box_unique_constraints ()  =
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
let given_constraints (grid )  =
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
let encode (grid )  =
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

let print_grid (grid ) =
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

let print_dimacs (cnf ) =
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

let print_summary (cnf ) (grid ) =
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

let parse_grid (s : string)  =
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