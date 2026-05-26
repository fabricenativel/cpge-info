from random import randint, seed
    

def est_triee(liste):
    return all(liste[i+1]>=liste[i] for i in range(len(liste)-1))

def fusion(l1,l2):
    if l1==[]:
        return l2
    if l2==[]:
        return l1
    if l1[0]<l2[0]:
        return [l1[0]]+fusion(l1[1:],l2)
    return [l2[0]]+fusion(l1,l2[1:])

def fusion_iter(l1,l2):
    i1,i2 = 0,0
    n1,n2 = len(l1),len(l2)
    l = []
    while i1+i2 < n1+n2:
        if (i1<n1 and i2<n2 and l1[i1]<=l2[i2]) or i2>=n2:
            l.append(l1[i1])
            i1 += 1
        else:
            l.append(l2[i2])
            i2 += 1
    return l
            
def tri_fusion(liste):
    if len(liste)<=1:
        return liste
    l1 = liste[:len(liste)//2]
    l2 = liste[len(liste)//2:]
    return fusion_iter(tri_fusion(l1),tri_fusion(l2))

def liste_aleatoire(n, vmin, vmax):
    return [randint(vmin,vmax) for _ in range(n)]


seed(42)
tl = liste_aleatoire(500,1,10000)
tl = tri_fusion(tl)
print(tl[250])
assert est_triee(tl), "La liste n'est pas triée"
print("all test ok")