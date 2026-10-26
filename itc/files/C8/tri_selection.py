def tri_selection(liste):
    '''Trie la liste  par sélection'''
    for i in range(len(liste)):
        imin = indice_min(liste, i)
        echange(liste, i, imin)
