def ordonnee(p):
    x,y = p
    return y

res = sorted([(2,2), (1,5), (6,2), (4,7)], key = ordonnee)

print(res)