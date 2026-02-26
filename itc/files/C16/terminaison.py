# Renvoie le quotient dans la division euclidienne de a par b avec a et b deux entiers naturels et b non nul
def quotient(a, b):
    assert (a >= 0 and b > 0)
    q = 0
    while (a - b >= 0):
        a = a - b
        q = q + 1
    return q

# Renvoie True si elt est dans liste et False sinon
def est_dans(elt, liste):
    if liste == []:
        return False
    return elt == liste[0] or est_dans(elt, liste[1:])


def syracuse(n):
    while n != 1:
        if n % 2 == 0:
            n = n//2
        else:
            n = 3*n+1
    return True
