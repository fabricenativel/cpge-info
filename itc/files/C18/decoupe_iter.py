def valeur_max(taille, prix):
    v = {0:0,1:prix[1]}
    for i in range(2,taille+1):
        v[i] = max(v[k]+prix[i-k] for k in range(i))
    return v[taille]       