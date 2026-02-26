let last_occ elt liste = 
  let rec aux elt liste cid cval =
    match liste with
    | [] -> cval
    | h::t -> if h=elt then aux elt t (cid+1) (cid) else aux elt t (cid+1) cval
  in
  aux elt liste 0 (-1);;

let tliste = [1; 5; 4; 5; 2; 5; 1; -1; 2];;
Printf.printf "Dernière occurrence de 5 = %d"  (last_occ (-1) tliste);

