{% set num = 20 %}
{% set niveau = "mp2i_s2"%}

{{ titre_chapitre(num,niveau)}}

{{ citation("Bad programmers worry about the code. Good programmers worry about data structures and their relationships.
","L. Torvalds","[lwn.net](https://lwn.net/Articles/193245/)") }}

## Cours

{{ cours(num) }}

## Travaux dirigés

{{ td(num) }}


## Travaux pratiques

{{ exo("Parcours en profondeur d'un graphe",[])}}

1. Visualiser l'[algorithme de parcours en profondeur d'un graphe](https://www.cs.usfca.edu/~galles/visualization/DFS.html){target=_blank} (site de l'université de San Francisco). On rappelle que dans ce parcours, on explore à chaque étape le premier voisin non encore exploré du sommet courant. Afin de s'assurer de la bonne compréhension de l'algorithme, on pourra prévoir le parcours puis lancer la visualisation afin de vérifier.

2. Dans cet algorithme on doit disposer d'une structure de données permettant de savoir si un sommet a déjà été visité ou non. On proposer d'utiliser un tableau de booléens  `visite` (si le sommet `i` n'a pas été encore visité alors l'élément d'indice `i` de visite vaut `false`). Ecrire une fonction 


{{ exo("Parcours en largeur d'un graphe",[])}}