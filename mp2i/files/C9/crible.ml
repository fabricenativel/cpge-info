let crible n =
  let cb = Array.make n true in
  cb.(0) <- false;
  cb.(1) <- false;
  let i = ref 2 in
  while !i <= int_of_float(sqrt(float_of_int n)) do
    if cb.(!i) then 
      let j = ref 2 in
        while !j * !i <n do
          cb.(!j* !i) <- false;  
          j := !j +1;
        done;
      else ();
    i := !i +1;
  done;
  cb

  let premiers n =
    let cl = crible n in
    let premiers = ref [] in
    for i=0 to n-1 do
      if cl.(i) then premiers := i::(!premiers);
    done;
    !premiers

let rec somme liste =
  match liste with
  | [] -> 0
  | h::t -> h + somme t
    