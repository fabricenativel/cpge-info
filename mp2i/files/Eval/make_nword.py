from random import randint

NW = 28395

writer = open("code2","w")

def make_word(size):
    w = "".join([chr(randint(97,122)) for _ in range(size)])
    nl = randint(1,7)
    if (nl==7):
        w += '\n'
    return w.capitalize()+" "

for _ in range(NW):
    writer.write(make_word(randint(3,9)))


writer.close()




