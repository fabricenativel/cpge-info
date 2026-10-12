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