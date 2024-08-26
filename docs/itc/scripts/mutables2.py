
# fonction qui ajoute 1 à son argument puis renvoie cet valeur
def incremente(n):
    n = n + 1
    return n

n = 42
# On modifie n en lui donnant la valeur renvoyée par la fonction
n = incremente(n)
print("n =",n)

