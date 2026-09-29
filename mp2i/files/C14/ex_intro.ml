let rec f a b =
  if a = 0 then b
  else 
    (if b = 0 then f (a-1) a
     else f a (b-1));;