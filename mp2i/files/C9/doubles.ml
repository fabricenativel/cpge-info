(* Renvoie le tableau des doubles des n premiers entiers *)
let doubles n =
  let tab = Array.make n 0 in
  for i = 0 to n-1 do
    tab.(i) <- 2*i;
  done;
  tab;;
