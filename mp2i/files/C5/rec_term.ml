let rec mult a b x =
  if b=0 then x else  mult a (b-1) (x+a);;


