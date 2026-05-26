let rec taille ab =
  match ab with
  | Vide -> 0
  | Noeud (sag, _, sad) -> 1 + taille sag + taille sad;;
