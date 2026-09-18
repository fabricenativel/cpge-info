nb_jours = {1: 31, 2: 28, 3: 31, 4: 30, 5: 31, 6: 30,
            7: 31, 8: 31, 9: 30, 10: 31, 11: 30, 12: 31}


def bissextile(annee):
    return (annee % 4 == 0 and annee % 100 != 0) or annee % 400 == 0


def lendemain(j, m, a):
    dec = 0
    if m == 2 and bissextile(a):
        dec = 1
    if j < nb_jours[m]+dec:
        return j+1, m, a
    if m < 12:
        return 1, m+1, a
    return 1, 1, a+1


def cree(date):
    j, m, a = date.split("/")
    return int(j), int(m), int(a)


def ecart(date1, date2):
    j1, m1, a1 = cree(date1)
    j2, m2, a2 = cree(date2)
    cpt = 0
    while (j1,m1,a1) != (j2,m2,a2):
        cpt += 1
        j1, m1, a1 = lendemain(j1, m1, a1)
    return cpt

print(ecart("25/01/1942","17/12/2022"))

