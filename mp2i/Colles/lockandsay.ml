let rec lockandsay previous =
  match previous with
  | [] -> []
  | x::[] -> [1;x]
  | x::y::[] -> if x=y then [2;x] else [1;x;1;y]
  | x::y::z::t -> if (x=y && y=z) then 3::x::lockandsay(t) else 
                  if x=y then 2::x::lockandsay(z::t) else
                    1::x::lockandsay(y::z::t)
let rec ls n =
  let rec aux n current =
    if n=1 then current else aux (n-1) (lockandsay current) in
    aux n [1];;

