let rec taille liste =
  match liste with
  | [] -> 0
  | h::t -> 1 + taille t

let rec est_dans elt liste =
  match liste with
  | [] -> false
  | h::t -> elt=h || est_dans elt t

let rec cree_liste elt rep =
  if rep = 0 then [] else elt::(cree_liste elt (rep-1))

let rec separe l =
  match l with
  | [] -> [], []
  | h::t -> let lpos, lneg = separe t in 
    if h>=0 then h::lpos,lneg else lpos,h::lneg
  
let indice_max liste =
    let rec indice_max_aux liste cmax limax pos =
  match liste with
  | [] -> limax
  | h::t -> if h<cmax then (indice_max_aux t cmax limax (pos+1)) else
    if h==cmax then (indice_max_aux t cmax (limax@[pos]) (pos+1)) else
    indice_max_aux t h [pos] (pos+1) 
    in
  indice_max_aux (List.tl liste) (List.hd liste) [0] 0




