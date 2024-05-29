with open("dico.txt") as reader:
    mots = reader.read().strip().split('\n')

for m in mots:
    s = set(list(m))
    if len(s)==4 and len(m)==12:
        print(m)
