import random

def find(elt,tab):
    comp = 0
    for x in tab:
        comp=comp+1
        if x==elt:
            return comp
    return comp

iter = 100000
tcomp = 0
for _ in range(iter):
    size = 100
    tab = [i for i in range(1,size+1)]
    target = 1
    random.shuffle(tab)
    tcomp = tcomp + find(target,tab)
print(f"Moyenne = {tcomp/iter}")

