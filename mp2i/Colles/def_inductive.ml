type nb =
| Z
| R1 of nb 
| R2 of nb
| R3 of nb;;

let rec res n =
  match n with
  | Z -> 0
  | R1 x -> (res x) + 5
  | R2 x -> (res x) + 2
  | R3 x -> -(res x);;