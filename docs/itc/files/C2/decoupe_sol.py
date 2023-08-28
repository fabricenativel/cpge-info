vmax = {}
def decoupe_max(taille, prix):
    if taille in vmax:
        return vmax[taille]
    if taille==0:
        vmax[taille] = []
        return vmax[taille]
    if taille==1:
        vmax[taille] = [1]
        return vmax[taille]
    else:
        possibles = [decoupe_max(k,prix)+[taille-k] for k in range(taille)]
        vpossibles = [sum(prix[m] for m in p) for p in possibles]
        vmax[taille] = possibles[vpossibles.index(max(vpossibles))]
        return vmax[taille]

print(decoupe_max(16,[0, 3, 6, 8, 12, 13, 16, 19, 24, 28, 29, 32, 33, 37, 40, 42, 43]))
