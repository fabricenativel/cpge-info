type peano =
  |Z
  |S of peano;;

let rec  int_to_peano n =
  if n = 0 then Z
  else S (int_to_peano (n-1));;

let rec peano_to_int p =
  match p with
  |Z -> 0
  |S q -> 1 + peano_to_int q;;

let rec add peano1 peano2 =
  match peano1 with
  |Z -> peano2
  |S p -> S (add p peano2);;
