from random import randint, shuffle

SIZE = 100000
TARGET = 42
MINV = -10000000
MAXV = 10000000
writer = open("numbers.txt","w")
sol = randint(MINV,MAXV)
nums = set()
v = randint(MINV,MAXV)
for n in range(SIZE-2):
    while v in nums or (42-v) in nums or v==sol or v==42-sol:
        v = randint(MINV,MAXV)
    nums.add(v)
    
nums.add(sol)
nums.add(42-sol)
nums = list(nums)
shuffle(nums)
for n in nums:
    writer.write(str(n)+'\n')
print("Fichier crée")