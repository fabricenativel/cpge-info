from random import randint
from time import time
import sys

sys.setrecursionlimit(10**6)

def appartient(x,ens):
    for i in ens:
        if i == x:
            return True
    return False

def intersection(ens1, ens2):
    res = []
    for i in ens1:
        if appartient(i, ens2):
            res.append(i)
    return res

def intersection2(ens1, ens2):
    if ens1==[] or ens2==[]:
        return []
    else:
        if ens1[0]==ens2[0]:
            return [ens1[0]] + intersection2(ens1[1:], ens2[1:])
        elif ens1[0]<ens2[0]:
            return intersection2(ens1[1:], ens2)
        else:
            return intersection2(ens1, ens2[1:])

n = 5000
ens1 = sorted([randint(0,n*10) for i in range(n)])
ens2 = sorted([randint(0,n*10) for i in range(n)])
deb = time()
inter1 = intersection(ens1, ens2)
print("Temps pour intersection1 :", time()-deb)
deb = time()
inter2 = intersection2(ens1, ens2)
print("Temps pour intersection2 :", time()-deb)

    