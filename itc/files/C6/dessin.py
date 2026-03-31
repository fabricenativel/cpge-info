def dessin(n):
    if n>0:
        print("\\"*n+"/"*n)
        dessin(n-1)

dessin(5)