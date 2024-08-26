def valeur_max(taille, prix):
    if taille<2:
        return prix[taille]
    else:
        return max(valeur_max(k,prix)+prix[taille-k] for k in range(taille))
        
print(valeur_max(12,[0, 2, 7, 11, 15, 17, 18, 23, 24, 27, 29, 33, 38]))