
(* fonction de recherche naive *)
let naive motif texte =
  let lm = String.length motif  in
  let lt = String.length texte  in
  let occ = ref [] in
  for it=0 to lt-lm do
    let im = ref 0 in
    while (!im<lm && motif.[!im]=texte.[it+ !im]) do
      im := !im +1;
    done;
    if (!im=lm) then occ := it::!occ
    done;
  !occ;;

let present motif texte = 
  let lm = String.length motif  in
  let lt = String.length texte  in
  try 
  for it=0 to lt-lm do
    let im = ref 0 in
    while (!im<lm && motif.[!im]=texte.[it+ !im]) do
      im := !im +1;
    done;
    if (!im=lm) then raise Exit (* Exit est prédéfinie *)
  done;
  false
  with Exit -> true;;


  (* Construit la table qui pour un emplacement n edans le motif et un caractere c donne l'emplacement du caractere c précédent dans le motif*)
let decalage motif =
  let lm = String.length motif - 1 in
  let table = Hashtbl.create (lm*lm) in
  for i=
