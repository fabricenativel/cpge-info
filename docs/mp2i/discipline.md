
{% set num = 2 %}
{% set niveau = "mp2i_s1"%}

{{ titre_chapitre(num,niveau)}}

{{ citation("Program testing can be used to show the presence of bugs, but never to show their absence! ","E. Dijkstra","[in Notes on structured programming, 1970](http://www.cs.utexas.edu/users/EWD/ewd02xx/EWD249.PDF)")}}

## Cours

{{ affiche_cours(num) }}


## Travaux dirigés

{{ td(num) }}


## Travaux pratiques

{{ exo("Recherche d'un élément dans un tableau",[],0)}}

Voici le code d'une fonction `indice` en C :

```c
    --8<-- "C2/rec_bug.c:3:18"
```

1. Les tests proposés pour cette fonction sont de vérifier qu'elle renvoie `-1` lorsqu'on cherche `12` dans le tableau `{2, 5, 6, 1}` et `0` lorsqu'on cherche `2` dans ce tableau. Cette fonction valide-t-elle ces tests ?

2. Par des tests appropriés, montrer que cette fonction n'est pas conforme à sa spécification.

3. Corriger cette fonction.

{{ exo("Validation de date",[])}}

1. Écrire une fonction `bissextile` qui prend en argument un entier strictement positif `annee` et renvoie `true` si `annee` est une année bissextile.
2. Écrire une fonction `verifie_date` prenant en argument trois entiers (`jour`, `mois` et `annee`) et renvoyant `true` si `jour/mois/annee` est une date valide.
3. Proposer un jeu de tests pour cette fonction.


{{ exo("Somme des éléments d'un tableau",[])}}

Afin de calculer la somme des éléments d'un tableau, un élève propose le code suivant qui selon lui permet de gagner du temps car on somme les éléments deux par deux :
```c
int somme_deux(int tab[], int size)
{
    /* renvoie la somme des éléments de tab*/
    int s = 0;
    for (int i = 0; i < size - 1; i += 2)
    {
        s = s + tab[i] + tab[i+1];
    }
    return s;
}
```

1. Montrer par un test approprié que cette fonction n'est pas conforme à sa spécification.
2. Écrire une version correcte de cette fonction.

{{ exo("Tri à bulles",[])}}

Le [tri à bulles](https://fr.wikipedia.org/wiki/Tri_%C3%A0_bulles){target = _blank} est un algorithme de tri qui consiste à parcourir de façon répétitive un tableau : si deux éléments consécutifs ne sont pas dans le bon ordre, alors on inverse leur position. À la fin du premier parcours, le plus grand élément se trouve forcément en dernière position. Le parcours suivant s'arrête donc à l'avant-dernier élément, et ainsi de suite. Par exemple, sur le tableau `{12, 9, 17, 11, 3}`, les étapes du tri seront :

* après le premier parcours : `{9, 12, 11, 3, 17}` 
* après le deuxième parcours : `{9, 11, 3, 12, 17}`
* après le troisième parcours : `{9, 3, 11, 12, 17}`
* après le quatrième parcours : `{3, 9, 11, 12, 17}`

Le but de l'exercice est d'implémenter cet algorithme.

1. Écrire une fonction de signature `void echange(int tab[], int i, int j, int taille)` qui échange les éléments d'indice `i` et `j` dans `tab`. On vérifiera les préconditions suivantes : `0 <= i < taille` et `0 <= j < taille`.
2. Écrire une fonction de signature `void parcours(int tab[], int limite, int taille)` qui parcourt `tab` jusqu'à l'indice `limite` en échangeant l'élément avec son voisin de droite s'il lui est supérieur. Donner les préconditions.
3. Écrire une fonction `void tri_bulles(int tab[], int size)` qui trie en place le tableau `tab`. Proposer des tests pour valider le comportement de cette fonction.

{{ exo("Nombres narcissiques",[])}}

Un nombre $a$ ayant $p$ chiffres en base 10, noté $a = \overline{a_{p-1}\dots a_1a_0}^{10}$, est dit [narcissique](https://fr.wikipedia.org/wiki/Nombre_narcissique){target=_blank} lorsqu'il est égal à la somme des puissances $p$-ièmes de ses chiffres, c'est-à-dire lorsque $a = a_{p-1}^p + \dots + a_1^p + a_0^p$. Exemples :

* $153$ est narcissique ($p=3$) car $1^3 + 5^3 + 3^3 = 153$
* $255$ n'est pas narcissique ($p=3$) car $2^3 + 5^3 + 5^3 = 258$
* $1634$ est narcissique ($p=4$) car $1^4 + 6^4 + 3^4 + 4^4 = 1634$
* $3375$ n'est pas narcissique ($p=4$) car $3^4 + 3^4 + 7^4 + 5^4 = 3188$

Le but de l'exercice est de trouver le plus grand nombre narcissique inférieur à un million.

1. Écrire une fonction prenant en entrée un entier $n$ et un entier $p$ et renvoyant $n^p$. On se limite au cas $p>0$ et $n\geqslant 0$ et on vérifiera ces préconditions à l'aide d'instructions `assert`. Écrire dans le code en commentaire une spécification précise de cette fonction et proposer un jeu de tests sous la forme d'instructions `assert`.

2. Écrire une fonction `nb_chiffres` prenant en entrée un entier $n \geqslant 0$ et renvoyant son nombre de chiffres. Par exemple `nb_chiffres(1634)` doit renvoyer 4.

    !!! aide
        Voir le [cours](#cours)

3. Écrire une fonction `est_narcissique` qui prend en argument un entier `n` et qui renvoie `true` si et seulement si `n` est un nombre narcissique.

    !!! aide
        On rappelle que si $a = \overline{a_{p-1}\dots a_1a_0}^{10}$, alors :

        * $a_0$ est le reste dans la division euclidienne de $a$ par 10,
        * le quotient dans la division euclidienne de $a$ par 10 est $\overline{a_{p-1}\dots a_1}^{10}$.

4. Tester cette fonction en écrivant les instructions `assert` permettant de vérifier les exemples de nombres narcissiques ou non donnés en début d'exercice.

5. Écrire une fonction `narcissique_seuil` qui prend en entrée un entier `n` et renvoie le plus grand nombre narcissique inférieur à cet entier `n`. Par exemple `narcissique_seuil(200)` doit renvoyer `153`. Quel est le plus grand nombre narcissique inférieur à un million ?  
Tester votre réponse {{ check_reponse("548834")}}

6. Écrire une fonction `compte_narcissique` qui prend en entrée un entier `n` et renvoie le nombre de nombres narcissiques inférieurs ou égaux à `n`. Combien de nombres narcissiques sont inférieurs à un million ?  
Tester votre réponse {{ check_reponse("21")}}

{{ exo("Recherche dichotomique et batterie de tests",[])}}

1. Écrire une fonction `int recherche_dichotomique(int tab[], int taille, int cible)` qui prend en argument un tableau `tab` d'entiers trié par ordre croissant, sa taille `taille` et un entier `cible`, et qui renvoie l'indice de `cible` dans `tab` si elle est présente, et `-1` sinon. On vérifiera la précondition `taille >= 0` à l'aide d'une assertion (`assert`).

2. Pour valider rigoureusement cette fonction, on utilise la méthode du **partitionnement du domaine d'entrée** et le test des **valeurs limites**. Écrire une fonction `void test_recherche_dichotomique(void)` contenant une suite d'instructions `assert` testant les cas suivants :
    * Tableau de taille nulle (`taille = 0`) et tableau à un seul élément (élément présent et absent) ;
    * `cible` présente aux extrémités (`tab[0]`, `tab[taille - 1]`) et au milieu du tableau ;
    * `cible` absente : strictement inférieure au minimum, strictement supérieure au maximum, et intercalée entre deux éléments du tableau.

3. Appeler la fonction `test_recherche_dichotomique` dans le `main` et vérifier que tous les tests sont validés.

{{ exo("Élimination des doublons dans un tableau trié",[])}}

On considère un tableau `tab` d'entiers trié par ordre croissant contenant d'éventuels doublons. On souhaite éliminer les doublons *en place* en déplaçant les valeurs uniques vers le début du tableau.

1. Écrire une fonction `int supprimer_doublons(int tab[], int taille)` qui modifie `tab` en place de sorte que ses $k$ premières cases contiennent les éléments uniques de `tab` triés par ordre strictement croissant, et qui renvoie ce nombre $k$ ($0 \le k \le \text{taille}$).  
    Par exemple, si `tab` contient `{1, 1, 2, 3, 3, 3, 5}` (`taille = 7`), après exécution la fonction renvoie `4` et les 4 premiers éléments de `tab` sont `{1, 2, 3, 5}`.

2. Écrire une fonction *oracle* `bool est_strictement_croissant(int tab[], int taille)` qui renvoie `true` si le sous-tableau des `taille` premiers éléments est trié par ordre strictement croissant et `false` sinon.

3. À l'aide de cet oracle et d'instructions `assert`, écrire une fonction `void test_supprimer_doublons(void)` testant systématiquement les cas suivants :
    * Tableau vide (`taille = 0`) et tableau ne contenant aucun doublon ;
    * Tableau dont tous les éléments sont identiques (ex : `{4, 4, 4, 4}`) ;
    * Tableau avec des doublons situés uniquement au début, au milieu ou à la fin.

{{ exo("Chasse au bug et couverture de code",[])}}

On dit qu'un tableau d'entiers de taille $n \ge 3$ forme une *vallée* s'il est d'abord strictement décroissant jusqu'à un minimum local, puis strictement croissant jusqu'à la fin. Par exemple `{9, 6, 2, 5, 8}` est une vallée, mais `{9, 6, 2}` (pas de remontée) et `{9, 2, 5, 2, 8}` (deux creux) n'en sont pas.

Pour tester cette propriété, un élève propose le code suivant :
```c
bool est_vallee(int tab[], int taille)
{
    /* Précondition : taille >= 3 */
    int i = 0;
    // Descente
    while (i < taille && tab[i] > tab[i+1])
    {
        i++;
    }
    // Si on n'a pas du tout descendu ou si on est arrivé au bout
    if (i == 0 || i == taille - 1)
    {
        return false;
    }
    // Remontée
    while (i < taille && tab[i] < tab[i+1])
    {
        i++;
    }
    return i == taille - 1;
}
```

1. Tracer le graphe de flot de contrôle de cette fonction.
2. Proposer un jeu de tests (tableaux d'entrée et sorties attendues) permettant d'exécuter 100 % des instructions du code sans déclencher de comportement indéfini.
3. Identifier le bug critique présent dans les conditions de boucle `tab[i] > tab[i+1]` et `tab[i] < tab[i+1]` (accès hors bornes lorsque `i == taille - 1`).
4. Proposer un test qui met en évidence ce problème, puis corriger la fonction.

{{ exo("Exponentiation rapide et mesure d'opérations",[])}}

L'algorithme d'exponentiation rapide permet de calculer $x^n$ (pour $x \in \mathbb{R}$ et $n \in \mathbb{N}$) en effectuant un nombre d'opérations proportionnel à $\log_2(n)$, contre $n$ multiplications pour l'algorithme naïf.

1. Écrire une fonction `double puissance_naive(double x, int n, int *nb_mult)` qui calcule $x^n$ par une boucle simple et incrémente le compteur `*nb_mult` à chaque multiplication effectuée.
2. Écrire une fonction `double puissance_rapide(double x, int n, int *nb_mult)` calculant $x^n$ par élévation au carré itérative en comptant également le nombre de multiplications effectuées :
    * On initialise le résultat `r = 1.0` et `p = x` ;
    * Tant que $n > 0$ : si $n$ est impair on multiplie `r` par `p`, puis on remplace `p` par `p * p` et $n$ par $n / 2$.
3. Écrire une fonction de test vérifiant à l'aide d'instructions `assert` que pour $n = 1000$ et $x = 1.001$ :
    * Les deux fonctions renvoient le même résultat ;
    * La méthode naïve effectue exactement 1000 multiplications ;
    * La méthode rapide effectue strictement moins de 20 multiplications (vérifier que `*nb_mult < 20`).

## Humour d'informaticien
![punition](./Images/C2/comments.webp){.imgcentre width=500px}