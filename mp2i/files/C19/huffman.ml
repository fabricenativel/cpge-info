type 'a file_priorite = {
  mutable taille : int;
  donnees : (int*'a) array};;

(* --8<-- [start:type] *)
type abh = 
  | Feuille of char 
  | Noeud of abh*abh;;
(* --8<-- [end:type] *)


let nbchar = 128;;

let fils i = 2 * i + 1;;

let parent i = (i-1)/2 ;;

let cree_file t default= {taille =  0; donnees = Array.make t (0,default)};;

let cmp_prio elt1 elt2 = 
  let p1 = fst elt1 in 
  let p2 = fst elt2 in
  p1 < p2;;

let taille fp = fp.taille;;

let swap tab i j =
  let temp = tab.(i) in
  tab.(i) <- tab.(j);
  tab.(j) <- temp;;

exception File_pleine;;
exception File_vide;;

let enfile elt fp =
  if fp.taille = Array.length fp.donnees then  raise File_pleine else
    (let cp = ref fp.taille in
     fp.taille <- fp.taille + 1;
     fp.donnees.(!cp) <- elt;
     while (!cp <>0 &&  cmp_prio fp.donnees.(!cp)  fp.donnees.(parent !cp)) do
       (
         swap fp.donnees !cp (parent !cp);
         cp := parent !cp;
       )
     done;
    );;

let defile fp =
  if fp.taille = 0 then raise File_vide else
    (
      let res = fp.donnees.(0) in
      swap fp.donnees 0 (fp.taille-1);
      fp.taille <- fp.taille-1;
      let cp = ref 0 in
      let lc = ref (fils !cp) in
      (*Tant qu'il y a deux fils et que l'un est inférieur on échange*)
      while (!lc+1 < fp.taille && (cmp_prio fp.donnees.(!lc) fp.donnees.(!cp) || cmp_prio fp.donnees.(!lc+1) fp.donnees.(!cp))) do
        if (cmp_prio fp.donnees.(!lc) fp.donnees.(!lc+1)) then
          (swap fp.donnees !cp !lc;
           cp := !lc)
        else  
          (swap fp.donnees !cp (!lc+1);
           cp := !lc+1);
        lc := fils !cp ;
      done;
      (*Il reste au plus un fils, on compare et on échange le cas échéant*)
      if (!lc<fp.taille && cmp_prio fp.donnees.(!lc)  fp.donnees.(!cp)) then swap fp.donnees !cp !lc;
      res;
    )
;;

let lire_fichier fname =
  let reader = open_in fname in
  let str = In_channel.input_all reader in
  List.init (String.length str) (fun n -> str.[n]) ;;

let occurrences lchar =
  let occ = Array.make nbchar 0 in
  let rec aux lc =
    match lc with
    | [] -> ()
    | x::xs -> occ.(int_of_char x) <- occ.(int_of_char x) + 1; aux xs in
  aux lchar;
  occ
;;

let initialise_file occ =
  (*Initialise la file de priorité en y enfilant les caractères avec leur nombre d'occurences *)
  let fp = cree_file nbchar (Feuille ' ') in
  for i=0 to nbchar -1 do
    if occ.(i)!=0 then enfile (occ.(i),Feuille (char_of_int i)) fp;
  done;
  fp;;

let cree_abh fp =
  if fp.taille = 0 then failwith "File de priorité vide !" else
    while fp.taille <> 1 do
      let p1,a1 = defile fp in
      let p2,a2 = defile fp in
      enfile (p1+p2, Noeud (a1,a2)) fp;
    done; 
  snd (defile fp);;


let huffmann txt =
  let ltxt = List.init (String.length txt) (fun n-> txt.[n]) in
  let occ = occurrences ltxt in
  let fp = initialise_file occ in
  cree_abh fp;;


(* --8<-- [start:visualise] *)
let visualise arbre =
  let num = ref 0 in
  let outc = open_out "temp.gv" in
  output_string outc "digraph mygraph {\n";
  let rec aux ab =
    let id =  !num in
    num := !num+1;
    (match ab with
     | Feuille c -> if c='"' then Printf.fprintf outc  "n%d [shape=circle, style=filled, fillcolor=lightblue, label=\"\\\"\"]\n" id else Printf.fprintf outc  "n%d [shape=circle, style=filled, fillcolor=lightblue, label=\"%c\"]\n" id c;
     | Noeud (g,d) -> Printf.fprintf outc "n%d [shape=point, width=0.05, height=0.05]\n" id;
      let idg = aux g in
      let idd = aux d in 
      Printf.fprintf outc "n%d -> n%d\n" id idg;
      Printf.fprintf outc "n%d -> n%d\n" id idd;
       ;
    );
    id
  in
  ignore (aux arbre);
  output_string outc "}\n";
  close_out outc;
  ignore (Sys.command "xdot temp.gv");;
(* --8<-- [end:visualise] *)

let cree_code code_abr =
  let code = Array.make nbchar "" in
  let rec aux_cc code_abr ch =
    match code_abr with
  |Feuille c -> (code.(int_of_char c) <- ch;)
  |Noeud(g,d) -> (aux_cc g (ch^"0"); aux_cc d (ch^"1") ;)
  in
  aux_cc code_abr "";
  code;;
;;

let taux  txt code =
  let l = String.length txt in
  let original = l*8 in
  let compresse = ref 0 in
  for i=0 to l-1 do 
    compresse := !compresse + String.length code.(int_of_char txt.[i]);
  done;
  float_of_int !compresse /. float_of_int original;;

let lire_fichier fname =
let reader = open_in fname in
In_channel.input_all reader;;

