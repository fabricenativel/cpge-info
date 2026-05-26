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
        Noeud(randomabr  (Array.sub label 0 (ls-2)),label.(ls-1),Vide) else
      Noeud(randomabr  (Array.sub label 0 k), label.(k) ,randomabr  (Array.sub label (k+1) (ls-k-1)  ))
    );;

let rec randomtree n e =
  if n = 0 then Vide else 
    (let k = Random.int n in
    Noeud(randomtree k (e+1) , e, randomtree (n-k-1) (e+k+1))
    )
  ;;

let rec prefixe_naif t =
  match t with
  | Vide -> []
  | Noeud (g, v, d) -> v :: prefixe_naif g @ prefixe_naif d

let  prefixe t =
  let rec aux_pre t acc =
    match t with
    | Vide -> acc
    | Noeud (g, v, d) -> v :: (aux_pre g (aux_pre d acc)) in
  aux_pre t [];;


let rec infixe_naif t =
  match t with
  | Vide -> []
  | Noeud (g, v, d) -> (infixe_naif g) @ [v] @ (infixe_naif d)


let infixe t =
  let rec aux_infixe t acc =
    match t with
    | Vide -> acc
    | Noeud (g, v, d) -> aux_infixe g (v::(aux_infixe d acc)) in
  aux_infixe t [];;

let rec postfixe_naif t =
  match t with
  | Vide -> []
  | Noeud (g, v, d) -> (postfixe_naif g) @ (postfixe_naif d) @ [v]

let rec postfixe t =
  let rec aux_postfixe t acc =
    match t with
    | Vide -> acc
    | Noeud (g, v, d) -> aux_postfixe g (aux_postfixe d (v::acc)) in
  aux_postfixe t [];;

let rec affiche ilist =
  match ilist with
  | [] -> print_newline()
  | h::t -> Printf.printf "%d; " h; affiche t
;;


let () = 
    Random.self_init();
    let lb = (make_label 10 0 50) in
    Printf.printf "[| ";
    for i = 0 to 9 do
      Printf.printf "%d; " lb.(i);
    done;
    Printf.printf "|]\n";
    let t = randomabr lb in
    Printf.printf "> Parcours prefixe \n";
    affiche (prefixe_naif t);
    affiche (prefixe t);
    Printf.printf "> Parcours infixe \n";
    affiche (infixe_naif t);
    affiche (infixe t);
    Printf.printf "> Parcours postfixe \n";
    affiche (postfixe_naif t);
    affiche (postfixe t);
    view(t)
    ;;
