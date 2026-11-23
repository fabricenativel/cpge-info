let conso poids = poids/3;;

let rec conso_total poids = 
  if conso poids>0 then conso poids + conso_total (conso poids) else 0;;
