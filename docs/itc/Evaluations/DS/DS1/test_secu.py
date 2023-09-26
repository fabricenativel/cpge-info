def num_secu(chaine):
    ns = ""
    # suppresion des espaces
    for c in chaine:
        if c!=" ":
            ns = ns + c
    return int(ns)

def clef(ns_debut):
    return 97-(ns_debut%97)

def num_secu_complet(ns_debut):
    return ns_debut*100 + clef(ns_debut)

def test_num_secu(ns):
    ns_complet = num_secu(ns)
    ns_debut = num_secu(ns[:-2])
    return num_secu_complet(ns_debut) == ns_complet


print(test_num_secu("1 70 05 83 050 042 92"))