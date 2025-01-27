let rec insertion elt ltriee =
  match ltriee with
  | [] -> [elt]
  | h::t -> if h<elt then h::(insertion elt t) else elt::h::t

let rec tri_insertion entiers =
  match entiers with
  | [] -> []
  | h::t -> insertion h (tri_insertion t)