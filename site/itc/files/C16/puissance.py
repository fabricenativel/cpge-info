# Calcule x puissance n, avec n>0
def puissance(x,n):
    p = 1
    for i in range(1,n):
        p = p * n
    return p

def puissance_rapide(x,n):
    if n==0:
        return 1
    p = puissance_rapide(x,n//2)
    if n%2==0:
        return p*p
    else:
        return p*p*x
        
    
