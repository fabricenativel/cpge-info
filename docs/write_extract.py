import os
from colorama import Fore

START_TAG = {"c" :"// --8<-- [start:", "ml" : "(* --8<-- [start:"}
END_TAG = {x : START_TAG[x].replace("start:","end:") for x in START_TAG}


def write_tag(fname):
    language = fname[fname.find(".")+1:]
    with open(dirname + "/" +fname) as reader:
        lines = reader.read().strip().split("\n")
        idx = 0
        print(Fore.BLUE + f"Traitement du fichier {fname}")
        cfound = False
        while idx<len(lines):
            if lines[idx].startswith(START_TAG[language]):
                cfound = True
                current_tag = lines[idx][len(START_TAG[language]):lines[idx].find("]")]
                idx += 1
                to_write = ""
                while not lines[idx].startswith(END_TAG[language]):
                    to_write = to_write + lines[idx] +"\n"
                    idx+=1
                print(Fore.YELLOW+ f" \t > Ecriture du fichier du tag {current_tag}")
                with open(dirname+"/"+current_tag+"."+language,"w") as writer:
                    writer.write(to_write)
            idx+=1
        if (not cfound):
            print(Fore.GREEN + "\t Aucun tag d'extraction trouvé !")



print("Ecriture des morceaux de code via les tag dans les fichiers ")
filiere = input("Entrer la filière : ")
chapitre = input("Entrer le numéro de chapitre : ")
dirname = f"/home/fenarius/Travail/Cours/cpge-info/docs/{filiere}/files/C{chapitre}"
source = [x for x in os.listdir(dirname) if x.endswith("c") or x.endswith("ml")]
for x in source:
    write_tag(x)
