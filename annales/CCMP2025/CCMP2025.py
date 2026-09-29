# --8<-- [start:Q3]
def profit(obj, S):
    pt = 0
    for i in range(len(S)):
        if S[i] == 1:
            ri, pi = obj[i]
            pt = pt + pi
    return pt
# --8<-- [end:Q3]

# --8<-- [start:Q4]


def contrainte(obj, S, b):
    poids = 0
    for i in range(len(S)):
        if S[i] == 1:
            ri, pi = obj[i]
            poids = poids + ri
    return poids <= b
# --8<-- [end:Q4]

# --8<-- [start:Q8]


def construitLi(obj):
    Lqi = []
    Li = []
    for i in range(len(obj)):
        Lqi.append(obj[i][1]/obj[i][0])
        Li.append(i)
    for i in range(1, len(Lqi)):
        x = Lqi[i]
        j = i
        while j > 0 and Lqi[j-1] < x:
            Lqi[j] = Lqi[j-1]
            Li[j] = Li[j-1]
            j -= 1
        Lqi[j] = x
        Li[j] = i
    return Li
# --8<-- [end:Q8]


def glouton(obj, b):
    # --8<-- [start:Q10]
    S = len(obj)*[0]
    Li = construitLi(obj)
    j = 0
    while b > 0 and j < len(obj):
        if obj[Li[j]][0] <= b:
            S[Li[j]] = 1
            b = b - obj[Li[j]][0]
        j += 1
    # --8<-- [end:Q10]
    return S
