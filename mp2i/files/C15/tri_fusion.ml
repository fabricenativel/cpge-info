let rec separe l =
  match l with
  | [] -> [],[]
  | [x] -> [x],[]
  | h1::h2::t-> let ft1,ft2 = (separe  t) in h1::ft1, h2::ft2;;

let rec fusion l1 l2 =
  match l1,l2 with 
  | [], x -> x
  | x, [] -> x
  | h1::t1, h2::t2 -> if h1<h2 then h1::(fusion t1 l2) else h2::(fusion l1 t2);;

let rec tri_fusion l =
  match l with
  | [] -> []
  | [x] -> [x]
  |  _ -> let l1,l2 = separe l in 
          let tl1 = tri_fusion l1 and tl2 = tri_fusion l2 in
          (fusion tl1 tl2);;