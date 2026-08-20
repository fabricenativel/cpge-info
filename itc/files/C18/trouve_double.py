
#Lecture des chaines de caractères et stockage dans la liste "chaines"
reader = open("chaines.txt")
chaines = reader.read().strip().split('\n')
reader.close()

# Renvoie True si elt est dans liste (sinon False)
def est_dans(elt,liste):
    for x in liste:
        if x==elt:
            return True
    return False

# Trouve la première chaine en double
deja_vu = []
for c in chaines:
    if est_dans(c,deja_vu):
        print(c)
    else:
        deja_vu.append(c)

# De même mais avec un dictionnaire 
memoire = {}
for c in chaines:
    if c in memoire:
        print(c)
    else:
        # On enregistre la présence de la clé (la valeur True n'a pas d'importance)
        memoire[c] = True
