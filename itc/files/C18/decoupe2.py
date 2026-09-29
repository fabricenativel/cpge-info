from random import randint
SIZE = 16



def get_vmax(decoupe_possible):
    #print(decoupe_possible)
    imax = 0
    vmax = sum(prix[m] for m in decoupe_possible[0])
    for i in range(1,len(decoupe_possible)):
        if sum(prix[m] for m in decoupe_possible[i])>vmax:
            vmax = sum(prix[m] for m in decoupe_possible[i])
            imax = i
    return imax

def valeur_max(taille):
    if taille==0: return []
    if taille==1: return [1]
    else:
        decoupe_possible = [valeur_max(k)+[taille-k] for k in range(taille)]
        ind_max = get_vmax(decoupe_possible)
        return decoupe_possible[ind_max]


found = False
while not found:
    prix = [0]
    for i in range(1,SIZE+1):
        prix.append(prix[i-1]+randint(1,5))
    ps = valeur_max(16)
    if len(set(ps))==4:
        found = True
print(prix)
print(ps)