from typing import Tuple, List

point = Tuple[float, float, float]
itineraire = List[point]

dem = {(2.3,7.5):11.3}
lat_ref = {x for (x,y) in dem}
long_ref = {y for (x,y) in dem}


# --8<-- [start:Q10]
def altitude_maximale(iti: itineraire) -> float:
    lat0, long0, alt_max = iti[0]
    for point in iti:
        lat, long, alt = point
        if alt > alt_max:
            alt_max = alt
    return alt_max
# --8<-- [end:Q10]


# --8<-- [start:Q11]
def denivele_globale(iti: itineraire) -> float:
    lat0, long0, alt0 = iti[0]
    return altitude_maximale(iti) - alt0
# --8<-- [end:Q11]

# --8<-- [start:Q12]
def denivele_positif_cumule(iti: itineraire) -> float:
    dpc = 0
    for i in range(1, len(iti)):
        alt_courante = iti[i][2]
        alt_precedente = iti[i-1][2]
        deniv = alt_courante - alt_precedente
        if deniv > 0:
            dpc += deniv
    return dpc
# --8<-- [end:Q12]

# --8<-- [start:Q13]
def alt_glissante(liste_alt: list, p: int):
    altg = []
    n = len(liste_alt)
    for i in range(len(liste_alt)):
        j = min(p-1, n-i-1)
        somme_alt = 0
        for k in range(i, i+j+1):
            somme_alt += liste_alt[k]
        altg.append(somme_alt/(j+1))
    return altg
# --8<-- [end:Q13]


# --8<-- [start:Q20]
def ref(valeur: float, liste_ref: list) -> float:
    # on détermine ind_deb et ind_fin tels que
    # liste_ref[ind_deb]< valeur <= liste_ref[ind_fin]
    # avec une méthode par dichotomie
    ind_deb = 0
    ind_fin = len(liste_ref) - 1
    while ind_deb < ind_fin - 1:
        k = (ind_deb+ind_fin)//2
        if valeur <= liste_ref[k]:
            ind_fin = k
        else:
            ind_deb = k
    # o on détermine le plus proche
    if liste_ref[ind_fin] - valeur < valeur-liste_ref[ind_deb]:
        return liste_ref[ind_fin]
    else:
        return liste_ref[ind_deb]
# --8<-- [end:Q20]


# --8<-- [start:Q21]
def standardise(liste_parcours:itineraire) -> itineraire:
    parcours_std = []
    for i in range(len(liste_parcours)):
        lat, long, alt = liste_parcours[i]
        lat_pp_dem = ref(lat_ref, lat)
        long_pp_dem = ref(long_ref, long)
        parcours_std.append(lat, long, dem[(lat_pp_dem,long_pp_dem)])
    return parcours_std
# --8<-- [end:Q21]


# --8<-- [start:Q26]
# On applique l'algorithme de Dijkstra :
sInit , sFin = "a", "f"
distance = dijkstra(G, sInit, sFin)

# On construit la liste du chemin en partant de la fin :
s = sFin
chemin = [s]
while s != sInit:
    chemin.append(distance[s][1])
    s = distance[s][1]
# On remet le chemin dans l'ordre du début vers la fin
chemin.reverse()

print("Un chemin de ", sInit, " à ", sFin, " est : ", chemin)
print("La difficulté minimale est de :",distance[sFin][0])
# --8<-- [end:Q26]

p0 = (47.8741, 1.8758, 100)
p1 = (47.8744, 1.8759, 102)
p2 = (47.8748, 1.8761, 110)
p3 = (47.8750, 1.8759, 108)
iti_test = [p0, p1, p2, p3]

assert (altitude_maximale(iti_test) == 110)
assert (denivele_globale(iti_test) == 10)
assert (denivele_positif_cumule(iti_test) == 10)
assert (alt_glissante([0, -2, 2, -2, 2, -2, 2, -2, 2], 2)
        == [-1, 0, 0, 0, 0, 0, 0, 0, 2])
assert (ref(11, [1, 2, 4, 5, 6, 10, 13, 15, 16, 17]) == 10)
