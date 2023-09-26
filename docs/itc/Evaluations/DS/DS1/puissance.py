''' Prend en argument un nombre x et un entier positif n et renvoie x puissance n'''
def puissance(x, n):
    assert type(n)==int and n>=0
    assert type(x)==int or type(x)==float
    p = 1
    for i in range(n):
        p = p*x
    return p

def puissance_rec(x,n):
    assert type(n)==int and n>=0
    assert type(x)==int or type(x)==float
    if n==0:
        return 1
    return x*puissance_rec(x,n-1) 


