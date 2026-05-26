
type litteral =
  | Var of int (* une variable logique *)
  | NVar of int (* la négation d'une variable logique*)
type clause = litteral list
type fnc = clause list


let rec print_clause c = 
  match c with
  | [] ->  Printf.printf " () ";
  | Var(n)::[] -> Printf.printf "p%d" n 
  | Var(n)::t -> Printf.printf "p%d ∨ " n; print_clause t 
  | NVar(n)::[] -> Printf.printf "¬p%d" n  
  | NVar(n)::t -> Printf.printf "¬p%d ∨ " n; print_clause t 
  
let rec print_fnc f=
  match f with
  | [] -> ()
  | h::[] -> print_string " ( ";print_clause h;print_string " ) "
  | h::t -> print_string " ( ";print_clause h;print_string " ) "; Printf.printf " ∧ "; print_fnc t;;

let cree_litteral n b =
  if b then NVar n else Var n;;

let extrait_var une_fnc =
  let aux une_clause = 
  match une_clause with
  | [] -> raise (Failure "Aucun littéral")
  | Var(n)::t -> n
  | NVar(n)::t -> n
  in
  match une_fnc with
  | [] -> raise (Failure "Aucun littéral")
  | h::t -> aux h;;

let rec supprime c l =
    match l with
    | [] -> []
    | h::t -> if h=c then t else h::supprime c t;;

let rec substitution une_fnc n v =
  match une_fnc with
  | [] -> []
  | h::t ->  (* Suppression entière de la clause si elle contient un litteral vrai *)
            if (v && List.mem (Var n) h) || (not v && List.mem (NVar n) h) then substitution t n v else
            (* Suppression du littéral de la clause si il est faux*)
            if (v && List.mem (NVar n) h) then (supprime( NVar n) h)::substitution t n v else
              if (not v && List.mem (Var n) h) then (supprime (Var n) h)::substitution t n v else
                h::substitution t n v;;

let satisfiable une_fnc = not (List.mem une_fnc []);;

let rec quine une_fnc valuation=
  match une_fnc with
  | [] -> true
  | []::t ->  false
  | h::t -> let p = extrait_var une_fnc in
            valuation.(p-1) <- true;
            let nf1 = substitution une_fnc p true  in
              if quine nf1 valuation  then true else 
                (valuation.(p-1) <- false;
                let nf2 = substitution une_fnc p false in
              if quine nf2 valuation  then true else false);;
  


  let () = let t = [ [Var 1; Var 2; NVar 3]
  ; [NVar 1; Var 2; Var 3]
  ; [Var 1; NVar 2; Var 3]
  ; [NVar 1; NVar 2; NVar 3] ] in
            let s = 3 in
          let valuation = Array.make s false in
         let res = quine t valuation in
         if res then
         (Printf.printf "Satisfiable : ";
         for i=0 to (s-1) do
          Printf.printf " %b" valuation.(i);
         done;
         print_newline ())
        else
          (Printf.printf "Non satisfiable \n";)
        ;;