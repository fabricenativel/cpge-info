let rec somme_carres n =
  if n = 0 then 0 else n*n + somme_carres (n-1);;

let () = print_int (somme_carres 2024); print_newline () ;;