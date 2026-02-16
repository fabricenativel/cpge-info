{{titre_concours("CCINP","2025")}}


!!! note
    * Ce corrigé peut contenir des erreurs ! Merci de me les signaler si vous en trouvez
    
## Enoncé

{{telecharger("Enoncé","CCINP2025.pdf")}}

## Partie I - Gestion de randonnées dans une base de données

!!! Warning "Attention"
    Le rapport de l'épreuve indique "*beaucoup de confusion entre `HAVING` et `WHERE`*", on rappelle donc que `WHERE` donne une condition sur les enregistrements (les lignes individuelles de la table) alors que `HAVING` donne une condition sur les résultats d'un `GROUP BY` c'est à dire sur les lignes agrégés après regroupement.

### Question 1

Une clé primaire doit pouvoir identifier de façon unique un enregistrement, comme deux randonnées peuvent a priori porter le même titre cet attribut ne peut pas servir de clé primaire. On peut proposer l'attribut `Id` qui est unique pour chaque enregistrement et donc peut servir de clé primaire

### Question 2
L'attribut `IdAuteur` de la table `Randonnee` référence l'attribut `Id` de la table `Auteur` qui est une clé primaire de cette table, c'est donc une clé étrangère.

### Question 3
```sql
SELECT Titre, Lieu, Distance 
FROM Randonnee
WHERE TYpe = "Pied";
```

### Question 4
```sql
SELECT IdAuteur, COUNT(*) as nbAct
FROM Randonnee
WHERE Type = "Pied" AND Niveau=3
GROUP BY idAuteur
ORDER By nbAct DESC;
```

### Question 5
```sql
SELECT Auteur.Pseudo, Randonne.Titre 
FROM Randonnee
JOIN Auteur ON Randonnee.IdAuteur = Auteur.Id
```

### Question 6
```sql
SELECT Auteur.Nom, Auteur.Prenom, COUNT(*) AS nbCheval
FROM  Auteur
JOIN Randonne ON Randonnee.IdAuteur = Auteur.Id
WHERE Type = "Cheval"
GROUP BY Auteur.Id
ORDER BY nbCheval DESC LIMIT 1;
```

## Partie II - Quelques calculs de dénivelés

### Question 7
```python
import gpxpy
```

!!! Warning "Attention"
    On doit bien comprendre que le sujet introduit :
    
    * le type `trpt` pour point de trace qui correspond à un **tuple de trois flottants** (latitude, longitude, altitude) si `point` est de type `trpt` on peut donc décompacter ce tuple afin de récupérer les trois composantes avec `#!python lat, long, alt = point` 
    * le type `itineraire` qui est une liste de `trpt`

### Question 8
La fonction `mystere` somme les altitudes des points de la liste `iti` puis divise par le nombre de points, dans le cadre de l'exemple on obtient donc $(100+102+110+108)/4$ c'est à dire $105$. C'est l'altitude moyenne de la randonnée.

### Question 9
La fonction mystère contient une boucle répétée $n$ fois où $n$ est la longueur de la liste donnée en paramètre. Cette boucle ne contenant que des opérations élémentaires (décompactage de tuple, addition et affectation), la complexité de cette fonction est linéaire en $n$.

### Question 10
```python
    --8<-- "CCINP2025/CCINP2025.py:Q10"
```

### Question 11
```python
    --8<-- "CCINP2025/CCINP2025.py:Q11"
```

### Question 12
```python
    --8<-- "CCINP2025/CCINP2025.py:Q12"
```

### Question 13
```python
    --8<-- "CCINP2025/CCINP2025.py:Q13"
```

### Question 14
 La fonction est constituée par deux boucles imbriquées, la boucle externe est répétée $n$ fois (où $n$ est la longueur de la liste) et la boucle interne est répétée $p$ fois. Ces boucles ne contenant que des opérations élémentaires, la fonction a une complexité en $\mathcal{O}(np)$.

### Question 15
Les variables `lat_ref` et `long_ref` sont des listes de flottants, `lat_ref` (resp. `long_ref`) contient la liste des latitudes (resp. longitudes) pour lesquelles on connait au moins une altitude de référence.

### Question 16
* La fonction `auxilaire` prend en argument deux listes d'éléments *comparables*, en effet on compare `x` (et `y`) à la liste vide et on effectue sur `x` et `y` des opérations `pop` réservées aux listes. Cette fonction renvoie une liste `z` (on effectue sur `z` une opération `append`).
* La fonction `principal` prend en argument une liste (puisqu'on appelle auxiliaire sur des tranches de l'argument) et renvoie une liste car auxiliaire renvoie une liste.

### Question 17

:material-checkbox-blank-outline: Itératif                  (`principal` ne contient pas de boucles)  
:material-checkbox-blank-outline: Algorithme glouton        (pas de choix optimum local en)  
:material-checkbox-marked-outline: Récursif                 (`principal` fait appel à elle même)                      
:material-checkbox-blank-outline: Programmation dynamique   (pas de chevauchement de sous problèmes)  
:material-checkbox-blank-outline: $k$ plus proches voisins  (pas de classification)          
:material-checkbox-marked-outline: Diviser pour régner      (on divise la liste à traiter en deux sous listes)  

### Question 18

La longueur de la liste `x` décroit strictement à chaque appel récursif et est minorée par 0 puisque la fonction s'arrête lorsque la longueur de la liste est inférieure ou égale à 1. La fonction `auxiliaire` se termine car à chaque appel récursif la somme des longueurs des deux listes `x` et `y` décroit de 1 et on renvoie directement le resultat lorsqu'une de ces deux listes est vide.

### Question 19

La fonction `principal` est une implémentation du *tri fusion*, en effet l'algorithme consiste à partitionner la liste `x` en deux en effectuant les extractions de tranches `x[0:m]` et `x[m:len(x)]` puis à trier récursivement ces deux listes (on appelle `principal` sur ces deux listes) et enfin à utiliser la fonction `auxiliaire` qui permet de renvoyer la fusion de ces deux listes triées (tout en vidant ces deux listes).

### Question 20
```python hl_lines="5 6 8 10 12 15 17"
    --8<-- "CCINP2025/CCINP2025.py:Q20"
```

### Question 21
```python
    --8<-- "CCINP2025/CCINP2025.py:Q21"
```

## Partie III - Organisation d'un Trek

### Question 22

Cette boucle parcourt les à fils non encore visités du sommet à traiter et sélectionne celui qui se trouve à la plus petite distance. L'algorithme effectue donc un choix optimal *local* (sans garantie que cela mène à la solution optimale). C'est donc un algorithme glouton.

### Question 23
`mystere2(G, "a", "f")` renvoie `["a", "c", "d", "e", "f"], 8`, car comme expliqué à la question 22, on avance toujours vers le sommet disponible situé à la distance minimale.

### Question 24
L'algorithme précédent ne donne pas le chemin de difficulté minimale en effet le chemin `a -> d -> e -> f` est de difficulté cumulée $4+ 1 + 1 = 6$.