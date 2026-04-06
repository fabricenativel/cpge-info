
let valeur t i j = t.(j) -. t.(i);;

let saut_max_naif t =
  let n =  Array.length t in
  let vmax = ref 0. in
  for i=0 to n-1 do
    for j=i to n-1 do
      if (valeur t i j) > !vmax then vmax := (valeur t i j);
    done;
  done;
  !vmax;;

let rec saut_max_aux t a b =
  if b-a=1 then (a,a,a,a) else
  (let n = (a+b)/2 in
    let ig, jg, ming, maxg = saut_max_aux t a n in
    let id, jd, mind, maxd = saut_max_aux t n b in
    let sautg = valeur t ig jg in
    let sautd = valeur t id jd in
    let sautgd = valeur t ming maxd in
    let mint = ref 0 in
    let maxt = ref 0 in
    if t.(ming)<t.(mind) then mint :=ming else mint:=mind;
    if t.(maxg)>t.(maxd) then maxt :=maxg else maxt:=maxd;
    if (sautg > sautd && sautg > sautgd) then (ig, jg, !mint, !maxt) else 
      if (sautg > sautgd) then (id, jd, !mint, !maxt) else (ming, maxd, !mint, !maxt));;

let saut_max_dpr t =
  let i,j, m, n = saut_max_aux t 0 (Array.length t) in
  valeur t i j;;

let ()  = let size = int_of_string (Sys.argv.(1)) in
          let test = Array.make size 0. in
          Random.self_init();
          for i=0 to size-1 do
            test.(i) <- Random.float 500.;
          done;
          (*Printf.printf "Saut max naif = %f\n" (saut_max_naif test);*)
          Printf.printf "Saut max dpr = %f\n" (saut_max_dpr test);;