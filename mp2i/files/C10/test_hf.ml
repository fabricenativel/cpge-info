let somme str =
  let value = ref 0 in
  for i = 0 to (String.length str - 1) do
    value := !value + int_of_char str.[i]
  done;
  !value;;

let produit str =
  let value = ref 1 in
  for i = 0 to (String.length str - 1) do
    value := !value * int_of_char str.[i]
  done;
  !value mod 9999;;

let polynomial str =
  let value = ref 0 in
  for i=0 to (String.length str - 1) do
    value := (!value*31 + int_of_char str.[(String.length str) - 1 - i])
  done;
  !value mod 10000;;

let () =
  let reader = open_in "test5000.txt" in
  let collision_somme = Array.make 10000 0 in
  let collision_produit = Array.make 10000 0 in
  let collision_polynomial = Array.make 10000 0 in
  let chaine = ref "" in
  for i=1 to 5000 do
    chaine := input_line reader;
    collision_somme.(somme !chaine) <- collision_somme.(somme !chaine) + 1;
    collision_produit.(produit !chaine) <- collision_produit.(produit !chaine) + 1;
    collision_polynomial.(polynomial !chaine) <- collision_polynomial.(polynomial !chaine) + 1;
  done;
  let max_coll_somme = ref 0 in
  let nb_coll_somme = ref 0 in
  let max_coll_produit = ref 0 in
  let nb_coll_produit = ref 0 in
  let max_coll_polynomial = ref 0 in
  let nb_coll_polynomial = ref 0 in
  for i=0 to 9999 do
    if collision_somme.(i) > !max_coll_somme then max_coll_somme := collision_somme.(i);
    if collision_produit.(i) > !max_coll_produit then max_coll_produit := collision_produit.(i);
    if collision_polynomial.(i) > !max_coll_polynomial then max_coll_polynomial := collision_polynomial.(i);
    if collision_somme.(i)>1 then nb_coll_somme := !nb_coll_somme + collision_somme.(i)-1;
    if collision_produit.(i)>1 then nb_coll_produit := !nb_coll_produit + collision_produit.(i)-1;
    if collision_polynomial.(i)>1 then nb_coll_polynomial := !nb_coll_polynomial + collision_polynomial.(i)-1;
  done;
  Printf.printf "Nombre maximal de collision somme = %d\n" !max_coll_somme;
  Printf.printf "Nombre total de collision somme = %d\n" !nb_coll_somme;
  Printf.printf "Nombre maximal de collision produit = %d\n" !max_coll_produit;
  Printf.printf "Nombre total de collision produit = %d\n" !nb_coll_produit;
  Printf.printf "Nombre maximal de collision somme = %d\n" !max_coll_polynomial;
  Printf.printf "Nombre total de collision somme = %d\n" !nb_coll_polynomial;