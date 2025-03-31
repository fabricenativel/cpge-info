let rec est_dans n l =
  (* Renvoie true si n est dans l et false sinon*)
  match l with
  | [] -> false
  | h::t -> h=n || est_dans n t;;

let seau n size =
  (* Renvoie le numéro de l'alvéole dans laquelle doit être rangée n*)
  n mod size;;

let appartient n ensemble size =
(* renvoie true si n est dans ensemble (représenté par une table de hachage int list array)*)
est_dans n (ensemble.(seau n size));;