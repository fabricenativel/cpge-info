memo = {}
def optimal(indice, pmax):
    if indice>len(sac)-1:
        memo[(indice,pmax)]=0
        return 0
    if pmax==0:
        memo[(indice,0)]=0
        return 0
    nom, valeur, poids = sac[indice]
    if poids>pmax:
        memo[(indice,pmax)]=0
        return 0
    avec = valeur + optimal(indice+1, pmax-poids)
    sans = optimal(indice+1,pmax)
    memo[(indice,pmax)]=max(avec,sans)
    return memo[(indice,pmax)]


def objets(p):
    l = []
    i = 0
    for i in  range(len(sac)):
        nom, valeur, poids = sac[i]
        if (i,p) in memo and (i+1,p) in memo and memo[(i,p)] > memo[(i+1,p)]:
            l.append(nom)
            p = p - poids
    print(l)

def glouton(sac, poids):
    sac_trie = sorted(sac, key= lambda x :  x[1]/x[2])
    poids_restant = poids
    contenu = []
    vmax = 0
    for objet in sac_trie:
        nom, valeur, poids = objet
        if poids<=poids_restant:
            contenu.append(nom)
            vmax += valeur
            poids_restant -= poids
    return contenu, vmax

sac = [("Hamburger",180,3),("Marteau",2050,41),("Parapluie",280,6),("Ballon",810,17),("Clé",990,20),("Sapin",1275,29),("Chapeau",2570,57),("Guitare",920,21)]
sac.sort(key = lambda x : x[2])
p = 80
print(optimal(0,p))
objets(p)
print(glouton(sac,80))