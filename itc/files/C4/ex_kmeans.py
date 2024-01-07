from random import shuffle
from matplotlib import pyplot


FNAME = "kmeansimple.txt"
NB_CLASSES = 3
COULEURS = ['red','blue','green']
CC = ['LightCoral','LightBlue','LightGreen']
CDOT = 'X'


def get_data():
    reader = open(FNAME,"r")
    content = reader.read().strip().split('\n')
    data = [list(map(float,d.strip().split(','))) for d in content]
    reader.close()
    return data

def distance(d1,d2):
    s = 0
    for i in range(len(d1)):
        s += (d2[i]-d1[i])**2
    return s

def get_centre(cluster):
    s = [0]*len(cluster[0])
    for i in range(len(cluster)):
        for j in range(len(s)):
            s[j]=s[j]+cluster[i][j]
    return [x/len(cluster) for x in s]

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

def init_disp(centres):
    c = 0
    for x,y,l in centres:
        pyplot.scatter([x],[y],color=COULEURS[c],marker=CDOT,s=100)
        c+=1

def disp_data(data):
    absx = [d[0] for d in data]
    absy = [d[1] for d in data]
    pyplot.scatter(absx,absy,color="gray",marker='.')

def disp_clusters(clusters):
    nc = 0
    for clust in clusters:
        absx = [c[0] for c in clust]
        absy = [c[1] for c in clust]
        pyplot.scatter(absx,absy,color=CC[nc],marker='.')
        nc+=1

def kmeans(data,max_iter=50,seuil=0.01):
    # choisir NB_CLASSES centre 
    shuffle(data)
    centres = data[0:NB_CLASSES]
    disp_data(data)
    pyplot.xlim(-5,5)
    pyplot.ylim(-1,1)
    pyplot.axis('equal')
    pyplot.savefig("start_simple.png",format='png')
    disp_data(data)
    init_disp(centres)
    pyplot.xlim(-5,5)
    pyplot.ylim(-1,1)
    pyplot.axis('equal')
    pyplot.savefig("ex3_simple0.png",format='png')
    nb_iter = 0
    nb_img = 1
    clusters = [[] for _ in range(NB_CLASSES)]
    stable = False
    # Itérer en recalculant les centres de chaque cluster
    while nb_iter<max_iter and not stable:
        clusters,moves = make_partition(data,centres,clusters)
        disp_clusters(clusters)
        init_disp(centres)
        pyplot.xlim(-5,5)
        pyplot.ylim(-1,1)
        pyplot.axis('equal')
        pyplot.savefig(f"ex3_simple{nb_img}.png",format='png')
        pyplot.clf()
        nb_img +=1
        centres = [get_centre(clusters[i]) for i in range(NB_CLASSES)]
        disp_clusters(clusters)
        init_disp(centres)
        pyplot.xlim(-5,5)
        pyplot.ylim(-1,1)
        pyplot.axis('equal')
        pyplot.savefig(f"ex3_simple{nb_img}.png",format='png')
        pyplot.clf()
        nb_img += 1
        nb_iter+=1
        print(f"Itération n°{nb_iter} : {moves} points déplacés")
        stable = moves/len(data)<seuil
    return clusters


def compte(cluster,valeur):
    nb = 0
    for d in cluster:
        if d[2]==valeur:
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
disp_clusters(clusters)
pyplot.xlim(-5,5)
pyplot.ylim(-2,2)
pyplot.axis('equal')
pyplot.show()