def imax(l:list[int])->int: # (1)!
    """Prend en entrée une liste non vide d'entiers 
    et renvoie l'indice de la première occurence du maximum""" 
    assert isinstance(l,list),"l'argument doit être une liste" #(2)!
    assert l!=[], "la liste en entrée doit être non vide" 
    im = 0
    maxi = l[0] # (3)!
    for i in range(1,len(l)):
        if l[i]>maxi:
            im = i
            maxi = l[i]
    return im

# Test avec une liste contenant un unique élément :
assert imax([15]) == 0
# Test avec un maximum négatif
assert imax([-12,-3,-15]) == 1
# Test avec le maximum situé en dernière position
assert imax([1, 9, 5, 2, 10]) == 4
# Test avec plusieurs occurences du maximum
assert imax([1, 2, 7, 7, 3, 7, 4, 7]) == 2