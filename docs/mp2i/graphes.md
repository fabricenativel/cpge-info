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

{{exo("Triangles dans un graphe",[])}}

On considère un graphe non orienté $G=(S,A)$ et on supposera que les sommets sont indexés par les entiers à partir de 0. On dit que $\{i,j,k \}$ est un triangle de $G$ si $ij$, $jk$ et $kj$ sont dans $A$. Les fonctions demandées sont à écrire en OCaml et on supposera dans toute la suite de l'exercice, qu'on représente les graphes par listes d'adjacence :
```ocaml
type graphe = {
  taille : int;
  ladj : int list array};;
```


1. Donner le nombre de triangles d'un graphe complet à $n$ sommets.

2. Ecrire une fonction `complet : int -> graphe` qui renvoie le graphe complet à `n` sommets.

3. En utilisant les aspects impératifs du langage (boucles et références), écrire une fonction `triangles : graphe -> (int*int*int) list` qui renvoie la liste des triangles du graphe, en utilisant l'algorithme qui consiste pour chaque triplet $(i,j,k)  \in \{0,\dots,|S|-1\}^3$ à tester s'il s'agit ou non d'un triangle.

4. On souhaite maintenant écrire une version de la fonction `triangles` sans utiliser les aspects impératifs du langage.

    1. Ecrire une fonction `sous_liste : 'a list -> int -> 'a list list` qui prend en argument une liste `lst` et un entier `n` et renvoie toutes les sous listes de longueur `n` de `lst`. Par exemple `#!ocaml sousliste [0; 1; 2; 3] 3` renvoie  `#!ocaml [[0; 1; 2]; [0; 1; 3]; [0; 2; 3]; [1; 2; 3]]`

        !!! aide
            On pourra procédér par correspondance de motif sur `lst` et `n` et utiliser le fait qu'une sous liste de longueur `n` de `lst` est soit une sous liste de longueur `n` de la queue de `lst`, soit la tête de `lst` suivie d'une sous liste de longueur `n-1` de la queue de `lst`.

    2. En utilisant la question précédente et `List.filter` écrire une version de `triangles` qui n'utilise ni boucles ni références.

5. Tester vos fonctions sur le graphe à **1000** sommets représenté par le fichier ci-dessous (sur chaque ligne, se trouve un arc donné sous la forme de ses deux extémités séparé par un caractère espace.)

    {{telecharger("graphe.txt","./files/C17/graphe.txt")}}
    Vérifier votre réponse : {{check_reponse("1373")}}

6. Une autre possibilité pour déterminer les triangles d'un graphe et de parcourir l'ensemble $A$ des arêtes, pour chaque arête $ij$ on cherche alors l'intersection des listes d'adjacences de $i$ et de $j$. Comparer les complexités des deux méthodes si on suppose que l'intersection est calculée en temps linéaire du nombre de sommets.

7. Ecrire une fonction `#!ocaml intersection int list -> int list -> int list` qui calcule en temps linéaire l'intersection de deux listes *en les supposants triées*.

8. Ecrire une nouvelle version de la fonction `triangles` qui utilise le parcours des arêtes.

{{exo("Coloration gloutonne",[])}}

Dans toute la suite de l'exercice, on considère un graphe $G=(S,A)$ où chaque sommet est identifié par un entier de $\{0, \dots, |S|-1 \}$. Les fonctions sont à écrire en OCaml et et on supposera ce graphe représenté par liste d'adjacence :
```ocaml
type graphe = {
  taille : int;
  ladj : int list array};;
```

La coloration d'un graphe consiste à attribuer une couleur à chacun des sommets de ce graphe de façon à ce que deux sommets adjacents soient de deux couleurs différentes. On s'intéresse généralement à une coloration utilisant un *minimum* de couleurs.

1. En donnant un exemple montrer que la coloration d'un graphe à $n$ sommets peut nécessiter $n$ couleurs.

2. Ecrire une fonction `adjacent : graphe -> int -> int -> bool` qui prend en argument un graphe ainsi que deux sommets et renvoie `true` si ces deux sommets sont adjacents et `false` sinon.

3. On propose de représenter la coloration d'un graphe à $n$ sommets par une un tableau de longueur $n$. Par exemple, si $n=3$, le tableau `#!ocaml [| 1; 2; 1 |]` signifie que les sommets 0 et 2 sont de la couleur 1 et le sommet 1 de la couleur 2. Ecrire une fonction `valide : graphe -> 'a array -> bool` qui prend en argument un graphe et une liste d'entiers et renvoie `true` si cette coloration est valide.

4. On propose un algorithme glouton pour colorier un graphe : on parcourt les sommets *dans leur ordre de numérotation* et on leur attribue la plus petite couleur disponible. Ecrire la fonction `glouton : graphe -> int array` qui renvoie la coloration gloutonne d'un graphe.

5. La coloration gloutonne utilise-t-elle toujours un nombre minimal de couleurs ?

    !!! aide
        On pourra considérer un graphe cycle et tester différentes  numérotation des sommets.



## Humour d'informaticien

![tree](./Images/C17/travelling_salesman_problem.png){.imgcentre width=500px}
