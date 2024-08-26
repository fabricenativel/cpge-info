#!/bin/python3
import os
import datetime
from colorama import Fore


# Le principe est de parcourir les dossiers des évaluations
# Celles non encore publiables sont taggés en ".later" 
# et ignorer par git donc non postés

BASEPATH = "/home/fenarius/Travail/Cours/cpge-info/docs"
NIVEAU = ["mp2i","pcsi","pc"]
TYPE = ["TP","DM","DS","IC"]
TODAY = datetime.date.today()
TAG = ".later"
PATH = {}
for niv in NIVEAU:
    PATH[niv] = {t : BASEPATH+"/"+niv+"/Evaluations/"+t+"/" for t in TYPE}
for niv in NIVEAU:
    print(Fore.RED+f"* Niveau : {niv.upper()}")
    file = "eval"+niv+".csv"
    if os.path.isfile(file):
        with open(file,"r",encoding="utf-8") as reader:
            for line in reader:
                td,nd,nomd,themesd,dated=line.split(";")
                eval = f"{td}{nd} : {nomd}"
                if nomd!="":
                    d,m,y = tuple(map(int,dated.split("/")))
                    publish_date = datetime.date(y,m,d)
                    to_check = PATH[niv][td]+td+nd+"/"
                    publiable = publish_date<=TODAY
                    direval = f"{PATH[niv][td]}{td}{nd}"
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

