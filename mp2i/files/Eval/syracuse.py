
def syracuse(n):
    if (n%2 == 0):
        return n//2
    else:
        return 3*n+1


'''found = False
n = 1
while not found:
    cn = n
    while cn<500000 and cn!=1:
        cn= syracuse(cn)
    if cn > 500000:
        found = True
        print(n)
    else:
        n += 1
'''

cn = 1819
while cn!=1:
    cn = syracuse(cn)
    if cn%2023 == 72: print("OK !!!!")
print("fail")