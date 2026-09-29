type formule =
    | X of int
    | Non of formule
    | Et of formule * formule
    | Ou of formule * formule
    | Imp of formule * formule
    | Equiv of formule * formule
    | Bot
    | Top
;;

let rec print_formule f = match f with
    | Bot -> print_string "F"
    | Top -> print_string "V"
    | X(n) -> (print_string "x("; print_int n; print_string ")")
    | Non(g) -> (print_string "¬"; print_formule g)
    | Et(g, h) -> print_op g h "^"
    | Ou(g, h) -> print_op g h "v"
    | Imp(g, h) -> print_op g h "->"
    | Equiv(g, h) -> print_op g h "<->"
and print_op g h symb =
    (print_string "(";
    print_formule g;
    print_string (" "^symb^" ");
    print_formule h;
    print_string ")")
;;

let f = Equiv(Imp(X(1), Non(Et(X(0), X(2))))
            , Bot);;

let snon x = not x;;

let set x y = match (x, y) with
    | (true, true) -> true
    | _ -> false
;;

let sou x y = (x || y);;

let simp x y = 
    if x then y else true
;;

let sequiv x y =
    x = y
;;

(* Question 3 *)

type valuation = {
    t: bool array;
    mutable parite: bool
};;

let rec eval v f = match f with
    | Bot -> false
    | Top -> true
    | X(n) -> v.t.(n)
    | Non(g) -> snon (eval v g)
    | Et(g, h) -> set (eval v g) (eval v h)
    | Ou(g, h) -> sou (eval v g) (eval v h)
    | Imp(g, h) -> simp (eval v g) (eval v h)
    | Equiv(g, h) -> sequiv (eval v g) (eval v h)
;;

let phi = {
    t = [| true; false; true |];
    parite = true
};;


let switch v i =
    v.t.(i) <- not (v.t.(i));
    v.parite <- not (v.parite)
;;

let first n = 
    {
        t = Array.make (n + 1) false;
        parite = true
    }
;;

(* dernier vrai prend un tableau de booléens et retourne l'indice de la
 * dernière case valant true. Retourne -1 sinon. *)

let dernier_vrai t =
    let n = Array.length t in
    let res = ref (-1) in
    for i = 0 to n - 1 do
        if t.(i) then
            res := i
        else
            ()
    done;
    !res
;;

exception Fin;;

let next v =
    let n = Array.length v.t in
    if v.parite then
        switch v (n - 1)
    else
        let d = dernier_vrai v.t in
        if d = 0 then
            raise Fin
        else
            switch v (d - 1)
;;

(* Question 7 *)

let print_valuation v = 
    let n = Array.length v.t in
    for i = 0 to n - 1 do
        if v.t.(i) then
           print_string "V "
        else
           print_string "F "
    done
;;

(* Question 8 *)
let rec maxvar f = match f with
    | Bot -> -1
    | Top -> -1
    | X(n) -> n
    | Et(g, h) -> max (maxvar g) (maxvar h)
    | Ou(g, h) -> max (maxvar g) (maxvar h)
    | Imp(g, h) -> max (maxvar g) (maxvar h)
    | Equiv(g, h) -> max (maxvar g) (maxvar h)
    | Non(g) -> maxvar g
;;

(* Question 9 *)
let table_verite f =
    let n = maxvar f in
    let phi = first n in
    try
        while true do
            print_valuation phi;
            print_string " || ";
            if eval phi f then
                print_string "V\n"
            else
                print_string "F\n"
            ;
            next phi
        done
     with
     | Fin -> print_string "terminé\n"
;;

print_formule f;;
print_newline ();;
table_verite f;;

(* Question 10 *)

exception Unsat;;

let sat f =
    let n = maxvar f in
    let phi = first n in
    try
        while (eval phi f = false) do
            next phi
        done;
        phi
    with
    | Fin -> raise Unsat
;;

let phisat = sat f in
print_valuation phisat;;
print_newline ();;

(* ENIGME DU SPHINX *)

let j1 = Et(Non(X(7)), Non(X(8)));;
let j2 = Ou(Ou(X(2), X(4)), X(5));;
let j3 = Et(Non(X(9)), Non(X(11)));;

let rec conjonction l = match l with
    | [] -> failwith ""
    | [f] -> f
    | t::q -> Et(t, conjonction q)
;;

let rec disjonction l = match l with
    | [] -> failwith ""
    | [f] -> f
    | t::q -> Ou(t, disjonction q)
;;

let unicitejour1 =
    let l = ref [] in
    for i = 0 to 6 do
        for j = i + 1 to 6 do
            l := Non(Et(X(i), X(j)))::(!l)
        done
    done;
    conjonction !l
;;

let existencejour1 = disjonction [X(0); X(1); X(2); X(3); X(4); X(5); X(6)];;

let uniciteverite =
    let l = ref [] in
    for i = 7 to 13 do
        for j = i + 1 to 13 do
            l := Non(Et(X(i), X(j)))::(!l)
        done
    done;
    conjonction !l
;;
let existenceverite = disjonction [X(7); X(8); X(9); X(10); X(11); X(12); X(13)];;

let r1 = Equiv(j1, disjonction [ Et(X(0), X(7)); Et(X(1), X(8)); Et(X(2), X(9)); Et(X(3), X(10)); Et(X(4), X(11)); Et(X(5), X(12)); Et(X(6), X(13))]);; 
let r2 = Equiv(j2, disjonction [ Et(X(0), X(8)); Et(X(1), X(9)); Et(X(2), X(10)); Et(X(3), X(11)); Et(X(4), X(12)); Et(X(5), X(13)); Et(X(6), X(7))]);; 
let r3 = Equiv(j3, disjonction [ Et(X(0), X(9)); Et(X(1), X(10)); Et(X(2), X(11)); Et(X(3), X(12)); Et(X(4), X(13)); Et(X(5), X(7)); Et(X(6), X(8))]);; 

let bigformule = conjonction [unicitejour1; existencejour1; uniciteverite; existenceverite; r1; r2; r3];;

print_formule bigformule;;
let phi = sat bigformule;;
print_valuation phi;;
