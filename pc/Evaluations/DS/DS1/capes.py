def fibonacci(n):
    termes = [0, 1]
    for i in range(n-2):
        termes.append(termes[-1]+termes[-2])
    return termes


def indice_min(entiers):
    mini, indice_min = entiers[0], 0
    for i in range(1, len(entiers)):
        if entiers[i] < mini:
            mini, indice_min = entiers[i], i
    return indice_min

def lettre_majoritaire(chaine):
    occurrences = {}
    for c in chaine:
        if c in occurrences:
            occurrences[c] += 1
        else:
            occurrences[c] = 1
    maxl = 0
    for c in occurrences:
        if occurrences[c] > maxl:
            maxl,lm = occurrences[c], c
    return lm

