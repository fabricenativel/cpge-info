def compte_occ(chaine, car):
    cpt = 0
    for c in chaine:
        if c==car:
            cpt += 1
    return cpt

def anagramme_bug(chaine1, chaine2):
    '''Renvoie True ssi chaine1 et chaine2 sont des anagrammes'''
    for c in chaine1:
        if compte_occ(chaine1,c)!=compte_occ(chaine2, c):
            return False
    return True

def anagramme(chaine1, chaine2):
    '''Renvoie True ssi chaine1 et chaine2 sont des anagrammes'''
    for c in chaine1:
        if compte_occ(chaine1,c)!=compte_occ(chaine2, c):
            return False
    return len(chaine1)==len(chaine2)

def cree_dico(chaine):
    dico = {}
    for c in chaine:
        if c in dico:
            # caractère déjà présent, on ajoute 1 à son nombre d'occurrences
            dico[c] = dico[c]+1  
        else:
            # caractère qui apparaît pour la première fois
            dico[c] = 1
    return dico

def egaux(dico1,dico2):
    if len(dico1)!=len(dico2):
        return False
    for cle in dico1:
        if (cle not in dico2 or dico1[cle]!=dico2[cle]):
            return False
    return True

def anagrammes_dico(chaine1,chaine2):
    dico1 = cree_dico(chaine1)
    dico2 = cree_dico(chaine2)
    return egaux(dico1,dico2)

def cree_dico_quadratique(chaine):
    dico = {}
    for c in chaine:
        if c not in dico:
            dico[c] = compte_occ(chaine, c)
    return dico

print(anagramme("niche", "chien"))