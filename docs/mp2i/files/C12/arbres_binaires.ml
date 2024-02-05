type ab = 
 |Vide 
 |Noeud of ab *  char * ab;;
let ninv = ref 0;;

let rec taille ab =
  match ab with
  | Vide -> 0
  | Noeud (sag, _, sad) -> 1 + taille sag + taille sad;;

let rec write_edge a writer =
    match a with
    | Vide -> ()
    | Noeud (sag,e,sad) ->
      match sag, sad with
      | Vide, Vide -> ();
      | Noeud (_, eg, _), Vide ->
          Printf.fprintf writer "%c -> %c\n" e eg;
          Printf.fprintf writer  "I%d [style=invis]\n %c -> I%d [style=invis]\n" !ninv e !ninv;
          ninv := !ninv +1;
          Printf.fprintf writer  "I%d [style=invis]\n %c -> I%d [style=invis]\n" !ninv e !ninv;
          ninv := !ninv +1;
          write_edge sag writer;
      | Vide, Noeud(_,ed,_) ->
          Printf.fprintf writer  "I%d [style=invis]\n %c -> I%d [style=invis]\n" !ninv e !ninv;
        ninv := !ninv +1;
          Printf.fprintf writer  "I%d [style=invis]\n %c -> I%d [style=invis]\n" !ninv e !ninv;
          ninv := !ninv +1;
          Printf.fprintf writer "%c -> %c\n" e ed;
          write_edge sad writer;
      | Noeud (_,eg,_), Noeud (_,ed, _ ) ->
          Printf.fprintf writer "%c -> %c\n" e eg;
          Printf.fprintf writer  "I%d [style=invis]\n %c -> I%d [style=invis]\n" !ninv e !ninv;
          ninv := !ninv +1;
          Printf.fprintf writer "%c -> %c\n" e ed;
          write_edge sag writer;
          write_edge sad writer;
      ;;

let view a =
  let outc = open_out "temp.gv" in
  output_string outc "digraph mygraph {\n graph";
  write_edge a outc;
  output_string outc "}\n";
  close_out outc;
  Sys.command "dot -Tpng temp.gv -o temp.png";
  Sys.command "eog temp.png";;
  

let rec prefixe a =
  match a with
  | Vide -> ()
  | Noeud (g,e,d) -> Printf.printf "%c " e; prefixe g; prefixe d;;


let rec infixe a =
  match a with
  | Vide -> ()
  | Noeud (g,e,d) ->  infixe g; Printf.printf "%c " e; infixe d;;

  let rec postfixe a =
    match a with
    | Vide -> ()
    | Noeud (g,e,d) ->  postfixe g; postfixe d; Printf.printf "%c " e;;

let () =
let  a = Noeud (
  Noeud(Noeud(Vide,'V',Noeud(Vide,'M',Vide)),'T',Noeud(Vide,'I',Vide)),
  'R',
  Noeud(Noeud(Noeud(Vide,'P',Vide),'F',Noeud(Vide,'A',Vide)),'C',Vide)
  ) in
prefixe a;
print_newline();
infixe a;
print_newline();
postfixe a;
print_newline();
Printf.printf "Taille : %d\n" (taille a);
