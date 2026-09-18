type ab = 
  | Vide
  | Noeud of ab * int * ab;;


let rec partage_elt liste elt =
  match liste with
  | [] -> [], []
  | h::t -> if h=elt then [], t else let p1,p2 = partage_elt t elt in h::p1, p2;;

let rec partage_longueur liste n =
  if n=0 then [], liste else let h = List.hd liste in let t = List.tl liste in let p1,p2 = partage_longueur t (n-1) in h::p1, p2;;

let rec reconstruit  prefixe infixe =
  match prefixe with
  | [] -> Vide
  | h::t -> let infixe_gauche, infixe_droit = partage_elt infixe h in
    let prefixe_gauche, prefixe_droit = partage_longueur t (List.length infixe_gauche) in
    Noeud (reconstruit prefixe_gauche infixe_gauche, h, reconstruit prefixe_droit infixe_droit);;


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

let view a=
  let ninv = ref 0 in
  let outc = open_out "temp.gv" in
  output_string outc "digraph mygraph {\n";
  write_edge a outc ninv;
  output_string outc "}\n";
  close_out outc;
  ignore (Sys.command "xdot temp.gv");
  ;;

let () = let ab = reconstruit [0; 1; 2; 3; 4; 5; 6; 7] [1; 2; 0; 5; 4; 6; 3; 7] in      
  view ab;

