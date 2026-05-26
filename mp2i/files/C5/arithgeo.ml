let rec un n a b=
 if n=0 then a else sqrt((un (n-1) a b) *. vn (n-1) a b)
 and
 vn n a b =
 if n=0 then b else ((un (n-1) a b) +. (vn (n-1) a b)) /. 2.0
