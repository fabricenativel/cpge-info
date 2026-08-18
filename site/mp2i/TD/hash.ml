let hash (k : string) : int =
  let n = String.length k in
  let rec compute_hash h i =
  if i = n then h
  else compute_hash (31*h + Char.code k.[i]) (i+1) in
  compute_hash 0 0