def nb_occ(car, chaine):
    # On initialise à 0 le nombre d'occurrences
    cpt = 0
    # On parcourt par élément la chaîne
    for elt in chaine:
        # Si un élément de la chaîne est le caractère cherché
        if elt == car:
            # On incrémente le nombre d'apparitions
            cpt += 1
    return cpt