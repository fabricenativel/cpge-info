# Exercice 2
1. Les minima locaux de l’arbre A sont 0, -4, 1

2. Définition inductive des arbres binaires :
Un arbre binaire est constitué de noeud, soit Vide, soit composé de 2 sous arbres et d'une valeur.

Définition de la hauteur d’un arbre :
La hauteur de l'arbre vide vaut -1, sinon récursivement, elle est vaut 1 + max(s_a_g, s_a_d)

3. Propriété : tout arbre non vide possède un minimum local.
Preuve : tout arbre admet au mois un minimum, ce minimum est un minimum local.

4.
En parcourant récursivement l'arbre en profondeur préfixe : 
Si le noeud visité est plus petit que ses voisins, on le renvoie
Sinon, si son sous arbre gauche n'est pas vide, on continue la recherche à gauche et à droite sinon.

5-6.
```ml
type ab = Vide | Noeud of ab*int*ab;;

let eti ab = match ab with
|Vide -> Int.max_int
|Noeud(g,v,d)-> v;;

let rec min ab = 
  let rec aux n ab = match ab with
  |Vide -> n
  |Noeud(g,v,d)-> if v < n && v < eti g && v < eti d 
                    then v
                    else if g = Vide then aux v d else aux v g 
  in
  aux Int.max_int ab;;

let rec min_locaux ab = 
  let rec aux n ab lst = match ab with
  |Vide -> lst
  |Noeud(g,v,d)-> let lst =  if v < n && v < eti g && v < eti d 
                            then v::lst
                            else lst in
                  aux v g ( aux v d lst ) in
  aux Int.max_int ab [];;
    
let a1 = Noeud(Noeud(Vide,6,Vide),1,Noeud(Vide,4,Vide));;
let a8 = Noeud(Vide,8,Vide);;
let a2 = Noeud(a8,2,a1);;
let am4 = Noeud(Vide,-4,Vide);;
let am2 = Noeud(Vide,-2,am4);;
let a3 = Noeud(am2,3,Vide);; 
let a0 = Noeud(a3,0,a2);;
```