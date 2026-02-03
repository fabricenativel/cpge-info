(* --8<-- [start:type_int] *)
type ab = 
  |Vide 
  |Noeud of ab * int * ab ;;
(* --8<-- [end:type_int] *)


(* --8<-- [start:voir] *)
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
(* --8<-- [end:voir] *)

let rec mystere ab = 
  match ab with
  | Vide -> []
  | Noeud(g,v,d) ->   v::mystere g @ mystere d;;

let prefixe ab =
  let rec aux_prefixe ab acc =
    match ab with
    | Vide -> acc
    | Noeud(g, v, d) -> v::aux_prefixe d (aux_prefixe g acc) in
  aux_prefixe ab [];;

let parcours_infixe ab = [];;

let est_abr ab =
  let pi = parcours_infixe ab in
  let rec est_croissant l =
    match l with
    | [] -> true
    | h::[] -> true
    | h1::h2::t -> h1<h2 && est_croissant (h2::t) in
  est_croissant pi;;

let rec plus_petit ab v =
  (*Vérifie que toutes les valeurs dans ab sont inférieures à v*)
  match ab with
  | Vide -> true
  | Noeud(g, r, d) -> r<v && plus_petit g v && plus_petit d v;;


let infixe ab = 
  let rec aux ab acc =
    match ab with
    | Vide -> acc
    | Noeud(g,v,d) -> v :: (aux g (aux d acc))
  in aux ab [];;

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
  view t;;

