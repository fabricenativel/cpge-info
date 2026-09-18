let rec expr a n =
  if n=0 then 1 else let a2 = expr a (n/2) in
    if n mod 2 = 0 then a2*a2 else a2*a2*a;;

(*Le nombre maximal de bits sur lequel on représente un code *)
let maxbits = 16;;
let maxcode = (expr 2 maxbits) - 1;; 
let nbchar = 128;;
let string_of_char c = String.make 1 c;;
 

let invcode_ascii()  =
  let icode = Array.make maxcode "" in
  for i=0 to nbchar - 1 do
    icode.(i) <- (string_of_char (char_of_int i)) ;
  done;
  icode;;

let cree_code_ascii () =
    let code = Hashtbl.create maxcode in
    for i=0 to nbchar-1 do
      Hashtbl.add code (string_of_char (char_of_int i)) i;
    done;
    code;;


let lire fname =
  let reader = open_in fname in
  let contenu = In_channel.input_all reader in
  List.of_seq (String.to_seq contenu);;
;;


let lire_codes fname =
  let reader = open_in fname in
  let lcodes = ref [] in
  let aux_lc ()=
    let c1 = input_byte reader in
    let c2 = input_byte reader in
    c1*256+c2 in
  try
  while true do
    let nc = aux_lc() in
    lcodes := nc::!lcodes;
  done;
  !lcodes
with End_of_file -> !lcodes;; 

let ecrire fname ilist =
  let writer = open_out fname in
  let rec aux_ec ilist =
    match ilist with
    | [] -> ()
    | h::t -> Printf.fprintf writer "%c%c"  (char_of_int (h/256)) (char_of_int (h mod 256)); aux_ec t;
  in
  aux_ec ilist;
  flush writer
;;

(* Compression LZW de texte donné sous la forme d'une liste de caractères*)
let compresse texte =
  let table_code = cree_code_ascii() in
  let rec emet_code texte prefixe  num_code acc =
    match texte with
    | [] -> Hashtbl.find table_code prefixe::acc
    | car::reste -> let np =  prefixe ^ (string_of_char car)  in
      if (Hashtbl.mem table_code np) then (emet_code reste np  num_code acc) else 
        if (num_code < maxcode) then 
        ( 
          Hashtbl.add table_code np num_code;
          (emet_code (car::reste) "" (num_code+1) (Hashtbl.find table_code prefixe::acc))
        ) else
          (emet_code (car::reste) "" num_code (Hashtbl.find table_code prefixe::acc))
      in
      emet_code texte "" nbchar [];;


      let rec decompresse lcode   =
      let icode = invcode_ascii() in
      let rec aux_dec lcode  acc idx =
        match lcode with
        | [] -> ""
        | h::[] -> acc^icode.(h)
        | h::n::t ->  if idx>=maxcode then (aux_dec (n::t)  (acc^icode.(h)) (idx+1)) else
                      if n<idx then
                      (icode.(idx) <- icode.(h)^(String.sub icode.(n) 0 1); aux_dec (n::t)  (acc^icode.(h)) (idx+1))
                      else
                        (icode.(idx) <- icode.(h)^(String.sub icode.(h) 0 1); aux_dec (n::t)  (acc^icode.(h)) (idx+1))
      in
      aux_dec lcode "" nbchar;;


let () =  let texte = lire (Sys.argv.(1)) in
          Printf.printf "Lecture du contenu de %s : ok ! \n" (Sys.argv.(1));
          let tc = compresse texte in
          let pre = (List.length texte)*8 in
          let post = (List.length tc)*16 in
          List.iter (fun c -> Printf.printf "%d " c) tc;
          Printf.printf "\n";
          Printf.printf "Taille avant = %d\n" pre ;
          Printf.printf "Taille après = %d\n" post;
          ecrire (Sys.argv.(1)^".lzw") tc;
          let ttc = lire_codes (Sys.argv.(1)^".lzw") in
          let texte_decompresse = decompresse ttc in 
          Printf.printf "Résultat de la décompression = %s \n" texte_decompresse
        ;;