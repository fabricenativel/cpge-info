def valeur(li,saut):
    i,j = saut
    return li[j]-li[i]

# On se contente de rechercher le maximum de tous les sauts possibles
def saut_max_naif(li):
    vsaut, imax, jmax = 0, 0, 0
    for i in range(len(li)):
        for j in range(i, len(li)):
            if valeur(li, (i,j)) > vsaut:
                vsaut, imax, jmax = valeur(li,(i,j)), i, j
    return (imax,jmax)

def saut_max_dynamique(li):
    mk, ik, jk = 0, 0, 0
    for k in range(1,len(li)):
        if li[k]<li[mk]:
            mk = k
        if valeur(li,(ik,jk))<li[k]-li[mk]:
            ik, jk = mk, k
    return (ik, jk)

from random import randint
l = [randint(1,100) for _ in range(1000)]
print("Naif = ",saut_max_naif(l),":",valeur(l,saut_max_naif(l)))
print("Dynamique = ",saut_max_dynamique(l),valeur(l,saut_max_dynamique(l)))