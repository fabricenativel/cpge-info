
type graphe = {
taille : int;
ladj : int list array};;


let cree_graphe n =
  {taille=n; ladj = Array.make n []}

let cree_arete g i j =
  g.ladj.(i) <- j::g.ladj.(i);
  g.ladj.(j) <- i::g.ladj.(j);;

let visualise g =
  let n = (g.taille - 1) in
  let writer = open_out "temp.gv" in
  output_string writer "graph mygraph {\n";
  let rec aux i wl =
    match wl with
    | [] -> ()
    | h::t -> if h>i then (Printf.fprintf writer "%d -- %d\n" i h); aux i t
  in
  for i=0 to n do
      Printf.fprintf writer "%d\n" i;
      aux i g.ladj.(i);
    done;
  output_string writer "}\n";
  close_out writer;
  ignore (Sys.command "dot -Tpng temp.gv -o temp.png");
  ignore (Sys.command "eog temp.png");;


  let () = let g = cree_graphe 5 in
          cree_arete g 0 1;
          cree_arete g 0 2;
          cree_arete g 0 3;
          cree_arete g 1 3;
          cree_arete g 2 4;
          visualise g;
