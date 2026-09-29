type complexe = float * float;;

let modu (z:complexe) = 
  let x = (fst z) in
    let y = (snd z) in 
      sqrt(x**2.+.y**2.);;

type menu = {entree : string; plat : string; dessert : string; prix : float};;

type rbarre = Plusinfini | Moinsinfini | Nombre of float;;

type carte = As | Roi | Dame | Valet | Nombre of int;;

let valeur c =
  match c with 
  | As -> 11
  | Roi -> 4
  | Dame -> 3
  | Valet -> 2
  | Nombre 10 -> 10
  | _ -> 0

  let est_paire c1 c2 = 
    match (c1, c2) with
    | (Roi, Roi) -> true
    | (Dame, Dame) -> true
    | (Valet, Valet) -> true
    | (Nombre x, Nombre y) -> x = y
    | (_,_) -> false
  
  type signe = Negatif | Nul | Positif

  let produit s1 s2 =
    match s1, s2 with 
    | Nul, _ -> Nul
    | _, Nul -> Nul
    | Positif, Positif -> Positif
    | Negatif, Negatif -> Positif
    | _,_ -> Negatif