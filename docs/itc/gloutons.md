{% set num = 7 %}
{% set niveau = "itc_s2"%}
{{ titre_chapitre(num,niveau)}}

## Cours

{{ affiche_cours(num) }}

## Travaux pratiques



{{ exo("Implémentation du rendu de monnaie en Python",[],0) }}

Le but de l'exercice est de compléter une fonction `rendu` écrite en Python qui implémente l'algorithme glouton pour le problème du rendu de monnaie. La fonction prend en argument :

* un flottant `somme` qui est la somme à rendre
* une liste `valeurs` contenant la somme des valeurs du système monétaire utilisé qu'on suppose *déjà triée* par ordre décroissant

Et elle doit renvoyer comme résultat une liste contenant les pièces à utiliser. On renvoie une liste vide lorsque l'algorithme échoue à trouver une solution. On rappelle que la stratégie gloutonne pour ce problème consiste à rendre à chaque étape la pièce de plus forte valeur possible.

1. Questions préliminaires

    a. Que doit renvoyer `rendu(18,[15,10,5,2,1])` ? Quelle est la solution optimale à ce problème ?

    b. Que doit renvoyer `rendu(17,[10,9,8,3])` ? Quelle est la solution optimale à ce problème ?

2. Recopier et compléter le code de la fonction ci-dessous :
    ```python linenums="1"
    def rendu(somme,valeurs):
        #la solution de l'algorithme initialisée à la liste vide
        solution = .....
        #la position dans la liste valeurs de la pièce testée
        indice = ....
        while somme!=0 and indice<len(valeurs):
            piece = valeurs[.....]
            # on teste si la piece est inférieure à la somme à rendre
            if piece<=......:
                # Si oui l'ajouter à la solution et diminuer la somme à rendre
                somme=...............
                solution...........(.....)
            else:
                # Sinon passer à la pièce suivante
                indice = ........
        if somme==0:
            return solution
        else:
            return []
    ```
3. Quel est le rôle du test `somme==0` en ligne 16 ? Que renverrait cette fonction pour le problème de la question **1.b)** si on supprime entièrement ce test (lignes 16 à 19) et qu'on le remplace par `return solution` ?

4. Tester cette fonction sur les exemples de l'exercice **1**.

{{exo("Problème du sac à dos",[])}}

Le but de l'exercice est d'implémenter la stratégie gloutonne afin de résoudre le problème du sac à dos. On prend comme exemple un sac ayant un poids maximal de **4kg** et les objets suivants :

![objets](Images/C7/pbsac.png){.imgcentre width=600px}

1. On représente un objet par un `tuple` en Python `(valeur,poids)`, par exemple les écouteurs sont représentés par le tuple `(90, 0.2)`. Créer la liste `objets` en python contenant les 8 tuples représentant chacun des 8 objets ci-dessus.

2. On rappelle que la première étape de la stratégie gloutonne est de classer les objets en utilisant un critère pertinent, par exemple le rapport `valeur/poids`. Ecrire une fonction `rapport` qui prend en argument un `objet` (donc un tuple) et renvoie le rapport `valeur/poids` de cet objet.

    !!! aide
        Pour récupérer la valeur et le poids d'un objet représenté par un tuple, on peut *décompacter* le tuple :
        `#!python valeur, poids = objet`

3. En utilisant `sorted` écrire une fonction `trie_objets` qui prend en argument une liste d'objets et renvoie cette liste triée par ordre décroissant du rapport valeur/poids.

    !!! aide
        * le paramètre `reverse` à `True` permet d'obtenir l'ordre décroissant.
        * le paramètre `key` permet de donner la clé de tri (c'est la fonction `rapport` de la question précédente).

4. Ecrire la fonction `glouton` qui prend en argument une liste d'objets et un poids maximal et renvoie la valeur obtenue pour le sac. Tester votre fonction sur l'exemple donné en introduction et vérifier votre résultat : {{check_reponse("1660")}}

5. Modifier la fonction précédente afin qu'elle renvoie aussi le contenu du sac.


{{exo("Somme maximale dans une matrice carrée",[])}}

On considère une matrice carrée de taille $n\times n$, $M_{i,j}$ ($0 \leqslant i \leqslant n-1$ et $0 \leqslant j \leqslant n-1$) à coefficients entiers et on s'intéresse aux chemins depuis la première valeur en haut à gauche ($M_{0,0}$) jusqu'à la dernière en bas et à droite ($M_{n-1,n-1}$) qui n'utilisent que les déplacements vers la droite ($\rightarrow$) ou vers le bas ($\downarrow$). Et on cherche à déterminer la somme obtenue si on se déplace avec  une stratégie gloutonne. Par exemple,
dans la matrice suivante :

$\left(\begin{matrix}
1 & 3 & 2 & 4 \\
5 & 6 & 1 & 2 \\
7 & 8 & 9 & 1 \\
4 & 2 & 3 & 5
\end{matrix}\right)$

La stratégie gloutonne donnera le chemin suivant en rouge et une somme de **38**.

$\left(\begin{matrix}
\textcolor{red}{1} & 3 & 2 & 4 \\
\textcolor{red}{5} & 6 & 1 & 2 \\
\textcolor{red}{7} & \textcolor{red}{8} & \textcolor{red}{9} & 1 \\
4 & 2 & \textcolor{red}{3} & \textcolor{red}{5}
\end{matrix}\right)$

1. En donnant un exemple montrer que la stratégie gloutonne ne donne pas toujours la somme optimale.

2. Ecrire une fonction `glouton` qui renvoie la somme obtenue la stratégie gloutonne

    !!! aide
        Utiliser deux variables `ligne` et `colonne` qui indique la position courante dans la matrice :

        * `ligne` et `colonne` sont initialisées à 0 car on démarre depuis le coin supérieur gauche
        * on choisit d'augmenter `ligne` ou `colonne` en comparant les valeurs se trouvant dans ces deux directions, *attention* cela n'est possible que si on a pas encore atteint la dernière ligne et la dernière colonne.
        * on se déplace tant qu'on a pas atteint la dernière position en bas et à droite

3. Tester votre fonction sur l'exemple suivant et vérifier votre résultat : {{check_reponse("261")}}
    ```python
     exemple = [
        [11, 19, 12,  2, 18, 18,  2,  9, 12, 17]
        [17, 14, 12, 10,  7, 18, 12,  5, 11,  7]
        [ 4,  8,  2, 12,  2, 17, 16, 13,  1,  6]
        [13,  8, 20, 10,  3, 12, 17, 12, 12,  9]
        [ 8,  3, 14, 17, 16, 10, 13, 10,  5, 20]
        [ 9, 13, 17,  9, 10,  1, 11, 19, 20, 19]
        [ 1,  6, 18, 15, 10,  2,  7,  9,  4, 20]
        [ 3,  8, 17, 18, 20, 19, 16,  8,  2, 14]
        [19, 17, 18,  9, 20, 15,  6,  5, 16,  3]
        [13, 14, 14,  9, 16,  8, 17, 15,  9, 11]
            ]
    ```

4. Modifier votre fonction afin qu'elle renvoie aussi le parcours dans la matrice sous la forme d'une liste de 0 (pour indiquer un déplacement à droite) et de 1 (pour indiquer un déplacement en bas).


{{exo("Choix d'activités",[])}}

On considère $n$ activités $A_i$ ($i \leqslant i \leqslant n-1$) ayant chacune une heure de début ($d_i$) et une heure de fin ($f_i$). Par exemple :

* $A_0 = (3,5)$ signifie que l'activité 0 commence à 3 heures et se termine à 5h
* $A_1 = (4,8)$ et donc $A_1$ est incompatible avec $A_0$ puisque leurs plages horaires respectives se chevauchent
* $A_2 = (6,7)$
* $A_3 = (1,2)$

Le but de l'exercice est de mettre en place une stratégie gloutonne sur ce problème, le choix local est de prendre l'activité qui se termine le plus tôt. Dans l'exemple ci-dessus, on classerait les activité par heure de fin croissante :
`[(1, 2), (3,5), (6,7), (4,8)]` et donc on pourrait prendre les activités $A_3$, $A_0$ et $A_2$.

1. Mettre en oeuvre cette stratégie en Python en écrivant une fonction `choix_activites` qui prend en argument une liste d'activités (données sous la forme de tuple `(debut,fin)`) et renvoie le nombre d'activités obtenu en  suivant la stratégie gloutonne

2. Modifier la fonction précédente afin qu'elle renvoie la liste des activités à choisir.