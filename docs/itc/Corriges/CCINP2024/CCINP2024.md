# Enoncé

{{telecharger("Enoncé","CCINP2024.pdf")}}

# Correction

## Question 1

Alice peut choisir de jouer n'importe quelle case *non vide* de son camp, donc ici les cases 2, 4 et 5

## Question 2

La situation initiale est :
{{awale([0,0,2,0,16,5,2,1,0,1,0,1])}}

Voici les différentes configurations obtenues selon le coup joué :



* Si Alice joue la case 2, son gain est nul
{{awale([0,0,0,1,17,5,2,1,0,1,0,1])}}

* Si Alice joue la case 4 elle récolte les cases 7 (2 graines), 8 (3 graines) et 9 (2 graines) pour un gain de 7:
{{awale([1,1,3,1,0,7,4,0,0,0,1,2])}}

* Si Alice joue la case 5, son gain est nul
{{awale([0,0,2,0,16,0,3,2,1,2,1,1])}}

## Question 3

Dans les deux situations, Alice ne peut jouer que la case 5.

* Dans la première situation, on obtient :
{{awale([0,0,0,0,0,0,2,2,2,2,2,0])}}
Mais la récolte d'Alice affame alors son adversaire et donc le coup n'est *pas valide* !

* Dans la seconde situation, on obtient :
{{awale([0,0,0,0,0,0,0,0,0,0,0,1])}}
Car Alice peut alors récolter les cases 6 à 10 (qui contiennent chacune 2 graines) pour un gain de 10.

## Question 4

```python
    --8<-- "CCINP2024/CCINP2024.py:Q4"
```

## Question 5

```python
    --8<-- "CCINP2024/CCINP2024.py:Q5"
```

## Question 6

Au plus, une case contient la totalité des graines donc 48. Donc 6 bits sont nécessaires pour stocker le nombre de graines de chaque case comme $2^6 = 64$, on peut représenter sur 6 bits les entiers de $0$ à $65$.

## Question 7

```python
    --8<-- "CCINP2024/CCINP2024.py:Q7"
```