let size = 10;;
let nb_sol = ref 0;;

let rec make_list n =
  if n = 1 then [0] else (n-1)::make_list (n-1);;

let rec insere_all elt liste =
  match liste with
  | [] -> [[elt]]
  | h::t -> (elt::h::t)::(List.map (fun x-> h::x) (insere_all elt t))
  
let rec permutation l =
  match l with
  | [] -> [[]]
  | h::t -> let temp = permutation t in List.flatten (List.map (fun l -> (insere_all h l)) temp);;

let valide_solution l =
  try 
  for i=0 to size-1 do
    for j=i+1 to size-1 do
      if j-i = abs(l.(j)-l.(i)) then raise Exit
      done;
    done;
  true;
  with Exit -> false;;

let rec affiche l =
  match l with
  | [] -> ()
  | h::t -> Printf.printf "%d; " h; affiche t;;

let rec check can = 
  match can with
  | [] -> ()
  | h::t -> if valide_solution (Array.of_list h)  then 
    nb_sol := !nb_sol + 1;
   check t;;


let () = let t = make_list size in
  let candidats = permutation t in print_string "ok";;
  (* check candidats;
  Printf.printf "Problèmes des %d reines : %d solutions \n" size !nb_sol;; *)
