
type digraph = {taille : int;  ladj : int list array};;

let cree_graphe n  = {taille = n; ladj= Array.make n []};;

let bfs graphe depart =
  let a_traiter = Queue.create() in
  let distance = Array.make graphe.taille (-1) in
  distance.(depart) <- 0;
  Queue.push  depart a_traiter;
  while not (Queue.is_empty a_traiter) do
    let sommet_courant = Queue.pop a_traiter in
    List.iter (fun s -> if (distance.(s)= -1) then (Queue.push s a_traiter; distance.(s)<-distance.(sommet_courant) + 1)) (graphe.ladj.(sommet_courant));
  done;
  distance;;

let rec ajoute_aretes graphe lar =
match lar with  
  | [] -> ()
  | (d,a)::t -> graphe.ladj.(d) <- a::graphe.ladj.(d); ajoute_aretes graphe t ;;

let () = 
  let test = cree_graphe 7 in
  ajoute_aretes test [(0,1);(0,3);(1,2);(2,4);(2,5);(3,4);(4,1);(6,2)];
  let pl = bfs test 0 in
  Array.iter (fun d -> Printf.printf "%d; " d) pl ;
  print_newline ();;

    
