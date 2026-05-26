from colorama import Fore

# --8<-- [start:Q4]
def tour_joueur1(jeu):
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
    # La prochaine position où on va semer
    pos = (case + 1) % 12
    while a_semer != 0:
        plateau[pos] += 1
        a_semer -= 1
        pos = (pos + 1) % 12
        # On ne doit pas semer dans la case initiale
        if (pos == case):
            pos = (pos + 1) % 12
    return (pos-1) % 12
# --8<-- [end:Q8]

# --8<-- [start:Q9]
def case_ramassable(plateau, case):
    '''Renvoie True si la case est ramassable, False sinon'''
    return (6 <= case <= 11) and (2 <= plateau[case] <= 3)
# --8<-- [end:Q9]

# --8<-- [start:Q10]
def ramasser_graines(plateau, case):
    '''Ramasse les graines de la case et renvoie le nombre de graines ramassées'''
    # le cas de base
    if not case_ramassable(plateau, case):
        return 0
    # l'appel récursif
    recolte = plateau[case]
    plateau[case] = 0
    return recolte + ramasser_graines(plateau, case - 1)
# --8<-- [end:Q10]

# --8<-- [start:Q11]
def test_famine(plateau, case):
    '''Renvoie True lorsque la récolte ne conduit pas à la famine de l'adversaire'''
    copie_plateau = plateau.copy()
    derniere_case = deplacer_graines(copie_plateau, case)
    recolte = ramasser_graines(copie_plateau, derniere_case)
    # On parcourt les cases de l'adversaire si l'une contient des graines, il n'y a pas famine
    for i in range(6, 12):
        if copie_plateau[i] != 0:
            return True
    return False
# --8<-- [end:Q11]

# --8<-- [start:Q12]
def test_case(plateau, case):
    '''Vérfie si la case choisie par le joueur est acceptable 
    renvoie True si la case est acceptable, False sinon'''
    condition3 = test_famine(plateau, case)
    # case acceptable
    test = (0 <= case <= 5) and (plateau[case] != 0) and condition3
    return test
# --8<-- [end:Q12]

# --8<-- [start:Q13]
def cases_possibles(jeu):
    '''Renvoie la liste des cases jouables'''
    plateau = jeu['plateau']
    return [i for i in range(6) if test_case(plateau, i)]
# --8<-- [end:Q13]

# --8<-- [start:Q14]
def tour_suivant(jeu):
    '''Renvoie True si le jeu peut continuer'''
    # On vérifie les conditions de fin de partie (voir page 9 du sujet)
    # 1. Un joueur a récolté au moins 25 graines
    if jeu['score'][0] >= 25 or jeu['score'][1] >= 25:
        return False
    # 2. Le nombre de tours joués >= 100
    if jeu['n']>=100:
        return False
    # 3. Il reste moins de 3 graines sur le plateau
    reste = 0
    for graines in jeu['plateau']:
        reste += graines
    if reste <= 3:
        return False
    # 4. Le joueur actif n'a pas de coup valide
    if len(cases_possibles(jeu)) == 0:
        return False
    return True
# --8<-- [end:Q14]

# --8<-- [start:Q15]
def tour_jeu(jeu, case):
    plateau = jeu['plateau']
    if test_case(plateau, case):  # La case jouée est acceptable
        # Semer et récupérer la derniere case atteinte
        derniere_case = deplacer_graines(plateau, case)
        # Récolter depuis la derniere case
        graines_gagnees = ramasser_graines(plateau, derniere_case)
        if tour_joueur1(jeu):
            jeu['score'][0] += graines_gagnees
        else:
            jeu['score'][1] += graines_gagnees
        jeu['n'] += 1
        tourner_plateau(jeu)
        return tour_suivant(jeu)
    else:
        print("La case choisie n'est pas valide !")
        return True
# --8<-- [end:Q15]

'''La fonction d'initialisation du jeu (donnée page 6 du sujet)'''


def initialisation(nom_joueur1, nom_joueur2):
    jeu = {}
    jeu['joueur1'] = nom_joueur1
    jeu['joueur2'] = nom_joueur2
    jeu['score'] = [0, 0]
    jeu['n'] = 0
    jeu['plateau'] = [4]*12
    return jeu

# --8<-- [start:Q16]
def gagnant(jeu):
    # Suivant le joueur actif on regarde quelle partie du plateau ramsser
    if tour_joueur1(jeu):
        for i in range(0, 6):
            jeu['score'][0] += jeu['plateau'][i]
        for i in range(6, 12):
            jeu['score'][1] += jeu['plateau'][i]
    else:
        for i in range(6, 12):
            jeu['score'][0] += jeu['plateau'][i]
        for i in range(0, 6):
            jeu['score'][1] += jeu['plateau'][i]
    if jeu['score'][0] > jeu['score'][1]:
        return jeu['joueur1']
    elif jeu['score'][0] < jeu['score'][1]:
        return jeu['joueur2']
    else:
        return "égalité"
# --8<-- [end:Q16]

def affiche(jeu):
    haut = chr(0x250f) + (chr(0x2501)+chr(0x2501)+chr(0x2533)) * \
        5 + chr(0x2501)+chr(0x2501) + chr(0x2513)
    sep = chr(0x2503)
    print(Fore.CYAN+haut)
    print(sep, end="")
    for i in range(11, 5, -1):
        if jeu['plateau'][i] < 10:
            print(" ", end="")
        print(Fore.YELLOW+str(jeu['plateau'][i]), end="")
        print(Fore.CYAN+sep, end="")
    print("")
    milieu = chr(0x2523) + (chr(0x2501)+chr(0x2501)+chr(0x254B)) * \
        5 + chr(0x2501)+chr(0x2501) + chr(0x252B)
    print(Fore.CYAN+milieu)
    print(sep, end="")
    for i in range(0, 6):
        if jeu['plateau'][i] < 10:
            print(" ", end="")
        print(Fore.YELLOW+str(jeu['plateau'][i]), end="")
        print(Fore.CYAN+sep, end="")
    print("")
    bas = chr(0x2517) + (chr(0x2501)+chr(0x2501)+chr(0x253B)) * \
        5 + chr(0x2501)+chr(0x2501) + chr(0x251B)
    print(Fore.CYAN+bas)
    score1 = Fore.WHITE+jeu["joueur1"]+" : "+Fore.RED+str(jeu["score"][0])
    score2 = Fore.WHITE+jeu["joueur2"]+" : "+Fore.RED+str(jeu["score"][1])
    print(score1+" "*(39-len(score1+score2))+score2)
    print(Fore.WHITE,end="")

# --8<-- [start:Q17]
def gain(jeu, case):
    '''Renvoie le nombre de graines gagnées et un nouveau dictionnaire'''
    njeu = copie(jeu)
    plateau = njeu["plateau"]
    # Semer et récupérer la derniere case atteinte
    derniere_case = deplacer_graines(plateau, case)
    # Récolter depuis la derniere case
    graines_gagnees = ramasser_graines(plateau, derniere_case)
    if tour_joueur1(jeu):
        jeu['score'][0] += graines_gagnees
    else:
        jeu['score'][1] += graines_gagnees
    njeu['n'] += 1
    tourner_plateau(njeu)
    return graines_gagnees, njeu
# --8<-- [end:Q17]

# --8<-- [start:Q20]
def max_vals(vals_jeu, profondeur):
    # On recherche l'indice du maximum
    ind_max = 0
    for i in range(1, len(vals_jeu)):
        # vals_jeu contient des couples (case, valeur de jeu) 
        if vals_jeu[i][1] > vals_jeu[ind_max][1]:
            ind_max  = i
    # Les deux cas à distinguer (le noeud de départ correspond à une profondeur nulle)
    if profondeur==0:
        return vals_jeu[ind_max][0]
    else:
        return vals_jeu[ind_max][1]
# --8<-- [end:Q20]


# --8<-- [start:Q19]
def Negawale(jeu, profondeur_max, profondeur):
    #Ce sont les conditions décrites à la page 12 du sujet : noeud feuille, profondeur maximale atteinte ou autre
    # Condition1 : noeud feuille (le jeu se termine)
    if (not tour_suivant(jeu)):
        if (tour_joueur1(jeu) and gagnant(jeu)==jeu["joueur1"]) or (not tour_joueur1(jeu) and gagnant(jeu)==jeu["joueur2"]):
            return 500
        elif (tour_joueur1(jeu) and gagnant(jeu)==jeu["joueur2"]) or (not tour_joueur1(jeu) and gagnant(jeu)==jeu["joueur1"]):
            return -500
        else:
            return 0
    # Condition 2 : profondeur maximale atteinte
    elif profondeur==profondeur_max:
        return 0
    else:
        choix_cases = cases_possibles(jeu)
        vals_jeu = []
        for case in choix_cases:
            g, nouveau_jeu = gain(jeu, case)
            p = Negawale(nouveau_jeu,profondeur_max, profondeur+1)
            vals_jeu.append([case, g-p])
        return max_vals(vals_jeu, profondeur)
# --8<-- [end:Q19]

''' La boucle principale du jeu en jcj (donnée page 7 du sujet)'''
def awale_jcj(nom_joueur1, nom_joueur2):
    jeu = initialisation(nom_joueur1, nom_joueur2)
    jeu_continue = True
    while jeu_continue:
        affiche(jeu)
        case_choisie = int(input("Choisissez une case: "))
        jeu_continue = tour_jeu(jeu, case_choisie)
    return gagnant(jeu)

# --8<-- [start:Q21]
def awale_ia(nom_joueur1, nom_joueur2):
    jeu = initialisation(nom_joueur1, nom_joueur2)
    jeu_continue = True
    while jeu_continue:
        affiche(jeu)
        case_choisie = Negawale(jeu, 6, 0)
        jeu_continue = tour_jeu(jeu, case_choisie)
        _ = input("")
    return gagnant(jeu)
# --8<-- [end:Q21]

print(awale_ia("Alice", "Bob"))
