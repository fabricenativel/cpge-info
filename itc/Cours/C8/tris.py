from random import randint
    

def est_triee(liste):
    return all(liste[i+1]>=liste[i] for i in range(len(liste)-1))

# --8<-- [start:indice_min]
def indice_min(liste, idx):
    '''Renvoie l'indice du plus petit élément de la liste à partir de l'indice idx'''
    imin = idx
    for i in range(idx+1, len(liste)):
        if liste[i] < liste[imin]:
            imin = i
    return imin
# --8<-- [end:indice_min]

# --8<-- [start:echange]
def echange(liste, i, j):
    '''Echange les éléments d'indices i et j dans la liste'''
    liste[i], liste[j] = liste[j], liste[i]
# --8<-- [end:echange]

# --8<-- [start:tri_selection]
def tri_selection(liste):
    '''Trie la liste  par sélection'''
    for i in range(len(liste)):
        imin = indice_min(liste, i)
        echange(liste, i, imin)
# --8<-- [end:tri_selection]



tl = [randint(1, 1000) for _ in range(100)]
tri_selection(tl)
assert est_triee(tl), "La liste n'est pas triée"
print("all test ok")