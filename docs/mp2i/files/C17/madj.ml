
(*--8<-- [start:struct]*)
type graphe = {
  taille : int; 
  madj : bool array array};;
(*--8<-- [end:struct]*)

let cree_graphe n =
  {taille = n; madj = Array.make_matrix n n false};;


(*--8<-- [start:visualise]*)
let visualise g =
  let n = (g.taille - 1) in
  let writer = open_out "temp.gv" in
  output_string writer "graph mygraph {\n";
  for i=0 to n do
    Printf.fprintf writer "%d\n" i;
    for j=i+1 to n do
      if g.madj.(i).(j) then Printf.fprintf writer "%d -- %d\n" i j;
    done;
  done;
  output_string writer "}\n";
  close_out writer;
  ignore (Sys.command "xdot temp.gv &");;
(*--8<-- [end:visualise]*)

let cree_arete graphe i j =
  graphe.madj.(i).(j) <- true;
  graphe.madj.(j).(i) <- true;;

let degre graphe i =
  let d = ref 0 in
  for j = 0 to (Array.length graphe.madj - 1) do
    if (graphe.madj.(i).(j)) then d:=!d+1;
  done;
  !d;;

let () = let g = cree_graphe 5 in
  cree_arete g 0 1;
  cree_arete g 0 2;
  cree_arete g 0 3;
  cree_arete g 1 3;
  cree_arete g 2 3;
  visualise g;
  Printf.printf "Le degré du sommet 0 est %d" (degre g 0);;
