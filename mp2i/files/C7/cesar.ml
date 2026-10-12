let chiffre caractere cle =
  let cle = cle mod 26 in
  let cle = if cle<0 then cle+26 else cle in
  match caractere with
  | 'a'..'z' -> let s = int_of_char 'a' and t = int_of_char caractere in char_of_int (s+((t-s)+cle) mod 26)
  | 'A'..'Z' -> let s = int_of_char 'A' and t = int_of_char caractere in char_of_int (s+((t-s)+cle) mod 26)
  | _ -> caractere;;


let reste chaine =
  String.sub chaine 1 (String.length chaine -1);;

let rec cesar chaine cle =
  if chaine ="" then "" else (String.make 1 (chiffre chaine.[0] cle)^(cesar (reste chaine) cle));;

let cesar2 chaine cle = String.map (fun c -> chiffre c cle) chaine;;