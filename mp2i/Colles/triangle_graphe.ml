
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



let cree_arete g i j =
  g.ladj.(i) <- j::g.ladj.(i);
  g.ladj.(j) <- i::g.ladj.(j);;