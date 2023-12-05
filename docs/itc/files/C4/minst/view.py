from random import shuffle

SIZE = 5000



reader = open("mnist_train.csv")
content = reader.read().strip().split('\n')
shuffle(content)
for nb in range(SIZE):
    img = 'P2\n28 28\n255\n'
    imgdata = content[nb].strip().split(',')
    img += '# '+imgdata[0]+'\n'
    for i in range(28):
        for j in range(28):
            img += imgdata[1+i*28+j]+' '
        img += '\n'
    writer = open(f"img{nb+1}.pgm","w")
    writer.write(img)
    writer.close()
