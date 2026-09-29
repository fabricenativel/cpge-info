from math import sqrt

N = 10000

def crible(n):
    est_premier = [True ] * (n+1)
    est_premier[0] = est_premier[1] = False
    for k in range(2,int(sqrt(n+1))+1):
        if est_premier[k]:
            m = 2
            while k*m<n+1:
                est_premier[k*m]=False
                m = m + 1
    premiers = [i for i in range(n+1) if est_premier[i]]
    return premiers

prem = crible(N)
print(prem)
print(f"Somme = {sum(prem)}")