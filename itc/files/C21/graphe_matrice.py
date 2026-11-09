import graphviz
from collections import deque

'''
Représentation d'un graphe par matrice d'adjacence
Pour simplifier les sommets sont numérotés depuis 0
'''

def ajoute_sommet(graphe):
    graphe.append([0]*len(graphe))
    for l in graphe:
        l.append(0)

def ajoute_arc(graphe,i,j):
     m = max(i,j)
     for m in range(len(graphe),m+1):
        ajoute_sommet(graphe)
     graphe[i][j] = 1


def visualise(graphe):
     img_graphe = graphviz.Digraph()
     n = len(graphe)
     for s in range(n):
          img_graphe.node(str(s))
     for s in range(n):
          for t in range(n):
               if graphe[s][t]==1:
                    img_graphe.edge(str(s),str(t))
     img_graphe.view()

ex = []
ajoute_arc(ex,0,1)
ajoute_arc(ex,0,2)

visualise(ex)
print(ex)