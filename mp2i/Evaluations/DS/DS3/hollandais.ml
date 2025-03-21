let echange tab i j =
  let temp = tab.(i) in
  tab.(i) <- tab.(j);
  tab.(j) <- temp;;

let hollandais tab =
  let n = Array.length tab in
  let i1 = ref 0 in
  let i2 = ref (n-1) in
  let i3 = ref (n-1) in
  while (i1<=i2) do
    match tab.(!i1) with
    | 1 ->  i1 := !i1 + 1;
    | 2 ->  echange tab !i1 !i2; i2 := !i2 -1;
    | 3 ->  echange tab !i1 !i2;
            echange tab !i2 !i3;
            i3 := !i3 - 1;
            i2 := !i2 - 1;
    | _ -> failwith "Bug"
      done;;

  let () = 
        Random.self_init ();
        let test = Array.make 100 0 in
        for i=0 to 99 do
          test.(i) <- 1+(Random.int 3);
        done;
        hollandais test;
        Array.iter (print_int) test;
        print_newline ();

