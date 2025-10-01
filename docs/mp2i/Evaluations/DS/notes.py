#!/bin/python3
import pyexcel_ods3 as ods
import os
from colorama import Fore


ODS_FILE = "Notes.ods"
CTITLE = Fore.RED+chr(0x25CF)+Fore.LIGHTCYAN_EX
TTITLE = Fore.LIGHTYELLOW_EX
BULLET = chr(0x2022)
DS = "DS"
SEXO = "Exercice"
COL_EXO  = 0
LIG_ELEVE = 1
TEX = "Modele.tex"
OFFSET_APPRECIATION = 2
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
		\begin{pspicture}(0,-0.1)(16,1.45)
			\psset{xunit=1,fillstyle=solid}
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
\end{tabularx}
'''
FIN = r'''\end{document}'''

DS_TITRE = (0,0)
EX_START = 3
ELEVE_START = 3

def ptitle(t):
    print(f"{CTITLE} {t} {Fore.WHITE}")

def get_nds(data):
    nb = 1
    while DS+str(nb) in data:
        nb += 1
    dds = data[DS+str(nb-1)][1][0].strftime("%d/%m/%Y")
    return nb-1,dds

def get_exos(data,nds):
    cl = EX_START
    lexo = []
    cexo = []
    nexo = 1
    end = False
    while not end:
        content = data[DS+str(nds)][cl]
        print(content)
        if content==[]:
            end=True
        elif isinstance(content[COL_EXO],str) and content[0].startswith(SEXO):
            lexo.append(cexo)
            cexo=[]
            nexo += 1
        else:
            cexo.append((nexo,content[COL_EXO],content[COL_EXO+1],content[COL_EXO+2]))
        cl += 1
    lexo.append(cexo)
    return lexo,cl
        
def get_points(exo):
    return sum(s[2] for s in exo)*5
    

def get_eleves(data,nds):
    eleves = data[DS+str(nds)][LIG_ELEVE][ELEVE_START:]
    return eleves


def get_col_eleve(eleve,leleves):
    return leleves.index(eleve)+ELEVE_START

def resultat(data,nds,eleve,leleves,lexo):
    col_eleve = get_col_eleve(eleve,leleves)
    resultat = {}
    cline = 2
    for exo in lexo:
        cline += 1
        for question in exo:
            try:
                resultat[question]=data[DS+str(nds)][cline][col_eleve]
            except:
                resultat[question]=0
            cline +=1
    return resultat

def get_appreciation(data, nds, leleves, apline):
    appreciation = {}
    for e in leleves:
        col_eleve = get_col_eleve(e,leleves)
        appreciation[e] = data[DS+str(nds)][apline][col_eleve]
    return appreciation


def get_note(resultat):
    s = 0
    t = 5 * sum(x[2] for x in resultat)
    traite = 0
    for x in resultat:
        if isinstance(resultat[x],int):
            s += resultat[x]*x[2]
            traite+=1
    return round(s/t*20,1),int(round(traite/len(resultat)*100,0))

def get_themes(lexos):
    th =set()
    for ex in lexos:
        for q in ex:
            th.add(q[3])
    return th

def get_rt(res_eleves,themes):
    rt = {t : [0,0] for t in themes}
    nq = {t : [0,0] for t in themes}
    for x in res_eleves:
        th = x[3]
        nq[th][0] += 5*x[2]
        nq[th][1] += 1
        if isinstance(res_eleves[x],int):
            rt[th][0] +=  res_eleves[x]*x[2]
            rt[th][1] += 1
    fr = {t : (rt[t][0],nq[t][0],rt[t][1],nq[t][1]) for t in themes}
    return fr


def get_rexo(res_eleves,nexo):
    rexo = {n : [0,0] for n in range(1,nexo+1)}
    texo = {n : [0,0] for n in range(1,nexo+1)}
    for x in res_eleves:
        nx = x[0]
        texo[nx][0] += 5*x[2]
        texo[nx][1] += 1
        if isinstance(res_eleves[x],int):
            rexo[nx][0] +=  res_eleves[x]*x[2]
            rexo[nx][1] += 1
    fr = {n : (rexo[n][0],texo[n][0],rexo[n][1],texo[n][1]) for n in range(1,nexo+1)}
    return fr

def get_ds_title(nds):
    l,c = DS_TITRE
    return data[DS+str(nds)][l][c]

def question(q,v1,v2):
    if v1==v2:
        return v1
    t = input(f"{q} ({v1} ... {v2}) : ")
    try:
        r = int(t)
        assert v1<=r<=v2
        return r
    except:
        question(q,v1,v2)

def pdisplay(p,t,z):
    res = str(int(p/t*100))+"\% \;"
    res += "{\\small ("+str(p).zfill(z)+"/"+str(t)+")}"
    return res
    
def format_nom(eleve):
    nom, prenom = eleve.split(",")
    return "{\\sc \\large "+nom+"}"+prenom

def make_tex_eleve(eleve,notes,rthemes,rexos, appreciation):
    snotes = " ".join([str(notes[e][0]) for  e in notes])
    top = TOP.replace("!!NOM!!",format_nom(eleve))
    top = top.replace("!!NOTE!!",str(notes[eleve][0]))
    top = top.replace("!!RANG!!",str(notes[eleve][2]))    
    top = top.replace("!!TRAITE!!",str(notes[eleve][1]))    
    top = top.replace("!!SERIE!!",snotes)    
    top = top.replace("!!N2!!",str(notes[eleve][0]/2))
    top = top.replace("!!MOYENNE!!",str(sum(notes[e][0] for e in eleves)/(2*len(notes))))
    top = top.replace("!!APRECIATION!!",appreciation[eleve])
    theme_part = r'''\medskip
    \ding{113} \textbf{\sffamily{Résultats par thème}} \medskip \\
    \renewcommand{\arraystretch}{1.2}
    \begin{tabular}{|l|r|r|}
    \cline{2-3}
    \multicolumn{1}{l|}{} & \multicolumn{1}{|c|}{Points} & \multicolumn{1}{|c|}{Traitées} \\
    \hline
    '''
    for th in themes:
        theme_part += f"{{{th}}} & {pdisplay(rthemes[eleve][th][0],rthemes[eleve][th][1],2)} & {pdisplay(rthemes[eleve][th][2],rthemes[eleve][th][3],1)} \\\\ \\hline "
    theme_part = theme_part + r"\end{tabular} \\\\"
    exo_part = r'''\medskip \\
    \ding{113} \textbf{\sffamily{Résultats par exercice}} \medskip \\
    \renewcommand{\arraystretch}{1.2}
    \begin{tabular}{|l|r|r|}
    \cline{2-3}
    \multicolumn{1}{l|}{} & \multicolumn{1}{|c|}{Points} & \multicolumn{1}{|c|}{Traitées} \\
    \hline
    '''
    for nex in rexos[eleve]:
        exo_part += f"Exercice {{{nex}}} & {pdisplay(rexos[eleve][nex][0],rexos[eleve][nex][1],2)} & {pdisplay(rexos[eleve][nex][2],rexos[eleve][nex][3],1)} \\\\ \\hline "
    exo_part = exo_part + r"\end{tabular} \\\\"
    return top+theme_part+exo_part

def make_tex(nds,dateds,notes,rthemes,rexos, appreciation):
    writer = open(DS+str(nds)+"-Resultats.tex","w")
    writer.write(ENTETE)
    writer.write(f"\RDS{{{nds}}}{{{dateds}}}\n")
    for e in eleves:
        writer.write(make_tex_eleve(e,notes,rthemes,rexos, appreciation))
        writer.write("\\pagebreak")
    writer.write(FIN)
    
if not os.path.isfile(ODS_FILE):
    print(f"Le fichier de notes ({ODS_FILE}) est absent !")
else:
    data = ods.get_data(ODS_FILE)
    nds,dateds = get_nds(data)
    print(f"{nds} devoirs")
    ptitle(f"Liste des DS")
    for i in range(1,nds+1):
        print(f"{TTITLE} {BULLET} DS{i} (le {dateds}) : {get_ds_title(i)} {Fore.WHITE}")
    rep = question("Entrez le numéro de DS",1,nds)
    ptitle(f"Liste des exercices du DS{rep}")
    lexos, apline = get_exos(data,rep)
    apline = apline + OFFSET_APPRECIATION
    nexos = len(lexos)
    for iex,ex in enumerate(lexos):
        print(f"{TTITLE} {BULLET} Exercice {iex+1} : {Fore.WHITE}{len(ex)} questions  -- {get_points(ex)} points ")
    eleves = get_eleves(data,rep)
    appreciations = get_appreciation(data, nds, eleves, apline)
    resultat_eleve = {e : resultat(data,nds,e,eleves,lexos) for e in eleves}
    dnotes = {e : get_note(resultat_eleve[e]) for e in eleves}
    rang = eleves.copy()
    rang.sort(key = lambda x : dnotes[x][0], reverse=True)
    notes = {e : (*dnotes[e],rang.index(e)+1) for e in  eleves}
    themes = get_themes(lexos)
    resultat_theme = {e : get_rt(resultat_eleve[e],themes) for e in eleves}
    resultat_exo = {e : get_rexo(resultat_eleve[e],nexos) for e in eleves}
    make_tex(nds,dateds,notes,resultat_theme,resultat_exo, appreciations)
    for e in dnotes:
        print(f"* {e} : **{dnotes[e][0]}**")