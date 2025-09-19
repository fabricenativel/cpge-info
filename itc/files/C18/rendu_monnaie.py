from math import inf
from functools import lru_cache

def ind_utilisable(minimum,systeme):
    if systeme[0]>minimum: return -1
    ind = 0
    while (ind<len(systeme)) and (systeme[ind]<=minimum):
        ind += 1
    return ind

@lru_cache
def rendu(somme,systeme):
    if somme==0:
        return 0
    ind = ind_utilisable(somme,systeme)
    if ind==-1: return inf
    return min([rendu(somme-systeme[k],systeme)+1 for k in range(ind)])

print(rendu(18,(2,4,7)))