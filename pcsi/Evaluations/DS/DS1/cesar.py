def codage(decalage):
    lettres = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    dico = {}
    for i in range(len(lettres)):
        icode = (i+decalage)%26
        dico[lettres[i]] = lettres[icode]
    return dico


def cesar(texte,decalage):
    dico = codage(decalage)
    texte_chiffre = ""
    for l in texte:
        if l in dico:
            texte_chiffre += dico[l]
        else:
            texte_chiffre += l
    return texte_chiffre

print(cesar("OK CA MARCHE BIEN !", 10))   
print(cesar("YU MK WKBMRO LSOX !", 16))        
