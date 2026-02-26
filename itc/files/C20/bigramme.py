# Pour convertir un fichier utf8 en ascii :
#   konwert utf8-ascii <source> -o <dest>

import random

LABELED = {"EN":"phrases_EN.txt","FR":"phrases_FR.txt","DE":"phrases_DE.txt"}

LETTERS = "abcdefghijklmnopqrstuvwxyz"

def make_dict(sentence):
    d = {}
    for i in range(len(sentence)-1):
        if sentence[i] in LETTERS and sentence[i+1] in LETTERS:
            bigramme = sentence[i]+sentence[i+1]
            if bigramme in d:
                d[bigramme]+=1
            else:
                d[bigramme]=1
    return d


def get_sentences(language,filename, nbtr, nbtest):
    with open(filename) as reader:
        sentences = reader.read().lower().split('\n')
    sentences = [(s,language) for s in sentences]
    labeled = sentences[:nbtr]
    for_test = sentences[nbtr+1:nbtr+nbtest+1]
    return labeled,for_test


def distance(d1,d2):
    s= sum([d2[c] for c in d2 if c not in d1])
    for c in d1:
        if c in d2:
            s += abs(d2[c]-d1[c])
        else:
            s += d1[c]
    return s


def knn(sentence, labeled, k):
    d = make_dict(sentence)
    dist = [(s,distance(d,make_dict(s)),l) for s,l in labeled]
    dist.sort(key = lambda x : x[1])
    pp = dist[0][0]
    ngh = {l:0 for l in LABELED}
    for i in range(k):
        s, d, lang = dist[i]
        ngh[lang]+=1
    lngh = [(l,ngh[l]) for l in LABELED]
    lngh.sort(key=lambda x : x[1], reverse=True)
    return s,lngh[0][0]

nb_training = 1000
nb_test = 100
labeled_data =[]
test_data = []
for l in LABELED:
    labeled,test = get_sentences(l, LABELED[l],nb_training,nb_test)
    labeled_data += labeled
    test_data += test

exphrase = input("Entrez une phrase à classer :")
pp, res = knn(exphrase,labeled_data,5)
print("Classé en ",res)
'''
sample = random.sample(test_data,nb_test)
confusion = {(x,y):0 for x in LABELED for y in LABELED}
n = 1
for s,l in sample:  
    pp, res = knn(s,labeled_data,1)
    if l!=res:
        print(f"Erreur de classification  pour {s} ({l}) classé en {res}, ressemblance avec {pp}")
    confusion[(l,res)]+=1

print(confusion)'''
