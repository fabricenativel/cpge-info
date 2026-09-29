from random import randint

n = int(input("Entrer la taille de la barre "))
fname = input("Entrer le nom du ficher à créer ")
writer = open(fname,"w")
writer.write("0\n")
cprice = 0
for i in range(1,n+1):
    cprice += randint(1,5)
    writer.write(str(cprice)+"\n")
