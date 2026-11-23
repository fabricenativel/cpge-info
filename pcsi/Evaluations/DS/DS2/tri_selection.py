from random import randint

def echange(lst, i, j):
    '''Echange les éléments d'indice i et j dans lst'''
    assert 0<= i < len(lst) and 0<=j < len(lst)
    lst[i], lst[j] = lst[j], lst[i]

def indice_min_depuis(lst, i):
    '''Renvoie l'indice du minimum de lst à partir de l'indice i'''
    imin = i
    for j in range(i+1, len(lst)):
        if lst[j] < lst[imin]:
            imin = j
    return imin

def tri_selection(liste):
    '''Trie la liste  par sélection'''
    for i in range(len(liste)):
        imin = indice_min_depuis(liste, i)
        echange(liste, i, imin)


alea  = [randint(0, 1000) for _ in range(100)]
tri_selection(alea)
assert(all(alea[i]<=alea[i+1] for i in range(len(alea)-1)))