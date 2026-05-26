let rec est_dans elt lst =
  (* Le cas de base est la liste vide, sinon elt est dans lst
  lorsque elt est la tête de lst ou qu'il est dans la queue de lst*)
  match lst with
  | [] -> false
  | h::t -> h=elt || est_dans elt t;;

let  manquant lst =
  let rec aux lst p =
    if est_dans p lst then aux lst (p+1) else p in
  aux lst 0;;

let rec non_consecutif lst =
  match lst with
  | [] -> 0
  | h::[] -> h+1
  | h1::h2::t -> if (h2-h1)>1 then h1+1 else non_consecutif (h2::t);;

let manquant_trie lst =
  let rec aux lst n =
    match lst with
    | [] -> n
    | h::t -> if h=n-1 then aux t n
              else if h=n then aux t (n+1)
              else n in
    aux lst 0;;

let trie lst =
  List.sort (fun a b -> a-b) lst;;

let rec aleatoire n vmin vmax =
  if n=0 then [] else (vmin + Random.int (vmax-vmin+1))::(aleatoire (n-1) vmin vmax);;

let () = Random.self_init ();
         let tlist = aleatoire 200000 0 100000 in
         Printf.printf "Premier manquant quadratique : %d\n" (manquant tlist);
         Printf.printf "Premier manquant linéarithmique : %d\n" (manquant_trie (trie tlist));

