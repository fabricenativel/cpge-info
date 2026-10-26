(* Évaluation directe d'une fonction anonyme *)
let a = (fun x -> x * x) 5;;

(* Fonction prenant une fonction en argument *)
let appliquer_deux_fois f x = f (f x);;
let b = appliquer_deux_fois (fun x -> 2 * x) 3;; (* vaut 12 *)

(* Fonction renvoyant une fonction *)
let derivee f dx = fun x -> (f (x +. dx) -. f x) /. dx;;
let cos_approx = derivee sin 1e-5;;
let c = cos_approx 0.;; (* proche de 1.0 *)

(* Composition de fonctions *)
let composer f g = fun x -> f (g x);;

(* Utilisation avec les fonctions sur les listes *)
let carres = List.map (fun x -> x * x) [1; 2; 3; 4];;
