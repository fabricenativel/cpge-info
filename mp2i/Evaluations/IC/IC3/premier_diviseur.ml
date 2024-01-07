let premier_diviseur n =
  let rec aux n c =
    if n mod c = 0 then c else aux n (c+1) in
  aux n 2;;
  