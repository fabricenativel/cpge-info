#! /bin/python3
import sys

def somme_tranche(liste, i,j):
    s = 0
    for k in range(i,j+1):
        s = s + liste[k]
    return s

def max_tranche(liste):
    maxss = liste[0]
    for i in range(len(liste)):
        for j in range(i,len(liste)):
            if somme_tranche(liste,i,j)>maxss:
                maxss=somme_tranche(liste,i,j)
    return maxss

reader = open(sys.argv[1],"r")
entiers = list(map(int,reader.read().strip().split('\n')))
print("Somme maximale d'une tranche : ",max_tranche(entiers))
