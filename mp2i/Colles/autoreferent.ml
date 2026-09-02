
let somme tab idx =
  let res = ref  0 in
  for i=0 to idx do
    res := !res + tab.(i);
  done;
  !res;;

let est_autoreferent tab =
  let n = Array.length tab in
  let occ = Array.make n 0 in
  try
  for i=0 to n-1 do
    if tab.(i)<0 || tab.(i)>n-1 then raise Exit else
    occ.(tab.(i)) <- occ.(tab.(i)) + 1
  done;
  for i=0 to n-1 do
    if tab.(i) <> occ.(i) then raise Exit;
  done;
  true
  with Exit -> false;
;;

let affiche tab =
  Printf.printf "[| ";
  for i=0 to Array.length tab -1 do
    Printf.printf "%d; " tab.(i)
  done;
  Printf.printf "|] \n";;

let compte tab elt idx =
  let res = ref 0 in
  for i = 0 to idx do 
    if tab.(i)=elt then res := !res + 1;
  done;
  !res;;

  let partiel t  k =
    let n = Array.length t in
    let cpt = Array.make  n  0 in
    try
    for i=0 to k-1 do
      cpt.(t.(i)) <- cpt.(t.(i)) + 1
    done;
    for i=0 to k-1 do
      if cpt.(i) > t.(i) then  raise Exit;
      done;
    true;
    with  Exit -> false;;










    
let valide_partielle tab idx =
  let n = Array.length tab in
  (* Vérifier que la somme + cases non=0 restant à remplir ne dépasse pas la taille du tableau *)
  if ((somme tab idx + (n-1-idx -(tab.(0) - compte tab 0 idx)) > n) || (not (partiel tab idx))) then false else true;;

let cree_autoreferent n =
  (* Essaye une valeur à l'index idx dans tab*)
  let rec recherche tab idx =
  if (idx==Array.length tab) (* on a complété tout les cases*)
    then if (est_autoreferent tab) then (affiche tab) else () else (
    try
    for valeur = 0 to Array.length tab - 1 do
      tab.(idx) <- valeur;
      (* On place une valeur, si pas d'incohérence on place la suivante*)
      if valide_partielle tab idx then recherche tab (idx+1) else raise Exit;
    done;
    ();
  with Exit -> ()) in
  recherche (Array.make n 0) 0;;


let () = cree_autoreferent (int_of_string Sys.argv.(1));;

