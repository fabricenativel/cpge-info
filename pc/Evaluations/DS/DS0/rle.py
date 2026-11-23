def rle_encode(texte):
    '''Renvoie la liste des couples (caractère, compte) selon le codage RLE'''
    if len(texte) == 0:
        return []
    res = []
    car_courant = texte[0]
    compte = 1
    for i in range(1, len(texte)):
        if texte[i] == car_courant:
            compte += 1
        else:
            res.append((car_courant, compte))
            car_courant = texte[i]
            compte = 1
    res.append((car_courant, compte))
    return res


def rle_decode(liste_rle):
    '''Reconstruit la chaîne d'origine à partir de sa représentation RLE'''
    res = ""
    for car, compte in liste_rle:
        res += car * compte
    return res


def longueur_totale(liste_rle):
    '''Renvoie la longueur de la chaîne décompressée sans la reconstruire'''
    total = 0
    for _, compte in liste_rle:
        total += compte
    return total


if __name__ == '__main__':
    # Tests
    s = "WWWBWWWWBBBWW"
    enc = rle_encode(s)
    assert enc == [('W', 3), ('B', 1), ('W', 4), ('B', 3), ('W', 2)]
    assert rle_decode(enc) == s
    assert longueur_totale(enc) == len(s) == 13

    assert rle_encode("AAABBCCCCA") == [('A', 3), ('B', 2), ('C', 4), ('A', 1)]
    assert rle_decode([('A', 3), ('B', 2), ('C', 4), ('A', 1)]) == "AAABBCCCCA"

    assert rle_encode("") == []
    assert rle_decode([]) == ""
    assert longueur_totale([]) == 0
    print("Tous les tests RLE sont validés !")
