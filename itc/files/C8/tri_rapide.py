def partitionne(l):
    pivot = l[-1]
    plus_petit = [x for x in l if x<pivot]
    plus_grand = [x for x in l if x>pivot]
    return plus_petit, plus_grand

def tri_rapide(l):
    if len(l) <= 1:
        return l
    l1,l2 = partitionne(l)
    lt1 = tri_rapide(l1)
    lt2 = tri_rapide(l2)
    return lt1+[l[-1]]+lt2

l = [3, 7, 1, 9, 5, 2, 6, 4, 8]
lt = tri_rapide(l)
print(lt)