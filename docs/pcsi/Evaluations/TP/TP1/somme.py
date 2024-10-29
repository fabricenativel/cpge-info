def somme(n):
    s = 0
    for i in range(1,n+1):
        if (i%7==0 and i%10==3):
            s = s + i
    return s

print(somme(200))