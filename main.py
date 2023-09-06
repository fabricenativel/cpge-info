import datetime

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
        4 : ("Algorithme pour l'IA et l'étude des jeux",":material-dice-multiple:{title='IA et jeux'}")
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

    # Progression : Thème, Titre, durée, fichiers
    env.variables['progression_mp2i_s1']={
        0 : [5,"Systèmes","systemes.md"],
        1 : [8,"Premiers pas en langage C","introC.md"],
        2 : [1,"Spécifications et tests","validation.md"],
        3 : [8,"Pointeurs et types structurés","pointeurs.md"],
        4 : [3,"Arithmétique des ordinateurs","arithmetique.md"],
        5 : [2,"Récursivité","recursivite.md"],
        6 : [9,"OCaml : aspects fonctionnels","introOCaml.md"],
        7 : [3,"Structures de données linéaires","listechainees.md"],
        8 : [1,"Terminaison, correction, complexité","terminaison.md"],
        9 : [9,"Ocaml : aspects impératifs","OCamlimp.d"]
    }
    env.variables['progression_mp2i_s2']={
        10 : [3,"Tableau associatif, hachage","hash.md"],
        11 : [7,"Introduction aux bases de données","introbd.md"],
        12 : [3,"Arbres binaires","arbres.md"],
        13 : [4,"Force brute, retour sur trace","forcebrute.md"],
        14 : [6,"Syntaxe des formules logiques","logique.md"],
        15 : [3,"Graphes","graphes.md"],
        16 : [4,"Décomposition en sous problèmes","decomposition.md"],
        17 : [2,"Induction","induction.md"],
        18 : [7,"Modèle entité-association, jointures","jointures.md"],
        19 : [4,"Algorithmes des textes","textes.md"],
        20 : [6,"Calcul propositionnel","propositionel.md"],
        21 : [4,"Algorithmes des graphes","algographes.md"]
    }

    # Progression : Thème, Titre, durée, fichiers
    env.variables['progression_itc_s3']={
        0 : [1,"Un peu de Python","revisions.md"],
        1 : [2,"Introduction aux bases de données","introbd.md"],
        2 : [3,"Programmation dynamique","progdyn.md"],
        3 : [2,"Requêtes sur plusieurs tables","jointures.md"],
        4 : [4,"k plus proches voisins, k-moyennes","knn.md"],
        5 : [4,"Algorithme pour l'étude des jeux","algojeux.md"]
    }

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
        ligne=f"# <span class='numeval'>dm{numero}</span> {titre} "
        ligne+="<span style='float:right;'>:material-home-search:{title='Devoir maison'}</span>"
        return ligne



    # Affichage téléchargement diaporama de cours
    @env.macro
    def cours(num):
        fichier=f'C{num}/C{num}-cours.pdf'
        aff_cours = f'''
<span class='centre'>[Support de cours chapitre {num} :fontawesome-regular-file-pdf:](./Cours/'''+fichier+'''){.md-button target=_blank}</span>
!!! warning "Attention"
    Ce diaporama ne vous donne que quelques points de repères lors de vos révisions. Il devrait être complété par la relecture attentive de vos **propres** notes de cours et par une révision approfondie des exercices.'''
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

    # Affichage de la liste des TP construite depuis le csv
    @env.macro
    def liste_tp(niveau):
        aff="\n"
        aff+= "|N° | Thèmes| Titre | Enoncé| Corrigé |\n"
        aff+= "|:-:|:-----:|-------|:-----:|:-----:|\n"
        FNAME = f"./tp{niveau}.csv"
        today = datetime.date.today()
        with open(FNAME,"r",encoding="utf-8") as f:
            nums=1
            for s in f:
                ico = ""
                lf=s.split(";") 
                y,m,d = tuple(map(int,lf[3].split("/")))
                publish_date = datetime.date(y,m,d)
                for theme in lf[2]:
                    ico = ico + env.variables["themes_"+niveau][int(theme)][1]
                if publish_date <= today:
                    aff+=f"|**{nums}**|{ico}|{lf[1]}|[:fontawesome-solid-file-pen:](../Evaluations/TP/TP{lf[0]}/TP{lf[0]}.pdf) | [:fontawesome-solid-file-circle-check:](../Evaluations/TP/TP{lf[0]}/TP{lf[0]}-Correction.pdf)  |\n"
                else:
                    aff+=f"|**{nums}**|{ico}|{lf[1]}|[:fontawesome-solid-file-pen:](../Evaluations/TP/TP{lf[0]}/TP{lf[0]}.pdf) | {publish_date.day}/{publish_date.month}/{publish_date.year}  |\n"
                nums+=1
        return aff
    
    # Affichage de la liste des DM construite depuis le csv
    @env.macro
    def liste_dm(niveau):
        aff="\n"
        aff+= "|N° | Thèmes| Titre | Enoncé| Corrigé |\n"
        aff+= "|:-:|:-----:|-------|:-----:|:-------:|\n"
        FNAME = f"./dm{niveau}.csv"
        today = datetime.date.today()
        with open(FNAME,"r",encoding="utf-8") as f:
            nums=1
            for s in f:
                ico = ""
                lf=s.split(";")
                y,m,d = tuple(map(int,lf[3].split("/")))
                publish_date = datetime.date(y,m,d)
                for theme in lf[2]:
                    ico = ico + env.variables["themes_"+niveau][int(theme)][1]
                if publish_date <= today:
                    aff+=f"|**{nums}**|{ico}|{lf[1]}|[:fontawesome-solid-file-pen:](../Evaluations/DM/DM{lf[0]}/) | [:fontawesome-solid-file-circle-check:](../Evaluations/DM/DM{lf[0]}-Correction/)|\n"
                else:
                    aff+=f"|**{nums}**|{ico}|{lf[1]}|[:fontawesome-solid-file-pen:](../Evaluations/DM/DM{lf[0]}/) | {publish_date.day}/{publish_date.month}/{publish_date.year}|\n"
                nums+=1
        return aff
