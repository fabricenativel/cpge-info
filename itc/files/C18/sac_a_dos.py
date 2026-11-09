objets =    [
        (0.2,90),
        (2.4,1100),
        (0.3,140),
        (0.8,380),
        (1.1,480),
        (1.4,620),
        (2.8,1320),
        (1,440)
            ]
psac = 4

def valeur(objet,i):
    return objet[i][1]

def poids(objet,i):
    return objet[i][0]

def enleve(liste,ind):
    return [liste[i] for i in range(len(liste)) if ind!=i]

def vmax(objets,psac):
    print(f"Objets : {objets}, Poids : {psac}")
    eligible = [objets[i] for i in range(len(objets)) if poids(objets,i)<=psac]
    if len(eligible)==0 : return 0
    return max(vmax(enleve(eligible,k),psac-poids(eligible,k))+valeur(eligible,k) for k in range(len(eligible)))

print(vmax(objets,psac))