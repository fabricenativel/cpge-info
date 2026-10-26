let rec fusion l1 l2 =
  match l1,l2 with
  | [], l2 -> l2
  | l1, [] -> l1
  | h1::t1, h2::t2 -> if h1<h2 then h1::fusion t1 l2 else h2::fusion l1 t2;;

let rec ack n m =
  match n, m with
  | 0, m -> m+1
  | n, 0 -> ack (n-1) 1
  | n, m -> ack (n-1) (ack n (m-1));;

