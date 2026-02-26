let rec puissance x n =
  if n=0 then 1 else x * puissance x (n-1)

let rec puissance_acc x n acc =
  if n=0 then acc else puissance_acc x (n-1) (x*acc) 

let rec puissance_rapide x n =
  if n=0 then 1 else
    if n mod 2 = 0 then 
      (puissance_rapide x (n/2) * puissance_rapide x (n/2)) 
else x * (puissance_rapide x (n/2) * puissance_rapide x (n/2))