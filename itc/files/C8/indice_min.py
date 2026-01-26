def indice_min(liste, idx):
    '''Renvoie l'indice du plus petit élément de la liste à partir de l'indice idx'''
    imin = idx
    for i in range(idx+1, len(liste)):
        if liste[i] < liste[imin]:
            imin = i
    return imin
