def racine(n):
    k = 0
    while k * k  <= n:
        k = k + 1
    return k - 1

def premier(n):
    for k in range(2,racine(n)+1):
        if n%k==0:
            return False
    return True

def somme(n):
    somme = 0
    for i in range(2,n+1):
        if premier(i):
            somme += i
    return somme

print(somme(10000))