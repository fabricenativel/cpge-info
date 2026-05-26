def somme(lst):
    s = 0
    for x in lst:
        s = s + x
    return s

def moyenne(lst):
    return somme(lst)/len(lst)

def maximum(lst):
    maxi = lst[0]
    for x in lst:
        if x>maxi:
            maxi=x
    return maxi

def minimum(lst):
    mini = lst[0]
    for x in lst:
        if x<mini:
            mini=x
    return mini

def moyenne_olympique(lst):
    somme = 0
    for x in lst:
        somme =  somme + x
    somme = somme - minimum(lst) - maximum(lst)
    return somme/(len(lst)-2)

def moyenne_ponderee(lst):
    somme = 0
    somme_coeff = 0
    for x in lst:
        # x est un tuple de la forme (note, coeff) qu'on décompacte :
        note, coeff = x
        somme_coeff = somme_coeff + coeff
        somme = somme + note*coeff
    return somme/somme_coeff