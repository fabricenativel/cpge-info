reader = open("mots.txt")
mots = reader.read().strip().split('\n')
reader.close()

md = {}
for m in mots:
    if m in md:
        md[m]+=1
    else:
        md[m]=1

for m in md:
    if md[m]>500 and len(m)>3:
        print(f"{m} : {md[m]}")
    