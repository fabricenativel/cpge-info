
from math import inf
from functools import lru_cache

def get_pmin(possibilites,utilisable):
    lmin = len(possibilites[0])
    pmin = utilisable[0]
    for i  in range(len(possibilites)):
        if len(possibilites[i])<lmin:
            lmin = len(possibilites[i])
            pmin = utilisable[i]
    return pmin

@lru_cache
def rendu(somme,systeme):
    if somme==0:
        return []
    utilisable = tuple([p for p in systeme if p<=somme])
    if len(utilisable)==0: return [10]*50 #Il faudrait renvoyer une liste de longueur infinie !
    possibilites = [rendu(somme-p,systeme)+[p] for p in utilisable]
    pmin = get_pmin(possibilites,utilisable)
    return rendu(somme-pmin,systeme)+[get_pmin(possibilites,utilisable)]

print(rendu(18,(2,4,7)))