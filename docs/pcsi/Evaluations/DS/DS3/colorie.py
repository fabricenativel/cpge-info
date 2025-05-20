
def degre(g, s):
    return len(g[s])

def appartient(lst, x):
    for elt in lst:
        if elt == x:
            return True
    return False

def sont_adjacents(g, s1,s2):
    return appartient(g[s1], s2)

def est_valide(g, coloration):
    for s in g:
        for v in g[s]:
            if coloration[s] == coloration[v]:
                return False
    return True

def colorie(g):
    res = [0] * len(g)
    for i in range(len(g)):
        dispo = [i for i in range(1,len(g)+1)]
        for j in g[i]:
            if res[j] in dispo:
                dispo.remove(res[j])
        res[i] = dispo[0]
    return res


ex = {0: [1, 2, 4],
1: [0, 2, 5],
2: [0, 1, 3, 5],
3: [2, 4],
4: [0, 3, 5],
5: [1, 2, 4]}

ex2 ={
    0:[2,3],
    1:[4,5],
    2:[0,4],
    3:[0,5],
    4:[1,2],
    5:[1,3]
}
assert est_valide(ex, colorie(ex))
assert est_valide(ex2, colorie(ex2))
print(colorie(ex2))