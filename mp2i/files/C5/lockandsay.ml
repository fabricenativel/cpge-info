let str_to_lst chaine =
  List.init (String.length chaine) (fun i -> chaine.[i]);;

let rec lst_to_str lst =
  match lst with
  | [] -> ""
  | h::t -> String.make 1 h ^ lst_to_str t;;

let rec suivant terme =
  let lterme = str_to_lst terme in
  let rec aux l =
    match l with
    | [] -> []
    | h::[] -> ['1'; h]
    | h1::h2::[] -> if h1=h2 then ['2';h1] else ['1';h1;'1';h2]
    | h1::h2::h3::t -> if (h1=h2 && h2=h3) then '3'::h1::aux t else
      if (h1=h2) then '2'::h1::aux (h3::t) else
        '1'::h1:: aux (h2::h3::t)
  in
  lst_to_str (aux lterme);;

let view n =
  let rec aux ui i n =
    if i<n then
      (Printf.printf "u%d = %s\n" i ui;
      aux (suivant ui) (i+1) n)
    in
    aux "1" 0 n
    ;;