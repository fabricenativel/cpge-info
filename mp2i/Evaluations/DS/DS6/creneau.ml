let rec ecart_total attrib =
  match attrib with
  |[] -> 0
  |(r,c)::t -> abs(r-c) + ecart_total t

let rec plus_proche cible disponibles =
  match disponibles with
  | [] -> failwith "Erreur"
  | h::[] -> h, []
  | h::t -> let v, reste = plus_proche cible t in
            if abs(h-cible) < abs(v-cible) then h, t else v, h::reste 

let rec naif demandes disponibles =
  match demandes with
  | [] -> []
  | h::t -> let c, r = plus_proche h disponibles in
            (h,c):: naif t r;;

let decroissant lst =
  List.sort (fun x y -> y - x) lst;;

let rec somme_ecart lst1 lst2 =
  match lst1, lst2 with
  | [], [] -> 0
  | [], _ -> failwith "Tailles différentes"
  | _, [] -> failwith "Tailles différentes"
  | h1::t1, h2::t2 -> abs(h1-h2) + somme_ecart t1 t2;;

let rec dynamique requetes creneaux =
  if List.length requetes = List.length creneaux then somme_ecart requetes creneaux else
  match requetes, creneaux with
  | [], _ -> 0
  | _, [] -> failwith "Bug !"
  | r::rs, d::ds -> let attribue = abs(r-d) + dynamique rs ds in
                    let passe = dynamique requetes ds in
                    min attribue passe;;
