from unidecode import unidecode 

reader = open("Vingt_mille_lieues_sous_les_mers.txt","r")
content = unidecode(reader.read().strip()).lower()
reader.close()

content = content.replace("\n"," ")
content = content.replace("'"," ")
tonly = ""
for c in content:
    if c in "abcdefghijklmnopqrstuvwxyz ":
        tonly +=c

words = tonly.split(" ")
words = list(filter(lambda x : len(x)>=2,words))

writer = open("mots.txt","w")
for w in words:
    writer.write(w+'\n')
writer.close()