open Hashtbl
let size = 32000;;
let ht = Hashtbl.create size

let rec binome n k = if k=0 || k=n then 1 else (binome (n-1) k) + (binome (n-1) (k-1))

let binome_fact n k =
  let fn = ref 1 in
  let fk = ref 1 in
  let fnk = ref 1 in
  for i = 2 to n do
  fn := !fn*i;
  if i<=k then fk:=!fk*i;
  if i<=n-k then fnk:=!fnk*i;
  done;
  !fn/(!fk * !fnk);;


let rec binome_memory n k =
  if Hashtbl.mem ht (n,k) then Hashtbl.find ht (n,k) else 
    if k=0 || k=n then 1 else
      (
    let res = (binome_memory (n-1) k) + (binome_memory (n-1) (k-1)) in
    Hashtbl.add ht (n,k) res;
    res);;


    let ()  = 
      Printf.printf "n = ";
      let n = read_int() in
      Printf.printf "k = ";
      let k = read_int() in
      (* Printf.printf "Sans mémoïsation = %d\n" (binome n k);*)
      Printf.printf "Avec mémoïsation = %d\n" (binome_memory n k);
      Printf.printf "Avec factoriel = %d\n" (binome_fact n k);;

