from random import randint

def somme_glouton(pyramide,i,j):
    if i==len(pyramide)-1:
        return pyramide[i][j]
    if pyramide[i+1][j]>pyramide[i+1][j+1]:
        sous_somme = somme_glouton(pyramide,i+1,j)
    else:
        sous_somme = somme_glouton(pyramide,i+1,j+1)
    return pyramide[i][j]+sous_somme

def glouton(pyramide):
    colonne = 0
    somme = pyramide[0][0]
    for i in range(1,len(pyramide)): 
        if pyramide[i][colonne]>pyramide[i][colonne+1]:
            somme+=pyramide[i][colonne]
        else:
            somme+=pyramide[i][colonne+1]
            colonne+=1
    return somme


p1 = [
    [5],
    [3,4],
    [9,2,6],
    [4,6,8,4],
    [3,9,2,5,7]   
]

p2 = [
    [7],
    [6,4],
    [1,3,4],
    [5,7,2,9],
    [4,7,8,1,6]   
]

size = 50
p3 = [[randint(1,10) for j in range(i)] for i in range(1,size+1)]

print(f"Résultat rec ={somme_glouton(p1,0,0)}")
print(f"Résultat iter ={somme(p1)}")
print(f"Résultat rec={somme_glouton(p2,0,0)}")
print(f"Résultat iter ={somme(p2)}")
print(f"Résultat rec={somme_glouton(p3,0,0)}")
print(f"Résultat iter ={somme(p3)}")

