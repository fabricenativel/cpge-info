hide: - navigation  in index.md

{{dm(2,"Le jeu de la vie ")}} 

Le devoir porte sur le [jeu de la vie](https://fr.wikipedia.org/wiki/Jeu_de_la_vie){target=_blank} inventé par le mathématicien [John Conway](https://fr.wikipedia.org/wiki/John_Horton_Conway){target=blank}. Pour découvrir ce "jeu", vous pouvez regarder l'excellente vidéo de la chaine youtube science étonnante :
<div class="centre"><iframe width="560" height="315" src="https://www.youtube.com/embed/S-W0NX97DB0?si=2xGfJnml3529SJqR" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe></div>


## Une version en une dimension

On s'intéresse dans un premier temps, à une version à une seule dimension du jeu de la vie, c'est à dire qu'on fait évoluer les cellules dans un tableau unidimensionnel (et pas sur une grille). La règle d'évolution est la suivante : une cellule devient ou reste vivante uniquement lorsqu'elle avait exactement une voisine vivante au tour précédent. D'autre part, on ne fait pas évoluer la première et la dernière cellule du tableau, elles restent mortes.

Par exemple, dans la configuration suivante, 
{{make_jeuvie(['...##.#.#.'],[])}} 
l'évolution suivante sera :
{{make_jeuvie(['..###.....'],[])}}

!!! note
    Le jeu se déroule en théorie dans un tableau infini, ici on supposera qu'on se restreint à un tableau de taille donnée `TAILLE` et que cette constante est définie en début de programme à l'aide de, par exemple, `#define TAILLE 100`. Par conséquent, on ne passera pas aux fonctions la taille du tableau de booléens (on utilisera la constante `TAILLE`).

1. Ecrire une fonction de signature `#!c void affiche(bool etat[])` qui prend en argument un état du jeu et l'affiche dans le terminal sous la forme d'une chaine de caractère où `#` indique les cellules vivantes et `.` les cellules vides. Par exemple (avec une taille de 10), si le tableau `etat `contient les valeurs `{false,false,false,true,true,false,true,false,true,false}` , l'affichage produit dans le terminal sera `...##.#.#.`.

2. Ecrire une fonction  `#!c bool* evolution(bool etat[])` qui renvoie le nouvel état du jeu après une application de la règle d'évolution. Par exemple, si le tableau `etat` contient `{false,false,false,true,true,false,true,false,true,false}`, alors la fonction evolution renvoie `false, false, true, true, true, false, false, false, false, false`.

3. Définir la constante `TAILLE` à 100 et définir un état de jeu ou toutes les cellules sont mortes sauf la cellule d'indice 50 qui est vivante et faire afficher l'évolution de l'état du jeu pour les 50 premières étapes. Le début de l'affichage devrait être :
```
..................................................#.................................................
.................................................#.#................................................
................................................#...#...............................................
...............................................#.#.#.#..............................................
..............................................#.......#.............................................
.............................................#.#.....#.#............................................
............................................#...#...#...#...........................................
...........................................#.#.#.#.#.#.#.#..........................................
..........................................#...............#.........................................
.........................................#.#.............#.#........................................
```

4. Ecrire une fonction `compte` qui prend en argument un état du jeu et renvoie le nombre de cellules vivantes.

5. On prend la constante `TAILLE` égale à 1000, et un tableau initialement vide à part la cellule d'indice 500 qui est vivante. Combien de cellules vivantes contient le tableau après 2024 évolutions ?   
Vérifier votre réponse : {{check_reponse("128")}}

## Généralisation et règles de Wolfram

Comme l'évolution d'une cellule ne dépend que de son état antérieur et de celui de ses voisines immédiates (à droite et à gauche). Ces trois cellules (la centrale et les deux voisines) peuvent être dans **8** configurations différentes, et donc une règle d'évolution possible est la donnée du nouvel état de la cellule centrale pour ces 8 configurations. Par exemple, la règle d'évolution dans la partie précédente correspond à

| Ancien état | Nouvel état de la cellule centrale|
|-------------|-----------------------------------|
|    `###`    | `.` |
|    `##.`    | `#` |
|    `#.#`    | `.` |
|    `#..`    | `#` |
|    `.##`    | `#` |
|    `.#.`    | `.` |
|    `..#`    | `#` |
|    `...`    | `.` |

Si on lit de bas en haut la règle on obtient `.#.##.#.` qui interprété comme un entier positif en binaire (avec  `#` correspondant au 1 et `.` au 0) donne $\overline{01011010}^{2} = \overline{90}^{10}$. Pour cette raison, la règle utilisée dans la partie précédente s'appelle [regle 90](https://en.wikipedia.org/wiki/Rule_90){target=_blank}. Et on peut donc associer à tout entier de l'intervalle $[0;255]$ une règle d'évolution.

1. Déterminer la règle de transformation pour l'entier 110

2. Ecrire une fonction de signature `bool* evolution_rule(bool etat[], int rnum)` qui prend en entrée un etat (sous la forme d'un tableau de booléens) et un numéro de règle `rnum` et renvoie l'état du jeu après une évolution. 

## Jeu de la vie sur une grille de taille 4x4
Le [jeu de la vie](https://fr.wikipedia.org/wiki/Jeu_de_la_vie){target=_blank} permet de faire évoluer un ensemble de cases (appelées cellule) d'une grille (théoriquement infinie mais qui sera limitée pour ce DM) en suivant les règles suivantes :

* une cellule (donc une case de la grille) n'a que deux états possibles : vivante (la case est remplie) ou morte (la case est vide)
* une cellule morte qui possède exactement trois voisines vivantes devient vivante
* une cellule vivante qui possède exactement 2 ou 3 voisines reste vivante sinon elle meurt.


Par exemple :
Dans la configuration suivante, où on a numéroté chacune des cellules vivantes de façon à décrire le processus :
{{ make_jeuvie(['...#','.##.','..#.','#...'],[1,2,3,4,5])}}

La cellule 1 possède 1 voisines donc elle meurt, de même que la cellule numérotée 5 qui n'a aucune voisine.
Les cellules 2, 3 et 4, restent vivantes car elles ont deux ou trois voisines.
Et deux nouvelles cellules apparaissent (on les a numérotés 6 et 7) dans les cases qui possédaient exactement trois voisines. La configuration suivante est donc :
{{ make_jeuvie(['..#.','.###','..#.','....'],[6,2,3,7,4])}}
Aux étapes suivantes, on obtient les configuration ci-dessous (on ne numérote plus les cellules pour simplifier):
{{ make_jeuvie(['.###','.#.#','.###','....'],[])}} {{ make_jeuvie(['.#.#','#...','.#.#','..#.'],[])}} {{ make_jeuvie(['....','##..','.##.','..#.'],[])}}


Le but de l'exercice est de simuler le jeu de la vie en C dans une grille de dimension données. On représentera dans la totalité du sujet une grille par un tableau a *une dimension* de booléens. C'est à dire qu'on utilise la technique de linéarisation du tableau vu en cours. Par exemple la grille {{ make_jeuvie(['....','##..','.##.','..#.'],[])}} 

sera représenté en mémoire par un tableau à une seule dimension : {{make_jeuvie(['....##...##...#.'],[])}}

où les cellules mortes sont `false` et les cellules vivantes `true`. 

!!! aide 
    On rappelle qu'en faisant cette linéarisation l'élément situé en ligne `i` et colonne `j` a pour indice `i*LARGEUR + j` dans le tableau linéarisé.

!!! note "Taille de la grille"
    Dans chaque partie du sujet, les dimension de la grille seront deux constantes entières notées `HAUTEUR` et `LARGEUR`. Pour définir ces constantes, deux possibilités s'offrent à vous :

    * utiliser `const` et les définir en variable globale en début de programme avec par exemple `const int HAUTEUR = 4;` (c'est la version recommandée au programme de mp2i).
    * utiliser une directive de précompilation `#define HAUTEUR 4` qui aura pour effet avant la compilation de remplacer dans votre code toutes les occurences de `HAUTEUR` par `4`.

Dans cette partie la grille est de dimension `4x4` et on cherche à reproduire l'évolution donnée en introduction. 

1. Ecrire une fonction `affiche` qui prend en argument un tableau de booléens de taille `HAUTEUR*LARGEUR` et l'affiche sous la forme d'une grille de `HAUTEUR` lignes sur `LARGEUR` colonnes en affichant `.` pour une cellule morte et `*` pour une cellule vivante. Vous pouvez tester votre fonction avec le tableau suivant :

    ```
    bool etat[HAUTEUR*LARGEUR] = {false,false,false,true,false,true,true,false,false,false,true,false,true,false,false,false};
    ```
    dont l'affichage devrait produire :
    ```
    ...#
    .##.
    ..#.
    #...
    ```

    !!! aide
        On rappelle qu'il est inutile de passer en argument la dimension du tableau car ce sont des variables globales

2. Ecrire une fonction `compte_voisin` qui prend en argument un tableau de booléens de taille `HAUTEUR*LARGEUR`, un entier `l` (la ligne), un entier `c` (la colonne) et renvoie le nombres de voisins de l'élément situé en ligne `l`, colonne `c`.

    !!! aide
        * On pourra écrire une fonction annexe qui teste si deux entiers `i` et `j` sont bien les indices de ligne et de colonne d'un élément de la grille (c'est à dire si `0 <= i < HAUTEUR` et `0 <= j < LARGEUR`).
        * Faites des tests pour cette fonction, par exemple pour la grille `etat` donnée à la question précédente, vous devriez obtenir :
            * `compte_voisin(etat, 0, 0) = 1`
            * `compte_voisin(etat, 1, 3) = 3`
            * `compte_voisin(etat, 3, 1) = 2`


3. Ecrire une fonction `etat_suivant` qui prend en argument un tableau de booléens de dimension `HAUTEUR*LARGEUR` et renvoie un **nouveau tableau de booléens, sans modifier celui donné en argument** contenant l'évolution suivante dans le jeu de la vie. Par exemple pour le tableau `etat` donné dans la question `1`, l'affichage du tableau produit par l'appel `etat_suivant(etat)` donne :
```
..#.
.###
..#.
....
```

4. Ecrire une fonction `copie_etat` qui prend en argument deux tableaux de booléens `etat1` et `etat2` de dimension `HAUTEUR*LARGEUR` ne renvoie rien et copie les valeurs de `etat2` dans `etat1`

5. Ecrire une fonction `evolution` qui prend en argument un tableau de booléens de dimension `HAUTEUR*LARGEUR` ainsi qu'un entier `nb_etapes` et un booléen `voir`. Cette fonction renvoie un tableau de booléens représentant l'état de la grille après `nb_etapes` evolutions, de plus si le booléen `voir` vaut `true` alors toutes les étapes intermédiaires sont affichées dans le terminal.
Par exemple, avec le tableau `etat` donné à la question 1, l'appel `resultat = evolution(etat, 10, true);` produit le résultat suivant dans le terminal :
```
..#.
.###
..#.
....

.###
.#.#
.###
....

.#.#
#...
.#.#
..#.

....
##..
.##.
..#.
```
Ce qui correspond bien aux évolutions du motif vu en introduction.

## Lecture depuis un fichier

Le but de cette partie est de modifier l'état d'un motif connu ; le [*glider gun*](https://conwaylife.com/wiki/Period-33_glider_gun){target=_blank}, téléchargeable ci-dessous sous la forme d'un fichier texte dans lequel les cellules vivantes sont représentées par le caractère `O` et les cellules mortes par `.`
{{telecharger("Glider gun","glidergun.cells")}}

!!! note
    Le jeu de la vie possède son propre [wiki](https://conwaylife.com/wiki/){target=_blank} sur lequel des passionés du jeu postent des motifs nouveaux regulièrement. Le motif du Glider gun donné ci-dessus est extrait de ce site.

Dans cette partie, on travaille sur une grille de dimensions `57x37`. On doit donc modifier les constantes `HAUTEUR` et `LARGEUR` en début de programme. 

1. Ecrire une fonction `lire_grille` qui prend en argument un nom de fichier. Ce fichier représente l'état d'une grille de jeu de la vie de dimension `57x37`, les cellules mortes sont représentés par le caractère `O` et les cellules vivantes par le caractère `.`, cette fonction renvoie un tableau de booléens qui représente un etat du jeu.

2. Ecrire une fonction `compte_vivant` qui détermine le nombre de cellules vivantes d'un état du jeu.

3. Donner le nombre de cellules vivantes après 100 évolutions du *Glider gun*. Vous pouvez tester votre réponse dans le formulaire ci-contre : {{check_reponse("237")}}

##  Visualisation sous forme d'image pbm

Le format d'image {{sc("pbm")}} pour *Portable Bitmap file forMat* est un format d'image élémentaire permettant de représenter des images en noir et blanc. Le fichier est au format texte, 

* sur la première ligne on doit écrire `P1`
* la seconde ligne contient les dimensions de l'image séparés par un espace (nombre de colonnes puis nombre de lignes)
* Les lignes suivantes sont des constituées de 1 et de 0. Un `1` indique un pixel noir et  un `0` un pixel blanc

Par exemple :
```
P1
4 4
0110
0010
0010
1000
```

est le fichier {{sc("pbm")}} d'une image 4x4 qui agrandi donne le résultat ci-dessous :   
&nbsp; &nbsp; ![ex_pbm](./ex_pbm.png)

!!! warning "Attention"
    Selon la configuration de votre ordinateur et votre système d'exploitation, il vous faudra peut-être installer une application permettant de visualiser les images au format {{sc("pbm")}}.

1. Ecrire une fonction `cree_image` qui prend en argument un etat du jeu de la vie (de dimension 57x37) et crée le fichier {{sc("pbm")}} correspondant.

2. Créer l'image au format {{sc("pbm")}} de l'état initial du *Glider gun*.  

3. Créer l'image du *Glider gun* après 100 itérations.

!!! lien "Pour aller plus loin"
    Divers outils existent pour transformer une suite d'image en une animation (gif animé ou vidéo). Sur un système d'exploitation Linux on pourra par exemple utiliser `convert` disponible après installé `ImageMagick`. 
