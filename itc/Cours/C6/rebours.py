def rebours(n):
    for i in range(n,0,-1):
        print(i)
    print("Partez !")

def rebours_recursif(n):
    if n==0:
        print("Partez !")
    else:
        print(n)
        rebours_recursif(n-1)