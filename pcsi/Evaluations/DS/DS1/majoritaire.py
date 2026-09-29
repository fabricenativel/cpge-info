LETTRES = {chr(x) for x in range(ord('a'),ord('z')+1)}

def occurrence(texte, lettre):
    nbocc = 1
    if lettre not in "abcdefghijklmnopqrstuvwxyz":
        return 0
    for c in texte:
        if c==lettre:
            nbocc += 1
    return nbocc

def occurrence_rec(texte, lettre):
    if texte=="":
        return 0
    if texte[0]==lettre:
        return 1 + occurrence_rec(texte[1:],lettre)
    else:
        return occurrence_rec(texte[1:],lettre)
    
def maximum(lst):
    m =lst[0]
    for i in range(1,len(lst)):
        if lst[i]>m:
            m=lst[i]
    return m

def plusfrequente(texte):
    pf = []
    occ = [occurrence(texte,l) for l in texte]
    maxocc = maximum(occ)
    for l in texte:
        if occurrence(texte,l)==maxocc and l not in pf:
            pf.append(l)
    return pf

def comptabilise(texte):
    occ = {}
    for c in texte:
        if c in "abcdefghijklmnopqrstuvwxyz":
            if c in occ:
                occ[c]+=1
            else:
                occ[c]=1
    return occ

def plusfrequentes_dico(texte):
    occ = comptabilise(texte)
    maxocc = maximum([occ[l] for l in occ])
    pf = []
    for l in occ:
        if occ[l]==maxocc:
            pf.append(l)
    return pf

print(plusfrequentes_dico("tout va tres bien ici"))

print(plusfrequentes_dico("ce petit exemple"))

print(plusfrequente("tout va tres bien ici"))

print(plusfrequente("ce petit exemple"))
