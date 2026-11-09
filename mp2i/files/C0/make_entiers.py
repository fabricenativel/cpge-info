from random import randint
with open("entiers.txt","w")  as writer:
    for _ in range(12487):
        writer.write(str(randint(0,10000))+"\n")

