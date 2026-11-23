s = 0
for i in range(1,100000):
    if i%10==7 or i%19==0:
        s+=i

print(s)