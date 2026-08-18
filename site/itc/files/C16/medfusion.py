from random import randint

def med(a):
    n = len(a)
    if (n % 2 == 1):
        return a[n//2]
    return (a[n//2-1]+a[n//2])/2

def med_tri(a,b):
    c =  a + b
    c.sort()
    return med(c)

def med_parcours(a,b):
    m = len(a)
    n = len(b)
    t = (m+n)//2
    ida = 0
    idb = 0
    while (ida+idb<t):
        if (ida<m and idb<n):
            if a[ida]<=b[idb]:
                ida+=1
            else:
                idb+=1
        elif (ida==m):
            idb+=1
        else:
            ida+=1
    if ((m+n)%2==1):
        if (ida<m and idb<n):
            return min(a[ida],b[idb])
        elif ida==m:
            return   b[idb]
        else:
            return a[ida]
    else:
        if (ida>0 and idb>0):
            left = max(a[ida-1],b[idb-1])
        elif ida==0:
            left = b[idb-1]
        else:
            left = a[ida-1]
        if (ida<m and idb<n):
            right = min(a[ida],b[idb])
        elif ida==m:
            right = b[idb]
        else:
            right = a[ida]
        return  (left+right)/2


def med_dicho(a, b):
    m = len(a)
    n = len(b)
    if m > n:
        return med_dicho(b, a)
    if m == 0:
        return med(b)
    # Par dichotomie on cherche le nombre d'elts k à prendre dans a
    kmin = 0
    kmax = m
    '''
    a[0],...a[k-1] | a[k]...a[m-1]
    b[0],...b[l-1] | b[l]...b[n-1]
    '''
    while (kmin<=kmax):
        k = (kmin+kmax)//2
        l = (n+m)//2 - k
        #La partitition est correcte si a[k-1]<=b[l] et b[l-1]<a[k]
        if  (k<=0 or l>=n or a[k-1]<=b[l]) and (l<=0 or k>=m or b[l-1]<=a[k]):
            if ((n+m)%2==1):
                if (k<m and l<n):
                    return min(a[k],b[l])
                elif k>=m:
                    return b[l]
                else:
                    return a[k]
            else:
                if (k>0 and l>0):
                    left = max(a[k-1],b[l-1])
                elif k==0:
                    left = b[l-1]
                else:
                    left = a[k-1]
                if (k<m and l<n):
                    right = min(a[k],b[l])
                elif k>=m:
                    right = b[l]
                else:
                    right = a[k]
                return  (left+right)/2
        elif (k>=m or b[l-1]>a[k]):
            kmin = k + 1
        else:
            kmax = k - 1
    assert False



        
for i in range(1000):
    print(f"Test n°{i} :")
    m = randint(1,30)
    n = randint(1,30)
    a, b = [randint(0,10)],[randint(0,10)]
    for _ in range(m):
        a.append(randint(a[-1],5+a[-1]))
    for _ in range(n):
        b.append(randint(b[-1],5+b[-1]))
    mt = med_tri(a,b)
    mp = med_parcours(a,b)
    md = med_dicho(a,b)
    print(f"\t Version tri : {mt}")
    print(f"\t Version parcours : {mp}")
    print(f"\t Version dicho : {md}")
    if (mt!=mp or mt!=md):
        print(a)
        print(b)
        _ = input("BUG !!!")

    

