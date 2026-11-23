from random import shuffle

NB_PATIENTS = 990
NB_OUT = 10

operations = ["-"] * 10 + ["+ "+str(i) for i in range(NB_PATIENTS)]


shuffle(operations)
with open("patients.txt","w") as writer:
    for op in operations:
        writer.write(op+"\n")


