(* Type "variable"  ayant un champ valeur mutable*)
type variable = {mutable valeur : int};;

(* on crée une variable ayant son champ valeur à 42 *)
let u = {valeur = 42};;

(* comme ce champ est mutable, on change la valeur avec <-*)
u.valeur <- 20;
(* cette expression renvoie unit et modifie la valeur de u*)

(* Affichera 20 *)
print_int u.valeur
