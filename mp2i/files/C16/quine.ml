
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
            valuation.(p) <- true;
            let nf1 = substitution une_fnc p true  in
              if quine nf1 valuation  then true else 
                (valuation.(p) <- false;
                let nf2 = substitution une_fnc p false in
              if quine nf2 valuation  then true else false);;
  


  let () = let j1 = [[Var 8];[Var 9]] in
           let j2 = [[Var 4; Var 6; Var 7]] in
           let j3 = [[Var 3];[Var 5]] in
           (* Unicité du jour ou on est et du jour où le sphinx ment*)
           let uni_jour = ref [] in
           let cl1 = ref [] in
           let cl2 = ref [] in
           for  i=1 to 7 do
            cl1 := [];
            cl2 := [];
            for j=1 to 7 do
              if  i=j then (cl1:= (Var j)::!cl1; cl2:= (Var (j+7))::!cl2;)
               else  (cl1:=(NVar j)::!cl1; cl2:=(NVar (j+7))::!cl2)
            done;
            uni_jour := !cl1::!cl2::!uni_jour
          done;
          print_fnc (j1@j2@j3);
          let enigme = j1@j2@j3@ (!uni_jour) in
          let valuation = Array.make 15 false in
         let res = quine enigme valuation in
         Printf.printf "Résolution = %b\n" res;
         for i=8 to 14 do
          Printf.printf "Ment jour %d = %b\n" i res
         done
        ;;