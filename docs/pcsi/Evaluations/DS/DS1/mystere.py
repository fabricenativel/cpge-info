def mystere(n:int) -> list[int]:
    assert n>=0, "L'entier n doit être positif"
    if n==0:
        return [0]
    res = []
    c = 0
    while n>0:
        c = n%10
        res.append(c)
        n = n//10
    return res
        