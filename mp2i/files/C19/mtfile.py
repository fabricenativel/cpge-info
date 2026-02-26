with open("test.txt","w") as writer:
    cpt = 100
    for i in range(ord('A'),ord('Z')+1):
        s = chr(i)*cpt
        writer.write(s)
        cpt -= 1;

