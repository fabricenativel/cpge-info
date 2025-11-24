def incremente(n):
    n.append(1)
    print("Valeur de n dans la fonction :",n)

n = [42]
incremente(n)
print("Valeur de n dans le programme principal ",n)