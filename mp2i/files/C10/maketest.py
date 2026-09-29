from random import randint
with open("test5000.txt","w") as writer:
    for _ in range(5000):
        rc = "".join([chr(randint(32,126)) for x in range(6)])
        writer.write(rc+"\n")

