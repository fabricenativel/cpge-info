from random import randint

def randlst(n, vmin, vmax):
    return [randint(vmin,vmax) for _ in range(n)]

def plusproches(lst):
    i1,i2 = 0, 1
    for i in range(len(lst)):
        for j in range(i+1,len(lst)):
            if abs(lst[i]-lst[j])<abs(lst[i1]-lst[i2]):
                i1, i2 = i, j
    return lst[i1],lst[i2]