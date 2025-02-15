import re

def get_test(filename):
    with open(filename) as reader:
        contenu = reader.read()
        sentences = re.findall(r'[A-Z][^.!?]*[.!?]',contenu)
    with open("phrase_"+filename,"w") as writer:
        for s in sentences:
            s = s.replace('\n','')
            s = s.replace('\r','')
            s = s.replace('  ',' ')
            s = s.replace('  ',' ')
            s = s.replace('  ',' ')
            if len(s)>50 and s[0] in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
                writer.write(s+'\n')

get_test("scarlet.txt")
get_test("miserables.txt")