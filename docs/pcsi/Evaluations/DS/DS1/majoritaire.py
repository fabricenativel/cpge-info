LETTRES = {chr(x) for x in range(ord('a'),ord('z')+1)}

def majoritaires(texte):
    occ = {}
    for c in texte:
        if c in LETTRES:
            if c in occ:
                occ[c]+=1
            else:
                occ[c]=1
    m = max(occ[c] for c in occ)
    return [c for c in occ if occ[c]==m]


print(majoritaires("tout va tres bien ici"))

print(majoritaires("ce petit exemple"))

