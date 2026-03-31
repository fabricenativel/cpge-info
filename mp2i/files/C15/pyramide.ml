let smax pyramide =
  let n = Array.length pyramide in
  let solutions = 
  let rec aux  i j =
    if i=n-1 then pyramide.(i).(j) else
      let gauche = aux (i+1) j in
      let droite = aux (i+1) (j+1) in
      pyramide.(i).(j) + max gauche droite in
  aux 0 0;;


