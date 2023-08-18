{% set num = 1 %}
{% set niveau = "mp2i_s1"%}

{{ titre_chapitre(num,niveau)}}

{{ citation("The only way to learn a new programming language is by writing programs in it","B. Kernighan & D. Ritchie","[in the C programming language 1978](https://en.wikipedia.org/wiki/The_C_Programming_Language)")}}


## Cours

{{ cours(num) }}

### Exemples du cours

* ??? langageC "Hello world"
    ```C
    --8<-- "C1/cours_ex1.c"
    ```

* ??? langageC "Somme des entiers de 1 à 100"
    ```c
    --8<-- "C1/cours_ex2.c"
    ```

* ??? langageC "Fonction Syracuse"
    ```c
    --8<-- "C1/cours_ex3.c"
    ```

## Travaux dirigés

{{ td(num) }}

## Travaux pratiques

{{ exo("Premières compilations",[],0) }}

1. Lancer VS Code et ouvrir un répertoire de travail (par exemple `~/TP/LangageC/TP1`)
2. Dans l'onglet extension (accessible via le raccourci clavier ++ctrl+shift+x++), chercher "C" et installer "*C/C++ IntelliSense, debugging, and code browsing.*"
3. Pour chacun des trois programmes vus en cours et disponibles [ci-dessus](#exemples-du-cours)
    1. Le copier dans VS code et l'enregistrer (la coloration syntaxique devrait être visible)
    2. Dans le terminal de VS Code le compiler avec `gcc`

        !!! warning "Attention"
            On rappelle qu'il est **très fortement recommandé** de toujours compiler avec les options `-Wall` et `-Wextra` et que l'option `-o` permet de spécifier un nom pour l'exécutable produit lors de la compilation

    3. Lancer l'exécution

        !!! aide 
            Il faut spécifier le chemin vers l'exécutable, ici `./`


{{ exo("Quelques fonctions pour démarrer",[]) }}

1. Ecrire une fonction `aire_disque` qui prend en argument un flottant `r` et renvoie l'aire du disque de rayon `r`, on définira une constante flottante `pi` de valeur `3.14159` qui sera utilisé dans le calcul.

2. Ecrire une fonction `valeur_absolue` qui prend en argument un flottant `x` et renvoie sa valeur absolue.

    !!! aide
        On rappelle que :  
        $|x| = \left\{ \begin{array}{rl} -x & \mathrm{\ si\ } x<0 \\ x & \mathrm{\ sinon} \end{array}\right.$

3. Ecrire une fonction `est_triangle` qui prend en argument trois entiers `a`,`b` et `c` et qui renvoie `true` si ces trois entiers peuvent être les longueurs des trois côtés d'un triangle. 

    !!! aide
        Cela revient à vérifier que les trois entiers vérifient l'inégalité triangulaire ou encore que le plus grand des trois est inférieur à la somme des deux autres.

4. On appelle *factorielle* d'un entier $n$ et on note $n!$ le produit de cet entier par tous ceux qui le précèdent à l'exception de zéro. Et on convient d'autre part que $0!=1$. Par exemple $5! = 5 \times 4 \times \times 3 \times 2 \times 1 = 120$. Ecrire une fonction `factorielle` qui prend en argument un entier `n` et renvoie sa factorielle.

5. Ecrire une fonction `bissextile` qui prend en argument un entier `annee` et renvoie `true` si cette année est bissextile et `false` sinon.

    !!! aide
        Une année est bissextile si elle est divisible par 4 mais pas par 100 ou s'il est divisible par 400.

{{ exo("Ecrire quelques boucles",[]) }}

1. Ecrire une fonction prenant en entrée un entier $n$ et renvoyant le plus petit entier $k$ tel que $2^k \geq n$.
2. Ecrire un programme permettant de calculer la somme suivante :  
 $\displaystyle{\sum_{k=1}^{100} k^2}$.

{{ exo("Un peu de dessin",[]) }}

1. Ecrire une fonction `carre_plein` prenant comme paramètre un entier `cote` et un caractère `car` et permettant d'afficher un carré de côté `cote` rempli de caractères `car`. Par exemple, `carre(5,'C')` produit l'affichage suivant :
```
CCCCC
CCCCC
CCCCC
CCCCC
CCCCC
```

2. Ecrire une fonction `rectangle_creux`  prenant trois paramètres : deux entiers `largeur` et `longueur` et un caractère `car` permettant d'afficher un rectangle creux de dimensions `largeur` sur `longueur` dont la bordure est constitué de caractères `car`. Par exemple `rectangle_creux(3,7,'~')` devrait produire l'affichage suivant :
```
~~~~~~~
~     ~
~~~~~~~
```

3. De la même façon écrire une fonction `triangle` prenant comme paramètre un entier `hauteur` et un caractère `car` telle que `triangle(6,'*')` produise l'affichage suivant :
```
     *
    ***
   *****
  *******
 *********
***********
```

{{ exo("Somme des éléments d'un tableau",[]) }}

1. Ecrire une fonction `somme` qui prend en argument un tableau ainsi que sa taille et renvoie la somme des éléments de ce tableau.

2. Créer un tableau de  `carres` de taille 100 et grâce à une boucle l'initialiser de façon à ce que `carres[i]=i*i`.

3. Calculer la somme des carres des entiers de 1 à 100.


{{ exo("Appartient à un tableau",[]) }}

1. Ecrire une fonction `appartient` qui prend en argument un tableau `tab` (et sa taille `t`) ainsi qu'un entier `n` et qui renvoie `true` si `n` est dans le tableau `tab` et `false` sinon.

2. En utilisant cette fonction et le tableau `carres` de la fonction précédente, vérifier que 5041 est un carré parfait mais pas  6726.

{{ exo("Longueur d'une chaine de caractères",[])}}

Ecrire une fonction `my_strlen` qui prend en argument une chaine de caractères et renvoie sa longueur

!!! aide
    On rapelle qu'une chaine de caractères en C se termine par le caractère nul `'\0'`


{{ exo("Manipulation des chaines de caractères",[])}}

1. Ecrire une fonction `retourne` qui prend en argument une chaine de caractères et affiche cette chaine écrite à l'envers. Par exemple `retourne("Bonjour")` affiche `"ruojnoB"`.

2. Ecrire une fonction `palindrome` qui prend en argument une chaine de caractères et renvoie `true` si cette chaine est un palindrome (c'est à dire qu'elle se lit indifféremment de gauche à droite ou de droite à gauche) et `false` sinon. Par exemple `palindrome("radar")` renvoie `true`.

{{ exo("Nombre parfait",[] )}}
Un nombre parfait est un entier positif égal à la  la somme de ses diviseurs stricts (c'est à dire autres que lui-même). Par exemple, 6 est un nombre parfait car $6 = 3 + 2 + 1$. 

1. Écrire une fonction `parfait` qui renvoie `true` si l'entier positif donné en argument est parfait et `false` sinon.
2. Utiliser cette fonction pour vérifier que $8128$ est un nombre parfait mais pas $2023$.


{{ exo("Triangle de Pascal",[]) }}

Ecrire un programme qui prend en argument un entier $1 \leq n \leq 10$ et affiche les $n$ premières lignes du [triangle de Pascal](https://fr.wikipedia.org/wiki/Triangle_de_Pascal){target=_blank}. Par exemple `pascal(4)` affiche :
```
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
```

!!! aide
    * On rappelle que le coefficient situé ligne $n$ et colonne $k$ noté $\displaystyle{\binom{n}{k}}$ se déduit de ceux de la ligne précédente grâce à la formule de Pascal : $\displaystyle{\binom{n}{k} = \binom{n-1}{k-1} + \binom{n-1}{k}}$
    * On pourra utiliser deux tableaux, l'un représentant la ligne précédente et un second la ligne en cours de construction.


{{ exo("Crible d'Erastothène",["dur"]) }}

On rappelle qu'un nombre premier est un entier naturel ayant exactement deux diviseurs 1 et lui-même, ainsi 13 est premier mais pas 15. Le [crible d'Erastothène](https://fr.wikipedia.org/wiki/Crible_d%27%C3%89ratosth%C3%A8ne) est un algorithme permettant de trouver tous les nombres premiers inférieurs ou égaux à un entier `n` donné. 

!!! abstract "Algorithme"
    * on crée un tableau de booléens `premiers` de taille `n+1`
    * on initialise le tableau à `true` sauf `premiers[0]` et `premiers[1]` qui sont à `false` puisque  $0$ et 1 ne sont pas premiers.
    * on parcourt ce tableau si `premiers[i]` est à `true` alors on met tous ses multiples (sauf lui-même) à `false`
    * le parcours s'arrête dès que l'entier `i` est supérieur à $\sqrt{n}$.  

1. Ecrire en C une fonction `crible` qui prend en paramètre un entier `n` et implémente cet algorithme. L'utiliser pour afficher les nombres premiers inférieurs à 100.

    !!! aide
        Vous devriez obtenir : `2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97`

2. Ecrire en C une fonction `somme_premiers` qui prend en argument un entier `seuil` et renvoie la somme de tous les nombres premiers inférieurs ou égaux à `seuil`. Par exemple `somme_premiers(100)` renvoie `1060`

??? lien "Pour aller plus loin"
    Les élèves ayant fait la spécialité {{sc("nsi")}} ou connaissant un minimum le langage Python peuvent coder ce même algorithme en Python et comparer les temps de calcul dans les deux langages sur par exemple `somme_premiers(5000000)`. 

## Humour d'informaticien

![punition](./Images/C1/punition.jpg){.imgcentre width=500px}