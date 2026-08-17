hide: - navigation  in index.md

{{dm(3,"Ensemble d'entiers - Terminaison - Pile")}} 

## Exercice 1 : Ensemble d'entiers

Première partie du sujet zéro de {{sc("ccmp")}} à télécharger ci-dessous :

{{telecharger("Exercice 1","./ExtraitS0_MPI.pdf")}}

!!! note "Remarques"
    * Le maillon de tête ne change *jamais* car une liste est toujours "encadrée" par les deux valeurs extrêmes `INT_MIN` et `INT_MAX`.  On n'a donc *pas* besoin de passer par référence l'adresse du pointeur de tête ("pas de `**`") 
    * Il faut bien avoir compris la spécification de la fonction de localisation : le champ donnée du maillon renvoyé est *strictement* inférieur à la valeur cherchée et le maillon suivant n'a pas cette propriété (son champ donnée est supérieur ou égal à la valeur cherchée).
    * Habituellement on nomme le `struct` avec le suffixe `_s`, dans cet énoncé le struct n'a pas de suffixe et c'est le type qui porte le suffixe `_t`.

1. Fonction `init`

    ??? Question "Corrigé"
        ```c linenums="1"
        --8<-- "DM3/mp-zero.c:Q1"
        ```

2. Fonction de localisation

    ??? Question "Corrigé"
        ```c linenums="1"
        --8<-- "DM3/mp-zero.c:Q2"
        ```

3. Jeu de données de test

    * Insertion dans une liste ne contenant pas encore l'élément 

        * état initial
        ```mermaid
        graph LR
            Start[-∞] --> A[ -4]
            A --> B[ 2]
            B --> C[ 3]
            C --> D[ 7]
            D --> End[+∞]
        ```
        * on insère 5, la fonction renvoie `true`
        * état final
        ```mermaid
        graph LR
            Start[-∞] --> A[ -4]
            A --> B[ 2]
            B --> C[ 3]
            C --> D[ 5]
            D --> E[ 7]
            E --> End[+∞]
        ```

    * Insertion dans une liste contenant déjà l'élément 

        * état initial
        ```mermaid
        graph LR
            Start[-∞] --> A[ -4]
            A --> B[ 2]
            B --> C[ 3]
            C --> D[ 7]
            D --> End[+∞]
        ```
        * on insère 3, la fonction renvoie `false`
        * état final
        ```mermaid
        graph LR
            Start[-∞] --> A[ -4]
            A --> B[ 2]
            B --> C[ 3]
            C --> D[ 7]
            D --> End[+∞]
        ```

4. A la ligne `7` du code proposé : `#!c maillon_t *p = localise(&t, v);`, on passe en argument l'adresse de `t` qui est de type pointeur sur maillon, on passe donc l'adresse de l'adresse d'un maillon alors que la fonction localise attend simplement un pointeur sur un maillon. On propose de corriger cette ligne en `#!c maillon_t *p = localise(t, v);`

5. La fonction `insere_erronne` ne traite pas le cas où l'élément à inséré est déjà présent dans la liste. D'autre part on pourrait aussi tester que la fonction `malloc` n'échoue pas. On propose la version corrigée suivante :

    ??? Question "Corrigé"
        ```c linenums="1"
        --8<-- "DM3/mp-zero.c:Q5"
        ```

6. Fonction de suppression d'un maillon

    ??? Question "Corrigé"
        ```c linenums="1"
        --8<-- "DM3/mp-zero.c:Q6"
        ```

7. Les fonction `insere` et `supprime` n'effectuent que des opérations élémentaires mais elles utilisent la fonction `localise` qui parcourt les éléments de la liste (jusqu'à trouver l'emplacement cherché), cette fonction a une complexité linéaire en fonction de la taille de la liste. Donc `insere` et `supprimer` ont une complexité en $\mathcal{O}(n)$ où $n$ est le nombre d'éléments de la liste.

8. Un programme C peut stocker ses données dans :

    * la pile , 
    * le tas (allocation dynamique par le programmeur), 
    * le segment des données statiques

    Dans le programme fourni, 

    * `#!c int v = 717` déclare une variable globale qui sera stocké dans le segment des *données statiques*
    * Cette valeur est utilisée à la ligne 17 comme paramètre de la fonction `insere` elle est donc stockée dans la pile lors de l'appel à `insere`
    * La fonction `insere` va allouer dynamiquement de la mémoire dans le tas pour le nouveau maillon, donc la valeur `717` sera aussi stocké dans le tas.

## Exercice 2 : Terminaison d'une fonction 

Montrer la terminaison de la fonction ci-dessous pour tout $n \in \mathbb{N}^*$ :

```ocaml
--8<-- "DM3/term.ml"
```

??? Question "Correction"
    
    Si $n \leq 2$ alors la fonction termine en moins de deux appels récursifs. Supposons maintenant que $n>2$ et montrons que les valeurs prises par $n$ lors des appels récursifs de *rang pair* est un variant. On note $n'$ (resp. $n''$) la valeur de $n$ après le premier (resp. le second) appel récursif.

    * Si $n$ est pair, on note $n=2k$ (k>1) et donc $n'=k$ puis,
        * si $k$ est pair alors $n'' = \frac{k}{2}$ et donc $n < n''$. 
        * sinon, $n'' = k+1$ , puisque $k>1$, $2k>k+1$ et on a encore $n > n''$.
    * Si $n$ est impaire, on note $n=2k+1$ (k>1) et donc $n'=2k+2$, $n'$ est donc nécessairement pair et donc $n'' = k+1$,
        on obtient encore $n>n''$.

    Les valeurs prises par $n$ lors des appels récursifs de rang pair sont donc strictement décroissantes comme de plus $n \in \mathbb{N}$, c'est un variant et donc cette fonction termine.

## Exercice 3 : Pile

1. Résoudre [l'exercice 10 du chapitre 8](https://fabricenativel.github.io/cpge-info/mp2i/sl/#exercice-10-mot-mystere) en utilisant OCaml

    ??? Question "Corrigé"
        On suit l'indication, et on utilise une pile, on parcourt un à un les caractères :

        * si on rencontre un caractère identique à celui situé au sommet de la pile, alors on dépile.
        * sinon on empile ce caractère.

        ```ocaml
        --8<-- "DM3/mystere.ml"
        ```

2. Même question en langage C

    ??? Question "Corrigé"
        On utilise une implémentation des piles avec une liste chainée
        ```c
        --8<-- "DM3/mystere.c"
        ```
