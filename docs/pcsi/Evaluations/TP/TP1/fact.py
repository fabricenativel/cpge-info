def factorielle(n):
    f = 1
    for i in range(2,n+1):
        f = f * i
    return f

def occurrence(chaine,c):
    occ = 0
    for x in chaine:
        if x==c:
            occ +=1
    return occ

print(occurrence(str(factorielle(100)),"1"))