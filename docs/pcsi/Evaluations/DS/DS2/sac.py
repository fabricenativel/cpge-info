def valeur_poids(objets, choix):
    v = 0
    p = 0
    for i in range(len(choix)):
        if choix[i] == 1:
            pobj, vobj = objets[i]
            v = v + vobj
            p = p + pobj
    return v, p


def glouton(objets, pmax):
    poids = 0
    valeur = 0
    for obj in objets:
        p, v = obj
        if poids + p <= pmax:
            poids += p
            valeur = valeur + v
    return valeur

def choix(n,k):
    # Chaine de caractères contenant les bits de k
    bits = bin(k)[2:] 
    # On rajoute des 0 à gauche pour obtenir une chaine de longueur n
    bits = '0'*(n-len(bits)) + bits
    # on transforme en liste de 0 et de 1:
    return [int(b) for b in bits]

def recherche_exhaustive(objets, pmax):
    n = len(objets)
    meilleure_valeur = 0
    for k in range(2**n):
        choix = choix(n, k)
        v, p = valeur_poids(objets, choix)
        if p <= pmax and v > meilleure_valeur:
            meilleure_valeur = v
    return meilleure_valeur