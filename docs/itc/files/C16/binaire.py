from random import randint

def to_bin(n):
    if n==0:
        return "0"
    else:
        r = ""
        while n!=0:
            r = str((n&1)) +r 
            n = n >> 1
    return r


for _ in range(1000):
    n =  randint(1,1000000)
    assert (bin((n))[2:]==to_bin(n))