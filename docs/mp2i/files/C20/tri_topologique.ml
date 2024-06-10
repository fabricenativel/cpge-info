
type digraph = {taille : int;  ladj : int list array};;

let cree_graphe n  = {taille = n; ladj= Array.make n []};;

  let dfs_stack graphe depart =
    let deja_vu =  Array.make graphe.taille false in
    let a_faire = Stack.create () in
    let tri = ref [] in
    Stack.push  depart a_faire;
    while not (Stack.is_empty a_faire) do
      let sommet_courant = Stack.pop a_faire in
      if not (deja_vu.(sommet_courant)) then(
          deja_vu.(sommet_courant) <- true;
          tri := sommet_courant::(!tri);
          List.iter (fun s-> Stack.push s a_faire) (graphe.ladj.(sommet_courant)););
      done;
    List.rev !tri;;

    
    let tri_topologique graphe =
      let deja_vu =  Array.make graphe.taille false in
      let tri_topo = ref [] in
      let rec aux_dfs s =
        if (not deja_vu.(s)) then (
          deja_vu.(s) <- true;
          List.iter aux_dfs (graphe.ladj.(s));
          tri_topo := s::(!tri_topo);
          ) in
      for i=0 to graphe.taille-1 do
        aux_dfs i;
      done;
     !tri_topo;;

     let ordre_dfs graphe =
      let deja_vu =  Array.make graphe.taille false in
      let ordre = ref [] in
      let rec aux_dfs s =
        if (not deja_vu.(s)) then (
          deja_vu.(s) <- true;
          List.iter aux_dfs (graphe.ladj.(s));
          ordre := s::(!ordre);
          ) in
      List.iter aux_dfs (List.init (graphe.taille) (fun i-> i));
     !ordre;;

let rec ajoute_aretes graphe lar =
match lar with  
  | [] -> ()
  | (d,a)::t -> graphe.ladj.(d) <- a::graphe.ladj.(d); ajoute_aretes graphe t ;;

let () = 
  let test = cree_graphe 8 in
  ajoute_aretes test [(0,2);(0,7);(1,0);(1,2);(1,5);(2,7);(2,3);(2,5);(3,7);(3,4);(3,6);(5,3);(6,4);(7,4)];
  let pp = tri_topologique test  in
  List.iter (fun d -> Printf.printf "%d " d) pp ;
  print_newline ();;
  

    
