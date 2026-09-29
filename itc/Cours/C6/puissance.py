def puissance_iteratif(a,n):
    p=1
    for k in range(n):
        p=p*a
    return p

def puissance_recursif(a,n):
    if n==0:
        return 1
    return a * puissance_recursif(a,n-1)