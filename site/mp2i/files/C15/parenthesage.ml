let nb_mult dim i j k=
  (* Le nombre de multiplication de la toute dernière multiplication (A1...Ak)*(Ak+1...Aj)*)
  let li, ci = dim.(i) in
  let lk, ck= dim.(i+k)  in
  let lj, cj= dim.(j) in
  li*ck*cj;;

let rec get_min lst =
  match lst with
  | [] -> failwith "Extraction minimum d'une liste vide"
  | h::[] -> h
  | h::t -> let m=get_min t in if h<m then h else m;;

let rec make_dim n mv=
if n=1 then [(1+Random.int mv,1+Random.int mv)]
else let prev = make_dim (n-1) mv in
  let t = fst (List.hd prev) in (1+Random.int mv, t)::prev;;


let opti dim = 
  (* Renvoie le nombre de multiplications optimales pour le produit du tableau de dimensions dim*)
  let n = Array.length dim in
  let rec opti_aux  i j =
    (*Fonction auxiliaire qui renvoie le nombre de multiplications optimale pour Ai..Aj 0<=i<j<=n-1*)
    if j=i then 0 else
    get_min (List.init (j-i) (fun k->opti_aux i (i+k) +opti_aux (i+k+1) j + nb_mult dim i j k)) in
  opti_aux 0 (n-1);;

let opti_memo dim =
  let n = Array.length dim in
  let memo = Hashtbl.create (n*n) in
  let rec opti_aux  i j =
    if Hashtbl.mem memo (i,j) then Hashtbl.find memo (i,j) else
    (*Fonction auxiliaire qui renvoie le nombre de multiplications optimale pour Ai..Aj 0<=i<j<=n-1*)
    if j=i then (Hashtbl.add memo (i,i) 0; 0) else
    let rep = get_min (List.init (j-i) (fun k->opti_aux i (i+k) +opti_aux (i+k+1) j + nb_mult dim i j k)) in 
    Hashtbl.add memo (i,j) rep; rep in
  opti_aux 0 (n-1);;

  

    



