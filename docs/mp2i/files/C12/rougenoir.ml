
type couleur = Rouge | Noir;;
type arb = Vide | Noeud of arb * (couleur*int) * arb;;

let ninv = ref 0;;

let string_of_color c =
  match c with
  | Rouge -> "red"
  | Noir -> "black";;

let rec write_edge a writer =
  match a with
  | Vide -> ()
  | Noeud (sag,(c,e),sad) ->  Printf.fprintf writer "%d [color = %s]\n" e (string_of_color c);
    match sag, sad with
    | Vide, Vide -> ();
    | Noeud (_, (_,eg), _), Vide ->
        Printf.fprintf writer "%d -> %d\n" e eg;
        Printf.fprintf writer  "I%d [style=invis]\n %d -> I%d [style=invis]\n" !ninv e !ninv;
        ninv := !ninv +1;
        Printf.fprintf writer  "I%d [style=invis]\n %d -> I%d [style=invis]\n" !ninv e !ninv;
        ninv := !ninv +1;
        write_edge sag writer;
    | Vide, Noeud(_,(_,ed),_) ->
        Printf.fprintf writer  "I%d [style=invis]\n %d -> I%d [style=invis]\n" !ninv e !ninv;
      ninv := !ninv +1;
        Printf.fprintf writer  "I%d [style=invis]\n %d -> I%d [style=invis]\n" !ninv e !ninv;
        ninv := !ninv +1;
        Printf.fprintf writer "%d -> %d\n" e ed;
        write_edge sad writer;
    | Noeud (_,(_,eg),_), Noeud (_,(_,ed), _ ) ->
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
ignore (Sys.command "eog temp.png");
();;


let rec recherche arn n =
  match arn with
  | Vide -> false
  | Noeud(g,(_,v),d) -> if v=n then true else if n<v then recherche g n else recherche d n;;

let rec hauteur arn =
  match arn with
  | Vide -> -1
  | Noeud(g,(_,v),d) -> 1 + max (hauteur g) (hauteur d);;

let rec hauteur_noir arn =
  match arn with
  | Vide -> 0
  | Noeud(g,(Noir,v),d) -> 1 + max (hauteur_noir g) (hauteur_noir d)
  | Noeud(g,(Rouge,v),d) -> max (hauteur_noir g) (hauteur_noir d);;

let rec infixe arn =
  match  arn with
  | Vide -> []
  | Noeud(g,(_,v),d) -> (infixe) g @ [v] @ (infixe d)

let rec string_of_list l =
  match l with
  | [] -> ""
  | h::t -> (string_of_int h)^" "^(string_of_list t);;

let rec is_sorted l =
  match l with
  | [] -> true
  | x::[] -> true
  | x::y::t -> x<y && is_sorted (y::t)

let verifie_abr arn =
  is_sorted (infixe arn);;

let rec verifie_couleurs arn =
  match arn with
  | Vide -> true
  | Noeud(Vide,_,Vide) -> true 
  | Noeud(Noeud(_,(Rouge,_),_),(Rouge,_),_) -> false
  | Noeud(_,(Rouge,_),Noeud(_,(Rouge,_),_)) -> false
  | Noeud(g,(_,_),d) -> verifie_couleurs g && verifie_couleurs d && hauteur_noir g == hauteur_noir d;;

let verifie arn = verifie_abr arn && verifie_couleurs arn;;

let rec insertion arn nv = 
  match arn with
  | Vide -> Noeud(Vide,(Rouge,nv),Vide)
  | Noeud(g,(c,v),d) -> if nv<v then Noeud((insertion g nv),(c,v),d) else Noeud(g,(c,v),(insertion d nv));;

let noircir_racine arn = 
  match arn with
  | Noeud(g,(Rouge,v),d) -> Noeud(g,(Noir,v),d)
  | _ -> arn;;

let correction_rouge arn =
  match arn with
  | Noeud(Noeud(Noeud(a,(Rouge,x),b),(Rouge,y),c),(Noir,z),d)
  | Noeud(a,(Noir,x),Noeud(b,(Rouge,y),Noeud(c,(Rouge,z),d)))
  | Noeud(Noeud(a,(Rouge,x),Noeud(b,(Rouge,y),c)),(Noir,z),d)
  | Noeud(a,(Noir,x),Noeud(Noeud(b,(Rouge,y),c),(Rouge,z),d))
  -> Noeud(Noeud(a,(Noir,x),b),(Rouge,y),Noeud(c,(Noir,z),d))
  | _ -> arn

let insertion2 a v =
  let rec insere a = match a with
  | Vide -> Noeud(Vide,(Rouge, v), Vide)
  | Noeud(g,(c, x), d) ->
          if v <= x then
              (Noeud(correction_rouge (insere g),(c, x), d))
          else
              (Noeud(g,(c, x), correction_rouge (insere d)))
  in
  noircir_racine (correction_rouge (insere a))
;;

let t1 = Noeud(Noeud(Vide,(Noir,0),Vide),(Noir,1),Noeud(Noeud(Vide,(Noir,2),Vide),(Rouge,3),Noeud(Vide,(Noir,4),Noeud(Vide,(Rouge,5),Vide))))

let t2 = Noeud(Noeud(Vide,(Noir,0),Vide),(Noir,1),Noeud(Noeud(Vide,(Noir,2),Vide),(Rouge,3),Noeud(Vide,(Noir,4),Noeud(Vide,(Rouge,5),Noeud(Vide,(Noir,6),Vide)))))



(* let () =
      Random.self_init();
      let seen = ref [] in
      let t = ref Vide in
      for i=0 to 30 do
          let xx = (Random.int 100) in
          if (not (List.mem xx !seen))  then 
          (t:= insertion2 !t xx;
          seen := !seen @ [xx]); 
      done;
      Printf.printf "Est bien un arbre rouge noir : %s\n"  (string_of_bool (verifie !t));
      view !t;; *)

let () =
      Printf.printf "n \t h \t hn \n";
      let disp = [10; 100; 1000; 10000; 100000; 1000000;] in
      let t = ref Vide in
      for i=1 to 1000000 do
          t:= insertion2 !t i;
          if List.mem i disp then Printf.printf "%d \t %d \t %d\n" i (hauteur !t) (hauteur_noir !t);
      done;
      Printf.printf "Est bien un arbre rouge noir : %s\n"  (string_of_bool (verifie !t));;

  