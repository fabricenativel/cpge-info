let aire_rectangle long larg = long * larg;;

let aire_cercle r = 
  let pi = 3.1415 in pi *. r *. r;;

print_int (aire_rectangle 4 10) ;;
print_newline() ;;
print_float (aire_cercle 5.);;
print_newline() ;;