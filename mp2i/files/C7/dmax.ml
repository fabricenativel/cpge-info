(* Maximum d'une liste d'entiers avec correspondance de motifs *)
(* Liste videe géré avec failwith *)

let rec maxl1 l = 
  match l with
  | [] -> failwith "Liste vide"
  | h::[] -> h
  | h::t -> 
      let m = maxl1 t in
      if h > m  then h else m;;

(* Maximum des éléments d'une liste avec List.fold_left *)
(* Liste vide gérée avec type option *)

let maxl2 l =
  (* si la liste est vide c'est None *)
  if l=[] then None else
    Some (List.fold_left (fun a b -> if a>b then a else b) Int.min_int l);;