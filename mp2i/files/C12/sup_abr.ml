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


let rec plus_petit tabr v =
  match tabr with
  | Vide -> true
  | Noeud (g, r, d) -> r < v && plus_petit d v ;;

let rec plus_grand tabr v =
    match tabr with
    | Vide -> true
    | Noeud (g, r, d) -> plus_grand g v && r > v;;

let rec est_abr tabr =
  match tabr with
  | Vide -> true
  | Noeud (g, v, d) -> est_abr g && est_abr d && plus_petit g v && plus_grand d v
;;

let rec est_abr2 tabr =
  let rec est_aux tabr vmin vmax=
  match tabr with
  | Vide -> true
  | Noeud (g, v, d) -> est_aux g vmin v && est_aux d v vmax in
  est_aux tabr Int.min_int Int.max_int;;

let rec extraire_min rabr =
  match rabr with
  | Vide -> failwith "L'arbre est vide !"
  | Noeud (Vide, r, d) -> r, d
  | Noeud (g, r, d) -> let mv, rt = extraire_min g in mv, Noeud (rt, r, d)
;;

let rec supprime_val tabr v=
  match tabr with
  | Vide -> failwith "Valeur non présente dans l'arbre"
  | Noeud (g, r, d) ->  if r=v then let mv, rd = extraire_min d in Noeud (g, mv, rd) else
                        if r>v then Noeud (supprime_val g v, r, d) else
                        Noeud (g, r, supprime_val d v)  

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
  let t = ref Vide in
  let nv = [| 9; 12; 2; 6; 13; 8; 0; 5; 7; 10|] in
  for i = 0 to 9 do
    t:= insere !t nv.(i);
  done;
  infixe !t;
  print_newline ();
  Printf.printf "%s \n" (makepst !t); 
  view (supprime_val !t 2);;
  
