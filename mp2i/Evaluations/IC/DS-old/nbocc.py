def nb_occ(car, chaine):
    # On initialise à 0 le nombre d'occurrence
    cpt = 0
    # On parcourt par élément la chaine
    for elt in chaine:
        # Si un élément est de la chaine est le caractère cherché
        if elt == car:
            # On incrémente le nombre d'apparitions
            cpt += 1
    return cpt