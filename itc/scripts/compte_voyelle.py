# --------- PYODIDE:code --------- #
def compte_voyelle(chaine):
    nb_voyelles = 0
    for i in range(len(chaine)):
        if chaine[i] == 'A' or chaine[i] == 'E' or chaine[i] == 'I' or chaine[i] == 'O' or chaine[i] == 'U' or chaine[i] == 'Y':
            nb_voyelles = nb_voyelles + 1
    return nb_voyelles