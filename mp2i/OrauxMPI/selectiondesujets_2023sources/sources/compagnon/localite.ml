
(******************************************************)
(* Concours commun INP                                *)
(* https://www.concours-commun-inp.fr                 *)
(* CC BY-NC-SA, Novembre 2023                         *)
(* https://creativecommons.org/licenses/by-nc-sa/4.0/ *)
(******************************************************)

type regexp =
  | Epsilon
  | Letter of string
  | Union of regexp * regexp
  | Concat of regexp * regexp
  | Star of regexp

(** Entrée : deux listes l1 et l2 dont les éléments sont de même nature et sont triés dans l'ordre croissant
Sortie : une liste l contenant tous les éléments de l1 et de l2 sans doublons et triée dans l'ordre croissant *)
let rec union (l1:'a list) (l2:'a list) :'a list = match l1, l2 with
  |[], l |l, [] -> l
  |t::q, a::b when t < a -> t::(union q (a::b))
  |t::q, a::b when t = a -> t::(union q b)
  |t::q, a::b -> a::(union (t::q) b)

(** Entrée : une expression régulière e
Sortie : la liste des premières lettres des mots du langage dénoté par e
ATTENTION : On ne pourra tester cette fonction qu'après avoir implémenté contains_epsilon *)
let rec compute_P (e:regexp) :string list = match e with
  |Epsilon -> []
  |Letter a -> [a]
  |Union (e1, e2) -> union (compute_P e1) (compute_P e2)
  |Concat (e1, e2) when contains_epsilon e1 -> union (compute_P e1) (compute_P e2)
  |Star e1 |Concat (e1, _) -> (compute_P e1)

