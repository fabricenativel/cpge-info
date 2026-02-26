let f n = n * (n-1);;

let g x = x**2. -. 3.0*.x +. 7.0 ;;

let deux_egaux a b c = (a=b) || (b=c) || (a=c);;

let syracuse n =
  if n mod 2 = 0 then n/2 else 3*n+1;;

let rec somme_carre n =
  if n=0 then 0 else n*n + somme_carre (n-1);;

let rec repete c n =
  if n= 1 then c else c ^ repete c (n-1);;

let rec triangle c n =
  if n=1 then print_string c else (print_string (repete c n); print_endline " "; triangle c (n-1)) ;;

let rec compte_rebours n = 
  if n=0 then print_endline "Partez" else (
    print_int n; 
    print_endline "";
    compte_rebours (n-1) );;

let abs_entier n =
  if n <0 then -n else n;;

let abs_flottant n =
  if n < 0. then -.n else n;;
