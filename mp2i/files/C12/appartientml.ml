let rec in_abr abr u =
  match abr with
  | Vide -> false
  | Noeud(g,v,d) -> if u=v then true else
    if u<v then in_abr g u else in_abr d u;;
