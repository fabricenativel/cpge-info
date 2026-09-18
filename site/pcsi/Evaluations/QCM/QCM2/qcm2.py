a = [10, 20, 30]
b = a
b[1] = 99
a.append(40)

lst = [4, 8, 15, 16, 23, 42]

for elt in lst:
    s = s + elt

for i in range(len(lst)):
    s = s + i

for i in range(len(lst)):
    s = s + lst[i]

for elt in lst:
    s = s + lst[elt]

def nb_pairs(lst):
    nb = 0
    for elt in lst:
        if elt % 2 == 0:
            nb += 1
    return nb

def deuxmax(lst):
    assert len(lst) >= 2, "La liste doit avoir au moins deux éléments"
    if lst[0] > lst[1]:
        max1 = lst[0]
        max2 = lst[1]
    else:
        max1 = lst[1]
        max2 = lst[0]
    for i in range(2, len(lst)):
        if lst[i] > max1:
            max2 = max1
            max1 = lst[i]
        elif lst[i] > max2:
            max2 = lst[i]
    return max2, max1
