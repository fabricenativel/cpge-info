def compte_occurence(elt,liste):
    occ = 0
    for x in liste:
        if x==elt:
            occ+=1
    return occ

def plus_frequent(liste):
    max_occ = 0
    for elt in liste:
        elt_occ = compte_occurence(elt,liste)
        if elt_occ>max_occ:
            max_occ = elt_occ
    return max_occ
        
