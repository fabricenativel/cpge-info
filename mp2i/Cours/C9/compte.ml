print_string "Nom du fichier : ";
let filename = read_line () in
let reader = open_in filename in
let nl = ref 0 in
let end_of_file = ref false in
while not !end_of_file do
  try
    (let _ = input_line reader in
    nl := !nl +1;)
  with
    End_of_file -> end_of_file := true;
done;
Printf.printf "Le fichier %s contient %d lignes \n" filename !nl;;