dico1 = {'A' : 5, 'B' : 12, 'C': 13}
dico2 = dico1
dico2['A'] = 20
# dico1 est modifié aussi et donc l'instruction suivante affiche 20
print(dico1['A'])