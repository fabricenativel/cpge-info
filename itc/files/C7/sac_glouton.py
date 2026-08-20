def rapport(objet):
    valeur, poids = objet
    return valeur/poids

def trie(objets):
    return sorted(objets, key=rapport, reverse=True)

def glouton(objets,pmax):
    objets_tries = trie(objets)
    poids_restant = pmax
    vmax = 0
    contenu = []
    for obj in objets_tries:
        valeur, poids = obj
        if poids <= poids_restant:
            poids_restant = poids_restant - poids
            vmax += valeur
            contenu.append(obj)
    return vmax, contenu

objets = [(90,0.2),(1100,2.4),(140,0.3),(810,1.7),(485,1.1),(620,1.4),(1320,2.8),(440,1)]
print(glouton(objets,4))