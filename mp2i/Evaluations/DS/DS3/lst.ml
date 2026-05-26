let rec est_trie lst =
  (* Renvoie true si lst est triée dans l'ordre croissant et false sinon*)
  match lst with
  | [] -> true
  | h::[] -> true
  | h::i::t -> if h<=i then est_trie t else false;;

  let rec est_trie lst =
    (* Renvoie true si lst est triée dans l'ordre croissant et false sinon*)
    match lst with
    | [] -> true
    | h::[] -> true
    | h::i::t -> if h<=i then est_trie (i::t) else false;;

  let rec fusion l1 l2 =
    match l1, l2 with
    | [], _ -> l2
    | _, [] -> l1
    | h1::t1, h2::t2 -> if h1<h2 then h1::(fusion t1 (h2::t2)) else  h2::(fusion (h1::t1) t2);;