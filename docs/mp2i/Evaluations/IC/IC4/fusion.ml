let rec fusion l1 l2 =
  match l1,l2 with
  | [], l2 -> l2
  | l1, [] -> l1
  | h1::t1, h2::t2 -> if h1<h2 then h1::fusion t1 l2 else h2::fusion l1 t2;;