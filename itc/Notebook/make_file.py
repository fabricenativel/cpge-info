from random import shuffle

reader = open("iris.csv")
content = reader.read().strip().split('\n')
reader.close()
shuffle(content)

writer1 = open("iris120.csv","w")
for i in range(0,120):
    writer1.write(content[i])
    writer1.write('\n')
writer1.close()

writer2 = open("iris30.csv","w")
for i in range(0,30):
    writer2.write(content[120+i])
    writer2.write('\n')
writer2.close()