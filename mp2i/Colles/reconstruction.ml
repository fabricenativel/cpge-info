type ab = 
 |Vide 
 |Noeud of ab *  int * ab;;

let ninv = ref 0;;

let rec write_edge a writer =
  match a with
  | Vide -> ()
  | Noeud (sag,e,sad) ->
    match sag, sad with
    | Vide, Vide -> ();
    | Noeud (_, eg, _), Vide ->
        Printf.fprintf writer "%d -> %d\n" e eg;
        Printf.fprintf writer  "I%d [style=invis]\n %d -> I%d [style=invis]\n" !ninv e !ninv;
        ninv := !ninv +1;
        Printf.fprintf writer  "I%d [style=invis]\n %d -> I%d [style=invis]\n" !ninv e !ninv;
        ninv := !ninv +1;
        write_edge sag writer;
    | Vide, Noeud(_,ed,_) ->
        Printf.fprintf writer  "I%d [style=invis]\n %d -> I%d [style=invis]\n" !ninv e !ninv;
      ninv := !ninv +1;
        Printf.fprintf writer  "I%d [style=invis]\n %d -> I%d [style=invis]\n" !ninv e !ninv;
        ninv := !ninv +1;
        Printf.fprintf writer "%d -> %d\n" e ed;
        write_edge sad writer;
    | Noeud (_,eg,_), Noeud (_,ed, _ ) ->
        Printf.fprintf writer "%d -> %d\n" e eg;
        Printf.fprintf writer  "I%d [style=invis]\n %d -> I%d [style=invis]\n" !ninv e !ninv;
        ninv := !ninv +1;
        Printf.fprintf writer "%d -> %d\n" e ed;
        write_edge sag writer;
        write_edge sad writer;
    ;;

let view a =
let outc = open_out "temp.gv" in
output_string outc "digraph mygraph {\n";
write_edge a outc;
output_string outc "}\n";
close_out outc;
ignore (Sys.command "dot -Tpng temp.gv -o temp.png");
ignore (Sys.command "eog temp.png");;

let affiche p =
  Printf.printf "[ ";
  let rec aux p =
    match p with 
    | [] -> Printf.printf "] \n"
    | h::[] -> Printf.printf "%d ]\n" h
    | h:: t -> Printf.printf "%d; " h; aux t
  in
  aux p;;

let infixe ab = 
  let rec aux ab acc =
    match ab with
    | Vide -> acc
    | Noeud(g,v,d) ->  aux g (v::(aux d acc))
  in aux ab [];;

let rec postfixe ab =
  match ab with
  | Vide -> []
  | Noeud(g,v,d) -> postfixe g @ postfixe d @ [v];;

let rec prefixe ab = 
  let rec aux ab acc =
    match ab with
    | Vide -> acc
    | Noeud(g,v,d) -> v :: (aux g (aux d acc))
  in aux ab [];;


let rec separe_valeur liste valeur =
  match liste with
  | [] -> failwith "L'entier n'est pas dans la liste"
  | h::t -> if h=valeur then [],t else let l1,l2 = separe_valeur t valeur in h::l1,l2

let rec separe_nb  liste nb =
  match liste, nb with
  | l , 0 -> [], l
  | [], _ -> failwith "Erreur d'index"
  | h::t, n -> let l1,l2 = separe_nb t (n-1) in h::l1, l2

let rec reconstruit prefixe infixe =
  match prefixe, infixe with
  | [],[] -> Vide
  | [],_ | _, [] -> failwith "Ne sont pas des parcours prefixe et infixe"
  | h::t, infi -> 
    let infixe1, infixe2 = separe_valeur infixe h  in
    let prefixe1, prefixe2 = separe_nb t (List.length infixe1)  in
    let p1 = reconstruit prefixe1 infixe1 in
    let p2 = reconstruit prefixe2 infixe2 in
      Noeud(p1, h ,p2);;

let rec randomtree n e =
  if n = 0 then Vide else 
    (let k = Random.int n in
    Noeud(randomtree k (e+1) , e, randomtree (n-k-1) (e+k+1))
    )
  ;;

let () = 
 let p = [0; 1; 2; 3; 4; 5; 6; 7] in
 let i = [1; 2; 0; 5; 4; 6; 3; 7] in
 let t = reconstruit p i in
 view t
;;

