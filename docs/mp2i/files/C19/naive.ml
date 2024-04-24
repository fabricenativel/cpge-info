(* fonction de recherche naive *)
let naive motif texte =
  let lm = String.length motif - 1 in
  let lt = String.length texte -1 in
  let occ = ref [] in
  for it=0 to lt-lm do
    let im = ref 0 in
    while (!im<=lm && motif.[!im]=texte.[it+ !im]) do
      im := !im +1;
    done;
    if (!im>lm) then occ := it::!occ
    done;
  !occ;;

let decalage motif
