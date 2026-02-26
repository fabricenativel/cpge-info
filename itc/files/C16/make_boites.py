from random import randint

ref=set()
while len(ref)!=1000:
    ref.add("".join([chr(randint(65,90)) for _ in range(4)]))

writer=open("boites.txt","w")
for r in ref:
    writer.write(f"{r} {randint(20,145)} {randint(42,240)} {randint(33,400)}\n")
writer.close()