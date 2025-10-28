def insere(liste, idx):
    '''Insère l'élément d'indice idx dans la liste triée'''
    while idx>0 and liste[idx]<liste[idx-1]:
        echange(liste, idx, idx-1)
        idx -= 1
