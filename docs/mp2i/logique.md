{% set num = 16 %}
{% set niveau = "mp2i_s2"%}

{{ titre_chapitre(num,niveau)}} 

{{ citation("Contrariwise, if it was so, it might be; and if it were so, it would be; but as it isn't, it ain't. That's logic.","L. Carroll","[in Through the looking glass, 1871](https://en.wikiquote.org/wiki/Through_the_Looking-Glass)")}}


## Cours


{{ cours(num) }}

## Travaux dirigés

{{ td(num) }}

## Travaux pratiques

!!! note
    Tous les exercices sont à faire en OCaml en utilisant le type vu en cours permettant de représenter une formule logique :
    ```ocaml
        --8<-- "C16/fl.ml:1:9"
    ```
    On rappelle qu'un premier exemple de fonction `fl -> int` calculant la taille d'une formule logique a été aussi donné en cours :
    ```ocaml
        --8<-- "C16/fl.ml:19:26"
    ```
    Toujours à titre d'exemple, la variable en Ocaml permettant de représenter la formule logique $(p \wedge \neg q) \to r$ est :
    ```ocaml
        --8<-- "C16/fl.ml:17:17"
    ```


{{ exo("Hauteur d'une formule logique",[],0)}}

Ecrire une fonction `hauteur fl -> int` qui renvoie la hauteur d'une formule logique.

{{ exo("Affichage d'une formule logique",[])}}

Ecrire une fonction `print_formule fl -> ()` qui affiche à l'écran une formule logique, Par exemple :

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


{{ exo("Valeur de vérité d'une formule logique",[])}}

On définit les valeurs de vérité avec le type `bool` de OCaml, `true` correspond à $V$ et `false` à $F$.

1. Ecrire les fonctions `fnon` `bool -> bool`, `fet`, `fou`, `fimp`, `fequ` toute de signature `bool -> bool -> bool` qui correspondent à la sémantique des connecteurs de la logique propositionnelle.

2. On représente une valuation par un tableau de booléens, par exemple le tableau `[| true; true; false |]` correspond à la valuation $\varphi(p_1)=V$, $\varphi(p_2)=V$ et $\varphi(p_3)=V$. Ecrire une fonction `eval : array bool -> fl -> bool` donnant la valeur de vérité d'une formule dans le contexte de la valuation donnée par le tableau de booléen.

3. Code de Gray  
Afin d'énumérer toutes les valuation possibles de $n$ variables logiques, on pourrait utiliser un compteur binaire. Une autre solution consiste à utiliser les [codes de Gray](https://fr.wikipedia.org/wiki/Code_de_Gray){target=_blank}. L'avantage de ces derniers est qu'on énumère les possibilités en changeant un *unique* caractère à chaque itération.  
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

    2. Ecrire une fonction `first : int -> valuation` qui renvoie le premier code de Gray (c'est à dire celle correspondante à toutes les variables ayant pour valeur $F$)

    3. Ecrire une fonction `next : valuation -> unit` qui met à jour la valuation en passant à la valeur suivante dans l'énumération de Gray.

        !!! aide
            Pour gérer le cas où on demande le code qui vient après le dernier code (c'est à dire qu'il n'y a pas de chiffre à gauche du 1 situé le plus à droite), on pourra au choix lever une exception (par exemple `Exit` est prédéfinie dans le langage) ou alors renvoyer un booléen qui indique si le code a pu être incrémenté ou non (la signature est dans ce cas `next : valuation -> bool`)

    4. Ecrire une fonction `affiche : valuation -> unit` permettant d'afficher une valuation par exemple sous la forme `0; 1; 0; 0`

4. Table de vérité  
On veut maintenant construire la table de vérité d'une formule

    1. Ecrire une fonction `max_var : fl -> unit` qui renvoie le plus grand numéro de variable utilisé dans une formule.

    2. Ecrire une fonction `table_verite : formule -> unit` qui affiche à l'écran la table de vérité d'une formule.

    3. Tester votre programme sur des formules connues ou sur celles vues en cours ou en TD.

5. Applications

    1. Proposer une fonction `sat_solve : formule -> bool * valuation` qui teste si une formule est satisfiable et renvoie `true` et la valuation correspondante si la formule est satisfiable et `false` accompagné de la valuation fausse pour toutes les variables dans le cas contraire.

    2. Ecrire une fonction `sont_equiv formule -> formule -> bool` qui teste l'équivalence de deux formules logiques.


{{exo("Implémentation de l'algorithme de quine",[])}}

Dans cet exercice, on implémente l'algorithme de Quine en supposant que les formules sont données sous forme normale conjonctive ({{sc("fnc")}}). Par exemple avec 3 variables logique $p, q$ et $r$, $P = (\neg p \vee q \vee r) \wedge (p \vee q) \wedge (p \vee q \vee \neg r)$ est sous {{sc("fnc")}}.

 On rappelle que chaque élément de la conjonction s'appelle une *clause*, par exemple $(\neg p \vee q \vee r)$ est une clause de P. Chaque clause est composé de *littéraux*, c'est à dire d'une variable logique ou de sa négation, on est donc amené à définir les types suivants en OCaml afin de représenter un {{sc("fnc")}} :

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