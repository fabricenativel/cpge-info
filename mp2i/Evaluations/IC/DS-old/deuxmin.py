def deuxmin(lst):
    assert len(lst)>=2, "La liste doit avoir au moins deux éléments"
    if lst[0]<lst[1]:
        min1 = lst[0]
        min2 = lst[1]
    else:
        min1 = lst[1]
        min2 = lst[0]
    '''On parcourt le reste de la liste :
        - Si un élément est plus petit que le plus petit (min1), il devient le nouveau min1 et l'ancien min1 devient min2.
        - Sinon, si l'élément est plus petit que le second minimum (min2), il devient le nouveau min2.'''
    for i in range(2, len(lst)): 
        if lst[i]<min1:
            min2 = min1
            min1= lst[i]
        elif lst[i]<min2:
            min2 = lst[i]
    return min1, min2

