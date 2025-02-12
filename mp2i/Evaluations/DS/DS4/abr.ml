type abr = 
  | Vide 
  | Noeud of  abr * int * abr;;

let rec insere valeur arbre = 
  match arbre with
  | Vide -> Noeud(Vide, valeur, Vide)
  | Noeud( g, v, d) -> 
    if valeur < v then Noeud(insere valeur g, v, d)
    else if valeur > v then Noeud(g, v, insere valeur d)
    else failwith "Element déjà présent";;

let rec write_edge a writer ninv=
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
      write_edge sag writer ninv;
    | Vide, Noeud(_,ed,_) ->
      Printf.fprintf writer  "I%d [style=invis]\n %d -> I%d [style=invis]\n" !ninv e !ninv;
      ninv := !ninv +1;
      Printf.fprintf writer  "I%d [style=invis]\n %d -> I%d [style=invis]\n" !ninv e !ninv;
      ninv := !ninv +1;
      Printf.fprintf writer "%d -> %d\n" e ed;
      write_edge sad writer ninv;
    | Noeud (_,eg,_), Noeud (_,ed, _ ) ->
      Printf.fprintf writer "%d -> %d\n" e eg;
      Printf.fprintf writer  "I%d [style=invis]\n %d -> I%d [style=invis]\n" !ninv e !ninv;
      ninv := !ninv +1;
      Printf.fprintf writer "%d -> %d\n" e ed;
      write_edge sag writer ninv;
      write_edge sad writer ninv;
;;

let view a =
  let ninv = ref 0 in
  let outc = open_out "temp.gv" in
  output_string outc "digraph mygraph {\n";
  write_edge a outc ninv;
  output_string outc "}\n";
  close_out outc;
  ignore (Sys.command "xdot temp.gv");;

let () = 
  let arbre = Vide in
  let arbre = insere 5 arbre in
  let arbre = insere 7 arbre in
  let arbre = insere 2 arbre in
  let arbre = insere 1 arbre in
  let arbre = insere 8 arbre in
  view arbre;;