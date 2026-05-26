import random
NB = 1000
writer = open("nuage.txt","w")
for i in range(NB):
    xi = -100 + random.random()*200
    yi = -100 + random.random()*200
    writer.write(f"{xi},{yi}\n")
writer.close()
