def evolution_case(precedente, centrale, suivante):
    if centrale==".":
        if (precedente=="#" and suivante==".") or (precedente=="." and suivante=="#"):
            return '#'
        else:
            return "."
    else:
        if (precedente=="#" and suivante=="#") or (precedente=="#" and suivante=="."):
            return '.'
        else:
            return "#"

def evolution(cases):
    netat = cases[0] #la case du début n'évolue
    for i in range(1,len(cases)-1):
        netat = netat + evolution_case(cases[i-1],cases[i],cases[i+1])
    netat = netat + cases[-1] #la dernière case n'évolue pas
    return netat

k = 256
dep = "."*k+"#"+"."*k
for _ in range(1000):
    dep = evolution(dep)

cpt = 0
for x in dep:
    if x=="#":
        cpt+=1
print(cpt)