def dechiffre(message, carre):
    res = ""
    for entier in message:
        if entier!=10:
            ligne = entier//10 - 1
            colonne = entier%10 - 1
            res += carre[ligne][colonne]
        else:
            res += " "
    return res

def cree_dico(polybe):
    dico = {' ' : 10}
    for i in range(5):
        for j in range(5):
            dico[polybe[i][j]] = (i+1)*10+(j+1)
    return dico

def chiffre(message, carre):
    dico = cree_dico(carre)
    res = [dico[x] for x in message]
    return res


clavier = [    
['A','Z','E','R','T'],
['Y','U','I','O','P'],
['Q','S','D','F','G'],
['H','J','K','L','M'],
['X','C','V','B','N']
]

colonne = [    
['A','F','K','P','U'],
['B','G','L','Q','V'],
['C','H','M','R','X'],
['D','I','N','S','Y'],
['E','J','O','T','Z']
]

print(dechiffre([54, 24, 55, 42, 24, 22, 14],clavier))
print(chiffre("BRAVO VOUS AVEZ REUSSI SO FAR SO GOOD", colonne))


print(dechiffre([21, 34, 11, 25, 53, 10, 25, 53, 15, 44, 10, 11, 25, 51, 55, 10, 34, 51, 15, 44, 44, 42, 10, 44, 53, 10, 12, 11, 34, 10, 44, 53, 10, 22, 53, 53, 41], colonne))
print(cree_dico(clavier))

print(chiffre("SUPER LES PCSI", colonne))