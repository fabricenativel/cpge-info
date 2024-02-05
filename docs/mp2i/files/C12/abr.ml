open Hashtbl

let ht = Hashtbl.create 1000;;

type abr = 
 |Vide 
 |Noeud of abr *  int * abr;;
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

let rec insere abr nv =
  match abr with
  | Vide -> Noeud(Vide,nv,Vide)
  | Noeud(g,v,d) -> if nv<v then Noeud(insere g nv, v, d) else Noeud(g, v, insere d nv);; 

let rec in_abr abr u =
  match abr with
  | Vide -> false
  | Noeud(g,v,d) -> if u=v then true else
                    if u<v then in_abr g u else in_abr d u;;

let () =
  Random.self_init();
  let t = ref Vide in
  let nv = ref (Random.int 100) in
  for i = 0 to 20 do
    while (Hashtbl.mem ht !nv) do
      nv := Random.int 100;
    done;
    Hashtbl.add ht !nv 0;
    t:= insere !t !nv;
  done;
  infixe !t;
  print_newline ();
  view !t;;
  
