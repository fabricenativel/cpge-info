from random import randint

def genere_matrice(n):
    return [[randint(1, 20) for _ in range(n)] for _ in range(n)]

def glouton(matrice):
    ligne = 0
    colonne = 0
    n = len(matrice)
    somme = matrice[ligne][colonne]
    while ligne !=n - 1 or colonne!=n - 1:
        if ligne == n - 1:
            colonne += 1
        elif colonne == n - 1:
            ligne += 1
        elif matrice[ligne + 1][colonne] > matrice[ligne][colonne + 1]:
            ligne += 1
        else:
            colonne += 1
        somme += matrice[ligne][colonne]
    return somme

matrice = genere_matrice(10)
for l in matrice:
    print('[',end="")
    for ic in range(len(l)-1):
        print(f'{l[ic]:2}',end=", ")
    print(f'{l[len(l)-1]:2}',end="]\n")

print(glouton(matrice))
          
