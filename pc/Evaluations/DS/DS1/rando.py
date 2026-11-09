
def import_rando(nom_fichier):
    reader = open(nom_fichier, "r")
    premiere_ligne = reader.readline()
    lignes = reader.read().strip().split('\n')
    reader.close()
    coords = []
    for l in lignes:
        lat, long, h, t = l.split(',')
        coords.append([float(lat), float(long), float(h), float(t)])
    return coords


def import_rando(nom_fichier):
    reader = open(nom_fichier, "r")
    lignes = reader.read().strip().split('\n')[1:]
    reader.close()
    coords = [list(map(float, l.split(','))) for l in lignes]
    return coords


def plus_haut(coords):
    premier_point = coords[0]
    phaut = premier_point[0], premier_point[1]
    max_haut = premier_point[2]
    for i in range(1, len(coords)):
        if coords[i][2] > max_haut:
            max_haut = coords[i][2]
            phaut = coords[i][0], coords[i][1]
    return phaut


def deniv(coords):
    dpositif, dnegatif = 0, 0
    for i in range(1, len(coords)):
        alt = coords[i][2]
        prec = coords[i-1][2]
        if alt > prec:
            dpositif += (alt-prec)
        else:
            dnegatif += (alt-prec)
    return dpositif, dnegatif

def deniv(coords):
    dpositif = sum([coords[i][2]-coords[i-1][2] for i in range(1,len(coords)) if coords[i][2]>coords[i-1][2]])
    dnegatif = sum([coords[i-1][2]-coords[i][2] for i in range(1,len(coords)) if coords[i-1][2]>coords[i][2]])
    return dpositif, dnegatif


from math import asin, sin, cos, sqrt, radians
RT = 6371
def distance(p1,p2):
    phi1, lambda1, alt1 = radians(p1[0]), radians(p1[1]), p1[2]
    phi2, lambda2, alt2 = radians(p2[0]), radians(p2[1]), p2[2]
    alt_moyenne = (alt1+alt2)/2 + RT*1000
    m1 = sin((phi2-phi1)/2)**2
    m2 = sin((lambda2-lambda1)/2)**2
    darc = 2*alt_moyenne*asin(sqrt(m1+cos(phi1)*cos(phi2)*m2))
    return sqrt(darc**2+(alt2-alt1)**2)

def distance_totale(coords):
    dt = 0
    for i in range(1,len(coords)):
        dt += distance(coords[i-1],coords[i])
    return dt

coords = import_rando("parcours.csv")
print(plus_haut(coords))
print(deniv(coords))
print(distance(coords[0],coords[1]))
print(distance_totale(coords))