let lplssc u v =
  let rec aux u v n m =
    if n=0 || m=0 then 0 else
      if u.[n-1] = v.[m-1] then 
        1 + aux u v (n-1) (m-1) else
          max (aux u v (n-1) m) (aux u v n (m-1)) in
  aux u v (String.length u) (String.length v);;
    

let lplssc_memo u v memo =
  let rec aux u v n m memo= 
    if memo.(n).(m) <> -1 then memo.(n).(m) else
      (if n=0 || m=0 then 
          (memo.(n).(m) <- 0; 0)
        else
          (if u.[n-1] = v.[m-1] then 
            (let r1 = 1 + aux u v (n-1) (m-1) memo in
            memo.(n).(m)<-r1; r1) else
            (let r2 = max (aux u v (n-1) m memo) (aux u v n (m-1) memo) in
            memo.(n).(m)<-r2; r2))
      ) in
    aux u v (String.length u) (String.length v) memo;;

let affiche memo =
  let n = Array.length memo in
  let m = Array.length memo.(0) in
  for i=0 to n-1 do
    for j=0 to m-1 do
      if (memo.(i).(j) <> -1) then
      (Printf.printf "%d &" memo.(i).(j);)
    else
      (Printf.printf "x ";)
    done;
    Printf.printf "\\\\ \n";
  done;;

let lplssc_iter u v memo =
  let n = String.length u  in
  let m = String.length v  in
  for i = 0 to n do
    memo.(i).(0) <- 0;
  done;
  for i = 0 to m do
    memo.(0).(i) <- 0;
  done;
  for i=1 to n do
    for j=1 to m do
      if u.[i-1]=v.[j-1] then
        memo.(i).(j) <- 1 + memo.(i-1).(j-1)
      else
        memo.(i).(j) <- max memo.(i-1).(j) memo.(i).(j-1)
      done;
    done;
  memo.(n).(m);;




let reconstruit u v memo =
  let n = ref (String.length u) in
  let m = ref (String.length v) in
  let res =  ref "" in
  while (!n <> 0) && (!m <> 0) do
    if (u.[!n-1]=v.[!m-1] && memo.(!n).(!m) = 1 + memo.(!n-1).(!m-1)) then
      (res :=  (String.make 1 u.[!n-1]) ^ !res ;
      n := !n -1;
      m := !m -1;)
    else
      ( if (memo.(!n-1).(!m) > memo.(!n).(!m-1)) then
       (n := !n -1;)
      else
        (m := !m -1;))
  done;
  !res;;




let () = 
  let u = "REGULARITE" in
  let v = "PERSEVERANCE" in
  let n = String.length u in
  let m = String.length v in
  let memo = Array.make_matrix (n+1) (m+1) (-1) in
  let memo2 = Array.make_matrix (n+1) (m+1) (-1) in
  Printf.printf "LPLSSC de %s et %s = %d \n" u v (lplssc u v);
  Printf.printf "LPLSSC (memo) de %s et %s = %d \n" u v (lplssc_memo u v memo);
  Printf.printf "LPLSSC (iter) de %s et %s = %d \n" u v (lplssc_iter u v memo2);
  affiche memo2;
  let ch = reconstruit u v memo in
  Printf.printf "PLSSC de %s et %s = %s \n" u v ch;;
     