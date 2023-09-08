hide: - navigation  in index.md

{{dm(1,"Constante de Kaprekar")}} 

!!! danger "Récupération du devoir"
    * La totalité du devoir est à rendre sous la forme d'un seul et unique fichier `dm1.c` que vous compléterez au fil des questions. Ce fichier vous a déjà été distribué et se trouve dans *votre répertoire personnel* du lycée. Vous pouvez y  accéder depuis un ordinateur du lycée ou depuis l'{{sc("ent")}} grâce à  l'application Nextcloud.
    * Votre fichier `dm1.c` complété devra être enregistré dans votre répertoire personnel du lycée et sera automatiquement ramassé à la date convenue.


## Partie I : une conjecture

On considère un nombre $n$ à quatre chiffres et on génère un nouveau nombre noté $k(n)$ de la façon suivante :

* former un nouveau nombre $n_1$ en rangeant les chiffres de $n$ dans l'ordre décroissant
* former un nouveau nombre $n_2$ en rangeant les chiffres de $n$ dans l'ordre croissant
* le nombre $k(n)$ est égal à la différence $n_1-n_2$

Par exemple si $n = 1492$ alors $n_1 = 9421$, $n_2 = 1249$ et  $k(1492) = 8172$.

1. Calculer $k(8172)$
2. Calculer $k(p)$ lorsque $p$ est un nombre à 4 chiffres ayant tous ses chiffres égaux.
3. Etant donné un entier $p$ ayant 4 chiffres, on définit maintenant la suite $(u_n)_{n \in \mathbb{N}}$ par :
$\left\{ \begin{array}{ll} u_0 &= &p \\ u_{n+1} & = &k(u_n) \\ \end{array} \right.$  
Vérifier que pour $u_0 = 2023$, la suite $(u_n)_{n \in \mathbb{N}}$ prend les valeurs : $2997$, $7173$, $6354$, $3087$, $8352$, $6174$, $6174$, $6174 \dots$ . 
4. Donner la suite des valeurs prises par $(u_n)_{n \in \mathbb{N}}$ lorsque $u_0 = 4691$ 
5. Donner la suite obtenue en démarrant avec le nombre de votre choix.
6. Quelle conjecture peut-on faire ? (n'oublier pas le cas évoqué à la question **2.**)

## Partie II : tri par sélection


!!! aide 
     * En cas de difficultés pour cette partie, pour ne pas rester bloqué, on pourra utiliser le [tri par insertion](https://fabricenativel.github.io/cpge-info/mp2i/introC/#exercice-11-tri-par-insertion) déjà vu et corrigé en TP.
     * D'autre part, compte tenu de notre avancée dans l'apprentissage du C, on s'interdit pour l'instant d'écrire des fonctions qui renvoient un tableau. On peut par contre, comme cela a été vu en cours, écrire des fonctions prenant un tableau (et donc sa taille) en argument.
    

L'algorithme du tri par sélection est un algorithme de tri qui permet de trier un tableau en place (sans créer de nouveau tableau), il consiste à :

* rechercher le plus petit élément du tableau à partir de l'indice 0
* échanger cet élément avec celui situé à l'indice 0
* rechercher le plus petit élément du tableau à partir de l'indice 1
* échanger cet élément avec celui situé à l'indice 1
* et ainsi de suite jusqu'à atteindre la fin du tableau

Par exemple pour trier le tableau $\{14, 11, 7, 18, 9\}$ :

* On recherche l'indice du plus petit depuis 0 : $\{14, 11, \overset{\textcolor{red}{_\wedge^{2}}}{7}, 18, 9 \}$, c'est $2$.
* on échange les éléments d'indice 2 et 0 : $\{7,11,14,18,9\}$
* On recherche l'indice du plus petit depuis 1 : $\{7, 11, 14 , 18, \overset{\textcolor{red}{_\wedge^{4}}}{9} \}$, c'est $4$.
* on échange les éléments d'indice 4 et 1 : $\{7,9,14,18,11\}$
* et ainsi de suite jusqu'à atteindre la dernière case du tableau

Le but de cette partie est de programmer cet algorithme en C.

1. Ecrire une fonction `echange` qui prend en argument un tableau d'entiers `tab` et deux indices `i` et `j` et qui échange les éléments d'indices `i` et `j` de ce tableau.

    !!! note
        On pourra donner aussi en argument la taille du tableau et vérifier les préconditions portant sur `i` et `j`.

2. Ecrire une fonction `indice_min_depuis` qui prend en argument un tableau d'entiers `tab`, sa taille `t` et un indice `i` et renvoie l'indice du minimum des éléments de ce tableau à partir de l'indice `i` (inclus).

3. En utilisant les deux fonctions précédentes, écrire une fonction `tri_selection` qui prend en argument un tableau `tab`, sa taille `t` et trie ce tableau en place grâce à l'algorithme du tri par sélection

4. Proposer un jeu de tests pour cette fonction.

## Partie III : Faire une itération

1. Ecrire une fonction `retourne` qui prend en argument deux tableau `tab`, et `rtab` de même taille `t` et rempli `rtab` avec le contenu de `tab` dans l'ordre inverse . Par exemple si `tab = { 2, 7, 8, 9}` alors après l'appel `retourne(tab,rtab, 4)`, le contenu de `rtab` sera `{ 9, 8, 7, 2}`.

2. Ecrire une fonction `valeur` qui prend en argument un tableau `tab`, sa taille `t` et l'entier dont les chiffres en base 10 sont les éléments de `tab`, par exemple si `tab = {2, 0, 2, 3}` alors `valeur(tab,4)` renvoie l'entier `2023`.

3. Compléter la fonction `kaprekar` ci-dessous qui prend en argument un entier `n` et renvoie la valeur obtenu après une itération 
``` c
int kaprekar(int n){
    int chiffres[4];
    int m1,m2;
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




4. Ajouter les instructions `assert` permettant de vérifier les préconditions  sur `n`, c'est à dire que $n \in \left[\!\left[0;9999\right]\!\right]$ et n'a pas tous ces chiffres égaux.

## Partie IV : Preuve numérique de la conjecture

1. Vérifier, grâce à un programme en C, la conjecture établie dans la première partie.
2. Donner le nombre maximal d'itérations nécessaire avant d'obtenir $6174$ et indiquer pour quelle(s) valeur(s) de départ il est atteint.

