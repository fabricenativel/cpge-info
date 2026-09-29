SIZE = 14
nb_sol = 0


def nqueens(echiquier,colonne):
    global nb_sol
    if colonne == SIZE:
         nb_sol+=1
    else:
        for p in range(SIZE):
            if all(echiquier[j]!=p and abs(echiquier[j]-p)!=abs(j-colonne) for j in range(colonne)):
                echiquier[colonne]=p
                nqueens(echiquier,colonne+1)
    
ech = [0]*SIZE
nqueens(ech,0)
print(f"Problèmes des {SIZE} reines : {nb_sol} solutions")