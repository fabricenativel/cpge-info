
type abr = Vide | Noeud of abr*char*abr;;

let rec insere a l =
  match a with
  | Vide -> Noeud(Vide,l,Vide)
  | Noeud(g,x,d) -> if l<=x then Noeud(insere g l, x, d) else Noeud(g, x, insere d l);;

let cree mot =
  let a = ref Vide in
  for i=0 to String.length mot - 1 do
  a := insere !a mot.[i];
  done;
  !a;;

let rec compte arbre lettre =
  match arbre with
  | Vide -> 0
  | Noeud(g,x,d) -> if lettre<x then compte g lettre else
                      if lettre=x then 1+ compte g lettre  else
                          compte d lettre;;

