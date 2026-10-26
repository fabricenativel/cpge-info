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

(* renvoie 2 listes : elts situés évant sep et elts situés après*)
let rec separe l sep acc =
  match l with 
  | [] -> acc, []
  | h::t -> if h=sep then (List.rev acc,t) else separe t sep (h::acc);;

(* renvoie les n premiers et le reste de la liste*)
let rec separe2 l n acc =
  if n=0 then (List.rev  acc, l) else separe2 (List.tl l) (n-1) ((List.hd l)::acc) ;;

  
let rec reconstruit pref infi =
  match pref, infi with
  | [],[] -> "Vide"
  | [],_ | _, [] -> failwith "Bug"
  | r::q, infi -> 
    let infi1, infi2 = separe infi r [] in
    let pre1, pre2 = separe2 q (List.length infi1) [] in
    let p1 = reconstruit pre1 infi1 in
    let p2 = reconstruit pre2 infi2 in
      "Noeud(" ^p1^ ","^ (string_of_int r)^","^p2^ ")";;

let rec randomtree n e =
  if n = 0 then Vide else 
    (let k = Random.int n in
    Noeud(randomtree k (e+1) , e, randomtree (n-k-1) (e+k+1))
    )
  ;;

let () = 
let t = randomtree 5 0 in
 affiche (postfixe t);
 affiche (prefixe t);
 view t
;;

