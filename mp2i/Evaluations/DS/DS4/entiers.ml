let rec succ_list entiers x =
  match entiers with
  | [] -> -1
  | h::t -> if h>x then h else succ_list t x

let rec intersection l1 l2 =
  match l1, l2 with
  | l1, [] -> []
  | [], l1 -> []
  | h1::t1, h2::t2 -> if h1 = h2 then h1::(intersection t1 t2) else
    if h1 < h2 then intersection t1 l2 else intersection l1 t2;;

let succ_vect entiers x =
  if x >= entiers.(entiers.(0)) then -1 else 
  if x< entiers.(1) then entiers.(1) else
    let rec aux entiers x deb fin =
      let mil = (deb+fin)/2 in
      if entiers.(mil) = x then entiers.(mil+1) else
        if entiers.(mil)<x then aux entiers x mil fin else aux entiers x deb mil
    in
    aux entiers x 1 entiers.(0)
  ;;

let size = 100;;

let union t1 t2 = 
  let r = Array.make size 0 in
    let rec aux  t1 t2 i1 i2 i =
      if i1>t1.(0) && i2>t2.(0) then 
        (r.(0) <- i-1;
        r)
      else(
      if i1>t1.(0) then 
        (r.(i) <- t2.(i2);
        aux  t1 t2 i1 (i2+1) (i+1)) else
      if i2>t2.(0) then 
          (r.(i) <- t1.(i1);
          aux  t1 t2 (i1+1) i2 (i+1)) else
      if t1.(i1) = t2.(i2) then 
        (r.(i) <- t1.(i1);
        aux  t1 t2 (i1+1) (i2+1) (i+1)) else
      if t1.(i1) < t2.(i2) then
        (r.(i) <- t1.(i1);
        aux  t1 t2 (i1+1) i2 (i+1)) else
          (r.(i) <- t2.(i2);
          aux  t1 t2 i1 (i2+1) (i+1))
      ) in
      aux t1 t2 1 1 1;;

let htsize = 1000;;

    let ajoute elt ensemble =
      let bucket = elt mod htsize in
      ensemble.(bucket) <- elt::ensemble.(bucket);;



  