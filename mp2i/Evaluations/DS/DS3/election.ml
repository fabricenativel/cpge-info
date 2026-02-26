let rec appartient c votes =
  match votes with
  | [] -> false
  | h::t -> h=c || appartient c t;;


let rec candidats votes =
  match votes with
  | [] -> []
  | h::t -> let cr = candidats t in if appartient h cr then cr else h::cr;;


let rec nb_votes c votes =
  match votes with
  | [] -> 0
  | h::t -> if h=c then 1 + nb_votes c t else nb_votes c t;;

let comptabilise votes =
  let cd = candidats votes in
  List.map (fun c -> (c,nb_votes c votes)) cd;;

let rec ajoute un_vote resultat =
  match resultat with
  | [] -> [(un_vote, 1)]
  | (v,r)::t -> if v=un_vote then (v, r+1)::t else (v,r)::(ajoute un_vote t)

let rec comptabilise2 votes acc =
  match votes with
  | [] -> acc
  | h::t -> comptabilise2 t (ajoute h acc);; 