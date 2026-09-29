hide: - navigation  in index.md

{{dm(1,"Constante de Kaprekar")}} 



## Partie I : une conjecture

1. Calculer $k(8172)$

    ??? Question "Corrigé"
        $k(8172) = 8721 - 1278$  
        $k(8172) = 7443$  

2. Calculer $k(p)$ lorsque $p$ est un nombre à 4 chiffres ayant tous ses chiffres égaux.

    ??? Question "Corrigé"
        Si tous les chiffres de l'entier $n$ sont égaux alors les deux nombres $n_1$ et $n_2$ sont égaux et donc $k(n)=0$.

3. Etant donné un entier $p$ ayant 4 chiffres, on définit maintenant la suite $(u_n)_{n \in \mathbb{N}}$ par :
$\left\{ \begin{array}{ll} u_0 &= &p \\ u_{n+1} & = &k(u_n) \\ \end{array} \right.$  
Vérifier que pour $u_0 = 2023$, la suite $(u_n)_{n \in \mathbb{N}}$ prend les valeurs : $2997$, $7173$, $6354$, $3087$, $8352$, $6174$, $6174$, $6174 \dots$ . 

    ??? Question "Corrigé"
        On calcule successivement :

        *  $u_1 = k(2023)$  
           $u_1 = 3220 - 223$  
           $u_1 = 2997$
        *  $u_2 = k(2997)$  
           $u_2 = 9972 - 2799$  
           $u_2 = 7173$
        *  $u_3 = k(7173)$  
           $u_3 = 7731 - 1377$  
           $u_3 = 6354$
        *  $u_4 = k(6354)$  
           $u_4 = 6543 - 3456$  
           $u_4 = 3087$
        *  $u_5 = k(3087)$  
           $u_5 = 8730 - 378$  
           $u_5 = 8352$
        *  $u_6 = k(8352)$  
           $u_6 = 8532 - 2358$  
           $u_6 = 6174$
        *  $u_7 = k(6174)$  
           $u_7 = 7641 - 1467$  
           $u_7 = 6174$
        
        A partir du rang 6, la suite est donc constante égale à 6174.

4. Donner la suite des valeurs prises par $(u_n)_{n \in \mathbb{N}}$ lorsque $u_0 = 4691$ 

    ??? Question "Corrigé"
        A partir de 4691, on obtient successivement les valeurs 8172, 7443, 3996, 6264, 4176, 6174, 6174 $\dots$.
        Donc comme précédemment, à partir d'un certain rang la suite est constante et vaut 6174.

5. Donner la suite obtenue en démarrant avec le nombre de votre choix.

    ??? Question "Corrigé"
        A partir de 1515, on obtient successivement les valeurs 4356, 3087, 8352, 6174, 6174 $\dots$.
        Donc comme précédemment, à partir d'un certain rang la suite est constante et vaut 6174.

6. Quelle conjecture peut-on faire ? (n'oublier pas le cas évoqué à la question **2.**)

    ??? Question "Corrigé"
        On conjecture donc que lorsque $p$ n'a pas tous ses chiffres égaux la suite $(u_n)_{n \in \mathbb{N}}$ définie ci-dessus est constante égale à $6174$ à partir d'un certain rang.

## Partie II : tri par sélection

1. Ecrire une fonction `echange` qui prend en argument un tableau d'entiers `tab` et deux indices `i` et `j` et qui échange les éléments d'indices `i` et `j` de ce tableau.

    ??? langageC "Correction"
        ```c
            --8<-- "DM1/kaprekar.c:7:14"
        ```


2. Ecrire une fonction `indice_min_depuis` qui prend en argument un tableau d'entiers `tab`, sa taille `t` et un indice `i` et renvoie l'indice du minimum des éléments de ce tableau à partir de l'indice `i` (inclus).

    ??? langageC "Correction"
        ```c
            --8<-- "DM1/kaprekar.c:16:30"
        ```

3. En utilisant les deux fonctions précédentes, écrire une fonction `tri_selection` qui prend en argument un tableau `tab`, sa taille `t` et trie ce tableau en place grâce à l'algorithme du tri par sélection

    ??? langageC "Correction"
        ```c
            --8<-- "DM1/kaprekar.c:32:39"
        ```

4. Proposer un jeu de tests pour cette fonction.

    ??? Question "Corrigé"
        Bien évidemment, on aura testé en amont les fonctions annexes (`echange` et `min_depuis`) puisque le tri en dépend. Pour le tri en lui-même, on pourra tester :

        * des tableaux contenant des valeurs positives et négatives
        * des tableaux contenant plusieurs fois la même valeur
        * un tableau à un seul ou deux éléments

## Partie III : Faire une itération

1. Ecrire une fonction `retourne` qui prend en argument un tableau `tab`, de taille `t` et retourne ce tableau . Par exemple si `tab = { 2, 7, 8, 9}` alors après l'appel `retourne(tab, 4)`, le contenu de `tab` sera `{ 9, 8, 7, 2}`.

    ??? langageC "Correction"
        ```c
            --8<-- "DM1/kaprekar.c:42:49"
        ```

2. Ecrire une fonction `valeur` qui prend en argument un tableau `tab`, sa taille `t` et l'entier dont les chiffres en base 10 sont les éléments de `tab`, par exemple si `tab = {2, 0, 2, 3}` alors `valeur(tab,4)` renvoie l'entier `2023`.

    ??? langageC "Correction"
        ```c
            --8<-- "DM1/kaprekar.c:52:63"
        ```

3. Compléter la fonction `kaprekar` ci-dessous qui prend en argument un entier `n` et renvoie la valeur obtenu après une itération 

    ??? langageC "Correction"
        ```c
            --8<-- "DM1/kaprekar.c:65:79"
        ```

4. Ajouter les instructions `assert` permettant de vérifier les préconditions suivantes sur `n`, c'est-à-dire que $n \in \left[\!\left[0;9999\right]\!\right]$ et n'a pas tous ces chiffres égaux.

    ??? Question "Corrigé"
        Pour tester que $n$ n'a pas tous ces chiffres égaux, on vérifie simplement qu'il n'est pas divisible par $1111$ (puisque c'est un nombre à 4 chiffres). L'instruction est : 
        ```c
            assert (n>0 && n<10000 && n%1111!=0);
        ```




## Partie IV : Preuve numérique de la conjecture

1. Vérifier, grâce à un programme en C, la conjecture établie dans la première partie
    
    ??? langageC "Correction"
        ```c
            --8<-- "DM1/kaprekar.c:82:109"
        ```

2. Donner le nombre maximal d'itérations nécessaire avant d'obtenir $6174$ 

    ??? Question "Corrigé"
        Le programme indique que le nombre d'itérations maximal est 7.

3. Donner une valeur de départ pour laquelle ce maximum d'itération est atteint.

    ??? Question "Corrigé"
        Une des valeurs pour laquelle ce maximum d'itérations est atteint est 9985.

    

