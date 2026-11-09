let meme_ligne n =
  let res = Array.make 9 0 in
  let ligne = n/9 in
  for i=0 to 8 do
    res.(i) <- 9*ligne+i;
  done;
  res;;

let meme_colonne n =
  let res = Array.make 9 0 in
  let colonne = n mod 9 in
  for i=0 to 8 do
    res.(i) <- colonne+i*9;
  done;
  res;;
  
let meme_bloc n =
  let res = Array.make 9 0 in
  let cl = 3*((n/9)/3) in
  let cc = 3*((n mod 9)/3) in
  let idx = ref 0 in
  for i=0 to 2 do
    for j=0 to 2 do
      res.(!idx) <- (cl+i)*9 + (cc+j);
      idx := !idx + 1;
    done;
  done;
  res;;



let verifie sudoku n =
  let ligne = meme_ligne n in
  let colonne = meme_colonne n in
  let bloc = meme_bloc n in
  try 
  for i = 0 to 8 do
    if  (n<>ligne.(i) && sudoku.(ligne.(i))=sudoku.(n)) || 
        (n<>colonne.(i) && sudoku.(colonne.(i))=sudoku.(n)) ||
        (n<>bloc.(i) && sudoku.(bloc.(i))=sudoku.(n)) then raise Exit
done;
 true;
with Exit -> false;;


let rec affiche sudo =
  for i = 0 to 8 do
    for j = 0 to 8 do 
      Printf.printf "%d " sudo.(i*9+j);
    done;
    print_newline ();
  done;
  ignore (read_line ());
;;

let rec resoud sudoku  n =
try 
if n=80 then raise Exit
else
  (
    if sudoku.(n)=0 then
    (
      for i=1 to 9 do
        sudoku.(n) <- i;
        if (verifie sudoku n) then resoud sudoku (n+1) else false; 
      done;
      sudoku.(n) <- 0;
      false;
        )
    else
    resoud sudoku (n+1);
  )
    with Exit -> true;
    ;;


let () =
let test = [| 
            5; 3; 0; 0; 7; 0; 0; 0; 0;
            6; 0; 0; 1; 9; 5; 0; 0; 0;
            0; 9; 8; 0; 0; 0; 0; 6; 0;
            8; 0; 0; 0; 6; 0; 0; 0; 3;
            4; 0; 0; 8; 0; 3; 0; 0; 1;
            7; 0; 0; 0; 2; 0; 0; 0; 6;
            0; 6; 0; 0; 0; 0; 2; 8; 0;
            0; 0; 0; 4; 1; 9; 0; 0; 5;
            0; 0; 0; 0; 8; 0; 0; 7; 9 
          |] in

          let res = resoud test 0 in
          if (res) then (affiche test) else (print_endline "Pas de solution !");;