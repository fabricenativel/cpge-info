let cree_liste () = []

let ajoute(elt,liste) = elt::liste

let retire_elt(liste) = List.hd liste, List.tl liste

let affiche liste =
  List.iter (Printf.printf "%d -> ") liste;;


let l = cree_liste() in
let l = ajoute(3,l) in 
let l = ajoute(7,l) in
affiche(l);;