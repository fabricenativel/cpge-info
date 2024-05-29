type ab = Feuille of int | Noeud of ab*ab;;

type heap_int = {mutable size : int; data : int array};;

type pqueue = 
{
  mutable size : int;
  data : (int*ab) array;
};;

let leftchild i n = let s = 2*i+1 in if s<n then s else -1;;

let parent i = let p = (i-1)/2 in if i<>0 then p else -1;;

let swap tab i j =
  let temp = tab.(i) in
  tab.(i) <- tab.(j);
  tab.(j) <- temp;;

  let insert v heap =
    let cp = ref heap.size in
    heap.data.(!cp) <- v;
    while (parent !cp) <> (-1)  && (fst heap.data.(parent !cp) > fst heap.data.(!cp)) do
        swap heap.data !cp (parent !cp);
        cp := parent !cp;
    done;
    heap.size <- heap.size + 1;;

let nbchar = 128;;

let frequence texte =
  let fq = Array.make nbchar 0 in
  for i=0 to String.length texte - 1 do
    fq.(int_of_char texte.[i]) <- fq.(int_of_char texte.[i]) + 1;
  done;
  fq;;

  let extract_min theap =
    let minv = theap.data.(0) in
    theap.data.(0) <- theap.data.(theap.size-1);
    let cp = ref 0 in
    let lc = ref (leftchild !cp theap.size) in
    while ( !lc <> (-1) && (fst theap.data.(!lc) < fst theap.data.(!cp) || (!lc+1 < theap.size && fst theap.data.(!lc+1) < fst theap.data.(!cp)))) do
      if (!lc+1 >= theap.size || fst theap.data.(!lc)< fst theap.data.(!lc+1)) then
       (swap theap.data !cp !lc;
        cp := !lc)
      else  
        (swap theap.data !cp (!lc+1);
        cp := !lc+1);
      lc := leftchild !cp theap.size;
    done;
    theap.size <- theap.size -1;
    minv;;

let construire_arbre fq =
  let todo = {size = 0; data = Array.make nbchar (0,Feuille(0))} in
  for i=0 to nbchar-1 do
    if fq.(i)<>0 then insert (fq.(i),Feuille(i)) todo;
  done;
  let  br1 = ref (0,Feuille(0)) in
  let  br2 = ref (0,Feuille(0)) in
  let code_abr = ref  (0,Feuille(0)) in
  while (todo.size <> 1) do
    br1 := extract_min todo;
    br2 := extract_min todo;
    code_abr := (fst !br1 + fst !br2, Noeud(snd !br1, snd !br2));
  insert !code_abr todo;
  done;
  !code_abr;;

let cree_code code_abr =
  let code = Array.make nbchar "" in
  let rec aux_cc code_abr ch =
    match code_abr with
  |   _,Feuille(n) -> (code.(n) <- ch;)
  |   _,Noeud(g,d) -> (aux_cc (0,g) (ch^"0"); aux_cc (0,d) (ch^"1") ;)
  in
  aux_cc code_abr "";
  code;;
;;

let lire fname =
  let reader = open_in fname in
  let contenu = ref "" in
  try
    while true do
      contenu := !contenu^ (input_line reader);
    done;
  !contenu
  with End_of_file -> !contenu;
;;

let () = let filename = Sys.argv.(1) in
            let contenu = lire filename in
            Printf.printf "Le fichier comporte %d caractères \n" (String.length contenu);
            let fq = frequence contenu in
            Printf.printf "Calcul des fréquences ok !\n";
            let ab_code = construire_arbre fq in
            Printf.printf "Construction arbre ok ! \n";
            let code = cree_code (ab_code) in
            for i=0 to nbchar-1 do
              if code.(i)<>"" then Printf.printf "%d ->  %c : %s\n" i (char_of_int i) code.(i);
            done;
            Printf.printf "Taille initiale (8 bits/char ) = %d \n" (String.length contenu*8);
            let tc = ref 0 in
            for i=0 to String.length contenu -1 do
              tc := !tc + String.length (code.(int_of_char contenu.[i]));
            done;
            Printf.printf "Taille compressée  = %d \n" !tc;
            Printf.printf "Taux de compression = %f \n" ((float_of_int !tc)/. float_of_int ((String.length contenu*8)));
          ;;


    

  

  


