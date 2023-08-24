from math import log2

DATA = "euler18.txt"
reader = open(DATA)
pyr = reader.read().strip().split('\n')
pyramide=[list(map(int,p.split(' '))) for p in pyr]

def get_child(i,j):
    return i+1,j,i+1,j+1

def max_traverse(pyramide):
    max_value = {(0,0):pyramide[0][0]}
    for i in range(0,len(pyramide)-1):
        for j in range(i+1):
            i1,j1,i2,j2 = get_child(i,j)
            if (i1,j1) not in max_value:
                max_value[(i1,j1)]=0
            if (i2,j2) not in max_value:
                max_value[(i2,j2)]=0
            if pyramide[i1][j1]+max_value[(i,j)]>max_value[(i1,j1)]:
                max_value[(i1,j1)]=pyramide[i1][j1]+max_value[(i,j)]
            if pyramide[i2][j2]+max_value[(i,j)]>max_value[(i2,j2)]:
                max_value[(i2,j2)]=pyramide[i2][j2]+max_value[(i,j)]
    return max(max_value[(i,j)] for i in range(len(pyramide)) for j in range(i+1))

print(max_traverse(pyramide))