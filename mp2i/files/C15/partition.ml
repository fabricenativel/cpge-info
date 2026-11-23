let cross elt l = List.map (fun x -> elt,x) l 

let rec crossl l1 l2 = 
  match l1 with
  | [] -> []
  | h::t -> (cross h l2)@crossl t l2;;

let rec partition n =
  if n=1 then [[1]] else (
    let p = Array.make (n-1) [[]] in
    for i=1 to (n-1) do
      p.(i) <- partition i;
    done; 
    let res = ref [[n]] in
    for i=1 to (n-1) do
      res:= !res 
    done;
    !res
  );;