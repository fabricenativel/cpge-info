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

# --8<-- [start:insere]
def insere(liste, idx):
    '''Insère l'élément d'indice idx dans la liste triée'''
    while idx>0 and liste[idx]<liste[idx-1]:
        echange(liste, idx, idx-1)
        idx -= 1
# --8<-- [end:insere]

# --8<-- [start:tri_insertion]
def tri_insertion(liste):
    '''Trie la liste  par insertion'''
    for i in range(len(liste)):
        insere(liste,i)
# --8<-- [end:tri_insertion]

# --8<-- [start:fusion]
def fusion(l1,l2):
    if l1==[]:
        return l2
    if l2==[]:
        return l1
    if l1[0]<l2[0]:
        return [l1[0]]+fusion(l1[1:],l2)
    return [l2[0]]+fusion(l1,l2[1:])
# --8<-- [end:fusion]

# --8<-- [start:tri_fusion]
def tri_fusion(liste):
    if len(liste)<=1:
        return liste
    l1 = liste[:len(liste)//2]
    l2 = liste[len(liste)//2:]
    return fusion(tri_fusion(l1),tri_fusion(l2))
# --8<-- [end:tri_fusion]


tl = [randint(1, 1000) for _ in range(100)]
tri_selection(tl)
assert est_triee(tl), "La liste n'est pas triée"
tl = [randint(1, 1000) for _ in range(100)]
tri_insertion(tl)
assert est_triee(tl), "La liste n'est pas triée"
tl = [randint(1, 1000) for _ in range(100)]
tl = tri_fusion(tl)
assert est_triee(tl), "La liste n'est pas triée"
print("all test ok")