with open("docs/mp2i/Evaluations/DS/DS1/DS1.tex", "r") as f:
    lines = f.readlines()

# The question about complexity starts around line 228
# We want to keep up to that block and delete everything after \end{Exercise} or duplicate questions.

# Find the line index of "Quelle est la complexité temporelle"
idx_complexite = -1
for i, line in enumerate(lines):
    if "Quelle est la complexité temporelle" in line:
        idx_complexite = i
        break

# The \tcor for complexity spans to idx_complexite + 1.
idx_after_complexite = idx_complexite + 2

# We keep lines up to idx_after_complexite
new_lines = lines[:idx_after_complexite]

new_questions = r"""
	\Question{On souhaite désormais, en plus de la longueur du plus long plateau, connaître le nombre de fois où cette longueur maximale apparaît dans le tableau. Écrire une fonction C \mintinline{c}{void info_plateau(int tab[], int n, int *max_len, int *occ)} qui affecte à la variable pointée par \texttt{max\_len} la longueur du plus long plateau, et à la variable pointée par \texttt{occ} le nombre de plateaux ayant cette longueur maximale.}
	\ifcorrige
\begin{langageC}
void info_plateau(int tab[], int n, int *max_len, int *occ) {
    *max_len = 1;
    *occ = 1;
    int len_actuelle = 1;
    for (int i = 1; i < n; i++) {
        if (tab[i] == tab[i-1]) {
            len_actuelle++;
        } else {
            len_actuelle = 1;
        }
        
        if (len_actuelle > *max_len) {
            *max_len = len_actuelle;
            *occ = 1;
        } else if (len_actuelle == *max_len) {
            *occ = *occ + 1;
        }
    }
}
\end{langageC}
	\fi
\end{Exercise}

\end{document}
"""

new_content = "".join(new_lines) + new_questions

with open("docs/mp2i/Evaluations/DS/DS1/DS1.tex", "w") as f:
    f.write(new_content)
