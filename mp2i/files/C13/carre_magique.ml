(* Insère x à la position p dans l*)
let rec insere x p l =
    match p, l with
    | 0, _ ->  x::l
    | _ , [] -> failwith "bug"
    | n, h::t -> h::(insere x (p-1) t)

(* Ranvoie la liste de listes ou  x est insérée à tous les emplacements possibles dans l*)
let insert_all x l =
  let res = ref [] in
  for i=0 to List.length l do
      res := (insere x i l)::!res ;
  done;
  !res;;
  
let rec every_insert x l =
  match l with
  | [] -> [[x]]
  | h::t -> let p = every_insert x t in (x::l)::List.map (fun y -> h::y) p;;

