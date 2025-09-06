import datetime
import csv
from hashlib import sha256

def define_env(env):
    "Hook function"

    # Les thèmes en mp2i : id : (nom,icone)
    env.variables['themes_mp2i']={
        1 : ("Méthodes de programmation",":fontawesome-solid-laptop-code:{title='Méthodes de programmation'}"),
        2 : ("Récursivité et induction",":fontawesome-solid-stairs:{title='Récursivité et induction'}"),
        3 : ("Structures de données",":fontawesome-solid-diagram-project:{title='Structures de données'}"),
        4 : ("Algorithmique",":fontawesome-solid-gears:{title='Algorithmique'}"),
        5 : ("Gestions des ressources de la machine",":fontawesome-solid-microchip:{title='Gestions des ressources de la machine'}"),
        6 : ("Logique",":fontawesome-solid-circle-chevron-up:{title='Logique'}"),
        7 : ("Base de données",":fontawesome-solid-database:{title='Base de données'}"),
        8 : ("Langage C",":material-language-c:{title='Langage C'}"),
        9 : ("Langage OCaml",":simple-ocaml:{title='Langage OCaml'}")
    }

    env.variables['themes_itc']={
        1 : ("Python",":fontawesome-brands-python:{title='Python'}"),
        2 : ("Base de données",":fontawesome-solid-database:{title='Base de données'}"),
        3 : ("Programmation dynamique",":fontawesome-solid-book-bookmark:{title='Dictionnaire et programmation dynamique'}"),
        4 : ("Algorithme pour l'IA et l'étude des jeux",":material-dice-multiple:{title='IA et jeux'}"),
        5 : ("Fonctions récursives",":fontawesome-solid-stairs:{title='Récursivité'}"),
        6 : ("Méthodes de programmation et analyse des algorithmes",":fontawesome-solid-gears:{title='Algorithmique'}"),
        7 : ("Représentation des nombres",":octicons-file-binary-16:{title='Représentation des nombres'}"),
        8 : ("Base des graphes, plus courts chemins",":material-graph:{title='Base des graphes'}")
    }
    
    # Les icones illustrant les exercices
    env.variables['icones_exo']={
        "dur": ":fontawesome-solid-bomb:{title='Exercice difficile'}",
        "rappel": ":fontawesome-solid-clock-rotate-left:{title='Retour sur des notions antérieures'}",
        "recherche": ":fontawesome-solid-search:{title='Exercice de recherche'}",
        "capacite": ":fontawesome-solid-puzzle-piece:{title='Exercice testant une capacité du chapitre'}",
        "concours": ":fontawesome-solid-graduation-cap:{title='Exercice extrait de concours'}",
    }
    
    env.variables['devant_exo']=':black_small_square:'
    env.variables['num_exo']=1
    env.variables['num_rep']=1

    # Progression : Thème, Titre, durée, fichiers
    env.variables['progression_mp2i_s1']={
        0 : [5,"Systèmes","systemes.md"],
        1 : [8,"Premiers pas en langage C","introC.md"],
        2 : [1,"Discipline de programmation","discipline.md"],
        3 : [8,"Pointeurs et types structurés","pointeurs.md"],
        4 : [3,"Arithmétique des ordinateurs","arithmetique.md"],
        5 : [2,"Récursivité","recursivite.md"],
        6 : [9,"OCaml : aspects fonctionnels","introOCaml.md"],
        7 : [1,"Terminaison, correction, complexité","terminaison.md"],
        8 : [3,"Structures de données séquentielles","sl.md"],
        9 : [9,"Ocaml : aspects impératifs","OCamlimp.md"]
    }
    env.variables['progression_mp2i_s2']={
        10 : [3,"Tableau associatif, hachage","hash.md"],
        11 : [7,"Introduction aux bases de données","introbd.md"],
        12 : [3,"Arbres binaires","arbres.md"],
        13 : [4,"Force brute, retour sur trace","forcebrute.md"],
        14 : [2,"Induction","induction.md"],
        15 : [4,"Décomposition en sous problèmes","decomposition.md"],
        16 : [6,"Logique","logique.md"],
        17 : [3,"Graphes","graphes.md"],
        18 : [7,"Modèle entité-association","mea.md"],
        19 : [4,"Algorithmes des textes","textes.md"],
        20 : [4,"Algorithmes des graphes","algographes.md"],
        21 : [4,"Complement sur les arbres","complement.md"]
    }

    # Progression : Thème, Titre, durée, fichiers
    env.variables['progression_itc_s1']={
        0 : [1,"Faire le point !","point.md"],
        1 : [1,"Bases de Python","bases.md"],
        2 : [1,"Listes","listes.md"],
        3 : [1,"Fichiers","fichiers.md"],
        4 : [6,"Discipline de programmation","discipline.md"],
        5 : [6,"Dictionnaires","dictionnaires.md"],
        6 : [5,"Récursivité","recursivite.md"]
    }
    env.variables['progression_itc_s2']={
        7 : [6,"Algorithmes gloutons","gloutons.md"],
        8 : [6,"Tris","tris.md"],
        9 : [7,"Représentation des entiers","entiers.md"],
        10 : [6,"Terminaison et corrections","terminaison.md"],
        11 : [8,"Graphes","graphes.md"],
        12 : [6,"Complexité","complexite.md"],
        13 : [7,"Représentation des flottants","flottants.md"],
        14 : [8,"Plus courts chemins dans un graphe","parcours.md"],
        15 : [1,"Manipulation d'images","images.md"]
    }
    env.variables['progression_itc_s3']={
        16 : [1,"Un peu de Python","revisions.md"],
        17 : [2,"Introduction aux bases de données","introbd.md"],
        18 : [3,"Programmation dynamique","progdyn.md"],
        19 : [2,"Requêtes sur plusieurs tables","jointures.md"],
        20 : [4,"k plus proches voisins, k-moyennes","knn.md"],
        21 : [4,"Algorithme pour l'étude des jeux","algojeux.md"]
    }

    with open("qcm.csv","r",encoding="utf-8") as f:
        questions = list(csv.DictReader(f,delimiter=";"))
    env.variables['qcm']=questions


    # affichage d'un chapitre dans la progression
    @env.macro
    def chapitre(num,theme,titre,lien,niveau):
        icone = env.variables['themes_'+niveau][theme][1]
        return f"|{icone}|[C{num}- {titre}]({lien})\n"

    # Affichage des chapitres de la progression
    @env.macro
    def affiche_progression(niveau):
        ret='''
|Thème |Titre        |
|-|-------------|
        '''
        progression_niveau = env.variables['progression_'+niveau]
        for k in progression_niveau:
           ret+=chapitre(k,progression_niveau[k][0],progression_niveau[k][1],progression_niveau[k][2],niveau[:-3])
        return ret
    
    # Affichage du titre sur la page d'un chapitre
    @env.macro
    def titre_chapitre(numero,niveau_semestre):
        # Position de l'ancre pour repérage dans la page
        titre = env.variables['progression_'+niveau_semestre][numero][1]
        theme = env.variables['progression_'+niveau_semestre][numero][0]
        icone = env.variables["themes_"+niveau_semestre[:-3]][theme][1]
        ligne=f"# <span class='numchapitre'>C{numero}</span> {titre} "
        ligne+=f"<span style='float:right;'>{icone}</span>"
        return ligne
    
    @env.macro
    def titre_concours(concours, annee):
        return f"# <span class='numchapitre'>{env.variables['icones_exo']['concours']}</span> {concours}  {annee}"
    


    # Affichage du titre TP noté
    @env.macro
    def tpnote(numero,titre):
        # Position de l'ancre pour repérage dans la page
        ligne=f"# <span class='numeval'>TP{numero}</span> {titre}"
        ligne+="<span style='float:right;'>:fontawesome-solid-circle-check:{title='TP noté'}</span>"
        return ligne
    
    # Affichage titre DM
    @env.macro
    def dm(numero,titre):
        ligne=f"# <span class='numchapitre'>DM{numero}</span> {titre} "
        ligne+="<span style='float:right;'>:material-home-search:{title='Devoir maison'}</span>"
        return ligne



    # Affichage téléchargement diaporama de cours
    @env.macro
    def affiche_cours(num):
        fichier=f'C{num}/C{num}-cours.pdf'
        aff_cours = f'''
<span class='centre'>[Support de cours chapitre {num} :fontawesome-regular-file-pdf:](./Cours/'''+fichier+'''){.md-button target=_blank}</span>
!!! warning "Attention"
    Ce diaporama ne vous donne que quelques points de repères lors de vos révisions. Il devrait être complété par la relecture attentive de vos **propres** notes de cours et par une révision approfondie des exercices.'''
        return aff_cours
    
    # Affichage téléchargement diaporama de cours
    @env.macro
    def fiche_cours(num):
        fichier=f'C{num}/C{num}-cours.pdf'
        aff_cours = f'''
<span class='centre'>[Fiche de cours chapitre {num} :fontawesome-regular-file-pdf:](./Cours/'''+fichier+'''){.md-button target=_blank}</span>'''
        return aff_cours

    # Affichage téléchargement fiche de TD
    @env.macro
    def td(num):
        fichier=f'TD{num}.pdf'
        aff_td = f'''
<span class='centre'>[Fiche de TD{num} :fontawesome-regular-file-pdf:](./TD/'''+fichier+'''){.md-button target=_blank}</span>'''
        return aff_td
    
    # Affichage titre d'une exercice
    @env.macro
    def exo(titre,licones,numero=1):
        if numero==0:
            env.variables['num_exo']=1
        ligne=f"### {env.variables['devant_exo']}   Exercice {env.variables['num_exo']} "
        if titre!="":
            ligne+=f": *{titre}*"
        if licones!=[]:
            ligne+=f"<span style='float:right;'>"
            for icone in licones:
                ligne+=f"<span style='float:right;'>&thinsp; {env.variables['icones_exo'][icone]}</span>"
            ligne+="</span>"
        env.variables['num_exo']=env.variables['num_exo']+1
        return ligne

    # Ecriture en petites majuscules à la façon de \sc de LaTeX
    @env.macro
    def sc(chaine):
        return f'<span style="font-variant:small-caps;">{chaine}</span>'

    # Citation en tête de chapitre
    @env.macro
    def citation(quote,author,source=None):
        co = f"<span class='quote'>\"{quote}\"</span><br>"
        co += f"<span class='author'>{author}</span><br>"
        if source!=None:
            co+=f"<span class='source'>({source})</span>"
        return co

    # Téléchargement d'un fichier
    @env.macro
    def telecharger(description,fichier,center=True):
        liens =f"[{description} :material-download:]({fichier})"
        liens+="{.md-button}"
        if center: liens="<span class='centre'>"+liens+"</span>"
        return liens
    
    # Tableau de données en ligne :
    @env.macro
    def table_data(headers,content):
        table = '<table class="data">'
        for i in range(len(headers)):
            table += f'<tr><th>{headers[i]}</th>'
            for c in content[i]:
                table += f'<td>{c}</td>'
            table+='</tr>'
        table += '</table>'
        return table
    
    # Voir les indices d'un iterable
    @env.macro
    def indices(content,quote=False):
        table = '<table class="data">'
        q = "\'" if quote else ""
        l1, l2 = '',''
        for i,c in enumerate(content):
            l1 += f'<td>{q}{c}{q}</td>'
            l2 += f'<td>{i}</td>'
        table+=f'<tr>{l1}</tr><tr>{l2}</tr>'
        table += '</table>'
        return table


    # Affichage de la liste des TP construite depuis le csv
    @env.macro
    def liste_eval(niveau,type):
        aff="\n"
        aff+= "|N° | Thèmes| Titre | Enoncé| Corrigé |\n"
        aff+= "|:-:|:-----:|-------|:-----:|:-----:|\n"
        FNAME = f"./{type}{niveau}.csv"
        utype = type.upper()
        today = datetime.date.today()
        if niveau=="pc" or niveau=="pcsi":
            tniv = "themes_"+"itc"
        else:
            tniv = "themes_"+niveau
        with open(FNAME,"r",encoding="utf-8") as f:
            nums=1
            for s in f:
                ico = ""
                lf=s.split(";") 
                y,m,d = tuple(map(int,lf[3].split("/")))
                publish_date = datetime.date(y,m,d)
                for theme in lf[2]:
                    ico = ico + env.variables[tniv][int(theme)][1]
                if publish_date <= today:
                    aff+=f"|**{nums}**|{ico}|{lf[1]}|[:fontawesome-solid-file-pen:](./{niveau}/Evaluations/{utype}/{utype}{lf[0]}/{utype}{lf[0]}.pdf) | [:fontawesome-solid-file-circle-check:](./{niveau}/Evaluations/{utype}/{utype}{lf[0]}/{utype}{lf[0]}-Correction.pdf)  |\n"
                nums+=1
        return aff
    
    @env.macro
    def affiche_eval(niveau):
        ttypes = ["DS","IC","TP"]
        noms = {"IC":"Interrogation de cours", "DS": "Devoirs surveillés", "DM" : "Devoirs maison", "TP": "Travaux pratiques"}
        entete = "|N° |Date| Thèmes| Titre | Enoncé| Corrigé |\n"
        entete+= "|:-:|:---|:-----:|-------|:-----:|:-------:|\n"
        listes = {k : f"###{noms[k]}\n"+entete for k in ttypes}
        FNAME = f"./eval{niveau}.csv"
        today = datetime.date.today()
        if niveau=="pc" or niveau=="pcsi":
            tniv = "themes_"+"itc"
        else:
            tniv = "themes_"+niveau
        with open(FNAME,"r",encoding="utf-8") as f:
            for s in f:
                ico = ""
                utype,numero,titre,themes,date=s.split(";") 
                d,m,y = date.strip().split("/")
                publish_date = datetime.date(*tuple(map(int,(y,m,d))))
                for theme in themes:
                    ico = ico + env.variables[tniv][int(theme)][1]
                if publish_date <= today:
                    listes[utype]+=f"|**{numero}**|{d}/{m}/{y}|{ico}|{titre}|[:fontawesome-solid-file-pen:](./{niveau}/Evaluations/{utype}/{utype}{numero}/{utype}{numero}.pdf) | [:fontawesome-solid-file-circle-check:](./{niveau}/Evaluations/{utype}/{utype}{numero}/{utype}{numero}-Correction.pdf)  |\n"      
                elif utype=="DS":
                    listes[utype]+=f"|**{numero}**|*prévu le {d}/{m}/{y}*||.......|:material-file-question-outline:| :material-file-question:|\n"
        return "\n".join([listes[k] for k in ttypes])
        

    # Affichage de la liste des DM construite depuis le csv
    @env.macro
    def liste_dm(niveau):
        aff="### Devoirs maison \n"
        aff+= "|N° | Thèmes| Titre | Enoncé| Corrigé |\n"
        aff+= "|:-:|:-----:|-------|:-----:|:-------:|\n"
        FNAME = f"./dm{niveau}.csv"
        today = datetime.date.today()
        with open(FNAME,"r",encoding="utf-8") as f:
            nums=1
            for s in f:
                ico = ""
                num,titre,themes,date=s.split(";")
                d,m,y = date.strip().split("/")
                publish_date = datetime.date(*tuple(map(int,(y,m,d))))
                for theme in themes:
                    ico = ico + env.variables["themes_"+niveau][int(theme)][1]
                if publish_date <= today:
                    aff+=f"|**{nums}**|{ico}|{titre}|[:fontawesome-solid-file-pen:](mp2i/Evaluations/DM/DM{num}/DM{num}.md) | [:fontawesome-solid-file-circle-check:](mp2i/Evaluations/DM/DM{num}/DM{num}-Correction.md)|\n"
                else:
                    aff+=f"|**{nums}**|{ico}|{titre}|[:fontawesome-solid-file-pen:](mp2i/Evaluations/DM/DM{num}/DM{num}.md) | {d}/{m}/{y}|\n"
                nums+=1
        return aff
    
    @env.macro
    def check_reponse(reponse,reset=1):
        if reset==0:
            env.variables['num_rep']=1    
        idquestion =  'q'+str(env.variables['num_rep'])
        hasrep = sha256(reponse.encode('utf-8')).hexdigest()
        idimg = idquestion+'img'
        to_disp=f'''
<input type="text" id="{idquestion}" class="text-input-neutral"> <img id="{idimg}" src="https://fabricenativel.github.io/cpge-info/images/circle-question.svg" width="24px" style="vertical-align:middle"> 
<input type="button" value="valider" class="repbutton" onclick="check('{idquestion}','{hasrep}')">
<input type="button" value="reset" class="repbutton" onclick="imgreset('{idquestion}')">
'''
        env.variables['num_rep']=env.variables['num_rep']+1
        return to_disp
    
    @env.macro
    def capytale(id):
        lien = "[![logo capytale](https://fabricenativel.github.io/cpge-info/images/capytale.png){.imgcentre width=150px border=2px}]"
        lien +=f"(https://capytale2.ac-paris.fr/web/c/{id}/metice)"
        lien += "{target=_blank}"
        return lien
    
    @env.macro
    def notebook(id,name,file,inadmo=False):
        res = "* Télécharger le notebook pour l'utiliser en local (installation de jupyter nécessaire)"
        res += telecharger(name,file)
        if not inadmo:
            res+='\n'
        else:
            res+='\n\t'
        res += "* Utiliser l'application Capytale (aucune installation nécessaire)"
        res += capytale(id)
        return res
    
    @env.macro
    def make_jeuvie(etat,num):
        car = ['&#9312;','&#9313;','&#9314;','&#9315;','&#9316;','&#9317;','&#9318;','&#9319;','&#9320;']
        res = "<table class='jeuvie'>"
        cpt = 0
        for lig in etat:
            res += '<tr>'
            for c in lig:
                if c=='.':
                    res = res + "<td><span class='cellule'>&nbsp;</span></td>"
                else:
                    if len(num)!=0:
                        res = res + f"<td><span class='cellule'>{car[num[cpt]-1]}</span></td>"
                        cpt += 1
                    else:
                        res = res + f"<td><span class='cellule'>&#128976;</span></td>"
            res += '</tr>'
        res += '</table>'
        return res
    
    @env.macro
    def file(elts):
        aff = '<table class="file"><tr>'
        for e in elts:
            aff += f'<td>{e}</td>'
        aff += '</tr></table>'
        return aff
    
    @env.macro
    def pile(elts):
        aff = '<table class="pile">'
        if elts==[]:
            aff += f'<tr><td>&nbsp;</td></tr>'
        for i in range(len(elts)-1,-1,-1):
            aff += f'<tr><td>{elts[i]}</td></tr>'
        aff += '</table>'
        return aff


    @env.macro
    def mpy(s):
        return "`#!python "+s+"`"


    @env.macro
    def affiche_question(num,index):
        lenonce = env.variables.qcm[num]["enonce"]
        # Traitement si enoncé sur plusieurs lignes
        nl = lenonce.find('\n')
        if nl>0:
            lenonce=lenonce.replace("\n",'"\n',1)
            lenonce=lenonce.replace("\n",'\n    ')
        else:
            lenonce+='"'
        # Traitement si image
        limg = env.variables.qcm[num]["image"]
        if limg!='':
            lenonce+=f'\n \t ![illustration](./images/C{env.variables.qcm[num]["chapitre"]}/{limg})'
            lenonce+='{: .imgcentre}\n'
        modele = f'''
!!! fabquestion "**{index}.** {lenonce}
    === "Réponses<span class='invisible'>{num}</span>"
        - [ ] a) {env.variables.qcm[num]["reponseA"]}
        - [ ] b) {env.variables.qcm[num]["reponseB"]}
        - [ ] c) {env.variables.qcm[num]["reponseC"]}
        - [ ] d) {env.variables.qcm[num]["reponseD"]}
    === "Correction<span class='invisible'>{num}</span>"\n'''
        for rep in "ABCD":
            clerep = "reponse"+rep
            if env.variables.qcm[num]["bonne_reponse"]==rep:
                modele+=f"        - [x] {rep.lower()}) =={env.variables.qcm[num][clerep]}== \n"
            else:
                modele+=f"        - [ ] {rep.lower()}) ~~{env.variables.qcm[num][clerep]}~~ \n"
        return modele

    @env.macro
    def affiche_qcm(liste_question):
        qcm = ""
        for index in range(len(liste_question)):
            qcm+=affiche_question(liste_question[index],index+1)
        return qcm
    
    @env.macro
    def qcm_chapitre(num_chap):
        index=1
        qcmc=""
        for num in range(len(env.variables.qcm)):
            if int(env.variables.qcm[num]["chapitre"])==num_chap:
                qcmc+=affiche_question(num,index)
                index+=1
        return qcmc
    
    @env.macro
    def all_qcm():
        index=1
        qcmc=""
        for num in range(len(env.variables.qcm)):
            qcmc+=affiche_question(num,index)
            index+=1
        return qcmc
    
    @env.macro
    def binaire(nombre):
        to_disp = '$'
        m = len(nombre)-1
        for c in nombre:
            to_disp += "\overset{\displaystyle{_{2^"+str(m)+"}}}{\\boxed{\\strut"+c+"}}"
            m -= 1
        to_disp += '$'
        return to_disp

    @env.macro
    def decimal(binaire):
        return "$"+str(int("0b"+binaire,2))+"$"
    
    @env.macro
    def binaire_dec(b):
        return binaire(b)+" = "+decimal(b)
    
    @env.macro
    def dec_bin(n,chiffres=8):
        to_bin = bin(n)[2:]
        return f"${n} =$" +" "+ binaire(to_bin.zfill(chiffres))
    
    @env.macro
    def awale(nseed):
        up = nseed[11:5:-1]
        down = nseed[0:6]
        res = f'<table class="awale-board"><tr>'
        for i in range(6):
            res += f'<td class="awale-cell"><div class="seed-count">{up[i]}</div></td>'
        res +='</tr> <tr>'
        for i in range(6):
            res += f'<td class="awale-cell"><div class="seed-count">{down[i]}</div></td>'
        res += f'</tr></table>'
        return res

    @env.macro
    def sujets(a):
        FNAME = "./annales.csv"
        corrige = {"0" : ":fontawesome-solid-square-xmark:{.rouge} non disponible",
                   "1": "[:white_check_mark: (F. Nativel)]",
                   "2": "[:white_check_mark: (V. Picard)]"
                   }
        res =  "|Banque|Sujet|Rapport|Corrigé|\n"
        res += "|------|-----|-------|-------|\n"
        with open(FNAME,"r",encoding="utf-8") as f:
            for s in f:
                banque,annee,titre,cor=s.strip().split(";")
                if annee==a:
                    res += f"|**{banque}**|[{titre}](./{banque}{a}/{banque}{a}.pdf)|[:fontawesome-solid-file:](./{banque}{a}/Rapport{a}.pdf)|"
                    res += f"{corrige[cor]}"
                    if cor!="0":
                        res+=f"(./{banque}{a}/{banque}{a}.md)"
                    res += "\n"
        return res

