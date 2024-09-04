{% set num = 6%}
{% set niveau = "itc_s1"%}
{{ titre_chapitre(num,niveau)}}

## Exemple introductif

On veut écrire une fonction qui produit l'affichage de triangles de `n` lignes, la première ligne contenant un `*`, la seconde deux `*` et ainsi de suite. Par exemple pour `n=4`, la fonction doit afficher :
```
*
**
***
****
```

Une des possibilités est d'utiliser une boucle, on dit que la fonction est **itérative**  :
```python
def triangle(n):
    for i in range(1,n+1):
        print("*"*i)
```
{{IDE()}}

En observant la représentation ci-dessous, on constate aussi qu'il est possible de définir un triangle de `5` lignes par rappport à un triangle de `4` lignes, et plus généralement un triangle de `n` lignes par rapport à un triangle de `n-1` lignes : 

![triangle_recursif](./Images/C6/triangle_rec.png){widtht=500px .imgcentre}

En effet, construire un triangle de `n` lignes c'est :

* construire un triangle de `n-1` lignes
* ajouter une ligne de `n` étoiles

on vient de donner une méthode de construction **récursive**, qui doit se compléter en précisant qu'elle n'est valable que pour `n>0`. Cette définition trouve se traduit en python par :
```python
def triangle_recursif(n):
    if n>0:
        triangle_recursif(n-1)
        print('*'*n)
```



