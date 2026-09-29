
gr = {i:[] for i in range(100)}
with open("graphe.txt") as reader:
    arcs = reader.read().strip().split('\n')

for a in arcs:
    i,j = list(map(int,a.split(' ')))
    assert i!=j
    gr[i].append(j)
    gr[j].append(i)

nt = 0
for i in range(100):
    for j in range(i+1,100):
        for k in range(j+1,100):
            if j in gr[i] and k in gr[j] and i in gr[k]:
                nt += 1
print(f"Nombre de triangles = {nt} \n")