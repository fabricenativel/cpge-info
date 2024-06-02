
let string_of_char c = String.make 1 c;;
 
let cree_code chaine =
  let code = Hashtbl.create 65535 in
  for i=0 to String.length chaine - 1 do
    Hashtbl.add code (string_of_char (chaine.[i])) i;
  done;
  code;;

let invcode chaine =
  let icode = Array.make 256 "" in
  for i=0 to String.length chaine - 1 do
    icode.(i) <- (string_of_char (chaine.[i])) ;
  done;
  icode;;

let cree_code_ascii () =
    let code = Hashtbl.create 65535 in
    for i=0 to 127 do
      Hashtbl.add code (string_of_char (char_of_int i)) i;
    done;
    code;;

let compresse texte code nb_char=
  let position = ref 0 in
  let plp = ref "" in
  let idx = ref 0 in
  let textcompresse =  ref [] in
  let cc = ref nb_char in
  while (!position < String.length texte) do
    (* emettre le code du plus long prefixe *)
    if (Hashtbl.mem code (String.sub texte (!position) (String.length texte - !position))) then
      (textcompresse := (Hashtbl.find code (String.sub texte (!position) (String.length texte - !position)))::!textcompresse ;
      position := String.length texte;
      )  
    else (
    plp := (String.make 1 (texte.[!position]));
    idx := 0;
    while (!position + !idx + 1< String.length texte && Hashtbl.mem code !plp) do
      idx := !idx + 1;
      plp := !plp ^ (String.make 1 (texte.[!position + !idx]));
    done;
    textcompresse :=  Hashtbl.find code (String.sub !plp 0 (String.length !plp - 1))::!textcompresse;
    (* Ajouter dans la table *)
    Hashtbl.add code (!plp) !cc;
    cc := !cc + 1;
    position := !position + !idx;
    );
  done;
  List.rev !textcompresse;;

let rec affiche  il =  
  match il with
  | [] -> ()
  | h::t -> Printf.printf "%d; " h; affiche t;;


  let rec decompresse lcode  chaine =
    let icode = invcode chaine in
    let rec aux_dec lcode  acc idx =
      match lcode with
      | [] -> ""
      | h::[] -> acc^icode.(h)
      | h::n::t ->  if (n<idx) then
                    (icode.(idx) <- icode.(h)^(String.sub icode.(n) 0 1); aux_dec (n::t)  (acc^icode.(h)) (idx+1))
                    else
                      (icode.(idx) <- icode.(h)^(String.sub icode.(h) 0 1); aux_dec (n::t)  (acc^icode.(h)) (idx+1))
    in
    aux_dec lcode "" (String.length chaine);;

let () =  let alphabet = Sys.argv.(2) in
          let scode = cree_code alphabet in
          let tc = compresse Sys.argv.(1) scode (String.length alphabet) in
          affiche tc;
          print_newline();
          Printf.printf "Décompression : %s \n" (decompresse tc alphabet);;