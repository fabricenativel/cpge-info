type 'a file_priorite = {
  mutable taille : int;
  donnees : (int*'a) array};;

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
