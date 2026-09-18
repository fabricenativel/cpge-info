from random import randint
from random import shuffle

message = "Magnifique"

def random_letter():
    if randint(0,1)==0:
        return chr(randint(ord('A'),ord('Z')))
    else:
        return chr(randint(ord('a'),ord('z')))

    

def make_usesless(nbz,nbl):
        lz = [random_letter() for _ in range(nbl)] + ['0']*nbz
        shuffle(lz)
        m10 = "".join([random_letter() for _ in range(10)])
        sol = "".join(lz)
        return sol+m10

'''
1. Remplir la file (garantie en terminant avec 10 lettres et avant random)
2. Insérez des 0 et juste après une lettre du mot caché suivi de caractères bidons
3. Compléter avec des caractères bidons
'''
 

res = make_usesless(42,420)
for c in message:
    res +='0'
    res += c 
    res += make_usesless(0,randint(0,42))

writer = open("touches.txt","w")
writer.write(res)
writer.close()
print("Terminé !")