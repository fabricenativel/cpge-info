
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
    smax = liste[0]
    n = len(liste)
    for i in range(0,n):
        s = 0
        for j in range(i,n):
            s = s + liste[j]
            if s>smax: 
                smax=s
    return smax

def max_tranchek(liste,start,k,end):
    sm_left = liste[k]
    sm_right = liste[k]
    sm = liste[k]
    for i in range(k-1,start-1,-1):
        sm = sm + liste[i]
        if sm>sm_left: sm_left=sm
    sm = liste[k]
    for i in range(k+1,end+1):
        sm = sm + liste[i]
        if sm>sm_right: sm_right=sm
    return max(sm_left,sm_right,sm_left+sm_right-liste[k])

def max_sous_somme_div_aux(liste, start, end):
    if end==start: return liste[start]
    if end==start+1: return max(liste[start],liste[end],liste[start]+liste[end])
    mid = (start+end)//2
    smax1 = max_sous_somme_div_aux(liste, start, mid-1)
    smax2 = max_tranchek(liste,start,mid,end)
    smax3 = max_sous_somme_div_aux(liste,mid+1,end)
    return max(smax1,smax2,smax3)



# Approche diviser pour régner 
def max_sous_somme_div(liste):
    return max_sous_somme_div_aux(liste,0,len(liste)-1)

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

vmin,vmax,size = -50,50,10
tliste = [randint(vmin,vmax) for _ in range(size)]
print(f"O(n^3) : {max_sous_somme1(tliste)}")
print(f"O(n^2) : {max_sous_somme2(tliste)}")
print(f"O(nlogn) : {max_sous_somme_div(tliste)}")
print(f"O(n) : {max_ss_dyn(tliste)}")

