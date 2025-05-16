let incremente v =
  let n = Array.length v in
  let pos = ref (n-1) in
  while (!pos >=0) && v.(!pos) do
    v.(!pos) <- false;
    pos := !pos - 1;
  done;
  if !pos >= 0 then (v.(!pos) <- true; true) else false;;

let bin_to_dec n b =
  (*Renvoie l'écriture de n en base 2 sur b bits*)
  let bin = Array.make b false in
  let vn = ref n in
  let i = ref (b-1) in
  while (!vn>0 && !i>=0) do
    bin.(!i) <- (!vn mod 2 = 1);
    i := !i - 1;
    vn := !vn / 2;
  done;
  bin;;