
from math import inf
from functools import lru_cache

@lru_cache
def rendu(somme,systeme):
    if somme==0:
        return 0
    utilisable = tuple([p for p in systeme if p<=somme])
    if len(utilisable)==0: return inf
    return min([rendu(somme-p,systeme)+1 for p in utilisable])

print(rendu(21,(2,5,8,20)))