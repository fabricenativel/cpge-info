reader = open("entiers.txt")
res = sum(list(map(int,reader.read().strip().split('\n'))))
print(res)