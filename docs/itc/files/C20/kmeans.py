from random import shuffle
from math import sqrt

FNAME = "wine.csv"
# Le diagnostique de maladie cardiaque est la dernière donnée (un entier entre 0 et 4)
NB_CLASSES = 3

def get_data():
    reader = open(FNAME,"r")
    content = reader.read().strip().split('\n')
    data = [list(map(float,d.strip().split(','))) for d in content]
    reader.close()
    return data

def distance(d1,d2):
    s = 0
    for i in range(1,len(d1)):
        s += (d2[i]-d1[i])**2
    return s

def get_centre(cluster):
    s = [0]*len(cluster[0])
    for i in range(len(cluster)):
        for j in range(1,len(s)):
            s[j]=s[j]+cluster[i][j]
    return [x/(len(cluster)-1) for x in s]

def get_classe(d,centres):
    mini = distance(d,centres[0])
    imini = 0
    for i in range(1,len(centres)):
        if distance(d,centres[i])<mini:
            mini = distance(d,centres[i])
            imini = i
    return imini

def make_partition(data, centres,old_cluster):
    clusters = [[] for _ in range(len(centres))]
    moves = 0
    for d in data:
        nc = get_classe(d,centres)
        clusters[nc].append(d)
        if d not in old_cluster[nc]:
            moves +=1
    return clusters,moves

def kmeans(data,max_iter=50,seuil = 0.01):
    # choisir NB_CLASSES centre 
    centres = [x for x in data]
    shuffle(centres)
    centres = centres[0:NB_CLASSES]
    nb_iter = 0
    clusters = [[] for _ in range(NB_CLASSES)]
    stable = False
    # Itérer en recalculant les centres de chaque cluster
    while nb_iter<max_iter and not stable:
        clusters,moves = make_partition(data,centres,clusters)
        centres = [get_centre(clusters[i]) for i in range(NB_CLASSES)]
        nb_iter+=1
        print(f"Itération n°{nb_iter} : {moves} points déplacés")
        stable = moves/len(data)<seuil
    return clusters


def compte(cluster,valeur):
    nb = 0
    for d in cluster:
        if d[0]==valeur:
            nb+=1
    return nb

data = get_data()
clusters = kmeans(data)
print("Nombre de valeurs par cluster  :  ")
for i in range(NB_CLASSES):
    print(f"Cluster n°{i+1} : {len(clusters[i])}")
print("Matrice de confustion : ")
for i in range(NB_CLASSES):
    for j in range(NB_CLASSES):
        print(compte(clusters[i],j+1)," ",end="")
    print(" ")