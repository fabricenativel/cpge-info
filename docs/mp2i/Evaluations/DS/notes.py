#!/usr/bin/env python3
import ezodf as ods
import os
from colorama import Fore
from datetime import date

# Le nom du fichier de notes
ODS_FILE = f"Notes{date.today().strftime("%Y")}.ods"
DS_DATE = (0, 0)  # Emplacement de la date du DS
DS_TITRE = (0, 1)  # Emplacment titre du DS
COL_EXO_START = 1
LIG_EXO = 1
CTITLE = Fore.RED+chr(0x25CF)+Fore.LIGHTCYAN_EX
TTITLE = Fore.LIGHTYELLOW_EX
COL_STAT_DS = 2
BULLET = chr(0x2022)
DS = "DS"
SEXO = "Exercice"
COL_EXO = 0
LIG_THEME = 4
LIG_ELEVE_START = 5
COL_ELEVE_START = 0
TEX = "Modele.tex"
OFFSET_NOTE = 1
OFFSET_APPRECIATION = 2
OFFSET_STAT = 4
ENTETE = r'''
\documentclass[11pt,a4paper]{article}
\usepackage{Act}
\begin{document}
\input{\detokenize{/home/fenarius/Travail/Cours/cpge-info/latex/Macros.tex}}
'''
TOP = r'''
\begin{tcolorbox}[enhanced,width=\textwidth,center upper,fontupper=\bfseries,drop shadow southwest,sharp corners]
!!NOM!!
\end{tcolorbox}
\medskip
\begin{tabularx}{\textwidth}{p{5cm}X}
	\alertbox{\faAward}{Note}{
		\begin{itemize}[leftmargin=0pt]
			\item[\textbullet] Note : \textbf{\large !!NOTE!!}
			\item[\textbullet] Rang : \textbf{!!RANG!!}
			\item[\textbullet] Traité : !!TRAITE!! \%
		\end{itemize}
	} &
	\alertbox{\faChartLine}{Statistiques des notes}{
        \psset{xunit=1cm, yunit=1cm,fillstyle=solid}
		\begin{pspicture}(0,-0.1)(16,1.45)
		   \savedata{\data}[!!SERIE!!]
		   \rput{-90}(0,0.9){\psBoxplot[barwidth=1.1cm,yunit=0.5,fillcolor=gray,linewidth=1pt]{\data}}
		   \psaxes[yAxis=false,dx=1cm,Dx=2,labelsep=1pt,linecolor=gray,xlabelFontSize=\scriptstyle](0,0)(10.1,4)
		   \psdot[dotsize=8pt,dotstyle=diamond,linecolor=black,fillstyle=solid,fillcolor=white,linewidth=1pt](!!N2!!,0.85)
           \psdot[dotsize=6pt,dotstyle=x,linecolor=black,linewidth=3pt](!!MOYENNE!!,0.85)
		   \end{pspicture}
	} \\
    
\end{tabularx}\\
\begin{tabularx}{\textwidth}{X}
\alertbox{\faComment}{Commentaire}
{
	!!APRECIATION!!
}
\end{tabularx} \vspace{0.1cm} \\
'''
BOTTOM = r'''
    \vspace{0.5cm}\\
    \ding{113} \textbf{\sffamily{Historique des notes}} \medskip \\
    \psset{xunit=1.4cm, yunit=0.2cm}
    \begin{pspicture}(-1,-1)(12,22)

% --- Axe X : numéros de devoir ---
\psaxes[
    Dx=1,
    Dy=2,
    Ox=0,
    Oy=0,
    labels=all,
    ticks=all,
](0,0)(0,0)(7,20)


\listplot[plotstyle=line,showpoints=true,linecolor=black,linewidth=0.7pt, dotstyle=diamond*, dotsize=0.2]{%
    !!NOT!!
}

% Minimum de la classe
\listplot[plotstyle=line,showpoints=true,linecolor=gray,linewidth=0.7pt, dotstyle=|, dotangle=90, dotsize=0.15, linestyle=dotted]{%
    !!MIN!!
}

% Maximum de la classe
\listplot[plotstyle=line,showpoints=true,linecolor=gray,linewidth=0.7pt, dotstyle=|, dotangle=90, dotsize=0.15, linestyle=dotted]{%
    !!MAX!!
}

% Moyenne de la classe
\listplot[plotstyle=line,showpoints=true,linecolor=gray,linewidth=0.7pt, dotstyle=x, dotsize = 0.15, linestyle=dashed]{%
    !!MOY!!
}
\end{pspicture}
'''
FIN = r'''\end{document}'''





def ptitle(t):
    print(f"{CTITLE} {t} {Fore.WHITE}")


def get_nds(data):
    return len(data.sheets)-2


def get_infods(data, nds):
    sheet_ds = data.sheets[DS+str(nds)]
    dds = sheet_ds[DS_DATE].value
    tds = sheet_ds[DS_TITRE].value
    return dds, tds


def get_exos(data, nds):
    # Renvoie la liste des coefficients des questions de chaque exo du DS
    sheet_ds = data.sheets[DS+str(nds)]
    col_exo = COL_EXO_START
    exos = []
    all_themes = []
    while sheet_ds[LIG_EXO, col_exo].value != "Note":
        nb_questions = (sheet_ds[LIG_EXO, col_exo]).span[1]
        coeff = [int(sheet_ds[LIG_EXO+2, col_exo+i].value)
                 for i in range(nb_questions)]
        themes = [(sheet_ds[LIG_EXO+3, col_exo+i].value)
                 for i in range(nb_questions)]
        # print(f"\t > {sheet_ds[LIG_EXO,col_exo].value} : {nb_questions} questions : {tuple(coeff)}")
        col_exo += nb_questions
        exos.append(tuple(coeff))
        all_themes.append(tuple(themes))
    return tuple(exos), tuple(all_themes)


def get_nomprenom(str):
    pos = 0
    while pos < len(str) and not str[pos].islower():
        pos = pos + 1
    return str[:pos-2], str[pos-1:]


def get_eleves(data, nds, lexos):
    # Renvoie une liste de  tuple pour chaque élève : (nom, prenom, points, appreciations)
    sheet_ds = data.sheets[DS+str(nds)]
    lig_eleve = LIG_ELEVE_START
    lst_eleves = []
    while sheet_ds[lig_eleve, COL_ELEVE_START].value != None:
        nom, prenom = get_nomprenom(sheet_ds[lig_eleve, COL_ELEVE_START].value)
        pts = []
        col = COL_ELEVE_START + 1
        for exo in lexos:
            pts_exos = [sheet_ds[lig_eleve, col+p].value
                       for p in range(len(exo))]
            pts.append(tuple(pts_exos))
            col = col + len(exo)
        note = sheet_ds[lig_eleve, col].value
        appreciation = sheet_ds[lig_eleve, col+1].value
        lst_eleves.append((nom, prenom, tuple(pts), note, appreciation))
        lig_eleve += 1
    return lst_eleves


def get_col_eleve(eleve, leleves):
    return leleves.index(eleve)+ELEVE_START


def resultat(data, nds, eleve, leleves, lexo):
    col_eleve = get_col_eleve(eleve, leleves)
    resultat = {}
    cline = 2
    for exo in lexo:
        cline += 1
        for question in exo:
            try:
                resultat[question] = data[DS+str(nds)][cline][col_eleve]
            except:
                resultat[question] = 0
            cline += 1
    return resultat


def get_appreciation(data, nds, leleves, apline):
    appreciation = {}
    for e in leleves:
        col_eleve = get_col_eleve(e, leleves)
        try:
            appreciation[e] = data[DS+str(nds)][apline][col_eleve]
        except:
            appreciation[e] = ""
    return appreciation


def get_all_notes(data, leleves, nds):
    all_notes = {}
    print(leleves)
    for e in leleves:
        all_notes[e] = []
        col_eleve = get_col_eleve(e, leleves)
        for ds in range(nds):
            _, lig_eleve = get_exos(data, ds+1)
            lig_eleve += OFFSET_NOTE
            all_notes[e].append(data["DS"+str(ds+1)][lig_eleve][col_eleve])
    return all_notes


def get_note(resultat):
    s = 0
    t = 5 * sum(x[2] for x in resultat)
    traite = 0
    for x in resultat:
        if isinstance(resultat[x], int):
            s += resultat[x]*x[2]
            traite += 1
    return round(s/t*20, 1), int(round(traite/len(resultat)*100, 0))



def get_rt(res_eleves, themes):
    rt = {t: [0, 0] for t in themes}
    nq = {t: [0, 0] for t in themes}
    for x in res_eleves:
        th = x[3]
        nq[th][0] += 5*x[2]
        nq[th][1] += 1
        if isinstance(res_eleves[x], int):
            rt[th][0] += res_eleves[x]*x[2]
            rt[th][1] += 1
    fr = {t: (rt[t][0], nq[t][0], rt[t][1], nq[t][1]) for t in themes}
    return fr


def get_rexo(res_eleves, nexo):
    rexo = {n: [0, 0] for n in range(1, nexo+1)}
    texo = {n: [0, 0] for n in range(1, nexo+1)}
    for x in res_eleves:
        nx = x[0]
        texo[nx][0] += 5*x[2]
        texo[nx][1] += 1
        if isinstance(res_eleves[x], int):
            rexo[nx][0] += res_eleves[x]*x[2]
            rexo[nx][1] += 1
    fr = {n: (rexo[n][0], texo[n][0], rexo[n][1], texo[n][1])
          for n in range(1, nexo+1)}
    return fr


def question(q, v1, v2):
    if v1 == v2:
        return v1
    t = input(f"{q} ({v1} ... {v2}) : ")
    try:
        r = int(t)
        assert v1 <= r <= v2
        return r
    except:
        question(q, v1, v2)


def pdisplay(p, t, z):
    res = str(round(p/t*100))
    res = " "*(len(res)-3)+res
    res = res + "\% \;"
    res = res + "{\\small ("+str(p).zfill(z)+"/"+str(t)+")}"
    return res


def format_nom(nom, prenom):
    return "{\\sc {\\large "+nom+"}} "+prenom


def make_tex_eleve(eleve, serie_notes, lexos, lthemes):
    nom, prenom, pts_exo, note, appreciation, rang = eleve
    print(nom, prenom, pts_exo, note, appreciation, rang)
    nbquestions = sum(len(ex) for ex in pts_exo)
    nbtraites = 0
    for ex in pts_exo:
        for q in ex:
            if q!='NT':
                nbtraites +=1
    traite = round(nbtraites/nbquestions*100)
    str_serie=" ".join(str(n) for n in serie_notes)
    top = TOP.replace("!!NOM!!", format_nom(nom, prenom))
    top = top.replace("!!NOTE!!", str(note))
    top = top.replace("!!RANG!!", str(rang))
    top = top.replace("!!TRAITE!!", str(traite))
    top = top.replace("!!SERIE!!", str_serie)
    top = top.replace("!!N2!!", str(note/2))
    top = top.replace("!!MOYENNE!!", str(sum(n for n in notes)/(2*len(notes))))
    top = top.replace("!!APRECIATION!!", appreciation)
    exo_part = r'''\medskip \\
    \ding{113} \textbf{\sffamily{Résultats par exercice}} \medskip \\
    \renewcommand{\arraystretch}{1.2}
    \begin{tabular}{|l|r|r|}
    \cline{2-3}
    \multicolumn{1}{l|}{} & \multicolumn{1}{|c|}{Points} & \multicolumn{1}{|c|}{Traitées} \\
    \hline
    '''
    for ind_ex in range(len(lexos)):
        pts_total = 5*sum(p for p in lexos[ind_ex])
        pts_eleve = 0
        total = len(lexos[ind_ex])
        traite = 0
        for ind_quest in range(len(lexos[ind_ex])):
            if pts_exo[ind_ex][ind_quest]!="NT":
                pts_eleve += int(lexos[ind_ex][ind_quest]*pts_exo[ind_ex][ind_quest])
                traite = traite + 1
        exo_part += f"Exercice {{{ind_ex+1}}} & {pdisplay(pts_eleve,pts_total,2)} & {pdisplay(traite,total,1)} \\\\ \\hline "
    exo_part = exo_part + r"\end{tabular} \\\\"
    theme_part = r'''\medskip
    \ding{113} \textbf{\sffamily{Résultats par thème}} \medskip \\
    \renewcommand{\arraystretch}{1.2}
    \begin{tabular}{|l|r|r|}
    \cline{2-3}
    \multicolumn{1}{l|}{} & \multicolumn{1}{|c|}{Points} & \multicolumn{1}{|c|}{Traitées} \\
    \hline
    '''
    lst_themes = []
    for ex in lthemes:
        for q in ex:
                lst_themes.append(q)
    pts_total = {t : 0 for t in lst_themes}
    pts_eleve = {t: 0 for t in lst_themes}
    nb_total = {t : 0 for t in lst_themes}
    traite_eleve = {t: 0 for t in lst_themes}
    for ind_ex in range(len(lexos)):
        for ind_qu in range(len(lexos[ind_ex])):
            pts_total[lthemes[ind_ex][ind_qu]] += 5*lexos[ind_ex][ind_qu]
            nb_total[lthemes[ind_ex][ind_qu]] += 1
            if pts_exo[ind_ex][ind_qu]!="NT":
                pts_eleve[lthemes[ind_ex][ind_qu]] += int(pts_exo[ind_ex][ind_qu]*lexos[ind_ex][ind_qu])
                traite_eleve[lthemes[ind_ex][ind_qu]] += 1
    for th in pts_total:
        theme_part += f"{{{th}}} & {pdisplay(pts_eleve[th],pts_total[th],2)} & {pdisplay(traite_eleve[th],nb_total[th],1)} \\\\ \\hline "
    theme_part = theme_part + r"\end{tabular} \\\\"
    return top+theme_part+exo_part


def make_tex(nds, dateds, eleves, notes, lexos, lthemes):
    writer = open(DS+str(nds)+"-Resultats.tex", "w")
    writer.write(ENTETE)
    writer.write(f"\RDS{{{nds}}}{{{dateds}}}\n")
    for e in eleves:
        writer.write(make_tex_eleve(e, notes, lexos, lthemes))
        writer.write("\\pagebreak")
    writer.write(FIN)


def get_stat_ds(data, nds, col):
    stat_ds = []
    for i in range(nds):
        _, lig = get_exos(data, i+1)
        lig += OFFSET_STAT
        try:
            moy, mini, maxi = data[DS+str(i+1)][lig][col], data[DS +
                                                                str(i+1)][lig+1][col], data[DS+str(i+1)][lig+2][col]
        except:
            moy, mini, maxi = 0, 0, 0
        stat_ds.append((moy, mini, maxi))
    return stat_ds


if not os.path.isfile(ODS_FILE):
    print(f"Le fichier de notes ({ODS_FILE}) est absent !")
else:
    data = ods.opendoc(ODS_FILE)
    print(data)
    nds = get_nds(data)
    ptitle(f"{nds} DS trouvés :")
    for i in range(1, nds+1):
        date_ds, titre_ds = get_infods(data, i)
        print(f"{TTITLE} {BULLET} DS{i} (le {date_ds}) : {titre_ds} {Fore.WHITE}")
    rep = question("Entrez le numéro de DS", 1, nds)
    date_ds, titre_ds = get_infods(data, rep)
    ptitle(f"Liste des exercices du DS{rep}")
    # lexos est un tuple dont chaque élement est un tuple représentant un exo et contenant les points de chaque question de l'exo
    lexos, lthemes = get_exos(data, rep)
    nexos = len(lexos)
    nbquestions = sum(len(ex) for ex in lexos)
    for iex, ex in enumerate(lexos):
        print(f"\t {TTITLE} {BULLET} Exercice {iex+1} : {Fore.WHITE}{len(ex)} questions  -- {sum(p for p in ex)*5} points : {ex}")
    eleves = get_eleves(data, nds, lexos)
    # eleves est une tuple contenant pour chaque eleve le tuple (nom, prenom, (points_ex1,...,pts_exn), note, appreciation)
    # Ajout du rang de chaque eleve
    notes = [e[-2] for e in eleves]
    notes.sort(reverse=True)
    eleves = [(*eleves[i],notes.index(eleves[i][-2])) for i in range(len(notes))]
    # Les points part theme
    # Création du fichier tex
    make_tex(rep, date_ds, eleves, notes, lexos, lthemes)
    print("Fiches de résultats générées !")
