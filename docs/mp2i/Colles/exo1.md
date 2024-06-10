# Exercice 1
1. Un arbre de recherche est un arbre binaire sur un ensemble ordonné dont chacun des noeuds a une étiquette supérieur ou égale à tous les élèments de l'arbre gauche et inférieur à ceux de l'arbre droit.

2. insertions successives de bacddabdbae 
```
          b
      a       c
  a       b       d
a       b       d   e
               d
```
La hauteur de l'arbre vaut 4

3.Par induction sur la taille n (entier positif), montrons $P_n$ : "lors d'un parcours en profondeur infixe, l'ordre est croissant".

$P_0$ trivial.
Supposons $P_n$ vrai.
Soit un arbre quelconque de taille n+1 de la forme (S_a_g,e,S_a_g) où S_a_g et S_a_d sont des sous arbres de taille inférieur ou égale à n. Lors de parcours infixes, d'une part, on obtient P_g et P_d deux listes croissantes dont les élèments sont respectivements tous inférieurs (supérieurs) à e.
Le parcours infixe de l'arbre complet est P_g+ e + P_d dont  l'ordre est croissant. $P_{n+1}$ est vraie. CQDF.  

4. Proposer un algorithme qui permet de compter le nombre d'occurrences d'une lettre dans un arbre
binaire de recherche de lettres. 
```
nb_occ(e,abr)
    si abr est vide alors retourner 0
    
    si e = ettiquette(abr) alors 
       val = 1
    sinon
       val = 0
    
    si e < ettiquette(abr) alors retourn val = val + nb_occ(e,S_a_g) sinon val + nb_occ(e,S_a_g)
```

Sa complexité est sa hauteur




5-6. Implémentation
```ml
type abr = Vide | Noeud of abr*char*abr;;

let rec insere e ab = match ab with
| Vide         -> Noeud(Vide,e,Vide)
| Noeud(g,v,d) -> if e <= v then Noeud(insere e g,v,d) else Noeud(g,v,insere e d);;

let rec occ e ab = match ab with
| Vide -> 0
| Noeud(g,v,d)-> if e > v then occ e d 
                else occ e g + if e = v then 1 else 0;;

let test = Vide;;
let test2 = insere 'b' test;;

```

