from random import randint

def rchar():
    minuscule = randint(0,1)
    return chr(randint(65+minuscule*32,90+minuscule*32))

def encode(texte,cle):
    enc = ""
    for t in texte:
        enc = enc + t
        for c in range(cle):
            enc = enc + rchar()
    return enc

key = 1
s = encode("Trop bien le Python",key)
print(s)
print(s[::key+1])