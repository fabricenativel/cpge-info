{% set num = 20 %}
{% set niveau = "mp2i_s2"%}

{{ titre_chapitre(num,niveau)}}

{{ citation("If in physics there's something you don't understand, you can always hide behind the uncharted depths of nature. You can always blame God. You didn't make it so complex yourself. But if your program doesn't work, there is no one to hide behind. You cannot hide behind an obstinate nature. If it doesn't work, you've messed up.","E. Djikstra","[Interview télévisée](https://pncnmnp.github.io/blogs/translating-dijakstra.html)") }}

## Cours

{{ affiche_cours(num) }}

## Travaux dirigés

{{ td(num) }}


## Travaux pratiques

!!! note
    On rappelle les structures de données utilisés en OCaml pour représenter les graphes :

    * par matrice d'adjacence :
    ```ocaml
    type graphe = {
    ordre : int; 
    madj : int array array};;
    ```
        
    * par liste d'adjacence :
    ```ocaml
    type graphe = {
    ordre : int;
    ladj : int list array};;
    ```

{{ exo("Nombre de chemins de longueurs k",[],0)}}

On rappelle que les puissances de la matrice d'adjacence d'un graphe donnent le nombres de chemins de longueurs $k$ entre deux sommets de ce graphe. Plus formellement, en notant $M$ la matrice d'adjacence d'un graphe $G$, le coefficient $M_{ij}^k$ de la puissance $k-$ième de $M$ est le nombre de chemins du sommet $i$ vers le sommet $j$ (voir l'exercice 9 de la [fiche de TD du chapitre 17](https://fabricenativel.github.io/cpge-info/mp2i/TD/TD17.pdf){target=_blank}).

1. Ecrire une fonction `#!ocaml mult int array array -> int array array -> int array array` qui prend en entrée deux matrices et calcule leur produit.

2. Ecrire une fonction  `#!ocaml expr: int array array -> int -> int array array` qui prend en entrée une matrice $M$ et un entier $k$ et renvoie $M^k$ en utilisant l'algorithme d'exponentiation rapide.

3. On considère le graphe suivant :

    ```mermaid
    graph LR
    A(("0"))
    B(("1"))
    C(("2"))
    D(("3"))
    E(("4"))
    F(("5"))
    G(("6"))
    H(("7"))
    A --> B
    A --> C
    B --> D
    C --> F
    C --> G
    E --> G
    E --> A
    D --> F
    G --> F
    B --> C
    F --> E
    F --> H
    H --> F
    D --> C
    ```
    Déterminer le nombre de chemins de longueur 42 entre le sommet 6 et le sommet 7.  
    Vérifier votre réponse : {{check_reponse("404536190")}}

{{ exo("Parcours en largeur d'un graphe",[])}}

1. Visualiser l'[algorithme de parcours en largeur d'un graphe](https://www.cs.usfca.edu/~galles/visualization/BFS.html){target=_blank} (site de l'université de San Francisco). On rappelle que dans ce parcours, on explore le graphe en "cercles concentriques" centrés sur le sommet de départ. Afin de s'assurer de la bonne compréhension de l'algorithme, on pourra prévoir le parcours puis lancer la visualisation afin de vérifier.

2. Ecrire en OCaml une fonction `bfs: graphe int -> int array` qui prend en argument un graphe et un sommet de départ et renvoie un tableau de d'entiers donnant la distance minimale en nombre d'arêtes entre le sommet de départ et les sommets du graphe.

    !!! note 
        Dans le cours, on avait utilisé la valeur `-1` pour indiquer l'absence de chemin. Une autre possibilité est d'utiliser un **type option** c'est en OCaml une façon élégante d'indiquer l'absence de valeur ici, le tableau de distance peut contenir un entier ou alors `None` pour indiquer qu'aucun chemin n'a été trouvé. c'est-à-dire qu'on utilise le type `#!ocaml None | Some of int` (voir la [documentation](https://ocaml.org/manual/5.2/api/Option.html){target=_blank}).

3. Vous pouvez télécharger ci-dessous un fichier texte représentant un graphe **non orienté** à 50 noeuds (et 100 arêtes). Chaque ligne est une arête sous la forme de deux entiers : sommet de départ et sommet d'arrivée. Ecrire une fonction `lire_graphe string -> int -> int*int list` qui prend en argument une chaine de caractère (le nom du fichier) ainsi qu'un entier `n` (le nombre de sommets) et renvoie un graphe d'ordre `n` en y créant chaque arête lue dans le fichier.
{{telecharger("Exemple (50 noeuds et 100 arêtes)","files/C20/ex50.txt")}}

4. Tester votre fonction de parcours en largeur sur ce graphe, un seul sommet se situe à la distance maximale. Multiplier le numéro de ce sommet par cette distance et tester votre résultat : {{check_reponse("200")}}

5. Pour le moment, notre fonction renvoie le tableau de distance mais sans indiquer le chemin à suivre. Créer un tableau `parent` qui indique lorsqu'un sommet est parcouru le sommet d'où l'on vient.

6. Utiliser ce tableau afin de pouvoir reconstruire *un* chemin depuis le sommet de départ 42 jusqu'à n'importe quel sommet du graphe.
    Un seul chemin de longueur 4 (la longueur minimale) permet de relier le sommet 42 au sommet 43.  Quel est ce chemin ? Vous pouvez vérifier votre résultat en entrant les sommets de ce chemin séparé par des points virgules (inclure 42 comme premier sommet et 43 comme sommet final)    {{check_reponse("42;29;9;49;43")}}

{{ exo("Parcours en profondeur d'un graphe",[])}}

1. Visualiser l'[algorithme de parcours en profondeur d'un graphe](https://www.cs.usfca.edu/~galles/visualization/DFS.html){target=_blank} (site de l'université de San Francisco). On rappelle que dans ce parcours, on explore à chaque étape le premier voisin non encore exploré du sommet courant. Afin de s'assurer de la bonne compréhension de l'algorithme, on pourra prévoir le parcours puis lancer la visualisation afin de vérifier.

2. Dans cet algorithme on doit disposer d'une structure de données permettant de savoir si un sommet a déjà été visité ou non. On proposer d'utiliser un tableau de booléens  `visite` (si le sommet `i` n'a pas été encore visité alors l'élément d'indice `i` de visite vaut `false`) et on rappelle que deux options sont envisageables :

    * utiliser la récursivité de façon à ce que les sommets en attente de traitement soient stockés dans la pile des appels récursifs
    * utiliser explicitement une pile (module `#!ocaml Stack` de OCaml)

    Ecrire les implémentations du parcours en profondeur en OCaml avec ces deux méthodes en vous aidant éventuellement de ce qui a été fait en cours.

3. Même question en C, il faudra dans le cas de l'utilisation explicite d'une pile en écrire une implémentation par liste chainée.

{{exo("Applications du parcours en profondeur",[])}}

1. Tri topologique

    1. Modifier le parcours en profondeur de l'exercice précédent afin de conserver l'ordre de visite des sommets. En déduire une fonction `#!ocaml tri_topologique: graphe -> int list` qui renvoie un tri topologique d'un graphe sans circuit donné en argument.

    2. Modifier la fonction précédente afin qu'elle lève une exception si on rencontre un circuit

    3. Tester sur le graphe suivant (sans circuit)

    ```mermaid
    graph LR
    S0(("0"))
    S1(("1"))
    S2(("2"))
    S3(("3"))
    S4(("4"))
    S5(("5"))
    S6(("6"))
    S7(("7"))
    S8(("8"))
    S7 --> S4
    S4 --> S8
    S5 --> S8
    S5 --> S1
    S8 --> S0
    S6 --> S3
    S1 --> S0
    S4 --> S3
    ```

    4. Ajouter un arc de façon à former un circuit dans le graphe précédent et tester la détection de cycle

2. Calcul des composantes connexes 

    1. Utiliser l'algorithme de parcours en profondeur afin d'implémenter une fonction  `#!ocaml composantes_connexes: graphe -> int list list` qui renvoie les composantes connexes sous forme de listes de sommets.

    2. Tester sur le graphe non orienté suivant :

    ```mermaid
    graph LR
    S0(("0"))
    S1(("1"))
    S2(("2"))
    S3(("3"))
    S4(("4"))
    S5(("5"))
    S6(("6"))
    S7(("7"))
    S8(("8"))
    S9(("9"))
    S7 --- S4
    S4 --- S8
    S8 --- S7
    S5 --- S1
    S2 --- S3
    S1 --- S2
    S1 --- S3
    S0 --- S6
    ```

{{ exo("Résolution de labyrinthe par un parcours en largeur",[])}}

On considère un labyrinthe de dimensions données et fourni sous la forme d'un fichier {{sc("ascii")}} où les caractères `.` indiquent les cases où il est possible de se déplacer et les caractères `@` indiquent un mur infranchissable. On donne les coordonnées d'une case en fournissant *d'abord le numéro de ligne puis le numéro de colonne* et la case  située en haut et à gauche est de coordonnées `(0,0)`. Dans l'exemple suivant, les dimensions sont de 10 sur 10 et les coordonnées de la case contenant un D sont `(6,4)` et celles de la case contenant un `A` sont `(1,6)`:

```
@@@@@@@@@@
@....@A@.@
@.@@.@...@
@.@@.@@.@@
@.@...@..@
@......@.@
@@@@D....@
@..@...@.@
@.....@@.@
@@@@@@@@@@
```

Les seuls déplacements autorisés dans le labyrinthe sont droite, haut, gauche et bas. Le but de l'exercice est de déterminer, le nombre minimal de déplacements entre deux cases données (lorsqu'un chemin entre ces deux cases existe). Dans l'exemple précédent, le nombre minimal de déplacements pour aller de `D` vers `A` est **11** et on a fléché ci-dessus un chemin possible :
```
@@@@@@@@@@
@....@A@.@
@.@@.@^<.@
@.@@.@@^@@
@.@...@^<@
@......@^@
@@@@x>>>^@
@..@...@.@
@.....@@.@
@@@@@@@@@@
```

Pour cela, l'idée est d'effectuer le **parcours en largeur** d'un graphe :

* chaque sommet du graphe est un état du labyrinthe indiquant les cases non encore visitées
* un arc va d'un sommet $s$ vers un sommet $t$ lorsqu'il est possible à partir de $s$ d'atteindre une case non encore parcourue qui sera alors marquée comme tel dans $t$.

Par exemple, sur le labyrinthe ci-dessus, en supposant qu'on se trouve initialement sur la case marquée d'un `D`, trois nouveaux états qu'on a indiqué en les marquants d'un `1` sont accessibles (en un déplacement):

```
@@@@@@@@@@
@....@A@.@
@.@@.@...@
@.@@.@@.@@
@.@...@..@
@...1..@.@
@@@@D1...@
@..@1..@.@
@.....@@.@
@@@@@@@@@@
```

A partir de ces nouveaux états, on peut accéder en deux déplacements aux cases indiquées ci-dessous avec un 2 :
```
@@@@@@@@@@
@....@A@.@
@.@@.@...@
@.@@.@@.@@
@.@.2.@..@
@..212.@.@
@@@@D12..@
@..@12.@.@
@...2.@@.@
@@@@@@@@@@
```

On donnera les fichiers représentant un labyrinthe sous le format suivant :

* La première ligne donne le nombre de lignes 
* La seconde ligne le nombre de colonnes
* La troisième ligne contient les coordonnées du points de départ (deux entiers : la ligne et la colonne)
* La quatrième ligne contient les coordonnées du point d'arrivée 

Ainsi, le problème de trouver le plus court chemin depuis le point `D` jusqu'au point `A` donné dans le labyrinthe en exemple sera représenté par le fichier {{sc("ascii")}} suivant :
```
10
10
6 4
1 6
@@@@@@@@@@
@....@.@.@
@.@@.@...@
@.@@.@@.@@
@.@...@..@
@......@.@
@@@@.....@
@..@...@.@
@.....@@.@
@@@@@@@@@@
```

1. On décide dans la suite de représenter la carte de taille `heightxwidth` par un tableau linéarisée c'est à dire que le point de coordonnées `l,c` dans la carte sera à l'indice `l*width+c` dans un tableau à une dimension. Ecrire les fonction suivantes :

    * `#!c int get_index(int l, int c, int width)` qui renvoie l'index dans le tableau linéarisé du point de coordonnées `l,c`
    * `#!c void get_lc(int index, int* l, int *c, int width)` qui modifie `*l` et `*c` afin qu'ils contiennent la ligne et la colonne correspondantes à l'index `index` dans le tableau linéarisé.

    ??? Question "Correction"
        ```c
        --8<-- "C20/laby.c:Q1"
        ```

2. Ecrire une fonction de signature `#!c int *read_map(char filename[], int* height, int* width, int* start, int* arrival)` qui prend en entrée un nom de fichier `filename`, modifie les entiers `height`, `width`, `start` et  `arrival` afin qu'ils contiennent le nombre de lignes du labyrinthe, le nombre de colonne, l'index dans le tableau linéarisé des points de départ et d'arrivée. Cette fonction renvoie un pointeur vers une matrice linéarisée d'entiers, dans lequel on représentant les cases vides par `0` et les murs par `1`. Ces deux constantes peuvent êtres définies (par exemple avec une directive de précompiliation en début de programme de façon explicite : `#!c #define EMPTY 0` et `#!c #define WALL 1`)

    ??? Question "Correction"
        ```c
        --8<-- "C20/laby.c:Q2"
        ```

 
3. On doit maintenant écrire la structure de données de file dans laquelle seront enfiler les états successifs lors du parcours en largeur du graphe. Pour cela on propose le type structuré suivant :

    ```c
        --8<-- "C20/laby.c:sd"
    ```

    C'est à dire qu'on représente une file d'attente par une liste chainée avec un pointeur sur le premier élément et un pointeur sur le dernier élément de la liste. Dans cette structure, il est bien important de comprendre que l'ajout d'un élément se fait **après le pointeur de queue** et que le retrait d'un élément se fait **depuis le pointeur de tête**.

    ```mermaid
    flowchart LR
    subgraph "Pointeurs d'accès"
        direction RL
        T[Start]
        Q[End]
    end
    subgraph "Liste chainée"
        direction RL 
        A(("A")) 
        B(("B"))
        C(("C"))
        D(("D"))
        E(("E"))
        N["NULL"]
        A -->  B --> C--> D --> E --> N
    end
    T --> A
    Q --> E
    ```

    Dans l'exemple ci-dessus, l'élément défilé serait A et on enfilerais un nouvel élément après E.

    Ecrire les fonctions suivantes qui permettront de manipuler cette structure de données :

    1. `#!c queue create()` qui renvoie une file vide (les deux pointeurs `start` et `end` sont `NULL`).
    2. `#!c bool is_empty(queue q)` qui renvoie `true` si la file est vide.
    3. `#!void insert(queue *q, int nodenum, int nodedist)` qui enfile un nouveau nom dont on donne l'indice `nodenum` et la distance par rapport au point de départ `nodedist`
    4. `#! node extract(queue *q)` qui défile un noeud.
    5. `#! void destroy(queue *q)` qui défile tous les éléments et libère l'espace mémoire alloué.

    ??? Question "Correction"
        ```c
        --8<-- "C20/laby.c:Q3"
        ```

4. Maintenant que nous disposons de la structure de données adéquate il nous reste à appliquer l'algorithme de parcours en largeur afin de déterminer la longueur minimale d'un chemin liant le point de départ à celui d'arriver. On commencer par initialiser une file avec pour seul élément le point de départ (représenté par son index dans le tableau linéarisé) associée à une distance de 0. Puis tant que cette file vide n'est pas vide et que l'arrivée n'a pas été atteinte, on défile un noeud et on enfile les cases adjacentes non encore parcourues (qu'on pourra marquer dans la carte à l'aide d'une constante `VISITED`). Ecrire une fonction `#!c int solve(char* fname)` qui prend en argument un nom de fichier contenant un labyrinthe (au format décrit en introduction) et renvoie la longueur d'un plus court chemin ou `-1` si aucun chemin n'existe.

    ??? Question "Correction"
        ```c
        --8<-- "C20/laby.c:Q3"
        ```

5. On peut à présent tester notre programme en lui donnant en entrée un fichier contenant un problème de labyrinthe. Par exemple pour le labyrinthe donné en exemple :
    ```
    10
    10
    6 4
    1 6
    @@@@@@@@@@
    @....@.@.@
    @.@@.@...@
    @.@@.@@.@@
    @.@...@..@
    @......@.@
    @@@@.....@
    @..@...@.@
    @.....@@.@
    @@@@@@@@@@
    ```
    Le programme doit renvoyer **11**.
    On propose ci-dessous un autre jeu de données avec un labyrinthe bien plus grands, il est extrait du site 
    [2D Pathfinding Benchmark](https://www.movingai.com/benchmarks/grids.html){target=_blank}. Et vous pouvez le télécharger ci-dessous :  
    {{telecharger("Labyrinthe","./files/C20/labyrinthe.txt")}}
    Et vous pouvez vérifier la réponse du programme : {{check_reponse("4847")}}

6. Pour le moment on dispose de la longueur minimale d'un chemin, mais pas du chemin lui-même. Afin de reconstruire le chemin parcouru, on propose d'enregistrer dans un tableau `parent` la case d'origine d'une case nouvellement atteinte. Ainsi à l'origine le point de départ n'a pas de parent, puis chaque case atteinte en un déplacement a pour parent la case de départ. Une fois la case d'arrivée atteinte, on remonte de proche en proche dans ce tableau afin de reconstruire le chemin parcouru. Ecrire une fonction de signature `#!c int* solve_path(char* fname)` qui renvoie un pointeur vers le tableau des cases parcourues si un chemin est trouvé et un pointeur {{sc("null")}} sinon. On pourra retrouver la taille de ce tableau car un chemin se termine forcément sur la case d'arrivée.




## Humour d'informaticien

![goto](./Images/C20/goto.png){.imgcentre width=500px}
