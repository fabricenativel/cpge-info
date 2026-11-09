let rec mult_russe a b =
  if a = 0 then 0 else
    let t = mult_russe (a/2) (b*2) in
    if a mod 2=1 then b+t else t;;

