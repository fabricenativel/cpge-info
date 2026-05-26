let make_start n =
let rec aux n acc  =
  if n==1 then acc else aux (n-1) ((n,true)::acc) in
  aux n [] ;;

let rec first_true crible =
  match crible with
  | [] -> -1
  | (x,true)::t -> x
  | (x,false)::t -> first_true t
