let rec est_dans element liste =
  match liste with
  | [] -> false
  | head::tail -> head = element || est_dans element tail

let rec syracuse n =
  if n=1 then 1 else
    if n mod 2 = 0 then syracuse (n/2) else syracuse(3*n+1) 
  