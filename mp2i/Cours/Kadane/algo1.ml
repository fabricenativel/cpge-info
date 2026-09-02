(* Lire la totalité d'un fichier dans une chaine de caractères*)
let lire_tout filename =
  let reader = open_in_bin filename in
    let data = really_input_string reader (in_channel_length reader) in
    close_in reader;
    let size = String.length data in
    if data.[size-1]='\n' then String.sub data 0 (size-1)  else data

(* Lecture des entiers et rangement dans un tableau*)
let lire_entiers = 
  let content = lire_tout Sys.argv.(1)  in 
    Array.of_list (List.map int_of_string (String.split_on_char '\n' content))

(* Somme de la tranche entre i et j*)
let rec somme_tranche tab i j =
  if i=j then tab.(i) else tab.(i) + somme_tranche tab (i+1) j

(* Tranche de somme maximale *)
let rec tranche_max_aux tab i j smax =
  if j= Array.length tab then 
    if i = Array.length tab then smax else tranche_max_aux tab (i+1) (i+1) smax
else
  let cs = somme_tranche tab i j in
  if cs > smax then tranche_max_aux tab i (j+1) cs else tranche_max_aux tab i (j+1) smax
  
let tranche_max tab =
  tranche_max_aux tab 0 0 tab.(0)

let () = print_string("Somme maximale d'un tranche = "); print_int (tranche_max lire_entiers); print_newline()  
