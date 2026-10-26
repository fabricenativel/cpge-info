def terme_suivant(n):
    return n//2 if n%2==0 else 3*n+1

def duree_vol(n):
    vol = 0
    while n!=1:
        n = terme_suivant(n)
        vol += 1
    return vol

def altitude_maxi(n):
    alt_max = n
    while n!=1:
        n = terme_suivant(n)
        if n>alt_max:
            alt_max = n
    return alt_max

maxvol = 0
maxi = []
for i in range(1,10001):
    if duree_vol(i) > maxvol:
        maxvol = duree_vol(i)
        maxi = [i]
    elif duree_vol(i) == maxvol:
        maxi.append(i)
        
print(maxvol,"pour",maxi)

print(altitude_maxi(9331))