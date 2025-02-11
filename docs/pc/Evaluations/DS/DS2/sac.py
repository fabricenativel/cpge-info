

def valeur(objet,i):
    return objet[i][1]

def poids(objet,i):
    return objet[i][0]

def enleve(liste,ind):
    return [liste[i] for i in range(len(liste)) if ind!=i]

def vmax(objets,psac):
    eligible = [objets[i] for i in range(len(objets)) if poids(objets,i)<=psac]
    if len(eligible)==0 : return 0
    return max(vmax(enleve(eligible,k),psac-poids(eligible,k))+valeur(eligible,k) for k in range(len(eligible)))



def glouton(objets, pmax):
    objets.sort(key=lambda x: x[1]/x[0], reverse=True)
    poids = 0
    contenu = []
    for obj in objets:
        if poids + obj[0] <= pmax:
            poids += obj[0]
            contenu.append(obj)
    return contenu

objets = [(4, 30), (5, 34), (6, 36), (7, 49), (10, 74)]
print([x[1]/x[0] for x in objets])
pmax = 10
print(glouton(objets, pmax))
print(vmax(objets, pmax))

