let rec fact n =
  if n = 0 then 1 else n *  fact (n-1)

let rec pairs liste =
  match liste with
  | [] -> []
  | head :: tail -> let ptail = pairs tail in 
    if head mod 2 = 0 then head::ptail else pairs ptail