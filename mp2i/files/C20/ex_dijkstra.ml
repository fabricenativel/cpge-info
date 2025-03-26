(* File de priorité NAIVE : la complexité des opérations pas le but*)
let tmax = 1000;

type fileprio = {mutable taille : int; elts : (int*int) array  };;

type wgraph = {ordre : int; ladj : (int*int) list array};;

(* renvoie une file vide *)
let cree_file () = {taille =0; elts = Array.make tmax (0,0)};;

exception FilePleine;;
exception FileVide;;
(* enfiler un élément *)
let enfile mafile elt =
  if (mafile.taille < tmax) then (
  mafile.elts.(mafile.taille) <- elt;
  mafile.taille <- mafile.taille + 1;)
else raise FilePleine;
;;

(* Teste si la file est vide *)
let est_vide mafile = 
  if mafile.taille=0 then true else false;;


(* Renvoie l'indice de l'élément ayant la plus petite priorité *)
let indice_mini mafile =
  if est_vide mafile then raise FileVide else
    (
      let imin = ref 0 in
      let vmin = ref (snd mafile.elts.(0)) in
      for i=1 to mafile.taille - 1 do
        if !vmin > (snd mafile.elts.(i)) then
          (
            imin := i;
            vmin := (snd mafile.elts.(i));
          )
      done;
      !imin;
    )
(* echange les elemts situés aux indices i et j dans tab*)
let swap tab i j =
  let temp = tab.(i) in
  tab.(i) <- tab.(j);
  tab.(j) <- temp;;


(* Renvoie l'élément de plus petit priorité *)
let defile mafile =
  let imin = indice_mini mafile in
  swap mafile.elts (mafile.taille - 1) (imin);
  mafile.taille <- mafile.taille - 1;
  mafile.elts.(mafile.taille)
;;

(* Renvoie son indice si un élément est présent dans la file et -1 sinon *)
let est_dans mafile elt =
  let ielt = ref 0 in
  try
    for i=0 to mafile.taille - 1 do
      if (fst elt = fst mafile.elts.(i)) then (ielt := i; raise Exit)
      done;
      -1
    with Exit -> !ielt;;

(* Modifie la priorité d'un élément présent dans la file et l'enfile sinon*)
let modifie_prio mafile elt =
  let ielt = est_dans mafile elt in
  if (ielt= -1) then enfile mafile elt else
    (if (snd elt < snd mafile.elts.(ielt)) then 
      mafile.elts.(ielt) <- elt;)
;;

let affiche mafile =
  Array.iter (fun (s,p) -> Printf.printf "(%d,%d); " s p) (Array.sub mafile.elts 0 mafile.taille);
  print_newline ()
;;

let dijkstra gr depart =
  (* Le tableau de distance*)
  let distance = Array.make gr.ordre (-1) in
  (* La file de priorité *)
  let a_traiter = cree_file() in
  (* Initialisation  *)
  modifie_prio a_traiter (depart,0);
  distance.(depart) <- 0;
  (* La boucle principale : on défile un sommet et on enfile ses fils non encore traités*)
  while (not (est_vide a_traiter)) do
    affiche a_traiter;
    let sc,dist = defile a_traiter in
    distance.(sc) <- dist;
    List.iter (fun (s,d) -> (if distance.(s)= -1 then modifie_prio a_traiter (s,d+dist))) (gr.ladj.(sc));    
  done;
  distance;;
  let cree_graphe n  = {ordre = n; ladj= Array.make n []};;
  let rec ajoute_aretes graphe lar =
    match lar with  
      | [] -> ()
      | (d,w,a)::t -> graphe.ladj.(d) <- (a,w)::graphe.ladj.(d); graphe.ladj.(a) <- (d,w)::graphe.ladj.(d); ajoute_aretes graphe t ;;
let () = 
let test = cree_graphe 6 in
ajoute_aretes test [(0,5,1);(0,1,2);(2,3,1);(1,4,3);(1,2,4);(2,5,4);(2,7,5);(3,3,5);(4,1,5);];
let d = dijkstra test 0 in
Array.iter (fun n -> Printf.printf "%d; " n) d;
print_newline()
;;


