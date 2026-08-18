from random import randint
from random import shuffle

nb_char = {"B":1,"r":2,"a":3,"v":4,"o":5}

for c in range(33,127):
    if chr(c) not in nb_char:
        nb_char[chr(c)] = randint(50,100)

file = []
for c in nb_char:
    file += list(c*nb_char[c])

shuffle(file)
writer = open("mot_cache.txt","w")
writer.write("".join(file))
writer.close()
