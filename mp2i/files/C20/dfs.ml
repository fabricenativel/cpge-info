
type digraph = {taille : int;  ladj : int list array};;

let cree_graphe n  = {taille = n; ladj= Array.make n []};;

let dfs graphe depart =
  (* Le tableau de booléens indiquant les sommets visités*)
  let deja_vu =  Array.make graphe.taille false in
  let rec aux_dfs s =
    (* On relance récursivement sur les voisins sortants *)
    if (not deja_vu.(s)) then (
      deja_vu.(s) <- true;
      List.iter aux_dfs (graphe.ladj.(s));) in
    (* L'appel récursif termine immédiatement sur un voisin déjà visité *)
  aux_dfs depart;
  deja_vu;;

  let dfs_stack graphe depart =
    let deja_vu =  Array.make graphe.taille false in
    let a_faire = Stack.create () in
    Stack.push  depart a_faire;
    while not (Stack.is_empty a_faire) do
      let sommet_courant = Stack.pop a_faire in
      if not (deja_vu.(sommet_courant)) then(
          deja_vu.(sommet_courant) <- true;
          List.iter (fun s-> Stack.push s a_faire) (graphe.ladj.(sommet_courant)););
      done;
    deja_vu;;



let rec ajoute_aretes graphe lar =
match lar with  
  | [] -> ()
  | (d,a)::t -> graphe.ladj.(d) <- a::graphe.ladj.(d); ajoute_aretes graphe t ;;

let () = 
  let test = cree_graphe 8 in
  ajoute_aretes test [(1,2);(1,0);(2,3);(2,1);(3,4);(4,2);(5,3);(6,7);(6,4);(7,6);(7,5)];
  let pp = dfs test 7 in
  Array.iter (fun d -> Printf.printf "%b " d) pp ;
  print_newline ();
  let ppq = dfs_stack test 7 in
  Array.iter (fun d -> Printf.printf "%b " d) ppq ;
  print_newline ();;

    
