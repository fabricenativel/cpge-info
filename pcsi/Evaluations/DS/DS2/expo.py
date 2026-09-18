def exp_iter(a, n):
    p = 1
    for i in range(n):
        p = p *a
    return p

def exp_rec(a, n):
    if n==0:
        return 1
    return a * expo_rec(a, n-1)

def exp_rapide(a, n):
    p = 1
    while n!=0:
        if n%2==1:
            p = p *a
        a = a * a
        n = n//2
    return p
    