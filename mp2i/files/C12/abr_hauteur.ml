
type abr = 
 |Vide 
 |Noeud of abr *  int * abr;;
let ninv = ref 0;;

let rec taille ab =
  match ab with
  | Vide -> 0
  | Noeud (sag, _, sad) -> 1 + taille sag + taille sad;;

let rec hauteur ab =
    match ab with
    | Vide -> -1
    | Noeud (sag, _, sad) -> 1 + max (hauteur sag) (hauteur sad);;

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
  

let random_tab n =
  let tab = Array.make n 0 in
  for i=0 to n-1 do
    tab.(i) <- i
  done;
  let j = ref 0 in
  let temp = ref 0 in
  for i=n-1 downto 1 do
    j := Random.int i;
    temp := tab.(i) ;
    tab.(i) <- tab.(!j);
    tab.(!j) <- !temp;
  done;
  tab;;


  let rec insere abr nv =
    match abr with
    | Vide -> Noeud(Vide,nv,Vide)
    | Noeud(g,v,d) -> if nv<v then Noeud(insere g nv, v, d) else Noeud(g, v, insere d nv);; 

let hrandom n =
  let rt = random_tab n in
  let ab = ref Vide in
  for i=0 to n-1 do
    ab := insere !ab rt.(i);
  done;
  hauteur !ab;;

let rec in_abr abr u =
  match abr with
  | Vide -> false
  | Noeud(g,v,d) -> if u=v then true else
                    if u<v then in_abr g u else in_abr d u;;

let () =
  Random.self_init();
  let n = 1024 in
  let hmin = ref n in
  let hmax = ref (-1) in
  let sh = ref 0 in
  let h = ref 0 in
  for i=1 to 1000 do 
      h := hrandom n; 
      Printf.printf "h courante = %d\n" !h;
      sh := !sh + !h;
      if !h < !hmin then hmin:=!h;
      if !h > !hmax then hmax:=!h;
  done;
  Printf.printf "Hauteur minimale = %d\n" !hmin;
  Printf.printf "Hauteur maximale = %d\n" !hmax;
  let hm = (float_of_int !sh) /. 1000. in
  Printf.printf "Hauteur moyenne = %f\n" hm;
  ;;
  
