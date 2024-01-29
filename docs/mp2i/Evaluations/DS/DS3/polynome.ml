(* Calcule a puissance n pour a et n entiers naturels*)
let rec puissance a n =
  if n=0 then 1 else a * (puissance a (n-1));;


(* Calcule la valeur en x du  du polynome de coefficient lcoeff*)
  let rec naif lcoeff x =
    match lcoeff with
    | [] -> 0
    | ak::t-> ak*puissance x (List.length t) + (naif t x );;

(* Evalue un polynome avec la méthode de Horner *)
let rec horner lcoeff x =
    match lcoeff with
    | [] -> 0
    | ak::t -> ak + x*(horner t x);;