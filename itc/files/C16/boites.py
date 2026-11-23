reader = open("boites.txt","r")
boites = reader.read().strip().split("\n")
vmax = 0
rmax = ""
for b in boites:
    ref, x, y ,z = b.split(' ')
    if int(x)*int(y)*int(z)>vmax:
        vmax = int(x)*int(y)*int(z)
        rmax = ref

print(f"Vmax={vmax} atteint pour la boite {rmax}")
        
