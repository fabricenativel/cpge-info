from math import sqrt

def somme_premiers(n):
    premiers = [True]*(n+1)
    for nb in range(2,int(sqrt(n+1))):
        if premiers[nb]:
            k=2
            while k*nb<n+1:
                premiers[k*nb]=False
                k+=1
    somme = 0
    for k in range(2,n+1):
        if premiers[k]: somme += k
    return somme

print(somme_premiers(10_000_000))