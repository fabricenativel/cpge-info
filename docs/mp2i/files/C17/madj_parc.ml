type graphe = {
  taille : int; 
  madj : bool array array};;

let cree_graphe n =
  {taille = n; madj = Array.make_matrix n n false};;


  let visualise g =
    let n = (g.taille - 1) in
    let writer = open_out "temp.gv" in
    output_string writer "digraph mygraph {\n";
    for i=0 to n do
      Printf.fprintf writer "%d\n" i;
      for j=0 to n do
        if g.madj.(i).(j) then Printf.fprintf writer "%d -> %d\n" i j;
      done;
    done;
    output_string writer "}\n";
    close_out writer;
    ignore (Sys.command "dot -Tpng temp.gv -o temp.png");
    ignore (Sys.command "eog temp.png");;

let pile_successeur g s =
  let ls = Queue.create() in
  for i=0 to (Array.length g.madj - 1) do
    if (g.madj.(s).(i)) then  Queue.push i ls 
  done;
  ls;;
  
let rec pp_aux graphe sommet visite =
  let n = graphe.taille in
  let rp = ref [sommet] in
  for i=0 to n-1 do
    if (graphe.madj.(sommet).(i) && not visite.(i))
       then (
        visite.(i) <- true;
        rp := !rp @ (pp_aux graphe i visite);
       )
  done;
  !rp;;

let pp graphe sommet  =
  let visite = Array.make graphe.taille false in
  visite.(sommet) <- true;
  pp_aux graphe sommet visite;;

let cree_arete graphe i j =
  graphe.madj.(i).(j) <- true;;

let degre graphe i =
  let d = ref 0 in
  for j = 0 to (Array.length graphe.madj - 1) do
    if (graphe.madj.(i).(j)) then d:=!d+1;
  done;
  !d;;

let rec affiche parcours =
  match parcours with
  | [] -> ()
  | h::[] -> Printf.printf " -> %d |" h;
  | h::t -> Printf.printf " -> %d" h; (affiche t);;

let () = let g = cree_graphe 8 in
          cree_arete g 1 0;
          cree_arete g 1 2;
          cree_arete g 2 1;
          cree_arete g 2 3;
          cree_arete g 3 4;
          cree_arete g 4 2;
          cree_arete g 5 3;
          cree_arete g 7 5;
          cree_arete g 6 4;
          cree_arete g 6 7;
          cree_arete g 7 6;
          visualise g;
          Printf.printf "Parcours depuis sommet 3 : ";
          affiche (pp g 3)
;;
