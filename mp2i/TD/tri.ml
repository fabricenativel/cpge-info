(* Vérifie qu'une liste est triée par ordre croissant *)
let rec est_triee = function
  | [] | [_] -> true
  | x :: (y :: _ as t) -> x <= y && est_triee t
