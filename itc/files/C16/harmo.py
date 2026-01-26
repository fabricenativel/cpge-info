def serie_harmonique(n):
    somme = 0
    for i in range(1,n+1):
        somme = somme + 1/i
    return somme