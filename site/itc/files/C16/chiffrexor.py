def lcode(texte):
    return([ord(c) for c in texte])


def chiffre(texte, cle):
    ctexte = lcode(texte)
    ccle = lcode(cle)
    res = [ctexte[i]^ccle[i%(len(ccle))] for i in range(len(ctexte))]
    print(res)
    return "".join(chr(r) for r in res)


print(chiffre("BRAVO VOUS AVEZ REUSSI","python"))
print(chiffre("2+5> N&6!;O/&<.H=+%*'!","python"))
