def max_liste(l):
    # la liste doit être non vide
    assert len(l)!=0
    current_max = l[0]
    for elt in l:
        if elt>current_max:
            current_max = elt
    return current_max
