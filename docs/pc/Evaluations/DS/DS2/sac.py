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


def dynamique(objets, pmax, i):
    if i >= len(objets) or pmax == 0:
        return 0
    p, v = objets[i]
    sans = dynamique(objets, pmax, i+1)
    if (p > pmax):
        return sans
    else:
        avec = v + dynamique(objets, pmax-p, i+1)
        return max(sans, avec)


objs = [(4, 20), (5, 28), (6, 36), (7, 50)]
assert valeur_poids(objs, [1, 0, 1, 0]) == (56, 10)

objets = [(4, 30), (5, 34), (6, 36), (7, 49), (10, 74)]
objets.sort(key=lambda x: x[1]/x[0], reverse=True)
pmax = 10
print(glouton(objets, pmax))
print(dynamique(objets, pmax, 0))
