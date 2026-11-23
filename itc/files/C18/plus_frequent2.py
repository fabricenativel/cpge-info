def plus_frequent(liste):
    nb_occ = {}
    for elt in liste:
        if elt not in nb_occ:
            nb_occ[elt] = 1
        else:
            nb_occ[elt] += 1
    return max(nb_occ[elt] for elt in nb_occ)