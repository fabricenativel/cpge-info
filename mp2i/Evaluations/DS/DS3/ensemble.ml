let rec est_ensemble l =
  match l with
  | [] -> true
  | h::[] -> true
  | h1::h2::t -> h1<h2 && est_ensemble (h2::t);;


let rec appartient x l =
  match l with
  | [] -> false
  | h::t -> if h=x then true else
    if h>x then false else appartient x t;;


let rec union l1 l2 =
  match l1, l2 with
  | [], l2 -> l2
  | l1, [] -> l1
  | h1::t1, h2::t2 -> if h1<h2 then h1::(union t1 l2) else 
    if h1=h2 then h1::(union t1 t2) else 
      h2::(union l1 t2);;

let rec intersection ens1 ens2 =
  match ens1, ens2 with
  | [], ens2 -> []
  | ens1, [] -> []
  | e1::r1, e2::r2 -> if e1=e2 then e1::(intersection r1 r2) else
    if e1<e2 then intersection r1 ens2 else
      intersection r2 ens1;;