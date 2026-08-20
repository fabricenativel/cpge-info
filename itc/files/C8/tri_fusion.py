def tri_fusion(liste):
    if len(liste)<=1:
        return liste
    l1 = liste[:len(liste)//2]
    l2 = liste[len(liste)//2:]
    return fusion(tri_fusion(l1),tri_fusion(l2))
