let rec infixe a =
  match a with
  | Vide -> ()
  | Noeud (g,e,d) ->  infixe g; Printf.printf "%c " e; infixe d;;
