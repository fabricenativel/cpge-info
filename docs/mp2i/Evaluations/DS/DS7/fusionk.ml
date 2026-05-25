let rec fusion lst1 lst2 =
  match lst1, lst2 with
  | [], lst2 -> lst2
  | lst1, [] -> lst1
  | h1::t1, h2::t2 -> if h1<h2  then h1::(fusion t1 lst2) 
                                else h2::(fusion lst1 t2);;

let kfusion tab_lst =
  let res = ref [] in
  let k = Array.length tab_lst in
  for i=0 to (k-1) do
    res := fusion !res tab_lst.(i)
  done;
  !res;;

