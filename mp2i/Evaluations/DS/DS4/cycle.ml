let f x y n = 
  let z = (x+2*y*y) mod n in
  let t = (3*x*x+y) mod n in
  (z,t);;

let view f x y n k =
  let rec aux x y k =
    if k=0 then [] else 
      let x1, y1 = f x y n in
      (x1,y1):: aux x1 y1 (k-1) in
    ((x,y)::aux x y k) ;;


let rec appartient elt lst =
  match lst with
  | [] -> false
  | h::t -> elt=h || appartient elt t;;

let cycle x y n =
  let rec aux xn yn vus =
    if appartient (xn,yn) vus then (xn,yn) else
      let xn1, yn1 = f xn yn n in
      aux xn1 yn1 ((xn,yn)::vus)
    in
  aux x y [];;

let cycle_ht x y n =
  let vus = Hashtbl.create 1000 in
  let rec aux xn yn i =
    if Hashtbl.mem vus (xn,yn) then (xn, yn, i- Hashtbl.find vus (xn,yn))  else
      let xn1, yn1 = f xn yn n in
      Hashtbl.add vus (xn,yn) i;
      aux xn1 yn1 (i+1)
    in
  aux x y 0 ;;