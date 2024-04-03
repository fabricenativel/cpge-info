let rec hof n = 
  match n with
| 0 -> 0
| n -> n - hof(hof(n-1));;

