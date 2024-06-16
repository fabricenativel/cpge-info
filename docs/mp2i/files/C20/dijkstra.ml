type wdigraph = {size : int;  ladj : (int*int) list array};;

type 'a file_priorite = {
  mutable taille : int;
  donnees : (int*'a) array};;

  let cree_graphe n  = {size = n; ladj= Array.make n []};;

let fils i = 2 * i + 1;;

let parent i = (i-1)/2 ;;
  
let cree_file t default= {taille =  0; donnees = Array.make t (0,default)};;

let prio elt = fst elt;;

let taille fp = fp.taille;;

let swap tab i j =
  let temp = tab.(i) in
  tab.(i) <- tab.(j);
  tab.(j) <- temp;;

exception File_pleine;;
exception File_vide;;

let est_vide fp = (fp.taille == 0);;

let enfile elt fp =
  if fp.taille = Array.length fp.donnees then  raise File_pleine else
  (let cp = ref fp.taille in
    fp.taille <- fp.taille + 1;
    fp.donnees.(!cp) <- elt;
    while (!cp <>0 && prio fp.donnees.(!cp) < prio fp.donnees.(parent !cp)) do
    (
      swap fp.donnees !cp (parent !cp);
      cp := parent !cp;
    )
    done;
  );;

let defile fp =
  if fp.taille = 0 then raise File_vide else
    (
    let res = fp.donnees.(0) in
    swap fp.donnees 0 (fp.taille-1);
    fp.taille <- fp.taille-1;
    let cp = ref 0 in
    let lc = ref (fils !cp) in
    while (!lc+1 < fp.taille && (min (prio fp.donnees.(!lc+1)) (prio fp.donnees.(!lc)) < prio fp.donnees.(!cp))) do
      if (prio fp.donnees.(!lc)< prio fp.donnees.(!lc+1)) then
       (swap fp.donnees !cp !lc;
        cp := !lc)
      else  
        (swap fp.donnees !cp (!lc+1);
        cp := !lc+1);
      lc := fils !cp ;
    done;
    if (!lc<fp.taille && prio fp.donnees.(!lc) < prio fp.donnees.(!cp)) then
      (swap fp.donnees !cp !lc);
    res;
    )
  ;;
    

let djikstra graphe depart =
  let a_traiter = cree_file graphe.size 0 in
  let distance = Array.make graphe.size Int.max_int in
  let deja_vu = Array.make graphe.size false in
  distance.(depart) <- 0;
  enfile (0,depart) a_traiter;
  while not (est_vide a_traiter) do
    let dist, sommet_courant = defile a_traiter in
    if (not deja_vu.(sommet_courant)) then
    (deja_vu.(sommet_courant) <- true;
    List.iter (fun (w,s) -> if (distance.(sommet_courant)+w < distance.(s)) then
    (distance.(s) <- distance.(sommet_courant)+w; enfile (distance.(s),s) a_traiter); )
    (graphe.ladj.(sommet_courant)););
  done;
  distance;;

  let rec ajoute_aretes graphe lar =
    match lar with  
      | [] -> ()
      | (d,w,a)::t -> graphe.ladj.(d) <- (w,a)::graphe.ladj.(d); graphe.ladj.(a) <- (w,d)::graphe.ladj.(d); ajoute_aretes graphe t ;;

  
let () = 
let test = cree_graphe 6 in
ajoute_aretes test [(0,5,1);(0,1,2);(2,3,1);(1,4,3);(1,2,4);(2,5,4);(2,7,5);(3,3,5);(4,1,5);];
let pl = djikstra test 0 in
Array.iter (fun d -> Printf.printf "%d; " d) pl ;
print_newline ();;