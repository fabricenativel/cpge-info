(* Fonction annexe permettant de renvoyer la liste des caractères présente dans la pile*)
let rec voir p =
  if Stack.is_empty p then "" else
    let c = Stack.pop p in
    (voir p) ^ (String.make 1 c);;

let () =
  let reader = open_in "mystere.txt" in
  let ma_pile = Stack.create () in
  try
    while true do
      let caractere = input_char reader in
      if Stack.is_empty ma_pile then Stack.push caractere ma_pile else
        (let sommet = Stack.top ma_pile in
         if caractere<>sommet then Stack.push caractere ma_pile else ignore (Stack.pop ma_pile)
        )
    done;
  with
  | End_of_file -> print_endline (voir ma_pile);
    close_in reader;
