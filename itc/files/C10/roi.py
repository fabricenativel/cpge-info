from random import randint

deplacements = {'N': (1, 0),
                'NE': (1, 1),
                'E': (0, 1),
                'SE': (-1, 1),
                'S': (-1, 0),
                'SO' : (-1,-1),
                'O' : (0,-1),
                'NO' : (1,-1)
                }

codage = {i+1:d for i,d in enumerate(deplacements)}


def deplacement(case, dep):
    lig, col = int(case[-1]), ord(case[0])
    dlig, dcol = deplacements[dep]
    nlig, ncol = lig+dlig, col+dcol
    if  1<=nlig<=8 and 'A'<=chr(ncol)<='H':
        return chr(ncol)+ str(nlig)
    else:
        return case

def promenade(depart, ldep):
    parcours = [depart]
    pos = depart
    for d in ldep:
        npos = deplacement(pos, d)
        if npos!=pos:
            parcours.append(npos)
            pos = npos
    return parcours

def compte(parcours):
    dico = {}
    for case in parcours:
        if case not in dico:
            dico[case]=1
        else:
            dico[case] +=1
    return dico

def max_dico(dico):
    maxc = 0
    for case in dico:
        if dico[case]>maxc:
            maxc = dico[case]
            casemax = [case]
        elif dico[case]==maxc:
            casemax.append(case)
    return casemax, maxc


start = 'E8'
ldep =  [codage[randint(1,8)] for i in range(100)]
print("déplacements", ldep)
parcours=promenade(start,ldep)
print(parcours)
dico = compte(parcours)
print(dico)
print(f"Nombre de case parcourues : {len(dico)}")
print(f"Case la plus visitée : {max_dico(dico)}")
