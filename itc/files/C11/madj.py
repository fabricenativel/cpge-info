import graphviz


def cree_graphe(n):
    """Initialise un graphe vide avec n sommets."""
    return [[False]*n for _ in range(n)]


def cree_arete(g, i, j):
    g[i][j] = True


def visualise(g):
    '''Visualise le graphe g sous forme d'image avec graphviz.'''
    img_graphe = graphviz.Digraph()
    for i in range(len(g)):
        img_graphe.node(str(i))
        for j in range(len(g)):
            if g[i][j]:
                img_graphe.edge(str(i), str(j))
    img_graphe.view()

def affiche_matrice(g):
    for i in range(len(g)):
        for j in range(len(g)):
            if g[i][j]:
                print("1", end=" ")
            else:
                print("0", end=" ")
        print()

def ronde(n):
    g = cree_graphe(n)
    for i in range(n):
        cree_arete(g, i, (i+1)%n)
    return g

g = ronde(5)
visualise(g)
affiche_matrice(g)
