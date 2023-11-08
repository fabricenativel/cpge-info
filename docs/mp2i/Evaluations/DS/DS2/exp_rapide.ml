let rec exp_rapide a n =
  if n=0 then 1 else 
    let pr =  exp_rapide a (n/2) in
    if n mod 2 = 0 then pr*pr else pr*pr*a
    
  