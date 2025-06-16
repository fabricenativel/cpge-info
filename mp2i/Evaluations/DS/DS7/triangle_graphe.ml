
type graphe = {
  taille : int;
  ladj : int list array};;

let cree_graphe n =
  {taille=n; ladj = Array.make n []};;


let rec intersection l1 l2 =
  match l1, l2 with
  | _, [] -> []
  | [], _ -> []
  | h1::t1, h2::t2 -> if h1=h2 then h1::intersection t1 t2 else
    if h1<h2 then intersection t1 l2 else
      intersection l1 t2;;

let ajoute_arete g i j =
  let rec insere elt lst =
    match lst with
    | [] -> [elt]
    | h::t -> if h<elt then h::insere elt t else elt::h::t in
  g.ladj.(i) <- insere j g.ladj.(i);
  g.ladj.(j) <- insere i g.ladj.(j);;
  

let triangle gr =
  let n = gr.taille in
  let res = ref [] in
  (* pour tous les arcs i, j où j est dans lst, ajoute (i,j,k) dans les triangles avec k dans l'intersection des listes d'adjacence*)
  let rec aux  i lst =
    match lst with
    | [] -> ()
    | j::t -> if j>i then res := !res @ List.map (fun k -> (i,j,k)) (List.filter (fun k -> (k>i && k>j))(intersection gr.ladj.(i) gr.ladj.(j))); aux i t 
  in
  for i = 0 to n-1 do
    aux i gr.ladj.(i);
  done;
  !res;;

let arete gr i =
  List.map (fun k-> (i,k)) (List.filter (fun k-> k>i) gr.ladj.(i))

let ex () =
  let gr = cree_graphe 5 in
  ajoute_arete gr 0 1;
  ajoute_arete gr 0 4;
  ajoute_arete gr 0 3;
  ajoute_arete gr 1 2;
  ajoute_arete gr 1 3;
  ajoute_arete gr 1 4;
  ajoute_arete gr 2 4;
  ajoute_arete gr 3 4;
  gr;;


