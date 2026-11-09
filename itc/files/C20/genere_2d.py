from random import uniform, random
from math import sqrt
from matplotlib import pyplot

# Génération d'un fichier de données pour k moyennes

# Génère nb points dans le disque ((cx,cy),rayon) pour la distance
def make_points(cx,cy,rayon,nb,distance=2):
    points = []
    for _ in range(nb):
        if distance==2: #distance euclidienne
            dx = rayon*uniform(-1,1)
            dy = sqrt(rayon**2-dx**2)*uniform(-1,1)
            points.append((cx+dx,cy+dy))
        if distance==1: #distance de manhattan
            dx = uniform(-rayon,rayon)
            dy = uniform(-rayon+abs(dx),rayon-abs(dx))
            points.append((cx+dx,cy+dy))
        if distance==0:
            dx = uniform(-rayon,rayon)
            dy = uniform(-rayon,rayon)
            points.append((cx+dx,cy+dy))
    return [p[0] for p in points],[p[1] for p in points]

def put(fdesc,xv,yv,cn):
    for i in range((len(xv))):
        fdesc.write(f"{xv[i]},{yv[i]},{cn}\n")

c1 = make_points(-3,0,1,5,2)
c2 = make_points(0,0,1,5,2)
c3 = make_points(3,0,1,5,2)
writer = open("kmeansimple.txt","w")
put(writer,c1[0],c1[1],1)
put(writer,c2[0],c2[1],2)
put(writer,c3[0],c3[1],3)
writer.close()
pyplot.scatter(c1[0],c1[1],color='gray',marker='.')
pyplot.scatter(c2[0],c2[1],color='gray',marker='.')
pyplot.scatter(c3[0],c3[1],color='gray',marker='.')
pyplot.axis('square')
pyplot.show()

