#!/bin/python3
import os
import datetime

SAVEPATH = "/home/fenarius/Travail/Cours/CorrectionCPGE/"
PATH = "/home/fenarius/Travail/Cours/cpge-info/docs"
NIVEAU = ["mp2i","itc"]
SRC = "Corrections"
TYPE = ["TP","DM","DS"]
TODAY = datetime.date.today()
EXT = {"TP":".pdf","DM":".md", "DS":".pdf"}

print("Vérification des corrections à publier")
for niv in NIVEAU:
    for type in TYPE:
        print(f"Niveau : {niv} - Type = {type}")
        file = type.lower()+niv+'.csv'
        publish_path = PATH+"/"+niv+"/Evaluations/"+type+"/"
        if os.path.isfile(file):
            print(f"> Fichier {file} trouvé, vérification des corrections")
            with open(file,"r",encoding="utf-8") as reader:
                for line in reader:
                    devoir=line.split(";")
                    y,m,d = tuple(map(int,devoir[3].split("/")))
                    publish_date = datetime.date(y,m,d)
                    if type=="TP":
                        corrige = publish_path+type+devoir[0]+"/"+type+devoir[0]+"-Correction"+EXT[type]
                        save = SAVEPATH+niv.upper()+"/"+type+"/"+type+devoir[0]+"-Correction"+EXT[type]
                    elif type=="DM":
                        corrige = publish_path+type+devoir[0]+"-Correction"+EXT[type]
                        save = SAVEPATH+niv.upper()+"/"+type+"/"+type+devoir[0]+"-Correction"+EXT[type]
                    else:
                        corrige = publish_path+type+devoir[0]
                        save = SAVEPATH+niv.upper()+"/"+type+"/"+type+devoir[0]+"/"                   
                    if publish_date<=TODAY:
                        print(f"\t * La correction du {type}{devoir[0]} {devoir[1]} peut être publié")
                        if os.path.isfile(corrige) or os.path.isdir(corrige):
                            print(f"\t   Déjà en ligne : pas de modification")
                        else:
                            if os.path.isfile(save) or os.path.isdir(save):
                                print(f"\t  A publier : fichier copié depuis la sauvegarde")
                                os.popen(f"cp -r {save} {corrige}")
                            else:
                                print(f"\t  A publier : fichier non trouvé la sauvegarde")
                    else:
                        print(f"\t * La correction du {type}{devoir[0]} {devoir[1]} ne peut PAS être publié")
                        if os.path.isfile(corrige) or os.path.isdir(corrige):
                            print(f"\t   Le fichier de correction existe et doit être déplacé avant le pull")
                            os.popen(f"mv {corrige} {save}")
                        else:
                            print(f"\t   Le fichier de correction n'a pas été trouvé")
        else:
            print(f"> Aucun {type} pour le niveau {niv}")

