open Queue
type ab = Vide | Noeud of ab * int * ab ;;

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

let rec mystere ab = 
  match ab with
  | Vide -> []
  | Noeud(g,v,d) ->   v::mystere g @ mystere d;;

let infixe ab = 
  let rec aux ab acc =
    match ab with
    | Vide -> acc
    | Noeud(g,v,d) -> v :: (aux g (aux d acc))
  in aux ab [];;

let largeur ab =
  let file = Queue.create () in
  Queue.add ab file;
  while not(Queue.is_empty file) do
    let node = Queue.pop file in
    match node with
    | Vide -> ()
    | Noeud(g,v,d) -> Printf.printf "%d " v; Queue.push g file; Queue.push d file;
  done;;

let () = 
let t = Noeud(
          Noeud(
            Noeud(Noeud(Vide,2,Noeud(Vide,3,Vide)),8,Vide),
            9,
            Noeud(Vide,12,Vide)),
          11,
            Noeud(Noeud(Vide,13,Vide),
            15,
            Vide)) 
        in
 view t;
 largeur t
;;

