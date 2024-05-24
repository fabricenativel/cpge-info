let rec entiers n =
  if n = 0 then [] else n::(entiers (n-1));;

  let combinaison k n =
    let memo = Hashtbl.create 10000 in
    let rec aux_combinaison k n memo =
    if Hashtbl.mem memo (k,n) then Hashtbl.find memo (k,n) else
    (
    if k=0 then [[]] else
     if k=n then [entiers n] else
      let p1 = aux_combinaison (k-1) (n-1) memo in
      let p2 = aux_combinaison k (n-1) memo in
      let res = List.map (fun x->n::x) (p1) @ p2 in
      Hashtbl.add memo (k,n) res;
      res) in
    aux_combinaison k n memo
    ;;

let cree_chemin combinaison =
  let carr = Array.of_list combinaison in
  let n = Array.length carr in
  let res = Array.make (2*n) false in
  for i=0 to n-1 do
    res.(carr.(i)-1)<-true;
  done;
  res;;

let read_data filename size =
  let reader = open_in filename in
  let data = Array.make_matrix size size  0 in
  for i=0 to size-1 do
    for j=0 to size-1 do
      data.(i).(j) <- Char.code (input_char reader) - 48
  done;
ignore (input_char reader);
done; 
  data;;

let val_chemin ch data =
  let vc = ref 0 in
  let l = ref 0 in
  let c = ref 0 in
  for i=0 to (Array.length ch - 1) do
    if ch.(i) then l := !l +1 else c := !c +1;
    vc := !vc + data.(!l).(!c)
  done;
  !vc;;

let solve_dp data =
  let n = Array.length data  in
  let minch = Array.make_matrix n n 0 in
  minch.(0).(0) <- 0;
  for i = 0 to n-1 do
    for j=0 to n-1 do
      if (i=0) && (j>0) then minch.(0).(j) <- data.(0).(j) + minch.(0).(j-1) else
        (
      if (j=0) && (i>0) then minch.(i).(0) <- data.(i).(0) + minch.(i-1).(0) else
        (
          if (i<>0 && j<>0) then minch.(i).(j) <- data.(i).(j) + min minch.(i-1).(j) minch.(i).(j-1);
        )
        )
      done;
    done;
    minch.(n-1).(n-1);;

let solve data =
  let n = Array.length data -  1 in
  let comb = Array.of_list (combinaison n (2*n)) in
  Printf.printf "Nombre de chemins à tester = %d\n" (Array.length comb);
  let minr = ref 0 in
  for i=0 to (Array.length comb - 1) do
    if val_chemin (cree_chemin (comb.(i))) data > !minr then minr:= val_chemin (cree_chemin (comb.(i))) data
  done;
  !minr;;


let () =  
          let data = read_data "ex1.txt" 4 in
          let sol = solve_dp data in
          let sol2 = solve data in
          Printf.printf "Valeur minimale (dp) = %d \n" sol;
          Printf.printf "Valeur minimale (fb) = %d \n" sol2;;
;;
