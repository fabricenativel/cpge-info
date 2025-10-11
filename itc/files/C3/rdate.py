reader = open("dates.txt")
contenu = reader.readlines()
dates = [ligne.strip().split("/") for ligne in contenu]
print(dates)