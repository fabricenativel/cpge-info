def mystere(adn):
    n = len(adn)
    a, c, g, t = (0, 0, 0, 0)
    i = n - 1
    while i>=0:
        if adn[i] == 'A':
            a += 1
        elif adn[i] =='C':
            c += 1
        elif adn[i] == 'G':
            g += 1
        elif adn[i] == 'T':
            t += 1
        i = i - 1
    return [100*a/n, 100*c/n, 100*g/n, 100*t/n]

def binaire(nb,c):
    fb = bin(nb)[2:]
    return (c-len(fb))*"0"+fb

def decode(format):
    code = {"00":"A", "01":"C", "10":"G", "11":"T"}
    res = ""
    for f in format:
        fb = binaire(f,8)
        nucleotide = code[fb[0:2]]
        repetition = 0
        poids = 1
        for c in fb[-1:1:-1]:
            repetition += poids*int(c)
            poids = poids * 2
        res += repetition*nucleotide
    return res


def est_adn(adn):
    for x in adn:
        if x!='A' and x!='C' and x!='G' and x!='T':
            return False
    return True

def occurrences(adn):
    assert est_adn(adn), "Ce n'est pas un brin d'adn"
    occ = {"A":0, "C":0, "G":0, "T":0}
    for x in adn:
        occ[x]+=1
    return occ

def encode(nucleotide, repetitions):
    code = repetitions
    if nucleotide=="C":
        code += 64
    elif nucleotide=="G":
        code += 128
    elif nucleotide=="T":
        code += 192
    return code

print(encode("C",37))
print(encode("T",7))
print(occurrences("ATCGTACGT"))
print(occurrences("TTTTGGTG"))
print((decode([101])))