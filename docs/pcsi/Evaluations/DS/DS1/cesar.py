def numero(car):
    lettres = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    for i in range(len(lettres)):
        if car==lettres[i]:
            return i
    return -1

def decalage(cle):
    lettres = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    return lettres[cle:]+lettres[:cle]

def cesar(chaine, cle):
    chiffre = ""
    dec = decalage(cle)
    for c in chaine:
        if numero(c)==-1:
            chiffre +=c
        else:
            chiffre += dec[numero(c)]
    return chiffre

assert numero('A')==0
assert numero('C')==2
assert numero('!')==-1