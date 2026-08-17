lst1 = [1, 3, 9, 27]
lst2 = lst1
lst1. append(81)

lst = [1, 2, 4, 8, 16]

for elt in range(lst):
    print(elt)

for elt in lst:
    print(elt)

for i in range(len(lst)):
    print(lst[i])

for i in range(len(lst)):
    print(i)

def nb_occ(car, chaine):
    nb = 0
    for elt in chaine:
        if elt==car:
            nb += 1
    return nb