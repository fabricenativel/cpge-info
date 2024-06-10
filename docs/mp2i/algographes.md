{% set num = 20 %}
{% set niveau = "mp2i_s2"%}

{{ titre_chapitre(num,niveau)}}

{{ citation("If in physics there's something you don't understand, you can always hide behind the uncharted depths of nature. You can always blame God. You didn't make it so complex yourself. But if your program doesn't work, there is no one to hide behind. You cannot hide behind an obstinate nature. If it doesn't work, you've messed up.","E. Djikstra","[Interview télévisée](https://pncnmnp.github.io/blogs/translating-dijakstra.html)") }}

## Cours

{{ cours(num) }}

## Travaux dirigés

{{ td(num) }}


## Travaux pratiques

{{ exo("Parcours en profondeur d'un graphe",[],0)}}

1. Visualiser l'[algorithme de parcours en profondeur d'un graphe](https://www.cs.usfca.edu/~galles/visualization/DFS.html){target=_blank} (site de l'université de San Francisco). On rappelle que dans ce parcours, on explore à chaque étape le premier voisin non encore exploré du sommet courant. Afin de s'assurer de la bonne compréhension de l'algorithme, on pourra prévoir le parcours puis lancer la visualisation afin de vérifier.

2. Dans cet algorithme on doit disposer d'une structure de données permettant de savoir si un sommet a déjà été visité ou non. On proposer d'utiliser un tableau de booléens  `visite` (si le sommet `i` n'a pas été encore visité alors l'élément d'indice `i` de visite vaut `false`). 


## Humour d'informaticien

![goto](./Images/C20/goto.png){.imgcentre width=500px}
