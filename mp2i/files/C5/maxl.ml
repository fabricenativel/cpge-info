
(* Renvoie le maximum des éléments d'une liste *)
let rec maximum l =
  match l with
  | [] -> None
  | h::[] -> Some h
  | h::t -> 
    match maximum t with 
    | Some maxt -> if maxt>h then Some maxt else Some h;;