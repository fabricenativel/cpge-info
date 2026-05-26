(* Calcule la somme des n premiers entiers*)
let somme n =
  let s = ref 0 in
  let i = ref 1 in
  while !i <= n do 
    s := !s + !i;
    i := !i + 1;
  done;
  !s;;
