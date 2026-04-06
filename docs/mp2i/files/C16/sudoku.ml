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
    