import graphviz
from collections import deque

def init(n):
    return {i : [] for i in range(n)}

def cree_arete(g, i, j):
    g[i].append(j)
    pos = len(g[i])-1
    while pos>0 and g[i][pos]<g[i][pos-1]:
        g[i][pos], g[i][pos-1] = g[i][pos-1],g[i][pos]
        pos= pos - 1

def degre(g,i):
    return len(g[i])

def voisins(g,s):
    return g[s]

def visualise(g):
        img_graphe = graphviz.Digraph()
        for s in g:
             img_graphe.node(str(s))
             for t in g[s]:
                  img_graphe.edge(str(s),str(t))
        img_graphe.view()


def largeur(g,s):
    a_traiter = deque()
    a_traiter.appendleft(s)
    visite = {i:False for i in range(len(g))}
    parcours = []
    while len(a_traiter)!=0:
          courant = a_traiter.pop()
          if not visite[courant]:
            visite[courant]=True
            parcours.append(courant)
            for suivant in g[courant]:
                 if not visite[suivant]:
                    a_traiter.appendleft(suivant)
    return parcours


g = init(5)
cree_arete(g, 0, 1)
cree_arete(g, 0, 2)
cree_arete(g, 1, 2)
cree_arete(g, 2, 3)
cree_arete(g, 4, 1)
visualise(g)
print(largeur(g,0))