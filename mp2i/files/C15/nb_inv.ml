let nb_inv l =
  let t = Array.of_list l in
  let n = Array.length t in
  let r = ref 0 in
  for i=0 to n-1 do
    for j=i+1 to n-1 do
      if t.(i) > t.(j) then r:=!r+1;
    done;
  done;
  !r;;

let rec nb_inv2 l =
  match l with
  | [] -> 0
  | h::t -> List.length (List.filter (fun x -> x<h) t) + nb_inv t;;

let rec separe l = 
  let rec nprem l n =
  match l, n with
  | l, 0 -> [], l
  |[], _ -> failwith "Bug"
  | h::t, n -> let l1,l2 = nprem t (n-1) in  h::l1, l2
  in
  nprem l (List.length l / 2);;


let rec inv_trie l1 l2 =
  match l1, l2 with
  | [], l2 -> 0
  | l1, [] -> 0
  | h1::t1, h2::t2 -> if h1>h2 then (List.length l1) + inv_trie l1 t2 else inv_trie t1 l2;;


let rec inv_dpr l =
  if (List.length l <2) then 0 else
  (let l1, l2 = separe l in
  let i1 = inv_dpr l1 in
  let i2 = inv_dpr l2 in
  let lt1 = List.sort compare l1 in
  let lt2 = List.sort compare l2 in
  i1 + i2 + (inv_trie lt1 lt2));;

let rec random_list n =
  if n= 0 then [] else
    (Random.int 100)::(random_list (n-1));;

let () = 
  let t = random_list 10000 in
  let r1 = nb_inv t in
  Printf.printf "Nombre d'inversion (naif) = %d\n" r1;
  let r2 = inv_dpr t in
  Printf.printf "Nombre d'inversion (dpr) = %d\n" r2;;
