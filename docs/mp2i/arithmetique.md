
{% set num = 4 %}
{% set niveau = "mp2i_s1"%}

{{ titre_chapitre(num,niveau)}}

{{ citation("It makes me nervous to fly an airplane since I know they are designed using floating-point arithmetic","A. Householder")}}

## Cours

{{ affiche_cours(num) }}

## Travaux Dirigés

{{ td(num) }}

## Travaux Pratiques

{{ exo("Puissance",[],0)}}

1. Ecrire une fonction `puissance` qui prend en argument un entier $n$ et un entier positif $p$ et renvoie $n^p$.
2. Modifier la fonction précédente de façon à prendre en compte le cas des exposants négatifs.
    
    !!! aide
        On rappelle que pour $n \in \mathbb{Z}^*,\; p \in \mathbb{N} \quad n^{-p} = \dfrac{1}{n^p}$

3. Proposer un jeu de test pour cette fonction.

{{ exo("Du binaire au décimal",[])}}

1. Ecrire une fonction `bin_to_decimal` qui convertit une écriture binaire en sa valeur décimale. L'écriture binaire sera lue comme un tableau d'entiers contenant des 0 ou des 1 et on prendra aussi en argument sa taille. Par exemple si le tableau `bin` contient les valeurs `1,0,1,1` alors `bin_to_decimal(bin,4)` doit renvoyer `11` (car $2^3 + 2^1+2^0 = 11$) 
2. Modifier la fonction `bin_to_decimal` qui prend maintenant en argument un troisième paramètre booléen `signe`, si `signe` vaut `true` l'écriture binaire est traité comme un complément à deux sur la longueur du tableau, sinon la fonction se comporte comme à la question précédente. Par exemple  `bin_to_decimal(bin,4,false)` doit renvoyer `11` (même comportement que ci-dessus) mais `bin_to_decimal(bin,4,true)` doit renvoyer  `-5`, en effet $-2^3+2^1+2^0=-5$.

3.  Vous avez (peut-être) utilisé la fonction `puissance` de l'exercice précédent, dans ce cas, reprendre cet exercice en remarquant que :

    $$
    \sum_{k=0}^{n} a_ib^i = a_0 + b\left( a_1 + b\left(a_2+ \dots (a_n-1+ba_n) \right) \right)
    $$

    et que par conséquent la somme de gauche peut se calculer (plus efficacement) sans utiliser le calcul explicite des puissances de $b$.




{{ exo("Conversion en décimal",[])}}

Ecrire une fonction `to_decimal` qui prend en argument un entier `base` (compris entre 2 et 16), un tableau de **caractères** `chiffres` et sa taille `size` et renvoie l'entier dont l'écriture en base `base` corresponds aux élements du tableau `chiffres`. Par exemple si `chiffres` contient `"C","7"`  alors `to_decimal(16,chiffres,2)` doit renvoyer $12\times 16+7 = 199$.

!!! aide
    * On utilisera (bien évidemment) les caractères "A", "B", "C", "D", "E", "F" pour les chiffres situés au delà de 9.
    * On écrira une version ne calculant pas explicitement les puissances de la base (voir la troisième question de l'exercice précédent)

{{ exo("Conversion depuis la base 10",[])}}

1. la base 2
    1. Ecrire en C, une fonction `binaire` qui prend en argument un entier `n` positif compris entre 0 et 255 et renvoie un tableau de 0 et de 1 contenant son écriture binaire sur 8 bits (avec les bits de poids forts en premier). Par exemple l'appel `binaire(28)` doit renvoyer le tableau  `00011100`.

        !!! aide
            On rappelle que la méthode consiste à effectuer des divisions successives par 2 puis à lire les restes obtenus dans l'ordre inverse.

    2. Ecrire un programme `bin.exe` qui utilise cette fonction, le `main` de ce programme accepte en ligne de commande un argument `n` et affiche ensuite l'écriture binaire de `n` dans le terminal. Par exemple `./bin.exe 135` affiche `11100001`.
    
    3. Expliquer rapidement pourquoi `./bin.exe 260` affiche  `00000100`.

    

2. la base 16
    1. Ecrire en C, une fonction `hexadecimal` qui prend en argument un entier `n` positif compris entre 0 et $2^{32}-1$ et renvoie un tableau de caractères correspondant aux chiffres en base 16 de l'écriture hexadécimal de `n`.
    2. De même que pour le binaire, écrire un programme `hex.exe` qui utilise cette fonction en prenant son argument sur la ligne de commande. Par exemple `./hex.exe 212` affiche `D4`.

{{ exo("Algorithme des divisions succesives",[])}}

Le but de l'exercice est d'écrire une implémentation en langage C de l'algorithme des divisions successives qui permet de convertir un nombre écrit en base 10 dans une base $b$ quelconque ($b \geqslant 2$). Si $b>10$, on utilise comme chiffre les lettres de l'alphabet, on déclare donc en début de programme une chaine de caractères :

```c
const char* CHIFFRES="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
```


1. Ecrire une fonction de signature  `#!c int nb_chiffres(int n, int b)` qui renvoie le nombre de chiffres de `n` en base `b`.
2. Ecrire une fonction de signature `#!c char* chiffres(int n, int b)` qui renvoie les chiffres de `n` en base `b` sous la forme d'une chaine de caractères. Par exemple `chiffres(42,2)` doit renvoyer le chaine de caractères `"101010"`

    !!! aide
        On pourra procéder de la façon suivante :

        * déterminer `p` le nombre de chiffres de `n` en base `b` grâce à la fonction de la question **1.**
        * allouer dans le tas un tableau de `p+1` caractères (on prévoit le caractère sentinelle en fin de chaine).
        * remplir ce tableau avec les restes successifs des divisions de `n` par `b`

3. Ecrire une fonction main qui accepte en ligne de commande des arguments et utiliser ces arguments (après conversion) dans l'appel à la fonction `chiffres` et écrit le résultat dans le terminal. Par exemple si votre executable s'appelle `baseb.exe`, alors on pourra écrire `./baseb.exe 42 2` pour optenir comme affichage dans le terminal l'écriture en base 2 de 42 c'est à dire `101010`.

4. Tester votre fonction en affichant l'écriture en base `26` de `403642` (on rappelle qu'il y a 26 chiffres en base 26, les premiers sont `0,1, .. ,9` et après on utilise  les lettres `A, B, ...`).  
Vérfier votre réponse {{check_reponse("MP2I")}}

{{ exo("Fonction atoi",[])}}

On rappelle que la fonction `atoi` (disponible sans `stblib.h`) permet de convertir une chaine de caractère en un entier. Par exemple `atoi("42")` renvoie l'entier (`int`) `42`. Le but de l'exercice est d'écrire votre propre version de cette fonction qu'on appellera `myatoi`, pour simplifier, cette fonction *ne gèrera pas les problèmes de dépassements de capacité*, ainsi lorsque la chaine de caractère en entrée correspond à l'écriture décimale d'un entier supérieur à `INT_MAX` ou inférieur à `INT_MIN` alors le résultat est indéfini. D'autre part, la fonction traitera le *début de la chaîne* jusqu'à rencontrer un caractère autre qu'un chiffre, si aucun chiffre n'est fourni la fonction renverra `0` . Voici des exemples de comportements attendus :

* `myatoi("78")` renvoie l'entier `78`
* `myatoi("-212")` renvoie l'entier `-212`
* `myatoi("77trucs212")` renvoie l'entier `77` (on a arrêté le traitement de la chaine au `t`)
* `myatoi("MPI")` renvoie `0` (aucun chiffre)


{{ exo("Attention aux flottants !",[]) }}

1. On considère le programme suivant :

    ```C linenums="1"
        --8<-- "C4/flottant1.c"
    ```

    1. Expliquer pourquoi ce programme ne termine pas
    2. Expliquer pourquoi en modifiant la ligne 9 en `#!c x = x + 0.25` le programme termine et indiquer l'affichage obtenu.
    3. Donner une autre modification de la ligne 9 qui permettrait aussi d'avoir un programme qui termine.

2. On considère le programme suivant :

    ```C linenums="1"
        --8<-- "C4/flottant2.c"
    ```

    1. Prédire l'affichage produit par ce programme, le tester.
    2. Même question si la ligne 6 est modifiée en `#!c double big = pow(2.0,52.0);`
    3. Expliquer les résultats obtenus.

3.    1. Justifier rapidement que pour tout entier $n \geq 1$,

        $$
        \sum_{k=1}^{n} \frac{1}{k(k+1)} = 1 - \frac{1}{n+1}
        $$

        !!! aide
            On pourra remarquer que $\frac{1}{k(k+1)} = \frac{1}{k} - \frac{1}{k+1}$

    1. Ecrire un programme calculant cette somme et comparer avec le résultat exact pour $n=999999$. On utilisera le spécificateur de format `%.16f` afin d'afficher 16 chiffres significatifs lors de `printf` sur les flottants.

        !!! Warning
            Si `i` est de type entier, l'opération `1/i` est la division entière, pour une division décimal l'un des arguments au moins doit être un nombre en virgule flotttante, on peut donc (par exemple) faire `1.0/i`.

4.  1. Ecrire un programme calculant la somme des inverses des nombres entiers allant de $1$ à $10^9$.
    2. Faire de même en inversant l'ordre des calculs c'est-à-dire en commençant par ajouter les nombres de plus grands dénominateurs.
    3. Expliquer la différence entre les deux résultats obtenus (visible en utilisant le spécificateur de format `%.16f` lors de l'affichage des flottants)
    4. Lequel des deux est selon vous le plus précis ? (justifier)


{{ exo("Erreur d'arrondi",[]) }}

Le calcul en arithmétique à virgule de $0.1+0.2$ ne donne pas exactement $0.3$. Cet exercice a pour but d'expliquer cette [erreur bien connue](https://0.30000000000000004.com/){target=_blank}.

1. Donner la représentation en simple précision au format de la norme IEEE-754 des nombres suivants :
    1. $0.1$
    2. $0.2$
    3. $0.3$

2. Faire l'addition "à la main" des représentations des $0.1$ et de $0.2$

3. Comparer le résultat obtenu avec la représentation de $0.3$ et en déduire l'erreur commise

4. Ecrire un programme qui affiche le résultat de $(0.2+0.1)-0.3$

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

On rappelle qu'en [TD](./TD/TD4.pdf) (exercice 10), on a établi que cette suite converge et a pour limite 0.

1. Ecrire un programme en C, qui  affiche les $30$ premiers termes de la suite $u$. On utilisera la constante `M_E` de `math.h` comme valeur de $e$. 

2. Expliquer le résultat obtenu.

{{ exo("Convergence numérique et mathématique",[])}}

On considère la suite $(u_n)_{n \in \mathbb{N}}$ définie par :  
$\left\{ \begin{array}{ll} u_1= \dfrac{5}{4} \\ u_2 = \dfrac{7}{5} \\ u_{n+2} = 10 - \dfrac{23}{u_{n+1}} + \dfrac{14}{u_nu_{n+1}} \end{array}\right.$

On rappelle qu'en [TD](./TD/TD4.pdf) (exercice 10), on a établi que cette suite converge et on a déterminé sa limite.


1. Ecrire un programme qui affiche les 40 premiers termes de la suite $u$.
2. Expliquer le résultat obtenu.

!!! note
    Cet exercice se contente d'exhiber une suite qui converge vers 2 mais qui numériquement semble converger vers 7. On ne détaille pas le principe de constructions de telles suites, il faut bien comprendre que 2 et 7 sont choisis au hasard et qu'il est assez facile de construire une suite qui converge vers une valeur $\alpha$ alors que numériquement elle semble converger vers une valeur différente $\beta$.  
    On pourra consulter les travaux de [Jean-Michel Muller et Vicent Lefèvre](https://images.math.cnrs.fr/Erreurs-en-arithmetique-des.html){target=_blank} dont cet exemple s'inspire.


{{exo("Exercice de synthèse : constante de Kaprekar",[])}}

Etant donné un nombre $n$, on considère le processus suivant appelé [Algorithme de Kaprekar](https://fr.wikipedia.org/wiki/Algorithme_de_Kaprekar){target=_blank} d'après le nom de son inventeur le mathématicien indien [D. R. Kaprekar](https://fr.wikipedia.org/wiki/Dattatreya_Ramachandra_Kaprekar){target=_blnak} :

* former le nombre $m$ écrit avec les chiffres de $n$ dans l'ordre décroissant
* former le nombre $p$ écrit avec les chiffres de $n$ dans l'ordre croissant
* calculer la différence  $m-p$ qu'on note $k(n)$.

Par exemple en base 10, avec $n=7182$, on obtient successivement : $m=8721$, $p=1278$ et donc $k(n) = 7443$. On peut recommencer le processus avec ce nouveau nombre on trouve alors $k(7443) = 7443 - 3447 = 3996$, en itérant encore le processus on obtient $6264$ puis $4176$ et enfin $6174$ qui s'avère être un point fixe c'est à dire que $k(6174) = 6174$. Le nombre $6174$ s'appelle la constante de Kaprekar et dans cet exercice nous allons montrer que le processus aboutit toujours à cette valeur pour n'importe quel entier de 4 chiffres de départ (avec ces chiffres non tous égaux). 

Comme nous devons travailler sur les chiffres de l'entier $n$ (les extraire, les trier), on propose de représenter un nombre par le tableau de ses chiffres, il sera aussi utile de disposer du nombre de chiffres du nombre aussi on propose le type structuré suivant permettant de représenter un nombre :

```c
--8<-- "C4/kaprekar.c:8:14"
```

!!! note
    On prendra soin au fil des questions de tester les fonctions déjà écrites.

1. Ecrire une fonction de signature `#!c nombre cree_nombre(int n)` qui prend en entrée un nombre positif `n` et renvoie un struct contenant son nombre de chiffres et le tableau de ses chiffres. Par exemple `cree_nombre(1492)` doit renvoyer une variable de type `nombre` dont le champ `nb_chiffres` vaut 4 et dont le champ `chiffres` pointe sur une zone mémoire contenant les entiers `{2, 9, 4, 1}`.

2. Ecrire une fonction `#!c int valeur(nombre n)` qui effectue l'opération inverse, elle prend une variable de type `nombre` en entrée et renvoie l'entier correspondant.

3. Ecrire une fonction `#!c void libere(nombre n)` qui libère l'espace mémoire occupé par les chiffres de `n` et mets son nombre de chiffres à 0.

3. Ecrire une fonction de signature `#!c nombre copie(nombre n)` qui renvoie une copie du struct nombre donné en argument.

2. Ecrire en utilisant l'algorithme de tri de votre choix (parmi le tri par sélection, par insertion ou à bulles) une fonction `tri` de signature `void tri(uint8_t tab[], int size)` qui tri *en place* le tableau `tab` dans l'ordre croissant. On pourra s'aider d'une fonction annexe qui échange dans un tableau deux éléments dont on donne les indices.

3. Ecrire une fonction de signature `#!c nombre decroissant(nombre n)` qui prend en entrée un nombre `n` et renvoie le nombre formé par les chiffres de `n` pris dans l'ordre décroissant.

4. Ecrire une fonction de signature `#!c void retourne(uint8_t tab[], int size)` qui retourne en place les éléments du tableau `tab`.

5. En utilisant les fonctions précédentes, écrire une fonction `#!c nombre kaprekar(nombre n)` qui renvoie le nombre obtenu à partir de `n` en effectuant une itération du processus de Kaprekar. 

6. Vérifier que pour tous les entiers à 4 chiffres (non tous égaux), la répétition du processus de Kaprekar aboutit toujours au point fixe $6174$. Quel est le nombre maximal d'itérations nécessaire pour obtenir $6174$ ?

7. Parmi les nombres à 5 chiffres existe-t-il des nombres qui sont des points fixes ? 

8. Vérifier qu'il y a deux nombres qui sont des points fixes dans le cas de nombres à 6 chiffres, quel est le plus petit d'entre eux ? {{check_reponse("549945")}}


!!! note
    On peut utiliser ce processus pour des nombres écris dans n'importe quel base, par exemple en base 16 et chercher s'il existe des points fixes.

## Humour d'informaticien
![punition](./Images/C4/cpp.webp){.imgcentre width=800px}