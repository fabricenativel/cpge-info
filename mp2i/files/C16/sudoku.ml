(* On représente une FNC sous la forme d'une liste de liste d'entiers :
chaque clause est une liste d'entiers, positif pour ou négatif si littéral vrai ou faux *)

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


  let num i j k =
    (*vrai si la valeur k figure ligne i colonne j*)
    81 * (i-1) + 9 * (j-1) + k

  let au_moins () =
    (*Renvoie la contrainte indiquant qu'au moins une valeur par case est vraie*)
    let lc = ref [] in
    for i=1 to 9 do
      for j=1 to 9 do
        lc := [List.init 9 (fun k-> num i j k)] @ !lc
      done;
    done;
    !lc;;

  let au_plus () =
    (*Renvoie la contrainte indiquant qu'il y a au plus une valeur par case*)
    let lc = ref [] in
    for i = 1 to 9 do
      for j = 1 to 9 do
        for k1 = 1 to 9 do
          for k2 = k1+1 to 9 do
            lc := [-(num i j k1); -(num i j k2)] :: !lc
          done;
        done;
      done;
    done;
    !lc;;

  let meme_ligne () =
    (*renvoie la liste des cases appartenant à une même ligne*)
    let ml = ref [] in
    for i = 1 to 9 do
      ml := List.init 9 (fun j -> (i,j+1))::!ml
    done;
    !ml;;

let meme_colonne () =
  (*Renvoie la liste des cases appartenant à une même colonne*)
  let mc = ref [] in
    for i = 1 to 9 do
      mc := List.init 9 (fun j -> (j+1,i))::!mc
    done;
    !mc;;

let meme_bloc ()=
(*Renvoie la liste des cases appartenant à un même bloc*)
(*(i,j) est la case supérieure gauche du bloc*)
let i = ref 1 in
let j = ref 1 in
let mb = ref [] in
let cases = ref [] in
while !i<9 do 
  j := 1;
  while !j<9 do
    cases := [];
    for k = 0 to 2 do
      for l = 0 to 2 do
        cases := (!i+k, !j+l)::!cases
      done;
    done;
    mb := !cases::!mb;
    j := !j + 3;
  done;
  i := !i + 3;
done;
!mb;;

let rec une_fois_au_moins lcases =
  let aux cases =
  (*Indique qu'une valeur apparait au moins une fois dans la listes cases *)
  let lc = ref [] in
  for k=1 to 9 do
    lc := List.map (fun (i,j)-> num i j k) cases::!lc;
  done;
  !lc in
  match lcases with
  | [] -> []
  | h::t -> aux h @ une_fois_au_moins t
;;

let rec une_fois_au_plus lcases =
  let aux cases =
  (*Indique qu'une valeur apparait au plus une fois dans la listes cases *)
  let lc = ref [] in
  for k1=1 to 9 do
    for k2=k1+1 to 9 do
    lc := List.map (fun (i,j)-> [-(num i j k1); -(num i j k2)]) cases @ !lc;
  done;
done;
  !lc in
  match lcases with
  | [] -> []
  | h::t -> aux h @ une_fois_au_plus t
;;

let () =
let contraintes =[
  [num 1 1 5]; [num 1 2 3]; [num 1 5 7]; 
  [num 2 1 6]; [num 2 4 1]; [num 2 5 9]; [num 2 6 5]; 
  [num 3 2 9]; [num 3 3 8]; [num 3 8 6];
  [num 4 1 8]; [num 4 5 6]; [num 4 9 3];
  [num 5 1 4]; [num 5 4 8]; [num 5 6 3]; [num 5 9 1];
  [num 6 1 7]; [num 6 5 2]; [num 6 9 6];
  [num 7 2 6]; [num 7 7 2]; [num 7 8 8];
  [num 8 4 4]; [num 8 5 1]; [num 8 6 9]; [num 8 9 5];
  [num 9 5 8]; [num 9 8 7]; [num 9 9 9]
] in
let lignes = une_fois_au_plus (meme_ligne ()) @ (une_fois_au_moins (meme_ligne ())) in
let colonnes = une_fois_au_plus (meme_colonne ()) @ (une_fois_au_moins (meme_colonne ())) in
let blocs = une_fois_au_plus (meme_bloc ()) @ (une_fois_au_moins (meme_bloc ())) in
let sudoku = contraintes @ au_moins () @ au_plus () @ lignes @ colonnes @ blocs in
Printf.printf "Formule logique construite - début de résolution \n";
let ok, valuation = quine sudoku in
if ok then
for i = 0 to (Array.length valuation -1) do
  if valuation.(i) then Printf.printf "%i \n" i;
done
else
  Printf.printf "Non satisfiable ! \n";
;;