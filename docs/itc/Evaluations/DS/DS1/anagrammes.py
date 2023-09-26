def supprime_premier(car, chaine):
    res = ''
    # On parcourt la chaine en la recopiant et
    # on s'arrête la première fois qu'on rencontre le caractère à supprimer
    for i in range(len(chaine)):
        if chaine[i]!=car:
            res = res + chaine[i]
        else:
            break
    #On copie le reste de la chaine
    res = res + chaine[i+1:]
    return res

def anagrammes_rec(chaine1,chaine2):
    if len(chaine1)==0 and len(chaine2)==0:
        return True
    nchaine2 = supprime_premier(chaine1[0],chaine2)
    # Si la suppression n'a rien donné, alors ce ne sont pas des anagrammes
    if len(nchaine2)==len(chaine2):
        return False
    return anagrammes_rec(chaine1[1:],nchaine2)

def cree_dico(chaine):
    dico = {}
    for c in chaine:
        if c in dico:
            #caractere déjà présent, on ajoute 1 à son nombre d'occurence
            dico[c] = dico[c]+1  
        else:
            #caractere qui apparait pour la première fois
            dico[c] = 1
    return dico

def egaux(dico1,dico2):
    if len(dico1)!=len(dico2):
        return False
    for cle in dico1:
        if (cle not in dico2 or dico1[cle]!=dico2[cle]):
            return False
    return True

def anagrammes_iter(chaine1,chaine2):
    dico1 = cree_dico(chaine1)
    dico2 = cree_dico(chaine2)
    return egaux(dico1,dico2)

print(anagrammes_iter("niche","chien"))