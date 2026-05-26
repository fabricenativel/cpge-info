code = {
    '#': (0, 0.01),
    'a': (0.01, 0.2),
    'b': (0.2, 0.3),
    'c': (0.3, 0.5),
    'd': (0.5, 0.9),
    'e': (0.9, 1)
}

# --8<-- [start:Q1]


def nbCaracteres(c: str, s: str) -> int:
    compteur = 0
    for l in s:
        if l == c:
            compteur += 1
    return compteur
# --8<-- [end:Q1]

# --8<-- [start:Q2]


def analyseTexteDictionnaire(s: str):
    R = {}
    for c in s:
        if c in R:  # Caractère déjà rencontré : on incrémente son nombre d'occurrences
            R[c] = R[c] + 1
        else:  # Le caractère apparaît pour la première fois
            R[c] = 1
    return R
# --8<-- [end:Q2]


def codeCar(car, g, d):
    long = d-g
    gcar, dcar = code[car]
    return g+gcar*long, g+dcar*long

# --8<-- [start:Q11]


def codage(s: str) -> (float, float):
    # Bornes de l'intervalle actuel
    g = 0.0
    d = 1.0
    for c in s:
        (g, d) = codeCar(c, g, d)
    return g, d
# --8<-- [end:Q11]


def decodeCar(x: float, g: float, d: float) -> str:
    r = (x-g)/(d-g)
    for c in code:
        if code[c][0] <= r < code[c][1]:
            return c


# --8<-- [start:Q14]
def decodage(x: float) -> str:
    g, d = 0.0, 1.0
    s = ""
    c = decodeCar(x, g, d)
    while c != "#":
        s = s+c
        g, d = codeCar(c, g, d)
        c = decodeCar(x, g, d)
    return s
# --8<-- [end:Q14]

# --8<-- [start:Q18]


def maximumListe(liste: [float]) -> (float, int):
    '''Pour une liste de flottant renvoie le couple (maximum des éléments, indice de la 1ere occurrence de ce maximum)'''
    assert len(liste) > 0
    vmax = liste[0]
    imax = 0
    for i in range(1, len(liste)):
        if liste[i] > vmax:
            vmax = liste[i]
            imax = i
    return (vmax, imax)
# --8<-- [end:Q18]

# --8<-- [start:Q19a]


def initialiserGlouton(Obs, E, K):
    probasInitiales = [E[Obs[0]][i] for i in range(K)]
    s, symbole = maximumListe(probasInitiales)
    return symbole
# --8<-- [end:Q19a]


# --8<-- [start:Q19b]
def glouton(Obs: [int], P: [[float]], E: [[float]], K: int, N: int) -> [int]:
    chemin = []
    symbole_prec = initialiserGlouton(Obs, E, K)
    chemin.append(symbole_prec)
    for symbole in Obs[1:]:
        probas = [P[symbole_prec][j] * E[symbole][j] for j in range(K)]
        s, symbole_prec = maximumListe(probas)
        chemin.append(symbole_prec)
    return chemin
# --8<-- [end:Q19b]

# --8<-- [start:Q23]
def construireTableauViterbi(Obs:[int], P:[[float]], E:[[float]], K:int, N:int) -> ([[float]],[[int]]):
    T, argT = initialiserViterbi(E, Obs[0], K, N)
    for j in range(1, N):
        for i in range(K):
            temp = [T[k][j-1]*P[k][i]*E[Obs[j][i] for k in range(K)]]
            T[i][j], argT[i][j] = maximumListe(temp)
    return T, argT
# --8<-- [end:Q23]


print(codage("adccb#"))
print(decodage(0.132969))
