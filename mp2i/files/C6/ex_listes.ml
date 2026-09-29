


(*longueur : 'a list -> int renvoie la longueur de la liste*)
let rec longueur lst =
  match lst with
  | [] -> 0
  | head::tail -> 1 + longueur tail ;;

(*appartient : 'a -> 'a list -> bool renvoie true ssi l'élément appartient à la liste*)
let rec appartient x lst =
  match lst with
  | [] -> false
  | h::t -> x=h || appartient x t;;

(*occurrences : 'a -> 'a list -> int renvoie le nombre d'occurrences d'un élément dans une liste*)
let rec occurrence x lst =
  match lst with
  | [] -> 0
  | h::t -> let n = occurrence x t in
            if x=h then 1+n else n;;

(* repete : 'a -> int -> 'a list renvoie une liste contenant la répétition du même élément n fois*)
let rec repete  elt n =
  if n=0 then [] else
    elt::(repete elt (n-1));;


(*Somme : int list -> int renvoie la somme des entiers de la liste*)
let rec somme lst =
  match lst with
  | [] -> 0
  | h::t -> h + somme t;;

type entieropt =
| Napoint
| Entier of int;;

(* nieme : 'a list -> int -> 'a renvoie le nième élément de la liste*)
let rec nieme lst n =
  match lst with
  | [] -> None
  | h::t -> if n=1 then (Some h) else nieme t (n-1);;

let add n m =
  match n,m with
  | None, None -> None
  | Some p, Some q -> Some (p+q)
  | None, Some q -> None
  | Some p, None -> None;;

(*Supprime : 'a -> 'a list -> 'a list supprime la première occurrence de l'élément dans la liste*)
let rec supprime x lst =
  match lst with
  | [] -> []
  | h::t -> if x=h then t else h::supprime x t;;

(*croissant 'a list -> bool qui renvoie true ssi la liste est triée *)
let rec croissant lst =
  match lst with
  | [] -> true
  | h::[] -> true
  | h1::h2::t -> if h1<=h2 then croissant (h2::t) else false;;

(*Minimum : 'a list -> 'a renvoie le minimum de la liste *)
let rec minimum lst =
  match lst with
  | [] -> failwith "Liste vide"
  | h::[] -> h
  | h::t -> let mint = minimum t in 
            if h<mint then h else mint;;


(*min_reste 'a list -> 'a * 'a list renvoie le plus petit élément de lst ainsi que lst privé de ce plus petit élément*)
let rec min_reste lst =
  match lst with
  | [] -> failwith "Echec, liste vide"
  | h::[] -> h, []
  | h::t -> let mint, restet = min_reste t  in
            if h<mint then h, t else mint, h::restet;;

(* tri_selection 'a list -> 'a list renvoie la liste triée en utilisant l'algorithme du tri par sélection*)
let rec tri_selection lst =
  match lst with
  | [] -> []
  | _ -> let m,r = min_reste lst in 
        m::(tri_selection r);;

let somme n =
  (*Renvoie la somme des n premiers entiers *)
  List.fold_left ( + ) 0 (List.init n (fun m->m));;

(* retourne 'a list -> 'a list renvoie a liste retournée, on pourra dans un premier temps utiliser l'opérateur de concaténation de liste puis faire sans en utilisant une fonction auxiliaire 'a list -> 'a list -> 'a list qui renvoie la liste retournée concaténée avec le second paramètre*)
let retourne lst =
  let rec aux lst acc =
    (*Renvoie lst retournée et concaténée avec acc*)
    match lst with
    | [] -> acc
    | h::t -> aux t (h::acc) in
  aux lst [];;
