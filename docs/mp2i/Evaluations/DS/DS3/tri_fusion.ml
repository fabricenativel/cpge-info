let rec fusion l1 l2 =
  match l1, l2 with
  | [], _ -> l2
  | _, [] -> l1
  | h1::t1, h2::t2 -> if h1<h2 then h1::(fusion t1 l2) else h2::(fusion l1 t2);;

let rec separe l =
  match l with
  |[] -> [], []
  |h::[] -> [h],[]
  |h1::h2::t  -> let l1,l2 = separe t in h1::l1, h2::l2;;

let rec tri_fusion l =
  match l with
  | [] -> []
  | h::[] -> [h]
  | _ -> let l1,l2 = separe l in
    let tl1 = tri_fusion l1 in
    let tl2 = tri_fusion l2 in
    fusion tl1 tl2;;
