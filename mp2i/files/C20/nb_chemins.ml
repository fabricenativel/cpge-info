type digraphe = {ordre : int; madj : int array array};;

let cree_graphe n = {ordre=n; madj = Array.make_matrix n n 0};;

let lire_graphe fname ordre =
  let reader = open_in fname in
  let gr =  cree_graphe ordre in
  try
    while true do
      let line = input_line reader in
      let sep = String.index line ' ' in
      let depart = int_of_string (String.sub line 0 (sep)) in
      let arrivee = int_of_string (String.sub line (sep+1) ((String.length line)-sep-1)) in
      gr.madj.(depart).(arrivee) <- 1;
    done;
    gr
  with End_of_file -> gr;;

let mult a b =
  let n = Array.length a in
  let c = Array.make_matrix n n 0 in
  for i=0 to (n-1) do
    for j=0 to (n-1) do
      for k=0 to (n-1) do
        c.(i).(j) <- c.(i).(j) + a.(i).(k)*b.(k).(j);
      done;
    done;
  done;
  c;;

let rec exp_rapide a n =
  if n=1 then a else let a2 = exp_rapide a (n/2) in
  if (n mod 2 = 0) then mult a2 a2 else mult a (mult a2 a2);;

let () = let gr = lire_graphe "ex_tp.txt" 8 in
         let nb_chemins = exp_rapide (gr.madj) 42 in
          Printf.printf "Nombre de chemins de longueur 42 entre 6 et 7 :  %d\n " nb_chemins.(6).(7);
;;