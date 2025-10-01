from random import randint

MAX_INT = 1000
NB_INT = 10000

writer = open("entiers.txt","w")
for i in range(NB_INT):
    writer.write(str(randint(-MAX_INT,MAX_INT))+'\n')
writer.close()