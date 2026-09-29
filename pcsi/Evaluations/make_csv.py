COLUMNS = "nom, prenom, id, sexe, mail\n"

stream = open("pcsi.csv","r")
eleves = stream.read().strip().split("\n")
stream.close()

writer = open("eleves_pcsi.csv","w")
writer.write(COLUMNS)
for e in eleves:
    id, np, s, m = e.split(";")
    print(np)
    sep = np.find(" ")
    n,p = np[:sep], np[sep+1:]
    writer.write(f"{n},{p},{id},{s},{m}\n")
writer.close()