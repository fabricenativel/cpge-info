
# Solutions = liste de dictionnaires, solutions[i] contient les solutions sous la forme valeur:[listes_pieces] pour les valeurs avec i pieces
solutions = [{0:[]}]


def rendu_monnaie(valeur,systeme,solutions):
    nb_pieces = 0
    while valeur not in solutions[nb_pieces]:
        nb_pieces=len(solutions)-1    
        new_sol = {}
        for p in systeme:
            for sol in solutions[nb_pieces]:
                if sol+p<=valeur and all(sol+p not in solutions[nb] for nb in range(nb_pieces+1)):
                    new_sol[sol+p]=solutions[nb_pieces][sol]+[p]
        solutions.append(new_sol)
        nb_pieces += 1
    return solutions[nb_pieces][valeur]

systeme = (10,8,4,3,1)
valeur = 1547

print(rendu_monnaie(valeur,systeme,solutions))
