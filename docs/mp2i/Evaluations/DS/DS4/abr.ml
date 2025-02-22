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
  ignore (Sys.command "xdot temp.gv &");;

let rec view_prefixe ab =
  match ab with
  | Vide -> ()
  | Noeud(g, e, d) -> print_int e; print_string " "; view_prefixe g; view_prefixe d;;

let rec view_infixe ab =
  match ab with
  | Vide -> ()
  | Noeud(g, e, d) ->  view_infixe g; print_int e; print_string " "; view_infixe d;;

let rec view_suffixe ab =
  match ab with
  | Vide -> ()
  | Noeud(g, e, d) ->  view_suffixe g; view_suffixe d; print_int e; print_string " ";;


let () = 
  let arbre = Noeud (
      Noeud(Noeud(Vide, 10, Noeud(Vide, 17, Vide)),28,Noeud(Vide,31,Vide)),
      42,
      Noeud(Noeud(Noeud(Vide,27,Vide),24,Vide),32,Vide)
  ) in
  print_string "Prefixe = ";
  view_prefixe arbre;
  print_newline ();
  print_string "Infixe = ";
  view_infixe arbre;
  print_newline ();
  print_string "Suffixe = ";
  view_suffixe arbre;
  print_newline ();
  view arbre;;