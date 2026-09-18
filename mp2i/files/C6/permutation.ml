let rec insere elt liste pos =
  if pos = 0 then elt::liste else
     (List.hd liste)::(insere elt (List.tl liste) (pos-1));;

let rec insere_all_aux elt liste pos acc =
  if pos=((List.length liste)+1) then acc else insere_all_aux elt liste (pos+1) ((insere elt liste pos)::acc);;

let rec insere_all elt lliste =
  match lliste with
  | [] -> []
  | h::t -> (insere_all_aux elt h 0 [])@(insere_all elt t);;

let rec permutation l =
  match l with
  | [] -> [[]]
  | h::t -> insere_all h (permutation t);;