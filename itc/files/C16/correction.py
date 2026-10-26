# Renvoie le nombre d'occurences d'elt dans liste
def nb_occ(elt, liste):
    cpt = 0
    for x in liste:
        if x == elt:
            cpt = cpt + 1
    return cpt

# Calcule n!
def fact(n):
    if n==0:
        return 1
    return n * fact(n-1)

# Renvoie la liste en dupliquant chaque élément
def duplique(liste):
    if liste==[]:
        return []
    return [liste[0],liste[0]] + duplique(liste[1:])