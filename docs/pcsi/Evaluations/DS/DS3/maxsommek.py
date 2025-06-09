def somme(lst):
    s = 0
    for x in lst:
        s += x
    return s

def somme_rec(lst):
    if lst==[]:
        return 0
    return lst[0] + somme_rec(lst[1:])

def sommek(lst, i, k):
    s = 0
    for j in range(i,i+k):
        s += lst[j]
    return s

def sommek_rec(lst, i, k):
    if k==0:
        return 0
    return lst[i] + sommek_rec(lst, i+1, k-1)

def sommek_max(lst, k):
    maxs = 0
    for i in range(len(lst)-k+1):
        s = sommek(lst, i, k)
        if s > maxs:
            maxs = s
    return maxs

def maxsommek2(lst, k):
    #La somme initiale est celle entre les indices 0 et k-1 (inclus)
    ns = sommek(lst, 0, k)
    maxs = ns
    for i in range(k, len(lst)):
        # La somme sur le tranche suivante de longueur k se déduit de la précédente
        ns = ns + lst[i] - lst[i-k]
        if ns > maxs:
            maxs = ns
    return maxs

assert(maxsommek2([2,7,-1,3,8,5],3)==16)