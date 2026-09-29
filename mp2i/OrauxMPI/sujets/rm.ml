let rec verifie systeme =
  match systeme with
  | [] -> false
  | p::[] -> p=1
  | p1::p2::rs -> p1>p2 && verifie (p2::rs);;

let rec monnaie systeme somme =
  match systeme, somme with
  | _, 0 -> 0
  | [], _ -> failwith "Impossible"
  | p::rs, s -> if p<=s then 1 + monnaie systeme (s-p) else monnaie rs s;;

let rec dynamique systeme somme =
  match systeme, somme with
  | _, 0 -> 0
  | [], _ -> Int.max_int
  | pk::rs, s -> if pk>s then dynamique rs somme else
              let sans = dynamique rs s in
              let avec = 1 + dynamique systeme (s-pk) in
              min avec sans;;
