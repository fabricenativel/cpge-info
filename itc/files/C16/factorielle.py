# Renvoie la factorielle de n (n>0)
def factorielle(n):
    if n==0:
        return 1
    return n * factorielle(n-1)