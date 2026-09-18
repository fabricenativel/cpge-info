type 'a file_priorite = {
  mutable taille : int;
  donnees : (int*'a) array};;

type abh = 
  | Feuille of char 
  | Noeud of abh*abh;;

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