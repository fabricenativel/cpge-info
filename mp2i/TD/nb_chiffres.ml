(* Version récursive en OCaml *)
let rec nb_chiffres n =
  if n < 10 then 1
  else 1 + nb_chiffres (n / 10)
