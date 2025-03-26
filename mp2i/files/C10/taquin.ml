open Hashtbl

(* Un taquin est une matrice de taille size*size on repère la case vide par 0 *)
let size = 3;;

(* Les déplacements dans l'ordre E, S, O, N*)
let dep = [| (0,1);(1,0);(0,-1);(-1,0) |];;

let echange tab i j =
  let temp = tab.(i) in
  tab.(i) <- tab.(j);
  tab.(j) <- temp;;

(* melange un tableau par l'algorithme de Fisher yates*)
let melange tab =
  Random.self_init ();
  let n = Array.length tab in
  let j = ref 0 in
  for i=n-1 downto  1 do
    j := Random.int (i+1);
    echange tab i !j;
  done;;

(* cree un taquin aléatoire si l'argument est true sinon le taquin solution *)
let cree_taquin mode =
  let taquin_lineaire = Array.init (size*size) (fun i->(i+1) mod (size*size)) in
  if mode then melange taquin_lineaire;
  let taquin = Array.make_matrix size size 0 in
  for i=0 to size-1 do
    for j=0 to size-1 do
      taquin.(i).(j) <- taquin_lineaire.(i*size+j);
    done;
  done;
  taquin;;


    

let longueur n =
  String.length (string_of_int n);;

let affiche taquin =
  let s = longueur (size*size) in
  print_endline (String.make (size*2) '-');
  for i=0 to size-1 do
    for j=0 to size-1 do
      if taquin.(i).(j)=0 then Printf.printf " %s" (String.make s '_') else
      Printf.printf "%s %d" (String.make (s-longueur taquin.(i).(j)) ' ') taquin.(i).(j);
    done;
    print_newline ();
  done;
  print_endline (String.make (size*2) '-')
;;

(* Renvoie la position de la case vide dans un taquin *)
let vide taquin =
  let rec cherche i j =
    if i>=size then failwith "Erreur : pas de case vide dans le taquin !"
    else if j>=size then cherche (i+1) 0 
    else if taquin.(i).(j)=0 then (i,j) else
      cherche i (j+1)  in
    cherche 0 0;;

    

(* Pour un taquin renvoie une liste de 4 booléens qui indique dans cet ordre si les déplacements E, S, O et N sont possibles *)
let deplacements taquin =
  let vl, vc = vide taquin in
  let est = (vc!=size-1) in
  let sud = (vl!=size-1) in
  let ouest = (vc!=0) in
  let nord = (vl!=0) in
  [| est;sud;ouest;nord |];;


(* cree un taquin ayant une solution *)
let sol_taquin n =
  let tq = cree_taquin false in
  let d = ref 0 in
  for i=0 to n-1 do
    d := Random.int 4;
    let tdep = deplacements tq in
    if tdep.(!d) then (
      let vl, vc = vide tq in
      let dl,dc = dep.(!d) in
      tq.(vl).(vc) <- tq.(vl+dl).(vc+dc);
      tq.(vl+dl).(vc+dc) <- 0;
    )
  done;
  tq;;

let deplace taquin dir =
  let nouveau = Array.make_matrix size size 0 in
  for i=0 to size-1 do
    for j=0 to size-1 do
      nouveau.(i).(j) <- taquin.(i).(j);
    done;
  done;
  let vl, vc = vide nouveau in 
  let dl, dc = dep.(dir) in 
  nouveau.(vl).(vc) <- nouveau.(vl + dl).(vc+dc);
  nouveau.(vl + dl).(vc+dc) <- 0;
nouveau
;;

let rec affiche_solution tq mvt =
  match mvt with
  | [] -> ()
  | h::t -> let ntq = deplace tq h in affiche ntq; affiche_solution ntq t;;
    

let resoud taquin =
  let solution = cree_taquin false in
  let configuration = Hashtbl.create 100000 in
  (*La table des configurations avec la liste de mouvements permettant d'y parvenir*)
  Hashtbl.add configuration taquin [];
  let courant = Queue.create () in
  Queue.add taquin courant;
  let temp = ref taquin in
  try
  while not (Queue.is_empty courant) do
    let depart = (Queue.pop courant) in
    let dep = deplacements depart in
    let mvt = Hashtbl.find configuration depart in
    for i=0 to 3 do
    if dep.(i) then temp := deplace depart i;
    (if not (Hashtbl.mem configuration !temp) then (Hashtbl.add configuration !temp (i::mvt); Queue.add !temp courant );
      if !temp = solution then raise Exit;)
    done;
  done;
  Printf.printf "Le taquin n'a pas de solution, %d configurations explorées !\n" (Hashtbl.length configuration);
  with Exit -> affiche_solution taquin (List.rev (Hashtbl.find configuration solution));;


let () =
  Random.self_init ();
  (* let mt = [| [|1; 2; 3|]; [|4; 5; 6|]; [|7; 0; 8|] |] *)
  let mt = cree_taquin true in
  resoud mt;;
;;
