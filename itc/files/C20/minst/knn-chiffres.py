SIZE = 28


def get_img(number):
    fname = 'img'+str(number)+'.pgm'
    reader = open(fname)
    for _ in range(3):
        reader.readline()
    classe = int(reader.readline().strip()[2:])
    data = []
    for _ in range(SIZE):
        data+= [int(x) for x in reader.readline().strip().split(" ")]
    return classe,data

def distance(img1,img2):
    s= 0
    for i in range(SIZE*SIZE):
        s = s + (img1[1][i]-img2[1][i])**2
    return s

def knn(img,entrainements,k):
    return sorted(entrainements,key=lambda x : distance(x,img))[:k]

def majoritaire(data):
    c = {i:0 for i in range(10)}
    max= 0
    for d in data:
        c[d[0]]+=1
    print(c)
    for i in range(10):
        if c[i]>c[max]:
            max = i
    return max

nb_trains = 4500
total = 5000
entrainements = [get_img(i) for i in range(1,nb_trains+1)]
a_classer = [get_img(i) for i in range(nb_trains+1,total)]
nb = 1
err = 0
k = 10
for c in a_classer:
    ac = majoritaire(knn(c,entrainements,k))
    print(f"Image n°{nb_trains+nb} : Classe = {c[0]} affecté à {ac}",end='')
    nb += 1
    if c[0]==ac:
        print(" > OK !")
    else:
        print(" > ERREUR !")
        err +=1
print(f"Nombre d'erreurs = {err}")
