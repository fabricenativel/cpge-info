# import Python à compléter...

# importation du fichier d'une randonnée
def importe_rando(nom_fichier):
    # À compléter...

coords = importe_rando("suivi_rando.csv")

# donne le point (latitude, longitude) le plus haut de la randonnée
def plus_haut(coords):
    # À compléter...

print("point le plus haut", plus_haut(coords))
# exemple : point le plus haut [45.461451, 6.443064]

# calcul des dénivelés positif et négatif de la randonnée
def deniveles(coords):
    # À compléter...

print("denivelés", deniveles(coords), "m")
# exemple : denivelés [4.059999999999945, -1.1759999999999309] m

RT = 6371 # rayon moyen volumétrique de la Terre en km

# distance entre deux points
def distance(coord1, coord2):
    # À compléter...

print("premier intervalle", distance(coords[0], coords[1]), "m")
# exemple : premier intervalle 16.230964254992816 m

# distance totale de la randonnée
def distance_totale(coords):
    # À compléter...

print("distance parcourue", distance_totale(coords), "m")
# exemple : distance parcourue 187.9700904658368 m