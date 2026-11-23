def simulation_langton(n=100, start_l=50, start_c=50, start_dir=0, nb_pas=1000):
    """
    Simulation de la fourmi de Langton sur une grille n x n.
    Orientation: 0: Haut, 1: Droite, 2: Bas, 3: Gauche
    Grille: 0 = Blanc, 1 = Noir
    """
    grille = [[0] * n for _ in range(n)]
    delta = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    dir_names = ["Haut", "Droite", "Bas", "Gauche"]

    l, c, d = start_l, start_c, start_dir

    for _ in range(nb_pas):
        couleur = grille[l][c]
        # Inversion de la couleur
        grille[l][c] = 1 - couleur
        # Rotation
        if couleur == 0:  # case blanche -> 90° à droite
            d = (d + 1) % 4
        else:             # case noire -> 90° à gauche
            d = (d - 1) % 4
        # Avancée d'une case
        dl, dc = delta[d]
        l += dl
        c += dc

    return l, c, dir_names[d]

ligne, col, orientation = simulation_langton(100, 50, 50, 0, 1000)
print(f"Après 1000 déplacements, la fourmi se trouve en ligne {ligne}, colonne {col} (orientée vers le {orientation}).")
