let rec mystere n =
  if n<10 then 1 else 1 + mystere (n/10)