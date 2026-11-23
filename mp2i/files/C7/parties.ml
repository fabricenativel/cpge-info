let rec parties l =
  (* renvoie les parties de l*)
  match l with
  | [] -> [[]]
  | h::t  -> let p = parties t in p @ List.map (fun x -> h::x) p;;

let rec combinaisons l n =
  (* renvoie les combinaisons de l à n éléments *)
  if n=0 then [[]] else
    match l with
    | [] -> []
    | h::t -> let p1 = combinaisons t (n-1) in
              let p2 = combinaisons t n in
              p2 @ List.map (fun x->h::x) p1;;
              


