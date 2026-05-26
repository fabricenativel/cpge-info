let rec insert_all x l =
  match l with
  | [] -> [[x]]
  | h::t -> (x::l)::(List.map (fun y->h::y) (insert_all x t));;

let rec permutation l =
  match l with
  | [] -> [[]]
  | h::t -> let pt=permutation t in List.flatten(List.map (fun x->insert_all h x) pt);;
