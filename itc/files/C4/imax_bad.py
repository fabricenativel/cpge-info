def imax(l):
    im = 0
    maxi = 0
    for i in range(len(l)):
        if l[i]>maxi:
            im = i
            maxi = l[i]
    return im

print(imax([1,8,1,10]))