def mystere(elt,liste):
    if liste==[]:
        return 0
    if elt==liste[0]:
        return 1+mystere(elt,liste[1:])
    else:
        return mystere(elt,liste[1:])
    

def occurence(elt,liste):
	occ=0
	for x in liste:
		if x==elt:
			occ=occ+1
	return occ