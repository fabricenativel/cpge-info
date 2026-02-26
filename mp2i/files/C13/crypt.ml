type letter = {car : char; mutable value : int}

let ok op1 op2 res = 
  

let get_letters op1 op2 res =
  let all = op1 ^ op2 ^ res in
  let letters = ref [] in
  for i = 0 to String.length all - 1 do
    if not (List.mem all.[i] (List.map (fun l -> l.car) !letters)) then
      letters := {car = all.[i]; value = -1}::(!letters)
    done;
!letters;;

let is_valid op1 op2 res =
   (List.length (get_letters op1 op2 res))<=10;;

let rec all_values letters =
  match letters with
  | [] -> true
  | h::t -> h.value <> -1 && all_values t;;



