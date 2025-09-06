# --------- PYODIDE:code --------- #
# fonction qui ajoute 1 à son argument puis l'affiche (ne renvoie rien)
def incremente(n):
    n = n + 1
    print("n (copie dans la fonction) = ",n)

n = 42
incremente(n)
print("n (original dans l'appel) =",n)

