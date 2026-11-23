
type digraph = {taille : int;  ladj : int list array};;


let cree_graphe n  = {taille = n; ladj= Array.make n []};;

let lire_graphe fname ordre =
  let reader = open_in fname in
  let gr =  cree_graphe ordre in
  try
    while true do
      let line = input_line reader in
      let sep = String.index line ' ' in
      let depart = int_of_string (String.sub line 0 (sep)) in
      let arrivee = int_of_string (String.sub line (sep+1) ((String.length line)-sep-1)) in
      gr.ladj.(depart) <- arrivee::(gr.ladj.(depart));
      gr.ladj.(arrivee) <- depart::(gr.ladj.(arrivee));
    done;
    gr
  with End_of_file -> gr;;



let bfs graphe depart =
  let a_traiter = Queue.create() in
  let distance = Array.make graphe.taille None in
  distance.(depart) <- Some 0;
  Queue.push  depart a_traiter;
  while not (Queue.is_empty a_traiter) do
    let sommet_courant = Queue.pop a_traiter in
    List.iter (fun s -> if (distance.(s)= None) then (Queue.push s a_traiter; distance.(s)<- Some (1+(Option.get distance.(sommet_courant))) )) (graphe.ladj.(sommet_courant));
  done;
  distance;;


  let bfs graphe depart =
    let a_traiter = Queue.create() in
    let distance = Array.make graphe.taille None in
    let parent = Array.make graphe.taille None in
    distance.(depart) <- Some 0;
    Queue.push  depart a_traiter;
    while not (Queue.is_empty a_traiter) do
      let sommet_courant = Queue.pop a_traiter in
      List.iter (fun s -> if (distance.(s)= None) then (Queue.push s a_traiter; parent.(s)<-Some sommet_courant; distance.(s)<- Some (1+(Option.get distance.(sommet_courant))) )) (graphe.ladj.(sommet_courant));
    done;
    distance, parent;;

let chemin parent origine arrivee =
  let chemin = ref [arrivee] in
  let sc = ref arrivee in
  while !sc <> origine do
    sc := Option.get parent.(!sc);
    chemin := !sc::(!chemin);
  done;
  !chemin;;


let rec ajoute_aretes graphe lar =
match lar with  
  | [] -> ()
  | (d,a)::t -> graphe.ladj.(d) <- a::graphe.ladj.(d); ajoute_aretes graphe t ;;

let () = 
  let test = lire_graphe "ex50.txt" 51 in
  let pl,pa = bfs test 42 in
  Array.iter (fun d -> if d=None then Printf.printf "x; " else Printf.printf "%d; " (Option.get d) ) pl ;
  print_newline ();
  List.iter (fun d-> Printf.printf "%d -> " d) (chemin pa 42 43);
  print_newline ();
;;

    
