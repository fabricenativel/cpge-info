

let no_threat tab n =
  let rec aux tab i n =
    if i=n then true else
      tab.(i) != tab.(n) && abs(tab.(i)-tab.(n)) != n-i && aux tab (i+1) n in
    aux tab 0 n;;


let affiche tab =
  print_string "[| ";
  Array.iter (fun x -> Printf.printf "%d " x) tab;
  print_string "|]\n";;

let solve tab =
  let n = Array.length tab in
  let rec aux_solve  i j sc =
    if i=n then (aux_solve (i-1) (tab.(i-1)+1) (sc+1)) else
      (if j=n  then 
        if i==0 then (Printf.printf "%d solutions trouvées \n" sc) else
        aux_solve (i-1) (tab.(i-1)+1) sc else 
    ( tab.(i) <- j;
      if no_threat tab i then
      aux_solve  (i+1) 0 sc
      else
        aux_solve i (tab.(i)+1) sc
    )) in
  aux_solve 0 0 0;;



let () = let size = int_of_string (Sys.argv.(1)) in
        let pos = Array.make size 0 in
        solve pos;;

  
