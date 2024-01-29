
type hashtable = (string * int) list array
let size = 100000
let ht = Array.make  size []
let reader = open_in "mots.txt" 

let hash string =
  let h = ref 0 in
  for i = 0 to (String.length string -1)
  do
   h := !h + (Char.code string.[i]);
done;
  !h mod size;;

let rec is_in cle l =
  match l with
  |[] -> false
  |(s,v)::t -> s=cle || (is_in cle t);;

let rec update cle valeur list =
  match list with
  | [] -> failwith "Modification d'une clé absente !"
  | (c,v)::t -> if c=cle then (cle,valeur)::t else  (c,v)::(update cle valeur t);;

let rec get_value cle list =
  match list with
  | [] -> failwith "Clé absente"
  | (c,v)::t -> if c=cle then v else (get_value cle t);;

let is_in_ht (ht:hashtable) s =
  let k = hash s in
  if (is_in s ht.(k)) then true else false;;

let add_ht (ht:hashtable) s v =
  let k = hash s in
  ht.(k) <- (s,v)::ht.(k)

let get_value_ht (ht:hashtable) s =
  let k =  hash s in
  get_value s ht.(k);;

let update_ht (ht:hashtable) s v =
  let k = hash s in
  ht.(k) <- (update s v ht.(k));;

  let count_word() =
    let rec read_all () =
    try 
      let line = input_line reader in
      if is_in_ht ht line then 
        (
          let ov = get_value_ht ht line in
          update_ht ht line (ov+1);
          read_all()
        )
      else
    (add_ht ht line 1; read_all())
    with End_of_file ->
      close_in reader
    in
      read_all()

let () =
    count_word ();
    Printf.printf "Nombre d'occurences pour 'nautilus' = %d\n" (get_value_ht ht "nautilus");; 

