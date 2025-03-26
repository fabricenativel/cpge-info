def occurrences(s, c):
    '''Renvoie le nombre d'apparition de c dans s'''
    cpt = 0
    for l in s:
        if l == c:
            cpt += 1
    return cpt


def occurrences_rec(s, c):
    if s == "":
        return 0
    else:
        if s[0] == c:
            return 1 + occurrences_rec(s[1:], c)
        else:
            return occurrences_rec(s[1:], c)
