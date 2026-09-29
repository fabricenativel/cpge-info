import random

FILENAME = "objets.txt"
SIZE = 24
RATIO = 500.0
PMAX = 10
DELTA = 0.25

def genere_objets():
    objets = []
    for i in range(SIZE):
        poids = round(random.random()*PMAX,1)
        valeur = int(poids*RATIO + random.randint(-int(RATIO*DELTA),int(RATIO*DELTA)))
        objets.append((poids,valeur))
    return objets
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

def calcule(choix,objets):
    p,v = 0,0
    for i in range(len(objets)):
        if choix[i]:
            p = p + objets[i][0]
            v = v + objets[i][1]
    return p,v

def brute_force(objets,psac):
    t = len(objets)
    choix = [0]*t
    vopti = 0
    while choix[0]!=2:
        p,v = calcule(choix,objets)
        if p<=psac  and v>vopti:
            vopti = v
        choix[t-1]+=1
        cp = t-1
        while cp!=0 and choix[cp]==2:
            choix[cp]=0
            choix[cp-1]+=1
            cp = cp-1
    return vopti


def glouton(objets,psac):
    sobj = sorted(objets, key=lambda o : o[1]/o[0], reverse=True)
    cp = 0
    vs = 0
    for o in sobj:
        if cp+o[0]<=psac:
            cp = cp+o[0]
            vs = vs+o[1]
    return vs

def gen_objets(objets):
    writer = open(FILENAME,"w")
    for o in objets:
        writer.write(f"{o[0]},{o[1]}\n")
    writer.close()

obj =  genere_objets()
gen_objets(obj)
psac = 0
for i in range(SIZE):
    psac += obj[i][0]
psac = int(psac/2)
print(f"Poids maxi = {psac}")
#print(f"Prog Dyn : {vmax(obj,psac)}")
print(f"Force Brute : {brute_force(obj,psac)}")
print(f"Glouton : {glouton(obj,psac)}")

