let rec somme l =
  match l with
  | [] -> 0
  | h::t -> h + somme t