from math import inf

def rm(somme,k):
    if (somme,k) in memo:
        return memo[(somme,k)]
    if k>=len(systeme): 
        memo[(somme,k)]=inf
        return inf
    if systeme[k]>somme:
        memo[(somme,k)] = rm(somme,k+1)
        return memo[(somme,k)]
    memo[(somme,k)] = min(1+rm(somme-systeme[k],k),rm(somme,k+1))
    return memo[(somme,k)]

def pieces(memo,somme):
    pieces = []
    while somme!=0:
        min = inf
        piece = None
        for i in range(len(systeme)+1,-1,-1):
            if (somme,i) in memo and memo[(somme,i)]<min:
                min = memo[(somme,i)]
                piece = systeme[i]
        somme = somme-piece
        pieces.append(piece)
    return pieces

systeme = (5, 4, 3, 1)
S = 7
memo = {(0,k):0 for k in range(len(systeme))}
for s in range(S+1):
    memo[(s,len(systeme))] = inf
print("Nombre de pièces : ",rm(S,0))
print("Liste des pièces ; ",pieces(memo,S))

print(memo)

