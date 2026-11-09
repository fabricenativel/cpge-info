let harmonique_asc n =
  let s = ref 0. in
  for i = 1 to n do 
    s := !s +. 1.0/.(float_of_int i);
  done;
!s;;

let harmonique_desc n = 
  let s = ref 0. in
  for i = n downto 1 do
    s := !s +. 1.0/.(float_of_int i);
  done;
!s;;



let() =
let n = int_of_float(2.0**(30.)) in
Printf.printf "Ascendant : %f\n" (harmonique_asc n);
Printf.printf "Ascendant : %f\n" (harmonique_desc n);

