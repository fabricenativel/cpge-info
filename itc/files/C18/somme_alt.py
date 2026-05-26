def somme_alt(tab):
    if len(tab)==0:
        return 0
    if len(tab)==1:
        return tab[0]
    return max(somme_alt(tab[1:]),tab[0]+somme_alt(tab[2:]))

print(somme_alt([7, 5, 3, 6]))
    