let rec insert_all elt liste =
  match liste with
  | [] -> [[elt]]
  | h::t -> let temp = insert_all elt t  in (elt::liste)::(List.map (fun l -> h::l) temp);;

let rec permutation liste =
  match liste with
  | [] -> [[]]
  | h::t -> let temp = permutation t in  List.flatten (List.map (fun x -> insert_all h x)  temp);;