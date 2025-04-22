{% set num = 17 %}
{% set niveau = "mp2i_s2"%}

{{ titre_chapitre(num,niveau)}}

{{ citation("Bad programmers worry about the code. Good programmers worry about data structures and their relationships.
","L. Torvalds","[lwn.net](https://lwn.net/Articles/193245/)") }}

## Cours

{{ affiche_cours(num) }}

## Travaux dirigés

{{ td(num) }}


## Travaux pratiques

{{ exo("Matrice d'adjacence en C",[],0)}}

Dans cet exercice, on s'intéresse à la représentation par matrice d'adjacence en C, on rappelle la structure de données vue en cours :

!!! langageC "Définition de la structure de données"
    ```c
    --8<-- "C17/madj_stat.c:struct"
    ```

1. Ecrire une fonction d’initialisation de prototype `#!c void init_graphe(graphe g, int size)` qui initialise un graphe de taille `size` en remplissant la matrice avec des valeurs `false`

2. Ecrire une fonction de création d'un arc dans un graphe de prototype `#!c void cree_arete(graphe g, int i, int j)` qui permet de créer une arête de entre les sommets `i` et `j`

3. On donne ci-dessous une fonction permettant de visualiser un graphe :

    ??? langageC "Fonction de visualisation"
        ```c
        --8<-- "C17/madj_stat.c:visualise"
        ```
    Créer et visualiser le graphe suivant :
    ```mermaid
    graph LR
    A(("0"))
    B(("1"))
    C(("2"))
    D(("3"))
    E(("4"))
    F(("5"))
    G(("6"))
    A --- B
    A --- C
    B --- D
    C --- F
    C --- G
    E --- G
    A --- E
    D --- F
    G --- F
    B --- C
    ```

4. Ecrire une fonction qui renvoie le degré d'un sommet dans un graphe

5. Ecrire une fonction qui renvoie un tableau de dimension `NMAX`, contenant les voisins d'un sommet `i` ce tableau contiendra une sentinelle `-1` indiquant la fin de la liste des sommets. Par exemple, sur le graphe représenté ci-dessus pour le sommet `0`, la fonction renvoie un tableau de taille `NMAX` dont les quatre premiers éléments sont `1,2,4` et `-1`.

6. Ecrire une fonction `complet` qui prend un graphe et sa taille effective en argument et ajoute tous les arcs possibles dans ce graphe. 

7. Ecrire une fonction `cycle` qui prend un graphe et sa taille effective en argument et en fait un [graphe cycle](https://fr.wikipedia.org/wiki/Graphe_cycle){target=_blank}


{{ exo("Matrice d'adjacence en OCaml",[])}}

Reprendre l'exercice précédent en OCaml en utilisant la structure de données vue en cours et rappelée ci-dessous :
!!! ocaml "Définition de la structure de données"
    ```ocaml
    --8<-- "C17/madj.ml:struct"
    ```

La fonction de visualisation pour OCaml est donnée ci-dessous :
??? ocaml "Fonction de visualisation"
    ```ocaml
    --8<-- "C17/madj.ml:10:23"
    ```

Pour la question **5.**, on pourra renvoyer la liste des sommets et pas un tableau.

{{ exo("Matrice d'adjacence dynamique linéarisée en C",[])}}

Reprendre l'exercice 1 en C en utilisant la structure de données d'une matrice linéarisée allouée en mémoire lorsque la taille est connue :
!!! langageC "Définition de la structure de données"
    ```c
    --8<-- "C17/madj_dyn.c:struct"
    ```
On rappelle qu'avec cette structure, il devient inutile de passer la taille du graphe en argument puisqu'on y accède directement via le champe `taille`.

!!! aide    
    Pour rappel :

    * La valeur de $M_{ij}$ se situe à l'indice $i \times |S| + j$ dans la matrice linéarisée
    * L'indice $k$ dans la matrice linéarisée correspond à la ligne $\left\lfloor \dfrac{k}{|S|} \right\rfloor$ et à la colonne $k \mod |S|$ de la matrice d'adjacence

On donne la fonction de visualisation adaptée à cette nouvelle structure
??? langageC "Fonction de visualisation"
    ```c
    --8<-- "C17/madj_dyn.c:visualise"
    ```

{{ exo("Listes d'adjacence en C",[])}}

On rappelle la structure de données vues en cours permettant de représenter un graphe par ses listes d'adjacence en C :
!!! langageC "Définition de la structure de données"
    ```c
    --8<-- "C17/ladj_stat.c:struct"
    ```

!!! warning "Attention"
    On rappelle que dans cette représentation la première colonne est le degré du sommet (et pas un numéro de sommet adjacent)
    A titre d'exemple, le graphe
    ```mermaid
    graph LR
    A(("0"))
    B(("1"))
    C(("2"))
    D(("3"))
    A --- B
    A --- C
    A --- D
    B --- C
    ```
    est représenté par le tableau d'entiers  $\begin{pmatrix}
    3 & 1 & 2 & 3 \\
    2 & 0 & 2 &  .\\
    2 & 0 & 1 & . \\
    1 & 0 & . & . \\
    \end{pmatrix}$ où `.` indique une valeur non utilisée du tableau.
    
1. Ecrire une fonction d’initialisation de prototype `#!c void init_graphe(graphe g, int size)` qui initialise un graphe de taille `size` en affectant le degré 0 à tous les noeuds.

2. Ecrire une fonction de création d'un arc dans un graphe de prototype `#!c void cree_arete(graphe g, int i, int j)` qui permet de créer une arête de entre les sommets `i` et `j`

3. On donne ci-dessous une fonction permettant de visualiser un graphe :

    ??? langageC "Fonction de visualisation"
        ```c
        --8<-- "C17/ladj_stat.c:visualise"
        ```
    Créer et visualiser le graphe suivant :
    ```mermaid
    graph LR
    A(("A"))
    B(("B"))
    C(("C"))
    D(("D"))
    E(("E"))
    F(("F"))
    G(("G"))
    A --- B
    A --- C
    G --- E
    C --- D
    D --- F
    B --- E
    E --- F
    A --- G
    ```

3. Ecrire une fonction qui affiche la matrice d'adjacence du graphe.

4. Ecrire une fonction qui renvoie le degré d'un sommet dans un graphe

5. Ecrire une fonction `existe` de prototype `#!c bool existe(graphe g, int i, int j)` qui renvoie `true` si il y a un arc entre les sommets `i` et `j` et `false` sinon.

6. Ecrire une fonction qui renvoie un tableau  contenant les voisins d'un sommet `i`. 


{{ exo("Listes d'adjacence en OCaml",[])}}

On rapelle la structure de données vue en cours permettant de représenter un graphe par liste d'adjacence en OCaml :
!!! ocaml "Définition de la structure de données"
    ```ocaml
    --8<-- "C17/ladj.ml:struct"
    ```

1. Ecrire une fonction d'initialisation `int -> graphe` qui renvoie un graphe d'ordre `n` n'ayant aucune arête

2. Ecrire une fonction qui permet de créer une arête dans un graphe.

3. La fonction de visualisation pour OCaml est donnée ci-dessous :

    ??? ocaml "Fonction de visualisation"
        ```ocaml
            --8<-- "C17/ladj.ml:visualise"
        ```
    
    Créer et visualiser le graphe suivant :
    ```mermaid
    graph LR
    A(("A"))
    B(("B"))
    C(("C"))
    D(("D"))
    E(("E"))
    F(("F"))
    G(("G"))
    A --- B
    A --- C
    G --- E
    C --- D
    D --- F
    B --- E
    E --- F
    A --- G
    ```

3. Ecrire une fonction qui affiche la matrice d'adjacence du graphe.

4. Ecrire une fonction qui renvoie le degré d'un sommet dans un graphe

5. Ecrire une fonction `existe` de prototype `#!c bool existe(graphe g, int i, int j)` qui renvoie `true` si il y a un arc entre les sommets `i` et `j` et `false` sinon.

6. Ecrire une fonction qui renvoie une liste  contenant les voisins d'un sommet `i`.


{{ exo("Listes chainées d'adjacence en C",[])}}

Comme indiqué en cours, on peut représenté les listes d'adjacence en C à l'aide d'un tableau de liste chainées. Reprendre les questions de l'exercice précédent à l'aide de cette nouvelle représentation.

```c
--8<-- "C17/ladj_dyn.c:struct"
```

Pour réviser la structure de liste chainées, on pourra revenir si besoin sur cet [exercice](https://fabricenativel.github.io/cpge-info/mp2i/sl/#exercice-3-listes-chainees-en-c)

On donne aussi pour cette représentation une fonction de visualisation !
??? langageC Fonction de visualisation
    ```c
    --8<-- "C17/ladj_dyn.c:visualise"
    ```

{{ exo("Graphes orientés",[])}}

!!! note
    Afin d'adapter les fonctions de visualisations  au cas des graphes orientés, il suffit d'apporter les modifications suivantes :

    * modifier la ligne écrivant l'entête `graph mygraph` dans le fichier *dot* en `digraph mygraph`
    * modifier les arcs entre les sommets en `->` (au lieu de `--`)

Dans le langage (C ou Ocaml) et avec la représentation de votre choix (matrice ou listes d'adjacence), représenter un graphe orienté et écrire sur le type `graphe`  les fonctions suivantes :

1. Test d'existence d'un arête
2. Ajout d'un arête.
3. Calcul du degré sortant d'un sommet.
4. Obtention de la liste des successeurs d'un sommet.
5. Calcul du degré entrant d'un sommet.
6. Obtention de la liste des prédécesseurs d'un sommet.





## Humour d'informaticien

![tree](./Images/C17/travelling_salesman_problem.png){.imgcentre width=500px}
