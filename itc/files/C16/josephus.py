n = 10000
cercle = [i for i in range(1,n+1)]
while (len(cercle)!=1):
    killer = cercle.pop(0)
    cercle.append(killer)
    cercle.pop(0)

print(f"survivant = {cercle[0]}")