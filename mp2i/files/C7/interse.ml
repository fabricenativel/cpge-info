let rec intersection l1 l2 =
  match l1, l2 with
  | l1, [] -> []
  | [], l2 -> []
  | h1::t1, h2::t2 -> 
    if h1=h2 then h1::(intersection t1 t2) else
      if h1<h2 then intersection t1 l2 
      else intersection l1 t2;;

let rec appartient x l =
  (* Cette fonction existe et s'appelle List.mem*)
  match l with
  | [] -> false
  | h::t -> h=x || appartient x t;;

  let rec inter2 l1 l2 =
    (* en utilisant appartient*)
    match l1 with
    | [] -> []
    | h::t -> if appartient h l2 then
              h::(inter2 t l2) else
              inter2 t l2;;
