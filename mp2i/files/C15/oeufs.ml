let rec get_min lst =
  match lst with
  | [] -> failwith "Minimum d'une liste vide"
  | h::[] -> h
  | h::t -> let mr = get_min t in if h<mr then h else mr

let lancer nb_etages nb_oeufs=
  let memo = Hashtbl.create 10000 in
  let rec aux nb_etages nb_oeufs =
  if Hashtbl.mem memo (nb_etages,nb_oeufs) then Hashtbl.find memo (nb_etages,nb_oeufs) else
  if nb_etages<2 || nb_oeufs=1 then (Hashtbl.add memo (nb_etages,nb_oeufs) nb_etages; nb_etages) else
    let poss = List.init nb_etages (fun k -> 1 + max (aux k (nb_oeufs-1)) (aux (nb_etages-k-1) nb_oeufs)) in
    let rep = get_min poss in
    (Hashtbl.add memo (nb_etages,nb_oeufs) rep; rep) in
  aux nb_etages nb_oeufs;;
