let rec exp_rapide a n =
  if n=0 then 1.0 else 
    let temp = exp_rapide a (n/2) in
    if (n mod 2=0) then temp*.temp else a*.temp*.temp;;