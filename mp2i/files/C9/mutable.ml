type variable = {mutable valeur : int};;

let a = {valeur = 5};;
a.valeur - 12;;

Printf.printf "Valeur de a = %d\n" a.valeur
