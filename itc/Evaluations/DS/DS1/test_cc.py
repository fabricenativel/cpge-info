def num_en_liste(n):
    lchiffres = []
    for c in str(n):
        lchiffres.append(int(c))
    return lchiffres

def impairs_pairs(lchiffres):
    limpairs = [lchiffres[i] for i in range(len(lchiffres)-1,-1,-2)]
    lpairs = [lchiffres[i] for i in range(len(lchiffres)-2,-1,-2)]
    return limpairs, lpairs
    
def traite_pairs(pairs):
    res = []
    for p in pairs:
        if p*2 < 10:
            res.append(p*2)
        else:
            res.append((2*p)//10 + (2*p)%10)
    return res

def test_num_cart(num):
    lchiffres = num_en_liste(num)
    limpairs, lpairs = impairs_pairs(lchiffres)
    lpairs = traite_pairs(lpairs)
    s = 0
    for c in limpairs:
        s = s + c
    for c in lpairs:
        s = s + c
    return s%10 == 0

print(test_num_cart(4762))