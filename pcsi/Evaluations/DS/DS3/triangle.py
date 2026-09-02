g = {
    0: [1, 3, 4],
    1: [0, 2, 3, 4],
    2: [1, 4],
    3: [0, 1, 4],
    4: [0, 1, 2, 3]
}

def est_arete(gr, s, t):
    for x in gr[s]:
        if x==t:
            return True
    return False

def intersection(lst1, lst2):
    i1 = 0
    i2 = 0
    inter =  []
    while i1<len(lst1) and i2<len(lst2):
        if lst1[i1]==lst2[i2]:
            inter.append(lst1[i1])
            i1 += 1
            i2 += 1
        elif lst1[i1]<lst2[i2]:
            i1 +=1
        else:
            i2+=1
    return inter

def triangles(gr):
    tr = []
    for s in gr:
        for t in gr[s]:
            if t>s:
                for x in intersection(gr[s], gr[t]):
                    if x>t:
                        tr.append((s,t,x))
    return tr

print(triangles(g))

