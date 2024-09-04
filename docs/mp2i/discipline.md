
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



## Humour d'informaticien
![punition](./Images/C2/comments.webp){.imgcentre width=500px}