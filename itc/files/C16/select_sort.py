# Echange les éléments situés aux indices i et j dans liste
def echange(liste, i, j):
    liste[i], liste[j] = liste[j], liste[i]

# Recherche l'indice du minimum de la liste à partir de l'indice i
def indice_min_depuis(liste, i):
    ind_mini = i
    mini = liste[i]
    for j in range(i+1,len(liste)):
        if liste[j]<mini:
            ind_mini = j
            mini = liste[j]
    return ind_mini

# Tri pas sélection
def tri_selection(liste):
    for i in range(len(liste)):
        j = indice_min_depuis(liste,i)
        echange(liste,i,j)


l = [12, 10, 18, 15, 14]
tri_selection(l)
print(l)
