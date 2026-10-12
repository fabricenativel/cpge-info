
'''
On considère un tableau d'entiers, quelle tranche de ce tableau a la somme de valeur maximale ?
'''

from math import inf
from random import randint

# Approche naïve 1 : calcul de toutes les sommes : O(n^3)
def somme_tranche(liste, i,j):
    s = 0
    for k in range(i,j+1):
        s = s + liste[k]
    return s

def max_sous_somme1(liste):
    maxss = -inf
    imax, imin = None, None
    for i in range(len(liste)):
        for j in range(i,len(liste)):
            if somme_tranche(liste,i,j)>maxss:
                maxss=somme_tranche(liste,i,j)
                imin = i
                imax = j
    return maxss, imin, imax

# Approche naïve 2 : éviter la triple boucle : O(n^2)
def max_sous_somme2(liste):
    ss = [somme_tranche(liste,0,i) for i  in range(len(liste))]
    maxss = -inf
    imax, imin = None, None
    for i in range(len(liste)):
        for j in range(i,len(liste)):
            if ss[j]-ss[i]+liste[i]>maxss:
                maxss = ss[j]-ss[i]+liste[i]
                imin, imax = i, j
    return maxss,imin, imax

# Approche programmation dynamique 
def max_ss_dyn(liste):
    maxss = liste[0]
    sc = liste[0]
    imax,imin = 0,0
    cimin, cimax = 0,0
    for i in range(1,len(liste)):
        if sc+liste[i]>liste[i]:
            sc = sc+liste[i]
            cimax = cimax+1
        else:
            sc = liste[i]
            cimin =i
            cimax =i
        if sc>maxss:
            maxss = sc
            imin = cimin
            imax = cimax
    return maxss, imin, imax

vmin,vmax,size = -50,50,100
tliste = [randint(vmin,vmax) for _ in range(size)]
print(f"O(n^3) : {max_sous_somme1(tliste)}")
print(f"O(n^2) : {max_sous_somme2(tliste)}")
print(f"O(n) : {max_ss_dyn(tliste)}")

