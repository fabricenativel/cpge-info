def next(terme):
    courant = terme[0]
    nb = 1
    suivant = ""
    for i in range(1,len(terme)):
        if terme[i]==courant:
            nb += 1
        else:
            suivant = suivant + str(nb)+courant
            courant = terme[i]
            nb = 1
    suivant = suivant + str(nb)+courant
    return suivant

def suivant_rec(terme):
    if len(terme)==0:
        return ""
    if len(terme)==1:
        return "1"+terme
    if len(terme)==2:
        if (terme[0]==terme[1]):
            return "2"+terme[0]
        else:
            return "1"+terme[0]+"1"+terme[1]
    else:
        if (terme[0]==terme[1]==terme[2]):
            return "3"+terme[0]+suivant_rec(terme[3:])
        if (terme[0]==terme[1]):
            return "2"+terme[0]+suivant_rec(terme[2:])
        else:
            return "1"+terme[0]+suivant_rec(terme[1:])


t = "1"
v = "1"
for i in range(20):
    print(f"U{i+1}={t}")
    print(f"V{i+1}={v}")
    t = next(t)
    v = suivant_rec(v)