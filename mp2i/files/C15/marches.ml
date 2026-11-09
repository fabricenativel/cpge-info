let ajoute c lstr = List.map (fun x -> c^x) lstr;;


let rec facons n =
  if n=1 then ["1"] else
    if n=2 then ["11"; "2"] else
      (ajoute "1" (facons (n-1)))  @ (ajoute "2" (facons (n-2)));;