let rec f91 n =
  Printf.printf "%d -> " n;
  if n>100 then n-10 else f91(f91(n+11));;
