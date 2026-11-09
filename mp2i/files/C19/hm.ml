type 'a file_priorite = {
  mutable taille : int;
  donnees : (int*'a) array};;

type ab = Feuille of int | Noeud of ab*ab;;


  let fils i = 2 * i + 1;;

  let parent i = (i-1)/2 ;;
  
let cree_file t default= {taille =  0; donnees = Array.make t (0,default)};;

let prio elt = fst elt;;

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
    while (!cp <>0 && prio fp.donnees.(!cp) < prio fp.donnees.(parent !cp)) do
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
    while (!lc < fp.taille && (prio fp.donnees.(!lc) < prio fp.donnees.(!cp) || (!lc+1 < fp.taille && prio fp.donnees.(!lc+1) < prio fp.donnees.(!cp)))) do
      if (!lc+1 >= fp.taille || prio fp.donnees.(!lc)< prio fp.donnees.(!lc+1)) then
       (swap fp.donnees !cp !lc;
        cp := !lc)
      else  
        (swap fp.donnees !cp (!lc+1);
        cp := !lc+1);
      lc := fils !cp ;
    done;
    res;
    )
  ;;

  let nbchar = 128;;

  let lire fname =
    let reader = open_in fname in
    In_channel.input_all reader;;
  ;;

  let frequence texte =
    let fq = Array.make nbchar 0 in
    for i=0 to String.length texte - 1 do
      fq.(int_of_char texte.[i]) <- fq.(int_of_char texte.[i]) + 1;
    done;
    fq.(13)<-0;
    fq;;


    let construire_arbre fq =
      let a_traiter = cree_file nbchar (Feuille(0)) in
      for i=0 to nbchar-1 do
        if fq.(i)<>0 then enfile (fq.(i),Feuille(i)) a_traiter;
      done;
      let  br1 = ref (0,Feuille(0)) in
      let  br2 = ref (0,Feuille(0)) in
      let code_abr = ref  (0,Feuille(0)) in
      while (a_traiter.taille <> 1) do
        br1 := defile a_traiter;
        br2 := defile a_traiter;
        code_abr := (fst !br1 + fst !br2, Noeud(snd !br1, snd !br2));
      enfile !code_abr a_traiter;
      done;
      snd !code_abr;;
    
    let cree_code code_abr =
      let code = Array.make nbchar "" in
      let rec aux_cc code_abr ch =
        match code_abr with
      |Feuille(n) -> (code.(n) <- ch;)
      |Noeud(g,d) -> (aux_cc  g (ch^"0"); aux_cc d (ch^"1") ;)
      in
      aux_cc code_abr "";
      code;;
    ;;

  
    let () = let filename = Sys.argv.(1) in
    let contenu = lire filename in
    Printf.printf "Le fichier comporte %d caractères \n" (String.length contenu);
    let fq = frequence contenu in
    Printf.printf "Calcul des fréquences ok !\n";
    for i=0 to nbchar-1 do
      if fq.(i)<>0 then Printf.printf "%d ->  %c : %d\n" i (char_of_int i) fq.(i);
    done;
    let ab_code = construire_arbre fq in
    Printf.printf "Construction arbre ok ! \n";
    let code = cree_code (ab_code) in
    let ti = ref 0 in
    for i=0 to nbchar-1 do
      if code.(i)<>"" then Printf.printf "%d ->  %c : %s\n" i (char_of_int i) code.(i);
      ti := !ti + fq.(i)
    done;
    ti := !ti*8;
    Printf.printf "Taille initiale (8 bits/char ) = %d \n" !ti;
    let tc = ref 0 in
    for i=0 to String.length contenu -1 do
      tc := !tc + String.length (code.(int_of_char contenu.[i]));
    done;
    Printf.printf "Taille compressée  = %d \n" !tc;
    Printf.printf "Taux de compression = %f \n" ((float_of_int !tc)/. float_of_int (!ti));
  ;;
