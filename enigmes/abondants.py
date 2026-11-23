def est_abondant(n):
    if n <= 1:
        return False
    s = 1
    d = 2
    while d * d <= n:
        if n % d == 0:
            s += d
            if d!=(n//d):
                s += n//d
        d += 1
    return s > n

cpt = 0
for i in range(100000):
    if est_abondant(i):
        cpt += 1

print(f"Réponse : {cpt}")