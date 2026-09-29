def incremente_valeurs(dictionnaire):
    """
    prend un dictionnaire en argument et ajoute 1
    à toutes les valeurs du dictionnaires
    """
    for cle in dictionnaire:
        dictionnaire[cle] += 1
    

mon_dico = {'A' : 5, 'B' : 12, 'C': 13}
incremente_valeurs(mon_dico)
# affiche {'A': 6, 'B': 13, 'C': 14}
print(mon_dico)