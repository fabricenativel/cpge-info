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

let make_label n minv maxv =
  let label = Array.make n minv in
  let inc = (maxv-minv)/n in
  label.(0) <- minv + 1 + Random.int inc;
  for i=1 to (n-1) do
    label.(i) <- label.(i-1) + 1 + Random.int inc;
  done;
  label;;

let rec randomabr label =
  let ls = Array.length label in
  if ls=0 then Vide else
    (
      let k = Random.int ls in
      if k=0 then 
        Noeud(Vide,label.(0),randomabr  (Array.sub label 1 (ls-1))) else
      if k=ls-1 then
        Noeud(randomabr  (Array.sub label 0 (ls-1)),label.(ls-1),Vide) else
      Noeud(randomabr  (Array.sub label 0 k), label.(k) ,randomabr  (Array.sub label (k+1) (ls-k-1)  ))
    );;

let rec randomtree n e =
  if n = 0 then Vide else 
    (let k = Random.int n in
    Noeud(randomtree k (e+1) , e, randomtree (n-k-1) (e+k+1))
    )
  ;;


let rec makepst ab =
  match ab with
  | Vide -> ""
  | Noeud(Vide,v,Vide) -> Printf.sprintf "\\TCircle{%d} \n" v
  | Noeud(Vide,v,d) -> let rep = Printf.sprintf "\\pstree{\\TCircle{%d}}\n{ \\Tn{} \n"  v in 
  rep ^ makepst d ^ "}"
  | Noeud(g,v,Vide) -> let rep = Printf.sprintf "\\pstree{\\TCircle{%d}}\n{ \\Tn{} \n"  v in 
  rep ^ makepst g ^ " \n \\Tn{} }"
  | Noeud(g,v,d) -> let rep = Printf.sprintf "\\pstree{\\TCircle{%d}}\n{" v in 
   rep ^ makepst g  ^ makepst d  ^"}";;

let () = 
    Random.self_init();
    let lb = make_label 8 10 42 in
    let t = randomabr lb in
    view(t);
    print_string (makepst t)
  ;;
