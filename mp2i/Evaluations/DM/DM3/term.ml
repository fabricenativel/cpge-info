let rec f n =
  if n=1 then 0
  else if n mod 2 = 0 then 1 + f (n/2)
  else 1 + f (n+1);;