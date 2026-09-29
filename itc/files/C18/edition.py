

def edition(m,n):
    if (len(m),len(n)) in dico:
        return dico[(len(m),len(n))]
    if len(m)==0:
        dico[(0,len(n))] = len(n)
        return len(n)
    if len(n)==0:
        dico[(len(m),0)] = len(m)
        return len(m)
    if m[-1]==n[-1]:
        c = 0
    else:
        c = 1
    r1 = 1+edition(m[:-1],n)
    r2 = 1+edition(m,n[:-1])
    r3 = c+edition(m[:-1],n[:-1])
    if r1<r2 and r1<r3:
        dico[(len(m),len(n))]=r1
        return r1
    if r2<r3:
        dico[(len(m),len(n))]=r2
        return r2
    dico[(len(m),len(n))]=r3
    return r3



dico = {}
s1 = "NICHE"
s2 = "CHIENS"
print("Distance d'édition =",edition(s1,s2))
for i in range(len(s1)+1):
    for j in range(len(s2)+1):
        if (i,j) in dico:
            print(dico[(i,j)],end=" ")
        else:
            print("x",end=" ")
    print(" ")
