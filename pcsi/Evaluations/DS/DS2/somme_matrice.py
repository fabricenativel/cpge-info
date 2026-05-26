def est_valide(chemin, n):
    '''Teste si un chemin est valide : 
    il ne doit contenir que des 0 et des 1
    il doit y avoir n-1 fois 0 et n-1 fois 1
    '''
    nb0 = 0
    nb1 = 0
    for pas in chemin:
        if pas==0:
            nb0 = nb0 + 1
        elif pas==1:
            nb1 = nb1 + 1
        else:
            return False
    if (nb0==n-1 and nb1==n-1):
        return True
    else:
        return False

def somme_chemin(chemin, matrice):
    lig = 0
    col = 0
    somme = matrice[lig][col]
    for pas in chemin:
        if pas==0:
            lig = lig + 1
        if pas==1:
            col = col + 1
        somme = somme + matrice[lig][col]
    return somme

def greedy(matrice):
    lig = 0
    col = 0
    somme = matrice[lig][col]
    n = len(matrice)
    while (lig<n-1 or col<n-1):
        if lig==n-1:
            col = col + 1
        elif col==n-1:
            lig = lig + 1
        elif matrice[lig+1][col]>=matrice[lig][col+1]:
            lig = lig + 1
        else:
            col = col + 1
        somme = somme + matrice[lig][col]
    return somme