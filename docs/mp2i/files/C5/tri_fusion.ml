let rec separe l =
  match l with 
  | [] -> [],[]
  | x::[] -> [x],[]
  | x::y::t -> let l1,l2 = separe t in x::l1,y::l2

let rec fusion l1 l2 =
  match l1,l2 with
  |x, [] -> x
  |[], y -> y
  |h1::t1, h2::t2 -> if h1<h2 then  h1 :: (fusion t1 (h2::t2)) else  h2::(fusion (h1::t1) t2)

let rec tri_fusion l =
  match l with
  | [] -> []
  | h::[] -> [h]
  | _ -> let l1,l2 = separe l in fusion (tri_fusion l1) (tri_fusion l2)


let rec affiche l =
  Printf.printf "[";
  let rec affiche_elts ll =
    match ll with 
    | [] -> Printf.printf "]"
    | x::[] -> Printf.printf "%d]" x
    | x::h -> Printf.printf "%d; " x; affiche_elts h  in
  affiche_elts l

