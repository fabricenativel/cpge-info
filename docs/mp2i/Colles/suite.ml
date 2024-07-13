let e = exp 1.0 -. Float.min_float;;

let rec u n = 
  if n = 0 then e -. 1.0 else 
    (float_of_int n) *. (u (n-1)) -. 1.0;;

let () = Printf.printf "%f \n" (u (int_of_string Sys.argv.(1)));;



