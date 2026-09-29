let size = 3000000;;


(* Fonction de hachage des chaines de caractères h(w) = s + somme des c_i*x^i *)
let hash str s x =
  let value = ref s in
  for i=0 to (String.length str - 1) do
    value := (!value*x + int_of_char str.[(String.length str) - 1 - i])
  done;
  (* En cas d'overflow on met le bit de poids fort à 0 *)
  (!value land max_int) mod size;;


let lecture filename =
  let reader = open_in filename in
  let l = in_channel_length reader in
  let contenu = really_input_string reader l in
  close_in reader;
  String.split_on_char '\n' contenu;; 


let cree_filtre chaines functions=
  let filtre = Array.make size false in
  let rec ajoute_chaine chaines =
    match chaines with
    | [] -> filtre
    | h::t -> for i=0 to (Array.length functions) - 1 do
                let s,x = functions.(i) in
                filtre.(hash h s x) <- true;
              done;
              ajoute_chaine t
  in
  ajoute_chaine chaines;;

let est_dans filtre chaine functions=
  try
    for i=0 to (Array.length functions) - 1 do
      let s,x = functions.(i) in
      if not filtre.(hash chaine s x) then raise Exit
    done;
    true;
  with Exit -> false;;


let () =
  let chaines = lecture "/usr/share/dict/french" in
  let hf = [| (0, 31); (0,33); (0,29); (0,37); (0,7); (0, 51); (0, 13) |] in
  let filtre = cree_filtre chaines hf in
  let fp = ref 0 in
  for i=0 to 1000 do
    let s = String.init 10 (fun i -> char_of_int (97+ Random.int 25))  in
    let t = est_dans filtre s hf in
    Printf.printf "%s -> %b\n" s t;
    if t then fp:=!fp+1;
  done;
 Printf.printf "Pourcentage de faux positifs = %f \n" (float_of_int (!fp)/.10.); 
;;
  