let rec fibo n =
  if n<2 then 1 else fibo (n-1) + fibo (n-2);;