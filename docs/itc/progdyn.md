{% set num = 2 %}
{% set niveau = "itc_s3"%}

{{ titre_chapitre(num,niveau)}}

## Cours

{{ cours(num) }}

## TP

### Manipulations des dictionnaires


{{ exo("Créer et manipuler un dictionnaire",[],0)}}

1. Créer un dictionnaire `conversion` dont les clés sont les chiffres (de 0 à 9) et les valeurs leur écriture en lettre. Par exemple `conversion[3] = "trois"`.
2. Ecrire une fonction `en_lettres` Python qui prend en entrée un nombre entier et écrit en  lettres chacun de ces chiffres par exemple `en_lettre(421)` affiche `quatre deux un`.

{{ exo("De l'utilité des dictionnaires",[])}}

Au jeu du Scrabble, chaque lettre a une valeur comme indiqué sur l'image ci-dessous :

![valeurs des lettres](./Images/C2/lettres.jpeg){.imgcentre width=300px}

Le but de l'exercice est d'écrire une fonction `score` qui prend un argument un `mot` et renvoie la somme des valeurs des lettres de ce mot. Par exemple `valeur("GIRAFE")` doit renvoyer 10 en effet :
![valeurs des lettres](./Images/C2/girafe.png){.imgcentre width=250px}
et donc la valeur est $2+1+1+1+4+1 = 10$

1. Compléter  une première version de `score` qui parcours les lettres du mots et ajoute la valeur suivant la lettre rencontrée.
```python
def score(mot):
    total = 0
    for lettre in ....:
        if lettre == 'A' or lettre=='E' or lettre=='I' ..... :
            total += 1
        if lettre == 'D' or lettre == 'G' or .......:
            totel += 2
        ...
        ...
    return ...
```

2. Les dictionnaires à la rescousse

    1. Créer un dictionnaire `valeur` dont les clés sont les lettres de l'alphabet et qui associe à chaque lettre sa valeur.

    2. Utiliser ce dictionnaire afin d'écrire une version bien plus courte et lisible de la fonction `score`.


{{ exo("Minimum et maximum",[]) }}

Ecrire une fonction `min_max` qui prend en argument une liste *non vide* et renvoie un dictionnaire dont les clés sont `"min"` et `"max"`. A la clé `"min"` est associée le minimum des valeurs de la liste et à la clé `"max"` leur maximum.

{{ exo("Moyennes des élèves",[])}}

Voici un dictionnaire representant  les notes obtenus par des élèves :
```python
notes = {
            "Albert"    : [7, 11, 15, 8, 9],
            "Alice"     : [14, 11, 6, 15],
            "Bob"       : [9, 9, 13, 14, 9],
            "Louise"    : [11, 13, 12, 14, 14],
            "Michelle"  : [2, 5, 4, 9],
            "Luc"       : [18, 14, 18, 11]
        }
```

1. Créer un dictionnaire possédant les mêmes clés (les prénoms) et contenant la moyenne de chaque élève.

    !!! aide 
        On pourra commencer par créer une fonction auxiliaire `moyenne` qui renvoie la moyenne des valeurs présentes dans la liste donnée en argument.

2. Trier ce dictionnaire par ordre croissant de moyenne.

{{ exo("A la recherche du mot caché",[])}}

Vous pouvez télécharger ci-dessous un fichier `mot_cache.txt` :  
{{telecharger("mot_cache.txt","./files/C2/mot_cache.txt")}}    

ce fichier contient de nombreux caractères : tous ceux de code {{sc('ascii')}} compris entre 33 (`!`) et 126 (`~`). Tous ces caractères apparaissent au moins à 50 reprises (et jusqu'à 100 fois) *à l'exception de quelques uns* qui apparaissent rarement (moins d'une dizaine de fois).  
Retrouver les caractères qui apparaissent rarement, ranger les dans l'ordre de leur nombre d'apparition pour obtenir le mot caché. Vous pouvez vérifier votre résultat ci-dessous :
{{ check_reponse("Bravo") }}

!!! aide
    * Revoir si nécessaire comment ouvrir un fichier en Python et en lire le contenu.
    * On pourra construire un dictionnaire dont les clés sont les caractères et les valeurs leur nombre d'apparition.



### Hachage

{{exo("Rappel du principe",[])}}

1. Ranger les entiers suivants : 176, 254, 1999, 2092, 565 dans une table de hachage de taille 9 avec la fonction de hachage $h(k) = k \mod 9$.
2. Donner un exemple de valeurs produisant une collision avec la valeur 176.

{{exo("Un exemple de fonction hachage",[]) }}

1. Ecrire une fonction `hash_str` qui prend en entrée une chaine de caractères {{sc("ascii")}} et renvoie la somme des codes {{sc("ascii") }} des caractères de cette chaine modulo 100.
2. Donner un exemple de collision pour cette fonction de hachage.

### Programmation dynamique


{{ exo("Coefficient du binôme",[]) }}

On rappelle que dans le triangle de Pascal, le coefficient situé ligne $n$ et colonne $k$ noté $\displaystyle{\binom{n}{k}}$ se déduit de ceux de la ligne précédente grâce à la relation de Pascal : $\displaystyle{\binom{n}{k} = \binom{n-1}{k-1} + \binom{n-1}{k}}$. On veut écrire une fonction `binom` qui prend en argument deux entiers $n$ et $n$ et renvoie $\displaystyle{\binom{n}{k}}$

1. Proposer une version récursive naïve de la fonction `binom`
2. Calculer grâce à cette fonction $\displaystyle{\binom{28}{12}}$ et noter le temps d'exécution
3. Proposer une version avec mémoïsation de la fonction `binom`, calculer de nouveau $\displaystyle{\binom{28}{12}}$ et comparere avec le temps d'exécution obtenu à la question précédente

{{ exo("La montée des marches",[]) }}

Pour gravir un escalier on peut faire des enjambées d'une ou deux marches. Par exemple pour monter un escalier de 4 marches, on pourrait faire `1+2+1` ou encore `2+2`. On s'intéresse au nombre de façons de monter un escalier de $n$ marches qu'on note $f_n$. 

1. Donner $f_0$ et $f_1$.

2. Etablir une relation de récurrence liant $f_{n}$, $f_{n-1}$ et $f_{n-2}$ pour $n \geq 2$.

    !!! Aide
        on pourra différencier les cas où la dernière enjambée fait une ou deux marches.

3. En déduire une fonction `python` récursive permettant de répondre au problème

    !!! Aide
        On donnera une fonction utilisant la mémoïsation

4. Proposer une version itérative permettant d'obtenir $f_n$ par une approche de bas en haut.

5. On s'intéresse maintenant à la construction effective de toutes les possibilités et on notera $p_n$ la liste des façons possibles de gravir un escalier de $n$ marches. Par exemple, en utilisant la notation des listes de Python, $p_5$ contient la liste `[1,1,2,1]`. 

    1. Donner $p_0$ et $p_1$.
    2. Etablir une relation de récurrence liant les éléments de $p_{n}$ à ceux de $p_{n-1}$ et $p_{n-2}$
    3. Ecrire une fonction python permettant de répondre au problème.

6. Dans le fichier `montees.txt` à télécharger ci-dessous, se trouvent 143 façons de monter un escalier de 12 marches. Sur chaque ligne du fichier, une des possibilités est donnée sous la forme d'une chaine de caractères composée de 1 et de 2.  
{{telecharger("montees.txt","./files/C2/montees.txt")}}    

    1. Combien de possibilités sont manquantes dans ce fichier ?
    2. Lesquelles ?


{{ exo("Découpe de valeur maximale",[]) }}

Le problème de la recherche de la découpe de valeur maximale d'une barre a été résolu [en cours](#cours). On donne ci-dessous la fonction python récursive avec mémoïsation (dans le dictionnaire `vmax`) qui répond au problème :

!!! Python
    ```python
    --8<-- "C2/decoupe_memo.py"
    ```

1. Faire fonctionner ce programme avec les données suivantes et donner la valeur de la découpe maximale.

    {{ table_data(["Longueur","Prix"],[[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16],[3, 6, 8, 12, 13, 16, 19, 24, 28, 29, 32, 33, 37, 40, 42, 43]] )}} 

2. Utiliser le tableau `vmax` des valeurs maximales des découpes déjà construit afin de déterminer une découpe maximale.

    !!! Aide
        On pourra remarquer que puisque `vmax[16] = vmax[7] + prix[9]` cela signifie qu'une découpe maximale peut-être obtenue avec un morceau de taille 9 et la  découpe maximale d'une barre de taille 7. En répétant ce processus de proche en proche on peut déterminer la taille des morceaux d'une découpe de valeur maximale.

3. On peut aussi modifier la fonction `valeur_max` ci-dessus afin qu'elle renvoie non pas la valeur de la découpe mais la découpe elle-même.

{{ exo("Problème du sac à dos",[]) }}
On dispose d’un sac à dos pouvant contenir un poids maximal $P$ et de $n$ objets ayant chacun un poids $(p_i)_{0\leq i \leq n-1}$ et une valeur $(v_i)_{0\leq i \leq n-1}$. *On suppose dans la suite que les objets sont rangés par ordre croissant de poids*. Le problème du sac à dos consiste à remplir ce sac en maximisant la valeur des objets qu’il contient. 

1. Proposer un programme résolvant ce problème par un algorithme glouton.

    !!! aide
        On rappelle que cet algorithme consiste à :
        
        * classer les objets par ordre d'importance (rapport poids/valeur, valeur, ...) 
        * remplir le sac en commençant par les objets de plus grande importance et en ajoutant l'objet tant que le poids maximal n'est pas atteint.
    
2. On considère les objets $\{(3.5,25),(3,18),(2.5,14),(2,10)\}$ avec un sac de poids maximal de 5 :
    1. Donner le résultat de l'algorithme glouton (en utilisant le critère de classement de votre choix)
    2. Le résultat obtenu est-il optimal ?

3. On veut maintenant résoudre ce problème par programmation dynamique :
    1. Etablir une relation de récurrence entre différentes instances du problème.

        !!! Aide
            On pourra noter  $S(p,k)$ le poids maximal atteignable pour un sac de poids maximal $p$ avec les objets $(p_i,v_i)_{0 \leq i \leq k}$ et chercher une relation de récurrence liant $S(P,k)$ à  d'autres instances du problèmes en distinguant deux cas :

            * $p_k \leq p$ et donc on peut (ou pas) prendre l'objet d'indice $k$
            * $p_k > p$ et donc l'objet d'indice $k$ ne rentre pas dans le sac

    2. En déduire une fonction Python permettant de déterminer la valeur maximale du sac.
    3. Déterminer un remplissage du sac réalisant la valeur maximale.

