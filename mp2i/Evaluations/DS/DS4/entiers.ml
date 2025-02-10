let rec succ_list entiers x =
  match entiers with
  | [] -> -1
  | h::t -> if h>x then h else succ_list t x
  
let succ_vect entiers x =
  if x >= entiers.(entiers.(0)) then -1 else (
  let imin = ref 1 in
  let imax = ref entiers.(0) in
  let found = ref false in
  let imid = ref 0 in
  while (!imax - !imin >=0 && not !found) do
    imid := (!imax + !imin)/2;
    if (entiers.(!imid)=x) then found:=true else
      if (entiers.(!imid)<x) then imin := !imid + 1  else imax := !imid-1
    done;
    if (!found) then entiers.(!imid+1) else entiers.(!imin))
  ;;

let size = 10;;

let union t1 t2 =
  (* size est la variable N de l'énoncé*)
  let t = Array.make size 0 in
  let size1 = t1.(0) in
  let size2 = t2.(0) in
  let i1 = ref 1 in
  let i2 = ref 1 in
  let i = ref 1 in
  while (!i1<=size1 || !i2<=size2) do
    Printf.printf "i1 = %d, i2 = %d, i = %d\n" !i1 !i2 !i;
    (* prendre dans t1 si t2 est vide OU si il reste des éléments dans les 2 et le plus petit est dans t1*)
    if (!i2>size2) || (!i1 <= size1 && !i2 <=size2 && t1.(!i1) <= t2.(!i2)) then
      (
        t.(!i) <- t1.(!i1);
        (* en cas d'égalité on avance aussi dans t2*)
        if (!i2<=size2 && t1.(!i1) = t2.(!i2)) then (i2 := !i2 +1);
        i1 := !i1 +1;
      ) else
    (* sinon prendre dans t2 *)
      (
        t.(!i) <- t2.(!i2);
        (* en cas d'égalité on avance aussi dans t1*)
        if (!i1<=size1 && t1.(!i1) = t2.(!i2)) then (i1 := !i1 +1);
        i2 := !i2 +1;
      );
      i := !i + 1;
      done;
      t.(0) <- !i-1;
      t;;



  