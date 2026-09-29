let rec est_prefixe pref texte =
  match pref, texte with
  | [], _ -> true
  | _, [] -> false
  | hp::tp, ht::tt -> hp=ht && est_prefixe tp tt;;

let  str_to_list s =
  List.init (String.length s) (fun i -> s.[i]);;


let naive motif texte =
  let lmotif = str_to_list motif in
  let ltexte = str_to_list texte in
  let rec aux ctexte cidex =
  match ctexte with
  | [] -> []
  | h::t -> if est_prefixe lmotif ctexte then
      cidex::(aux t (cidex+1))
    else
      aux t (cidex+1) in
  aux ltexte 0;;

let naive2 motif texte =
  let lm = String.length motif in
  let lt = String.length texte in
  let res = ref (-1) in
  try
  for it =0 to lt-lm do
    let im = ref 0 in
    while !im<lm && motif.[!im] = texte.[it+ !im] do
      im := !im + 1
    done;
    if !im = lm then
      (res := it;
      raise Exit;)
    done;
    -1;
    with Exit -> !res;;
  
  
