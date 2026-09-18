(* Ecrire une fonction fusion qui prend en entrée deux listes déjà triées
et renvoie leur fusion
Par exemple fusion [2; 6; 9] [1; 4; 5] donne [1; 2; 4; 5; 6; 9]
*)
let rec fusion l1 l2 =
  match l1,l2 with
  | [], _ -> l2
  | _, [] -> l1
  | h1::t1, h2::t2 -> 
    if h1<h2 then
      h1::(fusion t1 l2)  else
      h2::(fusion l1 t2);;

  (* Renvoie  deux moitiés d'une liste *)
  let rec separe l =
    match l with
    | [] -> [], []
    | h::[] -> [h], []
    | h1::h2::t -> let mt1, mt2 = separe t in h1::mt1, h2::mt2;;
  
  let rec tri_fusion l =
    match l with
    | [] -> []
    | h::[] -> [h]
    | _ -> let l1,l2 = separe l in
    let lt1 = tri_fusion l1 in
    let lt2 = tri_fusion l2 in
    fusion lt1 lt2;;
