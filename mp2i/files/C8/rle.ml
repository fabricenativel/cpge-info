let list_of_string s =
  let rec aux a b =
    if a>=b then [] else s.[a]::(aux (a+1) b) in
    let n = String.length s in
    aux 0 (n-1);;


let compression s =
  let rec aux s car rep =
    match s with
    | [] -> [(rep,car)]
    | h::t -> if h=car then aux t car (rep+1) else (rep,car)::(aux t h 1) in
    aux s (List.hd s) 0;;

let rec decompression lc =
  match lc with
  | [] -> ""
  | (rep,car)::t -> String.make rep car ^ (decompression t);;

let rec affiche lc =
  match lc with
  | [] -> print_newline()
  | (r,c)::t -> Printf.printf "(%d,'%c'); " r c; affiche t;;

let () = 
 let img = "_____________
( Hello world )
 -------------
        o   ^__^
         o  (oo)\\_______
            (__)\       )\\/\\
                ||----w |
                ||     ||
" in
    let lc = compression (list_of_string img) in
    affiche lc
  ;;
                  