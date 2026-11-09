# Ouverture du fichier
desc_fic = open("informaticiens.txt")
# Lecture de la première ligne 
ligne1 = desc_fic.readline()
# le pointeur de lecture est positionné à la ligne suivante, un autre appel à readline lira donc la 2e ligne
ligne2 = desc_fic.readline()
# Lecture terminée on ferme le fichier
desc_fic.close()
print(ligne1)
print(ligne2)