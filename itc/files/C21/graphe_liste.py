import graphviz
from collections import deque

'''
Représentation d'un graphe par liste d'adjacence
Le graphe (S,A) est représenté par le dictionnaire G
tel que S forment l'ensemble des clés de G, et G[s] = {x / (s,x) dans A}
'''

def ajoute_sommet(graphe,s):
    g[s] = []

def ajoute_arc(graphe,dep,arr):
    if dep in graphe:
        graphe[dep].append(arr)
    else:
         graphe[dep] = [arr]
    if arr not in graphe:
         graphe[arr]=[]


def parcours_largeur(graphe,start):
     file = deque()
     file.appendleft(start)
     deja_vu = {s:False for s in graphe}
     deja_vu[start] = True
     resultat = [start]
     while len(file)!=0:
          sommet_courant = file.pop()
          for s in graphe[sommet_courant]:
               if not deja_vu[s]:
                    deja_vu[s] = True
                    resultat.append(s)
                    file.appendleft(s)
     return resultat


def parcours_profondeur(graphe, depart, visite):
    if visite == None:
         visite = {s:False for s in graphe}
    if visite[depart]:
         return []
    else:
        visite[depart]=True
        res = [depart]
        for s in graphe[depart]:
              res += parcours_profondeur(graphe,s,visite)
        return res


def visualise(graphe):
        img_graphe = graphviz.Digraph()
        for s in graphe:
             img_graphe.node(s)
             for t in graphe[s]:
                  img_graphe.edge(s,t)
        img_graphe.view()



g = {}
ajoute_arc(g,'a','b')
ajoute_arc(g,'a','c')
ajoute_arc(g,'b','d')
ajoute_arc(g,'d','e')
ajoute_arc(g,'e','f')
ajoute_arc(g,'c','g')
ajoute_arc(g,'g','b')
visualise(g)
print(parcours_largeur(g,'a'))
print(parcours_profondeur(g,'a',None))