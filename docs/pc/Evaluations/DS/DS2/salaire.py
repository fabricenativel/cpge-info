
emploi1 = [0, 26, 39, 48, 54]
emploi2 = [0, 23, 36, 44, 49]
emploi3 = [0, 16, 32, 48, 64]
emploi4 = [0, 19, 36, 47, 56]
emplois = [emploi1, emploi2, emploi3, emploi4]
mats = {}


def salaire_max(duree, idx):
    if (duree, idx) in mats:
        return mats[(duree, idx)]
    if duree == 0:
        mats[(duree, idx)] = 0
        return 0
    if idx == len(emplois):
        mats[(duree, idx)] = 0
        return 0
    else:
        smax = 0
        for k in range(0, duree+1):
            if emplois[idx][k] + salaire_max(duree-k, idx+1) > smax:
                smax = emplois[idx][k] + salaire_max(duree-k, idx+1)
        mats[(duree, idx)] = smax
        return smax


print(salaire_max(4, 0))
print(mats)
