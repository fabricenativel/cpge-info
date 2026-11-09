def init_sol(nl,nc,v):
    return [[v]*nc for _ in range(nl)]

def copy_sol(sol):
    return [l.copy() for l in sol]

def transpose(sol):
    return [[sol[i][j] for i in range(len(sol))] for j in range(len(sol[0]))]

def verifie_ligne(sol, cle_l, i):
    if any(v==-1 for v in sol[i]):
        return True
    pos_zero = [-1]+[j for j in range(len(sol[i])) if sol[i][j]==0]+[len(sol[i])]
    blocs = [pos_zero[j+1]-pos_zero[j]-1 for j in range(len(pos_zero)-1) if pos_zero[j+1]-pos_zero[j]-1!=0]
    return cle_l[i] == blocs

def verifie(sol,cle_l,cle_c):
    return all(verifie_ligne(sol,cle_l,i) for i in range(len(sol))) and all(verifie_ligne(transpose(sol),cle_c,i) for i in range(len((transpose(sol)))))

def verif_ligne(sol, cle_l, i):
    pos_zero = [-1]+[j for j in range(len(sol[i])) if sol[i][j]==0]+[len(sol[i])]
    blocs = [pos_zero[j+1]-pos_zero[j]-1 for j in range(len(pos_zero)-1) if pos_zero[j+1]-pos_zero[j]-1!=0]
    return cle_l[i] == blocs

def verif(sol,cle_l,cle_c):
    return all(verif_ligne(sol,cle_l,i) for i in range(len(sol))) and all(verif_ligne(transpose(sol),cle_c,i) for i in range(len((transpose(sol)))))

def nb_un(sol_p,indice,ligne):
    if not ligne:
        return nb_un(transpose(sol_p),indice,True)
    nb = 0
    for j in range(len(sol_p[indice])):
        if sol_p[indice][j]==1:
            nb+=1
    return nb

sol_p = init_sol(5,5,-1)
nl,nc = 5,5
i_ligne = 0

# --8<-- [start:Q1]
def cases_noires(cle_l):
    '''Renvoie le nombre de cases à colorier en noire dans la solution'''
    a_colorier = 0
    for ligne in cle_l:
        for nb_cases in ligne:
            a_colorier = a_colorier + nb_cases
    return a_colorier
# --8<-- [end:Q1]

# --8<-- [start:Q2]
def compatibles(cle_l, cle_c):
    '''Renvoie True ssi le nombre de cases à colorier en ligne et en colonnes sont identiques'''
    return cases_noires(cle_l) == cases_noires(cle_c)
# --8<-- [end:Q2]

# --8<-- [start:Q3]
def taille_minimale(cle_l):
    '''Renvoie nombre minimal occupé par une clé de ligne'''
    taille_min = len(cle_l)-1
    for nb in cle_l:
        taille_min = taille_min + nb
    return taille_min
# --8<-- [end:Q3]

# --8<-- [start:Q6]
def liste_solutions(cle_l, cle_c):
    nl, nc = len(cle_l), len(cle_c)

    def liste_solution_aux(n, sol_p, liste):
        if n == nl*nc: # La grille est complète
            if verif(sol_p,cle_l,cle_c):
                liste.append(sol_p)
        else: #on complète la grille par un 0 ou un 1 
            candidat0 = copy_sol(sol_p) 
            candidat0[n//nc][n%nc] = 0
            liste_solution_aux(n+1, candidat0, liste)
            candidat1 = copy_sol(sol_p)
            candidat1[n//nc][n%nc] = 1
            liste_solution_aux(n+1, candidat1, liste)
    
    sol_p = init_sol(nl,nc,-1) 
    solutions = []
    liste_solution_aux(0,sol_p,solutions)
    return solutions
# --8<-- [end:Q6]

# --8<-- [start:Q8]
def conflit(c,s):
    # la case avant le bloc est noire
    if c>0 and sol_p[i_ligne][c-1]==1:
        return c-1
    # une des cases du bloc est blanche
    for j in range(s):
        if sol_[p][i_ligne][c+j]==0:
            return c+j
    # la case après le bloc est noire:
    if c+s<nc and sol_p[i_ligne][c+s]==1:
        return c+s
    return nc
# --8<-- [end:Q8]

# --8<-- [start:Q9]
def prochain(c,s):
    candidat = c
    while candidat<nc-s:
        if candidat!=0:
            while sol_p[i_ligne][candidat]==1:
                candidat = candidat + 1
        k = 0
        while k<s and candidat+k+1<nc and sol_p[i_ligne][candidat+k+1]!=0:
            k = k + 1
        if k==s and sol_p[i_ligne][candidat+k]!=1:
            return candidat
        else:
            candidat = candidat + k
    return -1
# --8<-- [end:Q9]

sol_p[0][0]=1
print(sol_p)
print(prochain(0,4))

# cle_l = [[2],[3,1],[4],[4],[1,1]]
# cle_c = [[1],[5],[4],[2],[4]]
# #print(verifie_ligne([[1,1,1,0,1]],[[3,1]],0))

# sols = liste_solutions(cle_l,cle_c)
# for s in sols:
#     print(s)


