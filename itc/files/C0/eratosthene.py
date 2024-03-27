from math import sqrt

N = 169

def crible(n):
    est_premier = [True ] * (n+1)
    est_premier[1] = est_premier[2] = False
    for k in range(2,int(sqrt(n+1))+1):
        if est_premier[k]:
            m = 2
            while k*m<n+1:
                est_premier[k*m]=False
                m = m + 1
    premiers = [p for p in range(2,n+1) if est_premier[p]]
    return premiers

print(crible(N))