def somme(n):
    s = 0
    for c in str(n):
        s += int(c)
    return s

def est_harshad(n):
    return n%somme(n)==0

def liste_harshad(deb,fin):
    lh = []
    for x in range(deb, fin):
        if est_harshad(x):
            lh.append(x)
    return lh

def consecutifs(lst):
    nb = 1
    start = lst[0]
    max_nb = 1
    max_start = lst[0]
    for i in range(1, len(lst)):
        if lst[i]==lst[i-1]+1:
            nb += 1
            if (nb>max_nb):
                max_nb = nb
                max_start = start
        else:
            start = lst[i]
            nb = 1
    return max_nb, max_start
