from random import randint
nbarcs = 1000
nbsommets = 100
arcs = set()
while len(arcs)!=nbarcs:
    i = randint(0,nbsommets-1)
    j = randint(0,nbsommets-1)
    if (i!=j):
        arcs.add((min(i,j),max(i,j)))
with open("graphe.txt",'w') as writer:
    for i,j in arcs:
        writer.write(f'{i} {j}\n')

