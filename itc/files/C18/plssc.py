from functools import lru_cache

@lru_cache
def lplssc(mot1,mot2):
    if len(mot2)==0 or len(mot1)==0:
        return 0
    if mot1[-1]==mot2[-1]:
        return 1 + lplssc(mot1[:-1],mot2[:-1])
    return max(lplssc(mot1[:-1],mot2),lplssc(mot1,mot2[:-1]))



@lru_cache
def plssc(mot1,mot2):
    if len(mot2)==0 or len(mot1)==0:
        return ""
    if mot1[-1]==mot2[-1]:
        return plssc(mot1[:-1],mot2[:-1])+mot1[-1]
    if len(plssc(mot1[:-1],mot2))>len(plssc(mot1,mot2[:-1])):
        return  plssc(mot1[:-1],mot2)
    else:
        return plssc(mot1,mot2[:-1])


print(lplssc("PROGRAMMATION","DYNAMIQUE"))
