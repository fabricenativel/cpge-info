{% set num = 16 %}
{% set niveau = "mp2i_s2"%}

{{ titre_chapitre(num,niveau)}} 

{{ citation("Contrariwise, if it was so, it might be; and if it were so, it would be; but as it isn't, it ain't. That's logic.","L. Carroll","[in Through the looking glass, 1871](https://en.wikiquote.org/wiki/Through_the_Looking-Glass)")}}


## Cours


{{ affiche_cours(num) }}

## Travaux dirigés

{{ td(num) }}

## Travaux pratiques

!!! note
    Tous les exercices sont à faire en OCaml en utilisant le type vu en cours permettant de représenter une formule logique :
    ```ocaml
    --8<-- "C16/fl.ml:1:8"
    ```
    On rappelle qu'un premier exemple de fonction `fl -> int` calculant la taille d'une formule logique a été aussi donné en cours :
    ```ocaml
    --8<-- "C16/fl.ml:18:25"
    ```
    Toujours à titre d'exemple, la variable en Ocaml permettant de représenter la formule logique $(p \wedge \neg q) \to r$ est :
    ```ocaml
    --8<-- "C16/fl.ml:16:16"
    ```



{{ exo("Hauteur d'une formule logique",[],0)}}

Ecrire une fonction `hauteur fl -> int` qui renvoie la hauteur d'une formule logique.


{{ exo("Affichage d'une formule logique",[])}}

1. Ecrire une fonction `print_formule fl -> ()` qui affiche à l'écran une formule logique, Par exemple :

    ```ocaml
        let ex = Imp (Et ((Var 1),(Non (Var 2))), (Var 3)) in
        print_formule ex;;
    ```
    Affiche à l'écran : `((p1 ∧ ¬p2) → p3)`

    !!! aide
        On pourra utiliser les symboles unicodes des formules logiques qu'on peut obtenir dans VS Code en maintenant enfoncé les touches ++ctrl++ et ++shift++ puis en tapant `u` suivi du caractère unicode.

        * pour $\top$ : `22A4`
        * pour $\bot$ : `22A5`
        * pour $\neg$ : `00AC`
        * pour $\wedge$ : `2227`
        * pour $\vee$ : `2228`
        * pour $\to$ : `2192`
        * pour $\leftrightarrow$ : `2194`

2. Modifier la fonction précédente afin qu'elle affiche les variables propositionnelles `p`, `q`, `r`, ... au lieu de `p1`, `p2`, `p3`, .... L'affiche de la formule donnée en exemple donnera alors  `((p ∧ ¬q) → r)`.

{{ exo("Valeur de vérité d'une formule logique",[])}}

On définit les valeurs de vérité avec le type `bool` de OCaml, `true` correspond à $\mathbb{1}$ et `false` à $\mathbb{0}$.

1. Ecrire les fonctions `fnon` `bool -> bool`, `fet`, `fou`, `fimp`, `fequ` toute de signature `bool -> bool -> bool` qui correspondent à la sémantique des connecteurs de la logique propositionnelle.

2. On représente une valuation par un tableau de booléens, par exemple le tableau `[| true; true; false |]` correspond à la valuation $\varphi(p_1)=\mathbb{1}$, $\varphi(p_2)=\mathbb{1}$ et $\varphi(p_3)=\mathbb{0}$. Ecrire une fonction `eval : array bool -> fl -> bool` donnant la valeur de vérité d'une formule dans le contexte de la valuation donnée par le tableau de booléen.

{{exo("Enumération des valuations",[])}}

Le but de l'exercice est d'énumérer de différentes façon les $2^n$ valuations possibles de $n$ variables propositionnelles

1. *Utilisation d'un compteur binaire* : écrire une fonction `incremente : bool array -> bool` qui ajoute 1 à la valuation donnée en argument et renvoie `true` s'il n'y a pas eu de dépassement de capacité. Dans le cas contraire, la valuation n'est pas modifiée et la fonction renvoie `false`. Par exemple si `v` est le tableau `[| true; false; true |]` alors `incremente v` renvoie `true` et modifie v en `[| true; true; false |]`.

2. *Conversion en base deux* : écrire une fonction `dec_to_bin : int -> int -> bool array` qui prend en entrée un entier positif `n` et un nombre de bits `b` et renvoie l'écriture binaire sur `b` bits de `n` sous la forme d'un tableau de `b` booléens.

3. *Utilisation des [codes de Gray](https://fr.wikipedia.org/wiki/Code_de_Gray){target=_blank}*, l'avantage de ces derniers est qu'on énumère les possibilités en changeant un *unique* caractère à chaque itération.  
L'algorithme d'énumération est le suivant :  
    * On commence par le code ne contenant que des 0
    * S'il y a un nombre pair de 1, on inverse le dernier chiffre
    * Sinon on inverse le chiffre situé à gauche du 1 le plus à droite

    On doit conserver pour chaque valuation la parité du nombre de 1 qu'il contient, pour cela on définit le type :
    ```ocaml
    type valuation = {
    t : bool array; (* le tableau de booléen *)
    mutable parite : bool (* la parité du nombre de 1*)}
    ```

    1. Ecrire une fonction `switch : valuation -> int -> unit` qui inverse l'un des bits d'un code de Gray.

    2. Ecrire une fonction `first : int -> valuation` qui renvoie le premier code de Gray (c'est-à-dire celle correspondante à toutes les variables ayant pour valeur $F$)

    3. Ecrire une fonction `next : valuation -> unit` qui met à jour la valuation en passant à la valeur suivante dans l'énumération de Gray.

        !!! aide
            Pour gérer le cas où on demande le code qui vient après le dernier code (c'est-à-dire qu'il n'y a pas de chiffre à gauche du 1 situé le plus à droite), on pourra au choix lever une exception (par exemple `Exit` est prédéfinie dans le langage) ou alors renvoyer un booléen qui indique si le code a pu être incrémenté ou non (la signature est dans ce cas `next : valuation -> bool`)

{{ exo("Construction de la table de vérité d'une formule",[])}}

Dans cet exercice, on veut écrire une fonction permettant d'afficher à l'écran la table de vérité d'une formule sur l'exemple de la formule `((p ∧ ¬q) → r)` on veut obtenir à l'écran :
```
│p│q│r│F│
├─┼─┼─┼─┤
│0│0│0│1│
│0│0│1│0│
│0│1│0│1│
│0│1│1│0│
│1│0│0│0│
│1│0│1│1│
│1│1│0│1│
│1│1│1│0│
```

On donne ci-dessous une fonction `entete` permettant d'afficher l'entête d'une table de vérité dont la liste des variables est donnée est argument :
```ocaml
    --8<-- "C16/table_verite.ml:59:69"
```

1. Ecrire une fonction `liste_var : fl -> int list` qui renvoie la liste des variables logiques utilisée dans une formule, par exemple `liste_var Imp (Et ((Var 1),(Non (Var 2))), (Var 3))` renvoie la liste `[1; 2; 3]`.

2. Ecrire une fonction `table_verite : formule -> unit` qui affiche à l'écran la table de vérité d'une formule.

3. Tester votre programme sur des formules connues ou sur celles vues en cours ou en TD.


{{exo("Satisfiabilité d'une formule",[])}}

On considère qu'une valuation est donnée sous la forme d'une tableau de booléens `bool array`. Par exemple  `[| false; true; false |]` correspond à la valuation $\varphi(p_1)=\mathbb{0}$, $\varphi(p_2)=\mathbb{1}$ et $\varphi(p_3)=\mathbb{0}$.

1. Ecrire une fonction `sat_solve : fl -> bool * bool array` qui utilise la table de vérité afin de tester si une formule est satisfiable et renvoie `true` et la valuation correspondante si la formule est satisfiable et `false` accompagné de la valuation fausse pour toutes les variables dans le cas contraire. Par exemple, pour la formule `p ∨ q` le fonction renvoie `true` et (par exemple) la valuation `[|false; true|]`.

{{exo("Equivalence de deux formules logiques",[])}}

Ecrire une fonction `sont_equiv fl -> fl -> bool` qui teste l'équivalence de deux formules logiques.

{{exo("Mise sous forme normale",[])}}

1. Ecrire une fonction `convertit: bool array -> fl` qui prend en argument un tableau de booléens représentant une valuation et la convertit en clause normale conjonctive sur ces variables par exemple `convertit [|true; false; false |]` renvoie `Et (Et (p, Non q), Non r)` (c'est à dire $p ∧ ¬q ∧ ¬r$).
2. Ecrire une fonction `fnd: fl -> fl` qui renvoie la formule logique donnée en argument sous forme normale disjonctive en utilisant la méthode "de la table de vérité"

{{exo("Implémentation de l'algorithme de quine",[])}}

Dans cet exercice, on implémente l'algorithme de Quine en supposant que les formules sont données sous forme normale conjonctive ({{sc("fnc")}}). Par exemple avec 3 variables logique $p, q$ et $r$, $P = (\neg p \vee q \vee r) \wedge (p \vee q) \wedge (p \vee q \vee \neg r)$ est sous {{sc("fnc")}}.

 On rappelle que chaque élément de la conjonction s'appelle une *clause*, par exemple $(\neg p \vee q \vee r)$ est une clause de P. Chaque clause est composé de *littéraux*, c'est-à-dire d'une variable logique ou de sa négation, on est donc amené à définir les types suivants en OCaml afin de représenter un {{sc("fnc")}} :

```ocaml
--8<-- "C16/quine.ml:2:6"
```

1. Créer la variable représentant la {{sc("fnc")}} $(p_1 \vee p2) \wedge (\neg p_2 \vee \neg p_3) \wedge (\neg p_1 \vee p_3) \wedge (p_1 \vee p_3)$

2. On donne ci-dessous une fonction permettant d'afficher une clause, en utilisant cette fonction, écrire `print_fnc -> fnc -> unit` qui affiche dans le terminal une {{sc("fnc")}}
```ocaml
--8<-- "C16/quine.ml:9:15"
```

3. Ecrire la fonction `extrait_var : fnc -> int` qui renvoie lorsqu'elle existe, la première variable de la première clause de de la {{sc("fnc")}} donnée en argument. 

5. Ecrire la fonction `substitue_fnc fnc -> int -> bool -> fnc` qui renvoie la {{sc("fnc")}} obtenue en remplaçant une variable logique par $\top$ ou $\bot$ dans toutes les clauses que contient cette {{sc("fnc")}}.

    !!! aide
        On distinguera les cas suivants :

        * Si le remplacement conduit à avoir un littéral vrai dans une clause alors cette clause est vraie et on la supprime entièrement de la  {{sc("fnc")}}
        * Si le remplacement conduit à avoir un littéral faux dans une clause alors ce littéral est supprimé entièrement de la clause
        
6. Ecrire une implémentation de l'algorithme de Quine qui renvoie un booléen indiquant si la {{sc("fnc")}} donnée en argument est satisfiable ou non.

7. Modifier la fonction précédente de façon à obtenir aussi la valuation rendant la formule satisfiable dans le cas où elle l'est.


## Humour d'informaticien

![threelogiciansjoke](./Images/C16/threelogicians.png){.imgcentre width=500px}