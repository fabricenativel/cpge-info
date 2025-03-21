# --8<-- [start:Q4]
def tour_jour1(jeu):
    '''Renvoie True si c'est le tour du joueur 1, False sinon.'''
    # jeu['n'] est nombre de tour déjà joués c'est le tour du joueur 1 lorsque jeu['n'] est pair
    return jeu['n'] % 2 == 0
# --8<-- [end:Q4]

# --8<-- [start:Q5] 
def tourner_plateau(jeu):
    '''Ne renvoie rien et modifie le plateau pour inverses les cases des joueurs 1 et 2'''
    jeu['plateau'][0:6], jeu['plateau'][6:12] = jeu['plateau'][6:12], jeu['plateau'][0:6]
# --8<-- [end:Q5] 

# --8<-- [start:Q7] 
def copie(jeu):
    '''Renvoie une copie du dictionnaire jeu'''
    copie_jeu = {}
    copie_jeu['joueur1'] = jeu['joueur1']
    copie_jeu['joueur2'] = jeu['joueur2']
    copie_jeu['score'] = jeu['score'].copy()
    copie_jeu['n'] = jeu['n']
    copie_jeu['plateau'] = jeu['plateau'].copy()
    return copie_jeu
# --8<-- [end:Q7]


# --8<-- [start:Q8]
def deplacer_graines(plateau, case):
    a_semer = plateau[case]
    plateau[case] = 0
    pos = (case + 1) % 12
    while a_semer != 0:
        plateau[pos] += 1
        a_semer -= 1
        pos = (pos + 1) % 12
    return pos
# --8<-- [end:Q8]

# --8<-- [start:Q9]
def case_ramassable(plateau, case):
    '''Renvoie True si la case est ramassable, False sinon'''
    return (6 <= plateau[case] <= 11) and (2 <= plateau[case] <= 3)
# --8<-- [end:Q9]
