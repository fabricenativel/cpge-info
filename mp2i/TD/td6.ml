let rec exp_rapide a n =
  if n=0 then 1 else 
    let pr =  exp_rapide a (n/2) in
    if n mod 2 = 0 then pr*pr else pr*pr*a;;

let test_egal a n = 
  let v1 = int_of_float ((float_of_int a) ** (float_of_int n)) in
  let v2 = exp_rapide a n in
  Printf.printf "V1 = %d\n" v1; 
  Printf.printf "V2 = %d\n" v2; 
  v1 = v2;;

let () = if (test_egal 5 15) then print_string "ok" else print_string "bug";;
