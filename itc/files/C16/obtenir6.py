from random import randint

N = 10000

def de():
    return randint(1,6)

def obtenir6():
    cpt = 1
    while de()!=6:
        cpt = cpt + 1
    return cpt

def approx():
    s = 0.0
    for i in range(1,N+1):
        s = s + (1/6)*i*(5/6)**(i-1)
    return s

somme = 0
for i in range(N):
    somme += obtenir6()
print(f"Moyenne = {somme/N}")
print(f"Approx = {approx()}")