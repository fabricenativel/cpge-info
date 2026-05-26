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
    let code = Hashtbl.create (maxcode/100) in
    for i=0 to nbchar-1 do
      Hashtbl.add code (string_of_char (char_of_int i)) i;
    done;
    code;;


let lire fname =
  let reader = open_in fname in
  In_channel.input_all reader
;;

let ecrire fname res =
  let writer = open_out fname in
  Printf.fprintf writer "%s" res;;

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
    if (!cc<maxcode) then
   (Hashtbl.add code (!plp) !cc;
    cc := !cc + 1;);
    position := !position + !idx;
    );
  done;
  List.rev !textcompresse, !cc ;;

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

let () =  let ascii = cree_code_ascii() in
          let texte = lire (Sys.argv.(1)) in
          Printf.printf "Lecture du contenu de %s : ok ! \n" (Sys.argv.(1));
          let tti = (String.length texte)*8 in
          Printf.printf "Taille initiale du texte : %d \n" tti;
          let tc, nmax = compresse texte ascii nbchar in
          let ttc = (List.length tc)*maxbits in
          Printf.printf "Taille du texte compressé : %d \n" ttc;
          Printf.printf "Nombre de codes générés : %d \n" nmax;
          Printf.printf "Taux de compression = %f \n" (float_of_int ttc /. float_of_int tti);
          let tdec = decompresse tc in 
          ecrire  "verifier.txt" tdec;
        ;;