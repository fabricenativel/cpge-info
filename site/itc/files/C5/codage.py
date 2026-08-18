import random

alphabet = [chr(c) for c in range(ord('A'),ord('Z')+1)]
code = [chr(c) for c in range(ord('A'),ord('Z')+1)]
random.shuffle(code)
codage = {alphabet[i] : code[i] for i in range(26)}
print(codage)
codage = {'A': 'Y', 'B': 'S', 'C': 'B', 'D': 'I', 'E': 'T', 'F': 'Q', 'G': 'N', 'H': 'U', 'I': 'X', 'J': 'F', 'K': 'C', 'L': 'W', 'M': 'K', 'N': 'H', 'O': 'E', 'P': 'G', 'Q': 'O', 'R': 'P', 'S': 'L', 'T': 'M', 'U': 'A', 'V': 'J', 'W': 'Z', 'X': 'V', 'Y': 'R', 'Z': 'D'}

decode = {codage[i] : i for i in codage}

for i in "SUPER ! VOUS AVEZ REUSSI L'EXERCICE":
    if i in codage:
        print(codage[i],end="")
    else:
        print(i,end="")
print()
