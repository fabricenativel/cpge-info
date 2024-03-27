open Hashtbl

let my_ht = Hashtbl.create 100000

let hash s =  
  let h = ref 0 in
  for i = 0 to (String.length s)-1 do
    h := !h*31 + Char.code s.[i]
  done;
  !h ;;



let () =
  for c = 65 to 90 do
    for b = 65 to 90 do
      for a = 65 to 90 do
        let h = hash ((String.make 1 (Char.chr c))^(String.make 1 (Char.chr b))^(String.make 1 (Char.chr a))) in
        if (Hashtbl.mem my_ht h) then print_endline "BUG" else (Hashtbl.add my_ht h true)
      done
    done
  done;
  print_endline "Terminé !";;