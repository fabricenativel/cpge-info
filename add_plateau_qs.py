with open("docs/mp2i/Evaluations/DS/DS1/DS1.tex", "r") as f:
    content = f.read()

new_questions = r"""
	\Question{En utilisant le type structuré \texttt{couple} défini à l'exercice précédent, écrire une fonction \mintinline{c}{couple info_plateau(int tab[], int n)} qui renvoie la longueur du plus long plateau dans le champ \texttt{premier} et la valeur des éléments de ce plateau dans le champ \texttt{second}. En cas d'égalité de longueur entre plusieurs plateaux, on conservera les informations du premier plateau rencontré.}
	\ifcorrige
\begin{langageC}
couple info_plateau(int tab[], int n) {
    couple res;
    res.premier = 1;
    res.second = tab[0];
    int len_actuelle = 1;
    for (int i = 1; i < n; i++) {
        if (tab[i] == tab[i-1]) {
            len_actuelle++;
        } else {
            len_actuelle = 1;
        }
        if (len_actuelle > res.premier) {
            res.premier = len_actuelle;
            res.second = tab[i];
        }
    }
    return res;
}
\end{langageC}
	\fi
	\Question{Écrire une fonction C \mintinline{c}{int nombre_plateaux(int tab[], int n)} qui compte et renvoie le nombre total de plateaux distincts présents dans le tableau. Par exemple, pour le tableau \texttt{\{4, 4, 1, 1, 1, 1, 2, 2\}}, la fonction devra renvoyer 3. Pour le tableau \texttt{\{1, 2, 3\}}, elle devra renvoyer 3.}
	\ifcorrige
\begin{langageC}
int nombre_plateaux(int tab[], int n) {
    int nb = 1;
    for (int i = 1; i < n; i++) {
        if (tab[i] != tab[i-1]) {
            nb++;
        }
    }
    return nb;
}
\end{langageC}
	\fi
\end{Exercise}"""

content = content.replace("\\end{Exercise}\n\n\n\\end{document}", new_questions + "\n\n\\end{document}")
# Just to be safe, maybe there's no double newline:
content = content.replace("\\end{Exercise}\n\n\\end{document}", new_questions + "\n\n\\end{document}")
content = content.replace("\\end{Exercise}\n\\end{document}", new_questions + "\n\\end{document}")

with open("docs/mp2i/Evaluations/DS/DS1/DS1.tex", "w") as f:
    f.write(content)
