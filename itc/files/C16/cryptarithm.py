reader = open("dictionnaire.txt")
words = reader.read().strip().split('\n')
reader.close()
letters = ["p","r","o","g","a","m","e","l","g","n"]

total = 0
idx = 0
while (idx<len(words)):
    if (len(words[idx])==10 and all(l in letters for l in words[idx])):
        print(words[idx])
        total+=1
    idx+=1