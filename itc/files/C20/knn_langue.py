# Pour convertir un fichier utf8 en ascii :
#   konwert utf8-ascii <source> -o <dest>

import random

TEST = {"EN":"olivertwist.txt","FR":"ble_en_herbe.txt"}
LABELED = {"EN":"scarlet.txt","FR":"miserables.txt"}

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


def get_labeled(language,filename):
    with open(filename) as reader:
        sentences = reader.read().lower().replace('\n',' ').split('. ')
    items = [(make_dict(s),language) for s in sentences]
    return items

def get_test(language,filename):
    with open(filename) as reader:
        sentences = reader.read().lower().replace('\n',' ').split('. ')
    return [(s,language) for s in sentences]

def distance(d1,d2):
    s= sum([d2[c]**2 for c in d2 if c not in d1])
    for c in d1:
        if c in d2:
            s += (d2[c]-d1[c])**2
        else:
            s += d1[c]**2
    return s


def knn(sentence, training, k):
    d = make_dict(sentence)
    dist = [(distance(d,t),l) for t,l in training]
    dist.sort(key = lambda x : x[0])
    ngh = {l:0 for l in LABELED}
    for i in range(k):
        d, lang = dist[i]
        ngh[lang]+=1
    if ngh["FR"]>ngh["EN"]:
        return "FR"
    else:
        return "EN"

labeled_data =[]
test_data = []
for l in LABELED:
    labeled_data += get_labeled(l, LABELED[l])
    test_data += get_test(l,TEST[l])


confusion = {(x,y):0 for x in LABELED for y in LABELED}
test = random.sample(test_data,100)
for s,l in test:   
    confusion[(l,knn(s,labeled_data,1))]+=1

print(confusion)

    