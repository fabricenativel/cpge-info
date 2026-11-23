from matplotlib import pyplot

reader = open("temps.csv","r")
data = reader.read().strip().split('\n')
reader.close()
print(data)
lp = [list(map(float,d.split(','))) for d in data]
pyplot.plot([x[0] for x in lp],[x[1] for x in lp],"-b",label="naïf")
pyplot.plot([x[0] for x in lp],[x[2] for x in lp],"-r",label="Strassen")
pyplot.title("Temps d'exécution des algorithmes de multiplication matricielle")
pyplot.legend(loc="upper left")
pyplot.xlabel("Taille des matrices")
pyplot.ylabel("Temps d'exécution en secondes")
pyplot.show()