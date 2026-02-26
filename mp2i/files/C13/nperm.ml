let rec all_swap x l =
  match l with
  | [] -> []
  | h::t -> [(x::t)] @ List.map (fun x->h::x) (all_swap x t);;

let rec permutation l =
  match l with
  | [] -> [[]]
  | h::t -> let p1 = permutation t in 
              let m1 = List.map (fun x->h::x) p1 in
              let p2 = all_swap h t in
              let m2 = List.map (fun x->permutation x) p2 in
              m1 @ List.map (fun x->h::x) (List.flatten m2);;
