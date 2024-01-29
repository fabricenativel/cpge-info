
open Hashtbl
let my_ht = Hashtbl.create 10000
let reader = open_in "mots.txt" 

let input =
  let rec read_all () =
  try 
    let line = input_line reader in
    if Hashtbl.mem my_ht line then Hashtbl.replace my_ht line ((Hashtbl.find my_ht line) +1)
     else Hashtbl.add my_ht line 1;
     read_all()
  with End_of_file ->
    close_in reader
  in
  read_all()

let () = Printf.printf "nautilus %d\n" (Hashtbl.find my_ht "nautilus") 
