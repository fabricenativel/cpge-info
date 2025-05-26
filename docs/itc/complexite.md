{% set num = 12 %}
{% set niveau = "itc_s2"%}
{{ titre_chapitre(num,niveau)}}

## Cours

{{ affiche_cours(num) }}

## Travaux pratiques

{{exo("Constante de Kaprekar",[],0)}}

Etant donné un nombre $n$ à 4 chiffres, on calcule le nombre $k(n)$ en faisant la différence entre les nombres obtenus en faisant la différence entre le nombre formé par les chiffres de $n$ dans l'ordre décroissant et celui formé par les chiffres de $n$ dans l'ordre croissant. Par exemple, $k(2025) = 5220 - 0225 = 4995$.  
**Attention** : si le nombre ne possède pas 4 chiffres alors on complète la liste de ses chiffres par des 0 pour en avoir 4. Par exemple $k(113) = 3110 - 113 = 2997$ (on complété la liste des chiffres avec un 0)


1. Ecrire la fonction `kaprekar` qui prend en entrée un entier `n` et renvoie `k(n)`

2. L'[algorithme de Kaprekar](https://fr.wikipedia.org/wiki/Algorithme_de_Kaprekar){target=_blank} consiste à itérer le processus précédent afin d'obtenir pour un entier $n$ de départ la suite $u_0 = n$ et $u_n = k(u_{n-1})$. Ecrire la fonction `kaprekar` qui prend en entrée un nombre `n` et construit la suite $u$ *jusqu'à obtenir un point fixe*.

3. Vérifier si $n$ est un nombre à 4 chiffres, n'ayant pas tous ces chiffres égaux alors le point fixe est toujours 6174

4. Quel est le plus grand nombre nécessitant le plus d'itération avant d'atteindre la valeur $6174$ ?
    Vérifier votre réponse : {{check_reponse("9985")}}

{{exo("Vérification de numéros de cartes de crédit",[])}}

Le but de l'exercice est d'implémenter l'algorithme de Luhn qui est utilisé pour vérifier qu'un numéro de carte de crédit est valide (cela permet d'indiquer à un utilisateur une éventuelle erreur de saisie). 

1. Ecrire une fonction `mult2` qui prend en argument un entier $c$ compris entre 0 (inclus) et 9 (inclus) et renvoie $2c$ si $2c <10$ et la somme des deux chiffres de $2c$ sinon. Par exemple `mult2(3)` renvoie 6 et `mult2(7)` renvoie 5.

2. Ecrire une fonction `pair_impair` qui prend en argument un entier `n` et renvoie la liste des chiffres de rang pair de `n` et celle des chiffres de rang impair (on numérote les chiffres de la droite vers la gauche en partant du dernier, ainsi le dernier chiffre est de rang impair, l'avant dernier pair et ainsi de suite). Par exemple `pair_impair(437716)` renvoie `[4, 7, 1], [3, 7, 6]`

3. Ecrire une fonction `somme` qui prend en argument une liste et renvoie la somme de ses éléments.

3. L'algorithme de Luhn consiste à utiliser la fonction `mult2` sur les chiffres de rang pair puis à en faire la somme et à ajouter à la somme des chiffres de la liste des chiffres de rang impair. Si le résultat obtenu est divisible par 10 alors le numéro est valide. Sur l'exemple précédent en appliquant  `mult2` à `[4, 7, 1]` on obtient `[8, 5, 2]` de somme `15`, on y ajoute la somme de `[3, 7, 6]` et on obtient `31` et donc `437716` n'est pas un numéro valide.

4. On donne ci-dessous une liste de 100 numéros de carte de crédit, quel est le seul numéro non valide ?
```python
numeros = [44724396297190980, 43812941463968050, 40336859619021165, 97597964422415457, 63536337821290779, 23593379330529192, 97589837393456264, 49578407512545811, 61260793581116966, 18229030539250716, 37661419230027694, 83581156863942036, 74789447939228909, 81951217181555722, 61458591443397390, 32616836055289686, 46290817839070207, 26437148529668464, 86755609112796028, 14389645842408464, 72720990480661263, 49874256626186371, 16903438994602296, 64128901250176874, 53533020809649422, 98705680238646633, 85084614929430435, 41112520608651663, 60019959766331664, 21281815098526996, 95450502161757745, 85678747145461081, 82458220821170890, 67599313123885579, 84856804675179117, 52069983417800204, 47585990612571006, 87506528950643599, 30803020167237142, 13940485924959645, 48298029626456742, 47138507898189063, 32386029801404399, 12354409205786577, 34853968470741591, 46003466701348719, 92693026950309371, 96173793280834549, 96281186183874465, 12510865919923254, 65193723559088809, 20330035658177402, 39127055853219640, 41057010958900453, 10443299015945605, 46593450887667429, 84983986612972153, 28781094621777423, 23001254903010795, 67742266247507485, 11626476304983383, 88445443233414572, 51696521110319347, 25122716434857190, 97952551849249814, 46392651429528390, 39373396873361454, 59233755763273459, 46368053811925930, 35311694316315746, 78237568108638542, 22231222579719332, 38119418911655365, 78471175610145217, 34899096301750635, 40720878286084573, 41155227796966741, 80881300081257552, 32557104073371197, 87179522658944421, 85770043209533859, 30704767511944407, 70563312858597934, 90699235054330625, 85812123348689794, 89448070096465873, 42563782299333777, 87017731661435741, 60070092775907955, 95358303409643638, 75812507878201098, 28998138610436481, 91287898770743086, 66348314720609533, 63370008434111897, 74458945060046982, 46194937943385775, 75423184274922445, 38537036031496736, 76948153146211653]
```
Teste votre réponse : {{check_reponse("28998138610436481")}}

{{ exo("Représentation d'un ensemble d'entiers",[])}}

On propose de représenter un ensemble d'entiers par la liste *triée* de ses éléments. Par exemple, l'ensemble $\{5, 7, 2 \}$ sera représentée par la liste `#!python [2, 5, 7]`.


1. Ecrire une fonction `appartient` qui prend en argument  un entier `x` et une liste représentant un ensemble `ens` et renvoie `True` si `x` est dans `ens` et `False` sinon.

2. En utilisant la fonction précédente, écrire une fonction `intersection` qui prend en argument deux listes `ens1` et `ens2` représentant chacune un ensemble et renvoie la liste représentant l'intersection de `ens1` et `ens2`.

3. Ecrire une version récursive de la fonction `intersection` qui utilise le fait que les deux listes soient triées (relancer la récursion en supprimant au moins un élément de chacune des deux listes)

4. Comparer les complexités des deux méthodes

5. Ecrire la fonction `insere` qui prend en argument  un entier `x` et une liste représentant un ensemble `ens` et renvoie la liste représentant l'ensemble `ens` dans lequel on a ajouté `x`. Par exemple `insere(4, [2, 5, 7])` renvoie `2, 4, 5, 7` et `insere(5, [2, 5, 7])` renvoie `[2, 5, 7]`.



{{exo("Jeu de la vie",[])}} 

On s'intéresse dans cet exercice, à une version unidimensionnelle du [jeu de la vie](https://fr.wikipedia.org/wiki/Jeu_de_la_vie){target=_blank}, c'est à dire qu'on fait évoluer des cellules ayant deux états possibles (vivantes ou mortes) dans un tableau unidimensionnel (et pas sur une grille). La règle d'évolution est la suivante : une cellule devient ou reste vivante uniquement lorsqu'elle avait exactement une voisine vivante au tour précédent. 

Par exemple, dans la configuration suivante, 
{{make_jeuvie(['...##.#.#.'],[1,2,3,4])}} 
l'évolution suivante sera :
{{make_jeuvie(['..###.....'],[5,6,7])}}

En effet :

* la cellule numérotée `5` est devenue vivante (elle était morte au tour précédent) car elle avait une seule voisine (la cellule  `1`)
* la cellule numérotée `6` est l'évolution de la celulle `1` qui est restée vivante (elle n'avait qu'une voisine vivante, la cellule `2`)
* la cellule numérotée `7` est l'évolution de la celulle `2` qui est restée vivante
* Les cellules `3` et `4` meurent car elles n'avaient aucune voisine.

!!! note
    Le "jeu" se déroule en théorie dans un tableau infini, ici on supposera qu'on se restreint à un tableau de taille donnée `TAILLE` et que cette constante est définie en début de programme à l'aide de, par exemple, `TAILLE=100` on ne fait pas évoluer la première et la dernière case du tableau qui restent toujours des cellules mortes.

1. Les cellules n'ayant que deux états possibles on représente un état du jeu par une liste de booléens. Ecrire une fonction de `affiche`  qui prend en argument un état du jeu et l'affiche dans le terminal sous la forme d'une chaine de caractère où `#` indique les cellules vivantes et `.` les cellules mortes. Par exemple (avec une taille de 10), si la liste `etat `contient les valeurs `[False,False,False,True,True,False,True,False,True,False]` , l'affichage produit dans le terminal sera `...##.#.#.`.

2. Ecrire une fonction  `evolution` qui prend en argument un etat du jeu de la vie et qui renvoie le nouvel état du jeu après une application de la règle d'évolution. Par exemple, si le tableau `etat` contient `[False,False,False,True,True,False,True,False,True,False]`, alors la fonction evolution renvoie `False, False, True, True, True, False, False, False, False, False`.


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

!!! lien "Pour aller plus loin"
    Pour aller plus loin, on pourra implémenter l'évolution d'[un jeu de la vie](https://fr.wikipedia.org/wiki/Jeu_de_la_vie){target=_blank} classique sur une grille rectangulaire qu'on pourra représenter par une liste de liste.



{{ exo("Crible d'Erastothène",[]) }}

On rappelle qu'un nombre premier est un entier naturel ayant exactement deux diviseurs 1 et lui-même, ainsi 13 est premier mais pas 15. Le [crible d'Erastothène](https://fr.wikipedia.org/wiki/Crible_d%27%C3%89ratosth%C3%A8ne) est un algorithme permettant de trouver tous les nombres premiers inférieurs ou égaux à un entier `n` donné. 

!!! abstract "Algorithme"
    * on crée une liste de booléens `premiers` de taille `n+1`
    * on initialise le tableau à `true` sauf `premiers[0]` et `premiers[1]` qui sont à `false` puisque  $0$ et $1$ ne sont pas premiers.
    * on parcourt ce tableau si `premiers[i]` est à `true` alors on met tous ses multiples (sauf lui-même) à `false`
    * le parcours s'arrête dès que l'entier `i` est supérieur à $\sqrt{n}$.  

1. Ecrire une fonction `crible` qui prend en paramètre un entier `n` et implémente cet algorithme. L'utiliser pour afficher les nombres premiers inférieurs à 100.

    !!! aide
        Vous devriez obtenir : `2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97`

2. Ecrire une fonction `somme_premiers` qui prend en argument un entier `seuil` et renvoie la somme de tous les nombres premiers inférieurs ou égaux à `seuil`. Par exemple `somme_premiers(100)` renvoie `1060`

3. Calculer la somme de tous les nombres premiers inférieur à 10000.  
Vérifier votre réponse : {{check_reponse("5736396")}}