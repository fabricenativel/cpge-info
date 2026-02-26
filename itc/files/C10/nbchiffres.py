def nbchiffres(n:int)->int:
    '''Renvoie le nombres de chiffres de n en base 10'''
    assert n>=0, "Le nombre doit être positif"
    if n==0:
        return 1
    p = 0
    while n>0:
        p = p + 1
        n = n//10
    return p
