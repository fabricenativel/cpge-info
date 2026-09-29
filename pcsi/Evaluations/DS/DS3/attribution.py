def ecart_total(attributions):
    ec = 0
    for une_attribution in attributions:
        demande, creneau = une_attribution
        ec = ec + abs(demande-creneau)
    return ec

def attribue(cible, disponibles):
    res = disponibles[0]
    for d in disponibles:
        if abs(cible-d)<abs(cible-res):
            res = d
    return res

def supprime(n, lst):
    res = []
    suppression = False
    for x in lst:
        if n==x and suppression==False:
            suppression=True
        else:
            res.append(x)
    return res

def attribution(demandes, creneaux):
    attrib = []
    cr = creneaux.copy()
    for d in demandes:
        c = attribue(d, cr)
        cr = supprime(c, cr)
        attrib.append((d,c))
    return attrib


print(attribution([9,11],[10, 7, 16]))
