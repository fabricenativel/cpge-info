hide: - navigation  in index.md

{{dm(1,"Constante de Kaprekar et algorithme de Luhn")}} 

## Constante de Kaprekar

### Une conjecture

On considère un nombre $n$ à quatre chiffres et on génère un nouveau nombre noté $k(n)$ de la façon suivante :

* former un nouveau nombre $n_1$ en rangeant les chiffres de $n$ dans l'ordre décroissant ;
* former un nouveau nombre $n_2$ en rangeant les chiffres de $n$ dans l'ordre croissant ;
* le nombre $k(n)$ est égal à la différence $n_1-n_2$.

Par exemple, si $n = 1492$, alors $n_1 = 9421$, $n_2 = 1249$ et $k(1492) = 8172$.

1. Calculer $k(8172)$.
2. Calculer $k(p)$ lorsque $p$ est un nombre à 4 chiffres ayant tous ses chiffres égaux.
3. Étant donné un entier $p$ ayant 4 chiffres, on définit maintenant la suite $(u_n)_{n \in \mathbb{N}}$ par :
$\left\{ \begin{array}{ll} u_0 &= &p \\ u_{n+1} & = &k(u_n) \\ \end{array} \right.$  
Vérifier que pour $u_0 = 2023$, la suite $(u_n)_{n \in \mathbb{N}}$ prend les valeurs : $2997$, $7173$, $6354$, $3087$, $8352$, $6174$, $6174$, $6174, \dots$. 
4. Donner la suite des valeurs prises par $(u_n)_{n \in \mathbb{N}}$ lorsque $u_0 = 4691$.
5. Donner la suite obtenue en démarrant avec le nombre de votre choix.
6. Quelle conjecture peut-on faire ? (N'oubliez pas le cas évoqué à la question **2.**)

### Tri par sélection


L'algorithme du tri par sélection est un algorithme de tri qui permet de trier un tableau en place (sans créer de nouveau tableau). Il consiste à :

* rechercher le plus petit élément du tableau à partir de l'indice 0 ;
* échanger cet élément avec celui situé à l'indice 0 ;
* rechercher le plus petit élément du tableau à partir de l'indice 1 ;
* échanger cet élément avec celui situé à l'indice 1 ;
* et ainsi de suite jusqu'à atteindre la fin du tableau.

Par exemple, pour trier le tableau $\{14, 11, 7, 18, 9\}$ :

* On recherche l'indice du plus petit depuis 0 : $\{14, 11, \overset{\textcolor{red}{_\wedge^{2}}}{7}, 18, 9 \}$, c'est $2$.
* On échange les éléments d'indice 2 et 0 : $\{7,11,14,18,9\}$.
* On recherche l'indice du plus petit depuis 1 : $\{7, 11, 14, 18, \overset{\textcolor{red}{_\wedge^{4}}}{9} \}$, c'est $4$.
* On échange les éléments d'indice 4 et 1 : $\{7,9,14,18,11\}$.
* Et ainsi de suite jusqu'à atteindre la dernière case du tableau.

Le but de cette partie est de programmer cet algorithme en C.

1. Écrire une fonction `echange` qui prend en argument un tableau d'entiers `tab` et deux indices `i` et `j` et qui échange les éléments d'indices `i` et `j` de ce tableau.

    !!! note
        On pourra donner aussi en argument la taille du tableau et vérifier les préconditions portant sur `i` et `j`.

2. Écrire une fonction `indice_min_depuis` qui prend en argument un tableau d'entiers `tab`, sa taille `t` et un indice `i` et renvoie l'indice du minimum des éléments de ce tableau à partir de l'indice `i` (inclus).

3. En utilisant les deux fonctions précédentes, écrire une fonction `tri_selection` qui prend en argument un tableau `tab`, sa taille `t` et trie ce tableau en place grâce à l'algorithme du tri par sélection.

4. Proposer un jeu de tests pour cette fonction.

### Faire une itération

1. Écrire une fonction `retourne` qui prend en argument un tableau `tab` de taille `t` et retourne ce tableau. Par exemple, si `tab = {2, 7, 8, 9}`, alors après l'appel `retourne(tab, 4)`, le contenu de `tab` sera `{9, 8, 7, 2}`.

2. Écrire une fonction `valeur` qui prend en argument un tableau `tab`, sa taille `t` et renvoie l'entier dont les chiffres en base 10 sont les éléments de `tab`. Par exemple, si `tab = {2, 0, 2, 3}`, alors `valeur(tab, 4)` renvoie l'entier `2023`.

3. Compléter la fonction `kaprekar` ci-dessous qui prend en argument un entier `n` et renvoie la valeur obtenue après une itération :
``` c
int kaprekar(int n){
    int chiffres[4];
    int n1,n2;
    // Extraction des chiffres et rangement dans le tableau chiffres
    for (int i=0;i<4;i++)
    {
        chiffres[i] = n .. 10;
        n = n ... 10;
    }
    tri_selection(.......);
    n1 = valeur(.......);
    retourne(......);
    n2 = valeur(.......);
    return .....;
}
```




4. Ajouter les instructions `assert` permettant de vérifier les préconditions sur `n`, c'est-à-dire que $n \in \left[\!\left[0;9999\right]\!\right]$ et n'a pas tous ses chiffres égaux.

### Preuve numérique de la conjecture

1. Vérifier, grâce à un programme en C, la conjecture établie dans la première partie.
2. Donner le nombre maximal d'itérations nécessaires avant d'obtenir $6174$.
3. Donner une valeur de départ pour laquelle ce maximum d'itérations est atteint.

## Algorithme de Luhn


L'[algorithme de Luhn](https://fr.wikipedia.org/wiki/Formule_de_Luhn), du nom de son inventeur 
[Hans Peter Luhn](https://fr.wikipedia.org/wiki/Hans_Peter_Luhn){.target =_blank} est célèbre car il est notamment utilisé pour vérifier qu'un numéro de carte de crédit est valide. Pour valider un numéro donné, on calcule à partir de ses chiffres une valeur appelée *somme de contrôle*. Si cette valeur est divisible par 10, alors le numéro est valide.

Le but de l'exercice est de mettre en œuvre cet algorithme puis de le tester. 

### Une fonction annexe 

1. On commence par écrire une fonction annexe qui sera utile dans le calcul de la somme de contrôle. Écrire une fonction de signature `#!c int mult2(int c)` qui prend en entrée un entier naturel $c$ tel que $0\leqslant c \leqslant 9$ et renvoie $2c$ lorsque $0\leqslant 2c \leqslant 9$ et la somme des deux chiffres de $2c$ sinon. On vérifiera les préconditions à l'aide d'instructions `#!c assert`.

2. Pour vérifier que la fonction `mult2` est totalement correcte, dix tests suffisent : lesquels et pourquoi ? Écrire ces dix tests sous forme d'instructions `#!c assert`.

### Validation d'un numéro

Le calcul de la somme de contrôle consiste à faire la somme des chiffres du numéro à tester en utilisant au préalable la fonction `mult2` sur les chiffres dont le rang est pair (c'est-à-dire en partant de la fin du nombre, le 2e chiffre, le 4e, ...). Par exemple :

* pour `267`, on doit faire `2 + mult2(6) + 7`, ce qui donne `2+3+7 = 12`.
* pour `15782`, on doit faire la somme `1 + mult2(5) + 7 + mult2(8) + 2`, ce qui donne : `1+1+7+7+2 = 18`.
* pour `124586`, on doit faire la somme `mult2(1) + 2 + mult2(4) + 5 + mult2(8) + 6`, ce qui donne : `2+2+8+5+7+6 = 30`.

On rappelle que le numéro est valide lorsque cette somme de contrôle est divisible par 10. Ainsi, parmi les trois exemples précédents, seul le dernier est un numéro valide.

3. Vérifier (à la main) que le numéro `4762` est valide, mais pas le numéro `5438`.

4. Écrire une fonction de signature `#!c bool valide(int n)` qui prend en entrée un numéro `n` et renvoie un booléen indiquant si ce numéro est valide.

    !!! aide
        On rappelle que `n%10` permet d'obtenir le dernier chiffre d'un nombre écrit en base 10.

### Tests

On donne ci-dessous la définition en C d'un tableau de 100 numéros dont un seul n'est pas valide :

```c
int numeros[100] = {42893834, 469308860, 816927776, 146369152, 577477938, 242383354, 198853863, 497604926, 965166499, 896414216, 252023627, 504900275, 833686900, 25200593, 448977637, 675139265, 651805400, 403834260, 40891723, 34557363, 350052114, 215953688, 947025672, 269564290, 364657825, 610215303, 787228626, 336651237, 451740674, 687031351, 15139298, 19798024, 156340226, 357230580, 691330690, 258981679, 599613932, 890184567, 281750117, 564780427, 311762298, 533773735, 594844219, 145449195, 84137843, 568985378, 345751986, 735943243, 497983155, 386643704, 295664130, 848035267, 127760916, 242689800, 117599563, 492418736, 378068621, 429991706, 829069962, 354972812, 117023051, 844209254, 374770840, 273363275, 726603368, 591265053, 57508467, 326217296, 6613137, 339258576, 416161248, 843538950, 398195826, 11005451, 988988143, 482333671, 105154348, 859903643, 743440430, 603137506, 771710878, 564268084, 451172761, 899471783, 806957882, 93935849, 917054033, 185026515, 523927549, 746123991, 539999326, 640950606, 115496762, 439933680, 439477399, 842100126, 556362267, 496985862, 693480949, 562975391, };
```

1. Déterminer à l'aide d'un programme utilisant la fonction de validation lequel de ces numéros est invalide.
Tester votre réponse : {{check_reponse("842100126")}}

2. Écrire une fonction qui prend en entrée un tableau d'entiers et renvoie le nombre de numéros valides dans ce tableau. Par exemple, sur le tableau `numeros` de 100 entiers donné en exemple, cette fonction doit renvoyer 99 puisqu'un seul numéro est invalide.

3. Dans la fonction `main` de votre programme, initialiser le générateur de nombres aléatoires avec la valeur **42** (on rappelle qu'il faut écrire `#!c srand(42)`). Puis générer un tableau de 10000 nombres aléatoires inférieurs à `100000000` (avec `#!c rand() % 100000000`) et, en utilisant la fonction écrite à la question précédente, déterminer le nombre de numéros valides dans le tableau. Tester votre réponse : {{check_reponse("949")}}

### Compléter un numéro valide

1. Écrire une fonction qui prend en entrée un entier `n` et détermine quel chiffre ajouter à droite de ce nombre de façon à ce que le nombre ainsi formé soit un numéro valide. Par exemple, pour 732, cette fonction renvoie 8 car le nombre 7328 est valide : `mult2(7) + 3 + mult2(2) + 8 = 5 + 3 + 4 + 8 = 20`.