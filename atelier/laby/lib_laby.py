import turtle
from time import sleep



VIDE = '.'
MUR = '@'
DEPART = 'D'
ARRIVEE = 'A'
VISITED = "#"
CHEMIN = "x"
COULEUR = {VIDE : "gray", MUR:"gray", DEPART:"green", ARRIVEE:"red", VISITED : "gray", CHEMIN : "gray"}
REMPLISSAGE = {VIDE : "white", MUR:"black", DEPART:"green", ARRIVEE:"red", VISITED:"lightgray", CHEMIN : "orange"}
CSIZE = 20
LARGEUR_ECRAN=1200
HAUTEUR_ECRAN=900
MARGE = 2*CSIZE
MOVES = {(1, 0), (-1, 0), (0, 1), (0, -1)}

def init():
    papier = turtle.Screen()
    papier.title("Résolution de labyrinthes")
    crayon = turtle.Turtle()
    crayon.hideturtle()
    papier.setup(width=LARGEUR_ECRAN,height=HAUTEUR_ECRAN)
    crayon.speed(0)
    papier.tracer(400)
    return papier, crayon


def lire_labyrinthe(fname):
    with open(fname) as reader:
        laby = reader.read().strip().split('\n')
    return laby

def putchar(crayon, l,c, car):
    l = -l*CSIZE + HAUTEUR_ECRAN//2-MARGE
    c = c*CSIZE - LARGEUR_ECRAN//2+MARGE
    if car in COULEUR:
        crayon.pencolor(COULEUR[car])
        crayon.fillcolor(REMPLISSAGE[car])
    else:
        crayon.pencolor('navy')
    if car==MUR or car==VIDE or car==VISITED or car==CHEMIN:
        crayon.penup()
        crayon.goto(c,l)
        crayon.pendown()
        crayon.setheading(0)
        crayon.begin_fill()
        for _ in range(4):
            crayon.forward(CSIZE)
            crayon.left(90)
        crayon.end_fill()
    elif car==DEPART or car==ARRIVEE:
        crayon.penup()
        crayon.goto(c+CSIZE//2,l+CSIZE//2)
        crayon.pendown()
        crayon.dot(CSIZE-2)
    else:
        crayon.penup()
        crayon.goto(c+CSIZE//2,l)
        crayon.pendown()
        crayon.write(car,align='center',font=('Arial',12,'bold'))

            
def position(carte, car):
    for i in range(len(carte)):
        if car in carte[i]:
            return (i, carte[i].find(car))
    return (-1,-1)

def visualise(crayon, carte):
    for l  in range(len(carte)):
        for c in range(len(carte[l])):
            putchar(crayon, l,c,carte[l][c])
                

def resolution(crayon, papier, carte, etapes =False, delai = 0):
    sl, sc = position(carte,'D')
    el, ec = position(carte,'A')
    visited = {(sl,sc)}
    reached = {(sl,sc)}
    solved = False
    step = 0
    while len(reached)!=0 and not solved:
        new = set()
        step += 1
        for (l,c) in reached:
            putchar(crayon,l,c,VISITED)
            for dl,dc in MOVES:
                if (l+dl,c+dc) not in visited and carte[l+dl][c+dc]==VIDE:
                    new.add((l+dl,c+dc))
                    visited.add((l+dl,c+dc))
                if (l+dl,c+dc)==(el,ec):
                    solved = True
        reached = new
        for (l,c) in reached:
            putchar(crayon,l,c,str(step))
        if etapes:
            _ = input("Appuyer entrée pour la prochaine étape")
        if delai!=0:
            sleep(delai)
            papier.update()
    return step

def chemin(crayon, carte):
    sl, sc = position(carte,'D')
    el, ec = position(carte,'A')
    visited = {(sl,sc):None}
    reached = {(sl,sc)}
    solved = False
    step = 0
    while len(reached)!=0 and not solved:
        new = set()
        step += 1
        for (l,c) in reached:
            putchar(crayon,l,c,VISITED)
            for dl,dc in MOVES:
                if (l+dl,c+dc) not in visited and carte[l+dl][c+dc]==VIDE:
                    new.add((l+dl,c+dc))
                    visited[(l+dl,c+dc)]=(l,c)
                if (l+dl,c+dc)==(el,ec):
                    visited[(l+dl,c+dc)]=(l,c)
                    solved = True
        reached = new
    chemin = []
    putchar(crayon,sl,sc,VIDE)
    putchar(crayon,sl,sc,DEPART)
    if solved:
        l,c = el,ec
        while visited[(l,c)]!=(sl,sc):
            chemin.append((l,c))
            l,c = visited[(l,c)]
            putchar(crayon, l, c, CHEMIN)
    return chemin

def attendre(crayon,papier):
    crayon.penup()
    crayon.goto(0,-HAUTEUR_ECRAN//2+MARGE)
    crayon.pendown()
    crayon.write("Cliquer pour fermer !",align='center',font=('Arial',12,'bold'))
    papier.update()
    papier.exitonclick()

