{% set num = 11 %}
{% set niveau = "itc_s2"%}
{{ titre_chapitre(num,niveau)}}

## Cours

{{ affiche_cours(num) }}

## Travaux pratiques

{{exo("Implémentation par matrice d'adjacence",[],0)}}

1. Ecrire une fonction `cree_graphe` qui prend en argument un entier `n` et renvoie une liste de `n` listes de `n` booléens (tous initialisés à `false`). Cette liste permet donc de représenter un graphe par *matrice d'adjacence*.

2. Ecrire une fonction `cree_arete` qui prend en argument un graphe représenté par une matrice d'adjacence et deux entiers `i` et `j` et modifie cette matrice de façon à créer l'arc `i -> j` du graphe.

3. On donne ci-dessous une fonction de visualisation d'un graphe représenté par une matrice d'adjacence :
    ```python
    def visualise(g):
        '''Visualise le graphe g sous forme d'image avec graphviz.'''
        img_graphe = graphviz.Digraph()
        for i in range(len(g)):
            img_graphe.node(str(i))
            for j in range(len(g)):
                if g[i][j]:
                    img_graphe.edge(str(i), str(j))
        img_graphe.view()
    ```
    **Attention** pour utiliser cette fonction il faut importer le module `graphviz`.  
    Créer un graphe à 5 sommets (numérotés 0,1,2,3 et 4) et y créer les arcs suivants : 
    `0 -> 1`, `0 -> 2`, `1 -> 2`, `2 -> 3`, `4 -> 1` puis visualiser ce graphe.

4. Ecrire une fonction qui affiche la matrice d'adjacence du graphe. Le résultat attendu pour le graphe ci-dessus est :
```
0 1 1 0 0 
0 0 1 0 0 
0 0 0 1 0 
0 0 0 0 0 
0 1 0 0 0
```


5. Ecrire une fonction qui `degre_sortant` qui prend en argument un graphe `g` représenté par une matrice d'adjacence ainsi qu'un entier `i` et renvoie le degre sortant de ce sommet.

6. Ecrire une fonction `sucesseurs` qui prend en argument un graphe `g` représenté par une matrice d'adjacence ainsi qu'un entier `i` et renvoie la liste des successeurs de ce sommet.

7. Ecrire une fonction `ronde` qui prend en entrée un entier `n` et renvoie un graphe dans lequel chaque sommet `i` a un unique successeur : le sommet `i+1` modulo `n`. 

8. Ecrire une fonction qui `degre_entrant` qui prend en argument un graphe `g` représenté par une matrice d'adjacence ainsi qu'un entier `i` et renvoie le degre entrant de ce sommet.

9. Ecrire une fonction `predecesseurs` qui prend en argument un graphe `g` représenté par une matrice d'adjacence ainsi qu'un entier `i` et renvoie la liste des predecesseurs de ce sommet.

10. Reprendre les questions précédentes dans le cadre d'un graphe non orienté.

{{exo("Implémentation par liste d'adjacence",[])}}

1. Ecrire une fonction `cree_graphe` qui prend en argument un entier `n` et renvoie un dictionnaire dont les clés sont les entiers de `0` à `n-1` et dont les valeurs sont des listes vides. Ce dictionnaire permet donc de représenter un graphe par *listes d'adjacence*.

2. Ecrire une fonction `cree_arete` qui prend en argument un graphe représenté par liste d'adjacence et deux entiers `i` et `j` et modifie ce dictionnaire de façon à créer l'arc `i -> j` du graphe.

3. On donne ci-dessous une fonction de visualisation d'un graphe représenté par une matrice d'adjacence :
    ```python
    def visualise(g):
        img_graphe = graphviz.Digraph()
        for s in g:
             img_graphe.node(str(s))
             for t in g[s]:
                  img_graphe.edge(str(s),str(t))
        img_graphe.view()
    ```
    **Attention** pour utiliser cette fonction il faut importer le module `graphviz`.  
    Créer un graphe à 5 sommets (numérotés 0,1,2,3 et 4) et y créer les arcs suivants : 
    `0 -> 1`, `0 -> 2`, `1 -> 2`, `2 -> 3`, `4 -> 1` puis visualiser ce graphe.

5. Ecrire une fonction qui `degre_sortant` qui prend en argument un graphe `g` représenté par liste d'adjacence ainsi qu'un entier `i` et renvoie le degre sortant de ce sommet.

6. Ecrire une fonction `sucesseurs` qui prend en argument un graphe `g` représenté par liste d'adjacence ainsi qu'un entier `i` et renvoie la liste des successeurs de ce sommet.

7. Ecrire une fonction `ronde` qui prend en entrée un entier `n` et renvoie un graphe dans lequel chaque sommet `i` a un unique successeur : le sommet `i+1` modulo `n`. 

8. Ecrire une fonction qui `degre_entrant` qui prend en argument un graphe `g` représenté par liste d'adjacence ainsi qu'un entier `i` et renvoie le degre entrant de ce sommet.

9. Ecrire une fonction `predecesseurs` qui prend en argument un graphe `g` représenté par une matrice d'adjacence ainsi qu'un entier `i` et renvoie la liste des predecesseurs de ce sommet.

10. Reprendre les questions précédentes dans le cadre d'un graphe non orienté.

{{exo("D'une représentation à l'autre",[])}}

1. Ecrire une fonction `matrice_vers_liste` qui prend en entrée un graphe représenté par une matrice d'adjacence (tel que dans l'exercice 1) et renvoie ce même graphe représenté par liste d'adjacence (tel que dans l'exercice 2).

1. Ecrire une fonction `liste_vers_matrice` qui prend en entrée un graphe représenté par liste d'adjacence (tel que dans l'exercice 2) et renvoie ce même graphe représenté par matrice d'adjacence (tel que dans l'exercice 1).



{{exo("Exercices sur Codex",[])}}

Quelques exercices sur les graphes sur [Codex](https://codex.forge.apps.education.fr/){target=_blank}

* [Les amis de mes amis](https://codex.forge.apps.education.fr/exercices/dico_amis/){target=_blank}
* [Abonnés sur un réseau social](https://codex.forge.apps.education.fr/exercices/aimer_etre_aime/){target=_blank}
* [Motif de déverrouillage d'un téléphone](https://codex.forge.apps.education.fr/exercices/deverouillage/){target=_blank}

