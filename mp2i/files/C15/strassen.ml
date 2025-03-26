let get_dim a =
  Array.length a, Array.length a.(0);;

(* Géneration aléatoire d'une matrice d'entiers compris en 0 et 9*)
let random_matrix n =
  let a = Array.make_matrix n n 0 in
  for i=0 to n-1 do
    for j=0 to n-1 do
      a.(i).(j) <- Random.int 10;
    done;
  done;
  a;;


(* Multiplication naïve de deux matrices*)
  let mult a b =
  let m, n = get_dim a in
  let n1, p = get_dim b in
  if (n <> n1) then failwith "Dimension incompatible" else
    (
      let c = Array.make_matrix m p 0 in
      for i=0 to m-1 do
        for j=0 to p-1 do
          for k=0 to n-1 do
            c.(i).(j) <- c.(i).(j) + a.(i).(k)*b.(k).(j)
          done;
        done;
      done;
      c
    );;

(*Additionne deux blocs de taille size des matrices a et b, on donne le coin sup gauche du bloc*)
let add_block a b l1 c1 l2 c2 size =
  let c = Array.make_matrix size size 0 in
  for i=0 to size-1 do
    for j=0 to size-1 do
      c.(i).(j) <- a.(i+l1).(j+c1) + b.(i+l2).(j+c2);
    done;
  done;
  c;;

  (*Soustrait deux blocs de taille size des matrices a et b, on donne le coin sup gauche du bloc*)
let sub_block a b l1 c1 l2 c2 size =
  let c = Array.make_matrix size size 0 in
  for i=0 to size-1 do
    for j=0 to size-1 do
      c.(i).(j) <- a.(i+l1).(j+c1) - b.(i+l2).(j+c2);
    done;
  done;
  c;;

let block a l c size =
  let e = Array.make_matrix size size 0 in
  for i=0 to size-1 do
    for j=0 to size-1 do
      e.(i).(j) <- a.(i+l).(j+c);
    done;
  done;
  e;;

let affiche a =
  let n,m = get_dim a in
  for i=0 to n-1 do
    for j=0 to n-1 do
      Printf.printf "%d " a.(i).(j);
    done;
    print_newline();
  done;;

(* Algorithme de strassen*)
let rec strassen a b   =
  let size = Array.length a in
  let c = Array.make_matrix size size 0 in 
  if size==2 then
    (
      c.(0).(0) <- a.(0).(0)*b.(0).(0) + a.(0).(1)*b.(1).(0);
      c.(0).(1) <- a.(0).(0)*b.(0).(1) + a.(0).(1)*b.(1).(1);
      c.(1).(0) <- a.(1).(0)*b.(0).(0) + a.(1).(1)*b.(1).(0);
      c.(1).(1) <- a.(1).(0)*b.(0).(1) + a.(1).(1)*b.(1).(1);
    )
  else
    (
  let p = size/2 in
  let m1 = strassen (add_block a a 0 0 p p p) (add_block b b 0 0 p p p)  in
  let m2 = strassen (add_block a a p 0 p p p) (block b 0 0 p) in
  let m3 = strassen (block a 0 0 p) (sub_block b b 0 p p p p) in
  let m4 = strassen (block a p p p) (sub_block b b p 0 0 0 p) in
  let m5 = strassen (add_block a a 0 0 0 p p) (block b p p p) in
  let m6 = strassen (sub_block a a p 0 0 0 p) (add_block b b 0 0 0 p p) in
  let m7 = strassen (sub_block a a 0 p p p p) (add_block b b p 0 p p p) in
  for i = 0 to p-1 do
    for j = 0 to p-1 do
      c.(i).(j) <- m1.(i).(j) + m4.(i).(j) - m5.(i).(j) + m7.(i).(j);
      c.(i).(j+p) <- m3.(i).(j) + m5.(i).(j);
      c.(i+p).(j) <- m2.(i).(j) + m4.(i).(j);
      c.(i+p).(j+p) <- m1.(i).(j) - m2.(i).(j) + m3.(i).(j) + m6.(i).(j);
    done;
  done;);
  c;;


  
let () =
  Random.self_init ();
  Printf.printf "Entrez un entier k (taille matrice = 2**k) = ";
  let k = read_int () in
  let n = int_of_float (2.0 ** float_of_int k) in
  let a = random_matrix n  in
  let b = random_matrix n in
  let s1 = Sys.time() in
  let c = mult a b in
  Printf.printf "Temps d'exécution naif = %f\n" (Sys.time() -. s1);
  let s2 = Sys.time() in
  let d = strassen a b in
  Printf.printf "Temps d'exécution Strassen = %f\n" (Sys.time() -. s2);;

  

