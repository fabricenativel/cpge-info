let rec fact n =
  if n=0 then 1 else n*fact (n-1)

let rec fact_acc  n acc =
  if n=0 then acc else fact_acc (n-1) (n*acc)

  