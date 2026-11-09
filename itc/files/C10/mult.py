def multiplie(n:int, m:int) -> int:
    '''Multiplie deux nombres positifs n et m sans utiliser *'''
    assert n>=0 and m>=0
    r = 0
    while m>0:
        r = r + n
        m = m - 1
    return r
