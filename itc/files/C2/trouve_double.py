reader = open("chaines.txt")
chaines = reader.read().strip().split('\n')
reader.close()
deja_vu = []

def est_dans(elt,liste):
    for x in liste:
        if x==elt:
            return True
    return False

for c in chaines:
    if est_dans(c,deja_vu):
        print(c)
        break
    else:
        deja_vu.append(c)

