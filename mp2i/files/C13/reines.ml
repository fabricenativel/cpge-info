let size = 14;;

let nb_sol = ref 0;;

let menace tab n =
  let i = ref 0 in
  let m = ref false in
  while not !m && !i<n do
    if (tab.(n) = tab.(!i) || abs(tab.(n)-tab.(!i))=n - !i) then m:=true;
    i := !i + 1;
  done;
  !m;;

let affiche tab =
  print_string "[| ";
  for i=0 to (Array.length tab - 1)  do
    Printf.printf "%d; " tab.(i);
  done;
  print_string "|]\n";;


let rec solution tab n =
  if (n=size) then
    (
      nb_sol := !nb_sol +1;
    )
  else
    (
    for i=0 to size-1 do
      tab.(n) <- i; 
      if not (menace tab n) then solution tab (n+1)
    done;
    );;

let () = let t = Array.make size 0 in 
  solution t 0;
  Printf.printf "Nombre de solutions = %d\n" !nb_sol;;

  
