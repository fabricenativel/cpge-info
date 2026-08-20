let tab_aleatoire n =
  Random.self_init ();
  let tab = Array.make n 0 in
  for i=0 to n-1 do
    tab.(i) <- Random.int ((1 lsl 30) - 1);
  done;
  tab;;

let chiffre n d =
  let sn = string_of_int n in
  if d>=(String.length sn) then 0 else int_of_string (String.make 1 sn.[(String.length sn) -d - 1]);;

let rec puissance a n = if n=0 then 1 else
  (let t = puissance a (n/2) in
    if n mod 2 = 0 then t*t else a*t*t);;

let chiffre2 n d =
  (n / (puissance 10 d)) mod 10;;


  let radix_pass integers rank =
    let size = Array.length integers in
    let temp = Array.make size 0 in
    let bucket_size = Array.make 10 0 in
    let bucket_position = Array.make 10 0 in
    for i=0 to (size-1) do
      let d = chiffre2 integers.(i) rank in
      bucket_size.(d) <- bucket_size.(d)+1;
    done;
    for i=1 to 9 do
      bucket_position.(i) <- bucket_position.(i-1) + bucket_size.(i-1);
    done;
    for i=0 to (size-1) do
      let d = chiffre2 integers.(i) rank in
      temp.(bucket_position.(d)) <- integers.(i); 
      bucket_position.(d) <- bucket_position.(d) + 1;
    done;
    for i=0 to (size-1) do
      integers.(i) <- temp.(i);
    done;
    ;;

  let radix_sort integers nb=
    for i=0 to (nb-1) do
        radix_pass integers i;
    done;;

let () =
  print_endline "Génération du premier tableau aléatoire ";
  let n = 10000000 in
  let tab = tab_aleatoire n in
  print_endline "Début du tri";
  let debut = Sys.time () in
  Array.sort (fun x y -> x - y) tab;
  let fin = Sys.time () in
  Printf.printf "Temps de calcul pour tri intégré (%d entiers) = %f\n" n (fin-.debut);
  for i=1 to n-1 do
    assert (tab.(i-1)<=tab.(i));
  done;
  print_endline "Génération du second tableau aléatoire ";
  let tab2 = tab_aleatoire n in
  print_endline "Début du tri";
  let debut2 = Sys.time () in
  radix_sort tab2 10 ;
  let fin2 = Sys.time () in
  Printf.printf "Temps de calcul pour tri radix  (%d entiers) = %f\n" n (fin2-.debut2);
  for i=1 to n-1 do
    assert (tab2.(i-1)<=tab2.(i));
  done;
  ;;