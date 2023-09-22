#!/bin/python3
import os
import datetime
from colorama import Fore


# Le principe est de parcourir les dossiers des évaluations
# Celles non encore publiables sont taggés en ".later" 
# et ignorer par git donc non postés

PATH = "/home/fenarius/Travail/Cours/cpge-info/docs"
NIVEAU = ["mp2i","itc"]
TYPE = ["TP","DM","DS","IC"]
TODAY = datetime.date.today()
TAG = ".later"

for niv in NIVEAU:
    print(Fore.RED+f"* Niveau : {niv.upper()}")
    for type in TYPE:
        file = type.lower()+niv+'.csv'
        publish_path = PATH+"/"+niv+"/Evaluations/"+type+"/"
        if os.path.isfile(file):
            print(Fore.YELLOW+f"\t > Type = {type}")
            with open(file,"r",encoding="utf-8") as reader:
                for line in reader:
                    devoir=line.split(";")
                    eval = f"{type}{devoir[0]} : {devoir[1]}"
                    y,m,d = tuple(map(int,devoir[3].split("/")))
                    publish_date = datetime.date(y,m,d)
                    to_check = publish_path+type+devoir[0]+"/"
                    publiable = publish_date<=TODAY
                    direval = f"{publish_path}{type}{devoir[0]}"
                    enligne = os.path.isdir(direval)
                    print(Fore.WHITE+f"\t \t {eval} : ",end='')
                    if publiable and enligne:
                        print(Fore.GREEN+"Publiable et déjà en ligne : pas de changements")
                    if not publiable and not enligne:
                        print(Fore.GREEN+"Non publiable et pas en ligne : pas de changements")
                    if publiable and not enligne:
                        os.popen(f"mv {direval}.later {direval}")
                        print(Fore.MAGENTA+f"Mis en ligne car publiable depuis le {publish_date}")
                    if not publiable and enligne:
                        os.popen(f"mv {direval} {direval}.later ")
                        print(Fore.MAGENTA+f"Taggé en later car publiable seulement à partir du {publish_date}")
        else:
            print(f"\t > Aucun {type} pour le niveau {niv}")

