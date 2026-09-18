(* Une variation du traditionnel Hello World : avec le nom*)
let hello () =
  print_string "Entrez votre nom : ";
  let nom = read_line () in
  Printf.printf "Bonjour %s \n" nom;;

let () = hello()