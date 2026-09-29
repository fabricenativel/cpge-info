vmax = {}
def valeur_max(taille, prix):
    if taille in vmax:
        return vmax[taille]
    if taille<2:
        vmax[taille] = prix[taille]
        return prix[taille]
    else:
        vmax[taille] = max(valeur_max(k,prix)+prix[taille-k] for k in range(taille))
        return vmax[taille]

def decoupe_max(taille,prix):
    ct = taille
    decoupe = []
    while ct!=0:
        for k in range(ct):
            if vmax[k]+prix[ct-k]==vmax[ct]:
                decoupe.append(ct-k)
                break
        ct = k
    return decoupe

# Création du tableau vmax des valeurs de découpes optimales
vm = valeur_max(16,[0, 3, 6, 8, 12, 13, 16, 19, 24, 28, 29, 32, 33, 37, 40, 42, 43])
print(vm)
# Utilisation pour reconstruire UNE solution
print(vmax)
print(decoupe_max(16,[0, 3, 6, 8, 12, 13, 16, 19, 24, 28, 29, 32, 33, 37, 40, 42, 43]))
