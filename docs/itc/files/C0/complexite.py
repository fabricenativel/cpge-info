# Renvoie true si elt est dans liste, et false sinon
def est_dans(elt, liste):
    for x in liste:
        if x == elt:
            return True
    return False


def f(x):
    return x**2 + 7*x - 1

def somme_f(valeurs):
    sf = 0
    for x in valeurs:
        sf = sf + f(x)
    return sf

# Renvoie l'indice du plus petit élément depuis l'indice start
def indice_min_depuis(liste,start):
    imin = start
    for i in range(imin+1,len(liste)):
        if liste[i]<liste[imin]:
            imin = i
    return imin

# Tri en place par sélection
def tri_selection(liste):
    for i in range(0,len(liste)):
        imin = indice_min_depuis(liste,i)
        liste[imin], liste[i] = liste[i], liste[imin]

