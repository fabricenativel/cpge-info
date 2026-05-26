let rec separe l pivot =
  match l with 
  | [] -> [], []
  | h::t -> let l1,l2 = separe t pivot in if h<pivot then h::l1,l2 else 
    if h>pivot then l1,h::l2 else l1,l2;;

let rec tri_rapide l =
  match l with
  | [] -> []
  | [x] -> [x]
  | h::t ->  let l1,l2 = separe l h in
  let lt1 = tri_rapide l1 in
  let lt2 = tri_rapide l2 in
  lt1 @ (h::lt2);;