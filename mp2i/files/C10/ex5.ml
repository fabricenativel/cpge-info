let rec hash s =
  let l = String.length s in
  if l=0 then 0 else
    let t = String.sub s 0 (l-1) in
    31 * (hash t) + Char.code s.[l-1];;

let () = 
    for a = 66 to 90 do
      for b = 66 to 90 do
        let ap = a - 1 in
        let bp = b + 31 in
        Printf.printf "hash ab \t= %d\n" (31*a+b);
        Printf.printf "hash a'b'\t = %d\n" (31*ap+bp);
      done
    done;;