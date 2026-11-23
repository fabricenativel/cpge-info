let rec max_rec lst =
  match lst with
  | [] -> failwith "La liste doit être non vide"
  | x::[] -> x
  | premier::reste -> let max_reste = max_rec reste in if premier>max_reste then premier else max_reste;;


let rec separe lst =
  match lst with
  | [] -> [], []
  | h::[] -> [h], []
  | h1::h2::t -> let s1, s2 = separe t in h1::s1, h2::s2;;

let rec max_dpr lst =
  match lst with
  | [] -> failwith "La liste doit être non vide"
  | x::[] -> x
  | _ ->  let lst1, lst2 = separe lst in
          let max1 = max_dpr lst1 in
          let max2 = max_dpr lst2 in
          if max1>max2 then max1 else max2;;