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

let rec randomtree n e etiquettes =
  if n = 0 then Vide else 
    (let k = Random.int n in
    Noeud(randomtree k (e+1) etiquettes , etiquettes.(e), randomtree (n-k-1) (e+k+1) etiquettes)
    )
  ;;
 
let rec min_locaux arbre =
  let rec aux_ml arbre parent =
  match arbre with 
  | Vide -> []
  | Noeud(Vide,e,Vide) -> if (e<parent) then [e] else []
  | Noeud(Noeud(gg,eg,gd),e,Vide) -> if (e<parent && e<eg) then e::(aux_ml (Noeud(gg,eg,gd)) e) else (aux_ml (Noeud(gg,eg,gd)) e)
  | Noeud(Vide,e,Noeud(dg,ed,dd)) -> if (e<parent && e<ed) then e::(aux_ml (Noeud(dg,ed,dd)) e) else (aux_ml (Noeud(dg,ed,dd)) e)
  | Noeud(Noeud(gg,eg,gd),e,Noeud(dg,ed,dd)) -> if (e<parent && e<eg && e<ed) then e::(aux_ml (Noeud(gg,eg,gd)) e)@(aux_ml (Noeud(dg,ed,dd)) e) else (aux_ml (Noeud(gg,eg,gd)) e)@(aux_ml (Noeud(dg,ed,dd)) e) 
  in aux_ml arbre Int.max_int

let rec trouve_min arbre =
  match arbre with
  | Vide -> failwith "Pas de minimum local dans un arbre vide !"
  | Noeud(Vide,e,Vide) -> e
  | Noeud(Noeud(gg,eg,gd),e,Vide) -> if e<eg then e else trouve_min (Noeud(gg,eg,gd))
  | Noeud(Vide,e,Noeud(gd,ed,dd)) -> if e<ed then e else trouve_min (Noeud(gd,ed,dd))
  | Noeud(Noeud(gg,eg,gd),e,Noeud(dg,ed,dd)) -> if (e<eg && e<ed) then e else if e>eg then trouve_min (Noeud(gg,eg,gd)) else trouve_min (Noeud(dg,ed,dd))

  let affiche p =
    Printf.printf "[ ";
    let rec aux p =
      match p with 
      | [] -> Printf.printf "] \n"
      | h::[] -> Printf.printf "%d ]\n" h
      | h:: t -> Printf.printf "%d; " h; aux t
    in
    aux p;;

let () = 
Random.self_init ();
 let mtree = randomtree 9 0 [| 0; 3; -2; -4; 2; 8; 1; 6; 4 |] in
 let mm = min_locaux mtree in
 affiche mm;
 Printf.printf "Premier minimum local trouvé = %d\n" (trouve_min mtree);
 view mtree;
;;