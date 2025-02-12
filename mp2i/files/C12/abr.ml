open Hashtbl

type abr = 
  |Vide 
  |Noeud of abr *  int * abr;;

let rec taille ab =
  match ab with
  | Vide -> 0
  | Noeud (sag, _, sad) -> 1 + taille sag + taille sad;;
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

let view a fname=
  let ninv = ref 0 in
  let outc = open_out fname in
  output_string outc "digraph mygraph {\n";
  write_edge a outc ninv;
  output_string outc "}\n";
  close_out outc;
  ignore (Sys.command ("xdot "^fname));;

let rec prefixe a =
  match a with
  | Vide -> ()
  | Noeud (g,e,d) -> Printf.printf "%d " e; prefixe g; prefixe d;;


let rec infixe a =
  match a with
  | Vide -> ()
  | Noeud (g,e,d) ->  infixe g; Printf.printf "%d " e; infixe d;;

let rec postfixe a =
  match a with
  | Vide -> ()
  | Noeud (g,e,d) ->  postfixe g; postfixe d; Printf.printf "%d " e;;

(* --8<-- [start:insereml] *)
let rec insere abr nv =
  match abr with
  | Vide -> Noeud(Vide,nv,Vide)
  | Noeud(g,v,d) -> if nv<v then Noeud(insere g nv, v, d) else Noeud(g, v, insere d nv);; 
(* --8<-- [end:insereml] *)

(* --8<-- [start:appartientml] *)
let rec in_abr abr u =
  match abr with
  | Vide -> false
  | Noeud(g,v,d) -> if u=v then true else
    if u<v then in_abr g u else in_abr d u;;
(* --8<-- [end:appartientml] *)

let rec extraire_min abr =
  match abr with
  | Vide -> failwith "arbre vide"
  | Noeud(Vide, v, d) -> v
  | Noeud(g, v, d) -> extraire_min g;;

let rec extraire_max abr =
  match abr with
  | Vide -> failwith "arbre vide"
  | Noeud(g, v, Vide) -> v
  | Noeud(g, v, d) -> extraire_max d;;

let rec supprime abr x =
  match abr with
  | Vide -> Vide
  | Noeud(g, v, d) -> if x<v then Noeud(supprime g x, v, d) else
    if x>v then Noeud(g, v, supprime d x) else
      match g,d with
      | Vide, Vide -> Vide
      | Vide, _ -> let mind = extraire_min d in Noeud(Vide, mind, supprime d mind) 
      | _, Vide -> let maxg = extraire_max g in Noeud(supprime g maxg, maxg, Vide)
      | _, _ -> let choix = Random.int 2 in if choix=1 then let mind = extraire_min d in Noeud(g, mind, supprime d mind) else let maxg = extraire_max g in Noeud(supprime g maxg, maxg, d);;


let melange tab =
  let n = Array.length tab in
  for i = 0 to n-1 do
    let j = Random.int n in
    let tmp = tab.(i) in
    tab.(i) <- tab.(j);
    tab.(j) <- tmp;
  done;;

let () =
  Random.self_init();
  let t = ref Vide in
  let size = 20 in
  let valeurs = Array.init size (fun i->i) in
  melange valeurs;
  for i = 0 to (size-1) do
    t:= insere !t valeurs.(i);
  done;
  print_newline ();
  view !t "dep";
  t := supprime !t 10;
  view !t "fin";
;;

