# importation des fonction de la librairie
from lib_laby import *

# création de la carte depuis le fichier 
carte = lire_labyrinthe("ex1.txt")
# initialisation de l'interface graphique
papier, crayon = init()
# visualisation du labyrinthe
visualise(crayon,carte)
# attendre un clic pour fermer l'interface graphique
attendre(crayon,papier)