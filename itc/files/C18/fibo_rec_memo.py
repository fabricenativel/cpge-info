# Le dictionnaire pour mémoïser
memo = {}

def fibonacci(n):
    assert n>=0
    # Si la valeur se trouve dans le dictionnaire, elle a déjà été calculée
    if n in memo:
        return memo[n]
    # Sinon on calcule et on enregistre dans le dictionnaire
    if n<2:
        memo[n] = n 
        return n
    memo[n] = fibonacci(n-1)+fibonacci(n-2)
    return memo[n]