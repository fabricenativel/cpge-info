
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

(* e_star = a*(ab)* *)
let e_star = Concat(Star (Letter "a"), Star (Concat (Letter "a", Letter "b")))

(** [union l1 l2] returns the sorted list containing the elements of [l1] and [l2] without duplicates. Both inputs are expected to be sorted in ascending order and without duplicates*)
let rec union (l1:'a list) (l2:'a list) = match l1, l2 with
  |[], l |l, [] -> l
  |t::q, a::b when t < a -> t::(union q (a::b))
  |t::q, a::b when t = a -> t::(union q b)
  |t::q, a::b -> a::(union (t::q) b)

let l1 = ["a";"ab";"c";"da"] and l2 = ["a"; "ac"; "ad"; "d"; "da"] in union l1 l2

(** [contains_epsilon e] returns true if and only if epsilon is in the langage denoted by e *)
let rec contains_epsilon (e:regexp) :bool = match e with
  |Epsilon -> true
  |Letter _ -> false
  |Union (e1, e2) -> (contains_epsilon e1) || (contains_epsilon e2)
  |Concat (e1, e2) -> (contains_epsilon e1) && (contains_epsilon e2)
  |Star _ -> true

(** [compute_P e] returns the list of letters that can start a word in the langage denoted by e *)
let rec compute_P (e:regexp) :string list = match e with
  |Epsilon -> []
  |Letter a -> [a]
  |Union (e1, e2) -> union (compute_P e1) (compute_P e2)
  |Concat (e1, e2) when contains_epsilon e1 -> union (compute_P e1) (compute_P e2)
  |Star e1 |Concat (e1, _) -> (compute_P e1)

let _ = compute_P e_star

let rec compute_D (e:regexp) :string list  = match e with
  |Epsilon -> []
  |Letter a -> [a]
  |Union (e1, e2) -> union (compute_D e1) (compute_D e2)
  |Concat (e1, e2) when contains_epsilon e2 -> union (compute_D e1) (compute_D e2)
  |Star e1 |Concat (_, e1) -> (compute_D e1)

let _ = compute_D e_star

(** [l1] and [l2] are expected to be lists containing strings of length one sorted in increasing order and without duplicates. [prod l1 l2] computes the "product" of [l1] and [l2]. The output is still sorted and (obviously) without duplicates.*)
let rec prod (l1:string list) (l2:string list) = match l1, l2 with
  |[], _ |_, [] -> []
  |t::q, l -> union (List.map (fun x -> t^x) l) (prod q l)

let l1 = ["a";"c";"d"] and l2 = ["a"; "e"] in prod l1 l2

let rec compute_F (e:regexp) :string list = match e with
  |Epsilon |Letter _ -> []
  |Union (e1, e2) -> union (compute_F e1) (compute_F e2)
  |Concat (e1, e2) -> let d_e1 = compute_D e1 and p_e2 = compute_P e2 in
                      union (union (compute_F e1) (compute_F e2)) (prod d_e1 p_e2)
  |Star e1 -> let d_e1 = compute_D e1 and p_e1 = compute_P e1 in
              union (compute_F e1) (prod d_e1 p_e1)

let _ = compute_F e_star

(* e_sum = a* + (ab)* *)
let e_sum = Union(Star (Letter "a"), Star (Concat(Letter "a", Letter "b")))
let _ = compute_P e_sum
let _ = compute_D e_sum
let _ = compute_F e_sum
