let rec insert x l =
  match l with
  | [] -> [x]
  | h::t -> if x<h then x::h::t else  h::(insert x t)

let rec insert_sort l =
  match l with
  | [] -> []
  | h::t -> insert h (insert_sort t)

let rec get_max l =
  match l with 
  | [] -> failwith "Maximum d'une liste vide"
  | [x] -> x
  | h::t -> if h>get_max t then h else get_max t;

let rec select_sort l =
  match l with
  | [] -> []
  | x::t -> max l :: select_sort (remove (max l ) t)