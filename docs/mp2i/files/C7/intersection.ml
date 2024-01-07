let rec intersection l1 l2 =
  match l1,l2 with
  | _, [] -> []
  | [], _ -> []
  | h1::t1, h2::t2 -> if h1=h2 then h1::(intersection t1 t2) else 
   if h1<h2 then intersection t1 l2 else intersection l1 t2;;

