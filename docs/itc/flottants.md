{% set num = 12 %}
{% set niveau = "itc_s2"%}
{{ titre_chapitre(num,niveau)}}


## Introduction 

Effectuer les calculs suivants dans la console Python de votre choix (un émulateur est disponible ci-dessous)
{{terminal()}}

1. Calculer `0.1 + 0.2`. Le résultat obtenu est-il **exactement** 0.3 ?
2. Que donne  `0.1 + 0.2 == 0.3` ?
3. Que donne  `2**50+0.1-2**50` ? Quel est le résultat correct de ce calcul ?
4. Que donne `10**500` ? Et `10.0**500` ?
5. Importer la fonction racine carré en tapant `from math import sqrt`, que donne `(sqrt(2))**2` ? Quel est le résultat correct de ce calcul ?
6. Quelle est l'écriture décimale de la fraction $\dfrac{1}{3}$ ? Que donne le calcul de `1/3` ?
7. Quelle conclusion tirer de ces quelques exemples ?

## Cours

{{ affiche_cours(num) }}

## Travaux pratiques


{{ exo("Un peu de programmation Python",[],0)}}

1. Ecrire une fonction python `decimale(chiffres_binaires)` qui prend en argument une liste `chiffres_binaires` représentant les chiffres situés *après la virgule* en écriture binaire et renvoie l'écriture décimale. Par exemples :

    * `decimale([0,1])` doit renvoyer $0,25$ en effet : $0,01_{2} = 2^{-2} = 0,25$
    * `decimale([1,1,0,1])` doit renvoyer $0,8125$ en effet : $0,1101_{2} = 2^{-1} + 2^{-2} + 2^{-4} = 0,8125$

2. Ecrire une fonction python `dyadique(chiffres_decimaux,taille_max)` qui prend en argument une liste `chiffres_decimaux` représentant les chiffres situés *après la virgule* en écriture décimale et renvoie l'écriture dyadique en se limitant à une mantisse de `taille_max`. Par exemples : 

    * `dyadique([7,5],12)` doit renvoyer `[1,1]` car $0,75_{10} = 0,11_{2}$
    * `dyadique([1],12)` doit renvoyer `[0,0,0,1,1,0,0,1,1,0,0,1]` car $0,1_{10} = 0,000110011001100110011..._{2}$ et on se limite à 12 chiffres après la virgule.


    !!! Aide
        Revoir si besoin l'algorithme vu en cours pour passer de l'écriture décimale à l'écriture dyadique.


{{ exo("Comparaisons entre flottants",[]) }}

On considère le programme Python suivant :
```python linenums="1"
x = 0.3
tour = 0
while x != 0.0:
    tour += 1
    x = x - 0.1
print("Nombre de passages dans la boucle = ",tour)
```

1. Combien de fois devrait-on passer dans la boucle `while` ? et quel est l'affichage attendu ?
2. Recopier et executer ce programme. Que se passe-t-il ? pourquoi ?
3. Remplacer le test de la ligne 3 par `while x > 0`. Expliquer le résultat obtenu


{{ exo("Discriminant",[])}}

1. Ecrire une fonction `discriminant` qui prend en paramètres trois flottants  $a,b$ et $c$ et renvoie $b^2-4ac$.
2. Ecrire une fonction `nombre_solutions` qui prend en paramètre un flottant $d$ et affiche `2 solutions` si $d>0$, `1 solution` si $d=0$ et `pas de solutions` si $d<0$.
3. Déterminer le nombre de solutions réelles des équations suivantes et comparer avec les résultats obtenus en utilisant les deux fonctions ci-dessous :
    * $x^2 + 1,4x - 0,49 = 0$
    * $x^2 + 0,6x - 0,09 = 0$
    * $x^2 + 0,4x - 0,04 = 0$
4. Interpréter ces résultats

{{ exo("Comportement d'une suite",[])}}

On considère la suite $(u_n)_{n \in \mathbb{N}}$ définie par :  
$\left\{ \begin{array}{ll} u_0=e-1 \\ u_{n+1} = (n+1)\,u_n - 1 \end{array}\right.$

1. Montrer que cette suite converge et a pour limite 0

    !!! aide
        On pourra note $\displaystyle{S_n = \sum_{k=0}^n \frac{1}{k!}}$, admettre que pour tout $n \in N$, $S_n \leqslant e \leqslant S_n + \dfrac{1}{n\,n!}$ et suivre les étapes suivantes :

        * montrer que $\displaystyle{e = \lim_{n \rightarrow +\infty} S_n}$
        * montrer que pour tout $n \in N$, $u_n = n!\,(e-S_n)$
        * conclure

2. Ecrire un programme, qui  affiche les $30$ premiers termes de la suite $u$. On utilisera la constante `e` de `math` comme valeur de $e$. 

2. Expliquer le résultat obtenu.

{{ exo("Convergence numérique et mathématique",[])}}

On considère la suite $(u_n)_{n \in \mathbb{N}}$ définie par :  
$\left\{ \begin{array}{ll} u_1= \dfrac{5}{4} \\ u_2 = \dfrac{7}{5} \\ u_{n+2} = 10 - \dfrac{23}{u_{n+1}} + \dfrac{14}{u_nu_{n+1}} \end{array}\right.$


1. Vérifier que le terme général de $(u_n)$ est $\dfrac{2^n+3}{2^{n-1}+3}$ et en déduire que $(u_n)$ converge et donner sa limite.
2. Ecrire un programme qui affiche les 40 premiers termes de la suite $u$.
3. Expliquer le résultat obtenu.