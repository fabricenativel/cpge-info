let rec insere abr nv =
  match abr with
  | Vide -> Noeud(Vide,nv,Vide)
  | Noeud(g,v,d) -> if nv<v then Noeud(insere g nv, v, d) else Noeud(g, v, insere d nv);; 
