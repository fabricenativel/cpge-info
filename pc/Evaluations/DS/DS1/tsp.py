from itertools import permutations
from math import inf
from random import randint

def make_random(n):
    mat = [[0]*n for _ in range(n)]
    for i in range(n):
        mat[i][i] = 0
        for j in range(i+1,n):
            mat[i][j]=randint(1,9)
            mat[j][i]=mat[i][j]
    return mat


def bruteforce(graphe):
    n = len(graphe)
    poss = permutations([i for i in range(1,n)])
    minl = inf
    sol = []
    for x in poss:
        p = [0] + list(x)
        cl = 0
        for i in range(1,len(p)):
            cl += graphe[p[i]][p[i-1]]
        cl +=graphe[p[-1]][p[0]]
        if cl<minl:
            minl = cl
            sol = [p+[0]]
        elif cl==minl:
            sol.append(p+[0])
    return minl, sol

def glouton(graphe):
    visited = [0]
    n = len(graphe)
    for i in range(n):
        cmin = inf
        start = visited[-1]
        next = 0
        for j in range(n):
            if j!=start and j not in visited and graphe[start][j] < cmin:
                cmin = graphe[start][j]
                next = j
        visited.append(next)
    long = sum(graphe[visited[i]][visited[i+1]] for i in range(len(visited)-1))
    return long, visited

ex = make_random(4)
print(bruteforce(ex))
print(glouton(ex))
print(ex)