let distance x1 y1 x2 y2 =
  sqrt((x1-.x2)**2.-.(y1-.y2)**2.) ;;

(* Curryfication *)
let distance_a_zero = distance 0. 0. ;;

print_float (distance 0. 0. 10. 7.);;
print_newline();;
print_float (distance_a_zero 10. 7.);;
print_newline();;