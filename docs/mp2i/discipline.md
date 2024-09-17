
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

Voici le code d'une fonction `recherche` en C :

```c
    --8<-- "C2/rec_bug.c:3:18"
```

1. Les tests proposés pour cette fonction sont de vérifier qu'elle renvoie `-1` lorsqu'on cherche `12` dans le tableau `{2, 5, 6, 1}` et `0` lorsqu'on cherche `2` dans ce tableau. Cette fonction valide-t-elle ces tests ?

2. Par des tests appropriés, montrer que cette fonction n'est pas conforme à sa spécification.

3. Corriger cette fonction

{{ exo("Validation de date",[])}}

1. Ecrire une fonction bissextile qui prend en argument un entier strictement positif `annee` et renvoie `true` si `annee` est une année bissextile.
2. Ecrire une fonction `verifie_date` prenant en argument trois entiers (jour, mois et annee)  et renvoyant `true` si `jour/mois/annee` est une date valide.
3. Proposer un jeu de tests pour cette fonction.


{{ exo("Somme des éléments d'un tableau",[])}}

Afin de faire la somme des éléments d'un tableau un élève propose le code suivant qui selon lui permet de gagner du temps car on somme les éléments deux par deux :
```c
int somme_deux(int tab[], int size)
{
    /* renvoie la somme des éléments de tab*/
    int s = 0;
    for (int i=0; i<n-1;i+=2)
    {
        s = s + tab[i] + tab[i+1];
    }
    return s;
}
```

1. Montrer par un test approprié que cette fonction n'est pas conforme à sa spécification.
2. Ecrire une version correcte de cette fonction.

{{ exo("Tri à bulles",[])}}

Le [tri à bulles](https://fr.wikipedia.org/wiki/Tri_%C3%A0_bulles){target = _blank} est un algorithme de tri qui consiste à parcourir de façon répétitive un tableau, si deux éléments ne sont pas de bon ordre, alors on inverse leur position. A la fin du premier parcours, le plus grand élément se trouve forcément en dernière position. Le parcours suivant s'arrête donc à l'avant-dernier élément, et ainsi de suite. Par exemple, sur le tableau `{12, 9, 17, 11, 3}` les étapes du tri seront :

* après premier parcours : `{9, 12, 11, 3, 17}` 
* après second parcours : `{9, 11, 3, 12, 17}`
* après troisième parcours : `{9, 3, 11, 12, 17}`
* après quatrième parcours : `{3, 9, 11, 12, 17}`

Le but de l'exercice est d'implémenter cet algorithme

1. Ecrire une fonction de signature `void echange(int tab[], int i, int j, int taille)` qui échange les éléments d'indice `i` et `j` dans `tab`. On vérifiera les préconditions suivantes : `0 <= i < taille` et `0 <= j < taille`.
2. Ecrire une fonction de signature `void parcours(int tab[], int limite, int taille)` qui parcours `tab` jusqu'à l'indice `limite` en échangeant l'élément avec son voisin de droite s'il lui est inférieure. Donner les préconditions.
3. Ecrire une fonction `void tri_bulles(int tab, int size)` qui trie en place le tableau `tab`. Propose des tests pour valider le comportement de cette fonction.

{{ exo("Nombres narcissiques",[])}}

Un nombre $a$ ayant $p$ chiffres en base 10, noté $a = \overline{a_{p-1}\dots a_1a_0}^{10}$ est dit [narcissique](https://fr.wikipedia.org/wiki/Nombre_narcissique){target=_blank} lorsqu'il est égal à la somme des puissance $p$ièmes de ses chiffres, c'est à dire lorsque $a = a_{p-1}^p + \dots + a_1^p + a_0^p$. Exemples :

* $153$ est narcissique ($p=3$) car, $1^3 + 5^3 + 3^3 = 153$
* $255$ n'est pas narcissique ($p=3$)  car, $2^3 + 5^3 + 5^5 = 258$
* $1634$ est narcissique ($p=4$) car, $1^4 + 6^4 + 3^4 + 4^4 = 1634$
* $3375$ n'est pas narcissique ($p=4$), car $3^4 + 3^4 + 7^4 + 5^4 = 3188$

Le but de l'exercice est de trouver le plus grand nombre narcissique inférieur à un million.

1. Ecrire une fonction prenant en entrée un entier $n$ et un entier $p$ et renvoyant $n^p$. On se limite au cas $p>0$ et $n\geqslant 0$ et on vérifiera ces préconditions à l'aide d'instructions. Ecrire dans le code en commentaire une spécification précise de cette fonction et proposer un jeu de tests sous la forme d'instructions `assert`.

2. Ecrire une fonction `nb_chiffres` prenant en entrée un entier $n \geqslant 0$ et renvoyant son nombre de chiffres. Par exemple `nb_chiffres(1634)` doit renvoyer 4.

    !!! aide
        Voir le [cours](#cours)

3. Ecrire une fonction `est_narcissique` qui prend en argument un entier `n` et qui renvoie `true` si et seulement si `n` est un nombre narcissique.

    !!! aide
        On rappelle que si $a = \overline{a_{p-1}\dots a_1a_0}^{10}$, alors :

        * $a_0$ est le reste  dans la division euclidienne de $a$ par 10,
        * le quotient dans la division euclidienne de $a$ par 10 est $\overline{a_{p-1}\dots a_1}^{10}$.

4. Tester cette fonction en écrivant les instructions `assert` permettant de vérifier les exemples de nombre narcissiques ou non donnés en début d'exercice.

5. Ecrire une fonction `narcissique_seuil` qui prend en entrée un entier `n` et renvoie le plus grand nombre narcissique inférieur à cet entier `n`. Par exemple `narcissique_seuil(200)` doit renvoyer `153`. Quel est le plus grand nombre narcissique inférieur à un million ?  
Tester votre réponse {{ check_reponse("548834")}}

6. Ecrire une fonction `compte_narcissique` qui prend en entrée un entier `n` et renvoie le nombre de nombres narcissiques inférieurs ou égaux à `n`. Combien de nombre narcissiques sont inférieurs à un million ?  
Tester votre réponse {{ check_reponse("21")}}

## Humour d'informaticien
![punition](./Images/C2/comments.webp){.imgcentre width=500px}