(* type graphe *)
type graphe = {taille : int; ladj : (int*int) list array };;


let cree_file () = ref [];;

let est_vide fp =
  !fp=[];;


let prio elt =
  let sommet, p, parent = elt in p;;

let enfile fp elt =
      fp := elt::(!fp)

let plus_petit fp =
   List.fold_left (fun x s -> if prio x < prio s then x else s)  (List.hd !fp) !fp;;

let defile fp =
  let minp = plus_petit fp in
  fp := List.filter (fun x -> x <> minp) (!fp);
  minp;;

let cree_graphe n  = {taille = n; ladj= Array.make n []};;

let rec ajoute_aretes graphe lar =
    match lar with  
      | [] -> ()
      | (d,w,a)::t -> graphe.ladj.(d) <- (w,a)::graphe.ladj.(d);  ajoute_aretes graphe t ;;


let init_graphe () =
let test = cree_graphe 6 in
ajoute_aretes test [(0,5,1);(0,1,2);(2,3,1);(1,4,3);(1,2,4);(2,5,4);(2,7,5);(3,3,5);(4,1,5);];
test;;

    let visualise g =
      let n = (g.taille - 1) in
      let writer = open_out "temp.gv" in
      output_string writer "digraph mygraph {\n";
      let rec aux i wl =
        match wl with
        | [] -> ()
        | (w,h)::t -> Printf.fprintf writer "%d -> %d [label = %d] \n" i h w; aux i t
      in
      for i=0 to n do
        Printf.fprintf writer "%d\n" i;
        aux i g.ladj.(i);
      done;
      output_string writer "}\n";
      close_out writer;
      ignore (Sys.command "xdot temp.gv &");;

      
let dijkstra graphe source =
  let n = graphe.taille in
  let dist = Array.make n (-1) in
  let parents = Array.make n (-1) in
  let file = cree_file () in
  enfile file (source,0,-1);
  while not (est_vide file) do
    let sommet, prio, pred = defile file in
    if dist.(sommet)=(-1) then 
      (
        dist.(sommet) <- prio;
        parents.(sommet) <- pred;
        List.iter (fun (w,t) -> if dist.(t)=(-1) then  enfile file (t, prio+w, sommet);) graphe.ladj.(sommet);
      )
done;
  dist, parents;;