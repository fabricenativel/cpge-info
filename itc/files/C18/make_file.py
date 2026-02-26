from random import randint
from random import shuffle

def make_rs():
    size = randint(4,10)
    lchar = [chr(randint(65,90)) for _ in range(size)]
    return "".join(lchar)+"\n"

to_write = [make_rs() for n in range(5000)]
to_write.append(to_write[0])
print("La chaine qui se répète : ",to_write[0])
shuffle(to_write)

writer=open("chaines.txt","w")
for c in to_write:
    writer.write(c)
writer.close()
