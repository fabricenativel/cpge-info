from math import inf
from functools import lru_cache

def rm(somme,systeme):
    # si aucune piece utilisable alors on renvoie inf
    if len(systeme)==0: return inf
    if systeme[0]>somme: 
        return rm(somme,systeme[1:])
    return min(1+rm(somme-systeme[0],systeme),rm(somme,systeme[1:]))
