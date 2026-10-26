'''Trouver les couples (a,b) et (c,d) tels que a<=b et c<=d et a³+b³=c³+d³'''
import heapq

MAX = 20000


def value(a,b):
    return a**3+b**3

def brute(n, nb):
    mem = {}
    for i in range(n):
        for j in range(i,n):
            if value(i,j) in mem:
                mem[value(i,j)].append((i,j))
                #print(f"Solution trouvée : {mem[value(i,j)]}")
            else:
                mem[value(i,j)] = [(i,j)]
    minv=0
    while (minv not in mem or len(mem[minv])!=nb):
        minv +=1
    return minv, mem[minv]

def taxicab(n,nb):
    mem = {}
    tas = []
    a,b=1,1
    v = value(a,b)
    for i in range(1,n):
        heapq.heappush(tas,(value(a,i),a,i))
    found = False
    while not found:
        v,a,b = heapq.heappop(tas)
        if v not in mem:
            mem[v]=[(a,b)]
        else:
            mem[v].append((a,b))
            if len(mem[v])==nb:
                found = True
        heapq.heappush(tas,(value(a+1,b+1),a+1,b+1))
    return v, mem[v]

        
print(taxicab(MAX,4))