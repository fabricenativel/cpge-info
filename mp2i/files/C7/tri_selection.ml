let rec aleatoire n vmax =
  if n=0 then [] else (Random.int vmax)::(aleatoire (n-1) vmax)

let affiche entiers =
  print_char '[';
  let rec aff_aux entiers =
    match entiers with
    | [] -> print_char ']'
    | h::[] -> print_int h; print_string " ]\n"
    | h::t -> print_int h; print_string "; "; aff_aux t
  in aff_aux entiers

let min_reste entiers =
  let rec aux entiers cmin creste=  
    match entiers with 
    | [] -> cmin, creste
    | h::t -> if h<cmin then aux t h (cmin::creste) else aux t cmin (h::creste)
  in aux (List.tl entiers) (List.hd entiers) []

let rec tri_selection entiers =
  if entiers = [] then [] else
    let min, reste = min_reste entiers in
    min::(tri_selection reste)