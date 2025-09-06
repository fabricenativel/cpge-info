
def nombre(l):
    n = 0
    for i in range(len(l)):
        n = (n*10) + l[i]
    return n

def k(n):
    ch = [int(n) for n in str(n).zfill(4)]
    croissant = sorted(ch)
    decroissant = sorted(ch, reverse=True)
    cr = nombre(croissant)
    dr = nombre(decroissant)
    return dr - cr
    
def kaprekar(n):
    res = [n]
    while n != k(n):
        res.append(k(n))
        n = k(n)
    return res

maxl = 0
maxn = 0
for i in range(10000):
    if i%1111!=0:
        kn = kaprekar(i)
        if kn[-1]!=6174:
            print("Bug !")
            assert 0==1
        if len(kn) >= maxl:
            maxl = len(kn)
            maxn = i
print(maxn, kaprekar(maxn))

print(k(113))