with open("docs/mp2i/Evaluations/DS/DS1/DS1.tex", "r") as f:
    content = f.read()

exercise_text = r"""
\begin{Exercise}[title = {Rotation d'un tableau}]\\
	Une rotation à droite d'un cran d'un tableau décale tous ses éléments vers la droite, le dernier élément venant prendre la première place. Par exemple, le tableau \texttt{\{1, 2, 3, 4, 5\}} devient \texttt{\{5, 1, 2, 3, 4\}}. On s'interdit d'utiliser un second tableau temporaire (les modifications doivent être faites \textit{en place}).
	\Question{Écrire une fonction C \mintinline{c}{void rotation_droite_un(int tab[], int n)} qui effectue une rotation à droite d'un cran du tableau \texttt{tab} de taille \texttt{n}.}
	\ifcorrige
\begin{langageC}
void rotation_droite_un(int tab[], int n) {
    if (n <= 1) return;
    int dernier = tab[n-1];
    for (int i = n-1; i > 0; i--) {
        tab[i] = tab[i-1];
    }
    tab[0] = dernier;
}
\end{langageC}
	\fi
	\Question{Pour effectuer une rotation de $k$ crans (avec $k \geqslant 0$), une première méthode consiste à appeler $k$ fois la fonction \texttt{rotation\_droite\_un}. Écrire la fonction \mintinline{c}{void rotation_k_naif(int tab[], int n, int k)} correspondante, et déterminer sa complexité temporelle dans le pire des cas (on pourra simplifier en supposant $0 \leqslant k < n$).}
	\ifcorrige
\begin{langageC}
void rotation_k_naif(int tab[], int n, int k) {
    for (int i = 0; i < k; i++) {
        rotation_droite_un(tab, n);
    }
}
\end{langageC}
	\fi
	\tcor{La complexité de \texttt{rotation\_droite\_un} est en $\mathcal{O}(n)$. Appelée $k$ fois, la complexité de \texttt{rotation\_k\_naif} est en $\mathcal{O}(k \times n)$. Si $k$ est de l'ordre de $n$ (par exemple $k = n/2$), la complexité globale est en $\mathcal{O}(n^2)$.}
	\Question{On souhaite réaliser la rotation de $k$ crans en temps linéaire $\mathcal{O}(n)$. Pour cela, on suppose disposer d'une fonction \mintinline{c}{void inverser(int tab[], int i, int j)} qui inverse l'ordre des éléments du tableau entre les indices \texttt{i} et \texttt{j} inclus (principe vu dans un exercice précédent). Montrer comment accomplir une rotation à droite de $k$ crans en utilisant exactement 3 appels à la fonction \texttt{inverser}. (On supposera $0 \leqslant k < n$).}
	\tcor{
		Pour réaliser une rotation de $k$ crans vers la droite, il suffit de :
		\begin{enumerate}
			\item Inverser la totalité du tableau (indices $0$ à $n-1$).
			\item Inverser les $k$ premiers éléments (indices $0$ à $k-1$).
			\item Inverser les éléments restants (indices $k$ à $n-1$).
		\end{enumerate}
	}
	\ifcorrige
\begin{langageC}
void rotation_k_opti(int tab[], int n, int k) {
    if (n <= 1 || k == 0) return;
    inverser(tab, 0, n - 1);
    inverser(tab, 0, k - 1);
    inverser(tab, k, n - 1);
}
\end{langageC}
	\fi
	\tcor{Chaque élément est lu et écrit au plus deux fois. L'algorithme effectue donc un nombre d'opérations proportionnel à $n$, sa complexité est bien en $\mathcal{O}(n)$.}
\end{Exercise}

\end{document}
"""

content = content.replace("\\end{document}", exercise_text)

with open("docs/mp2i/Evaluations/DS/DS1/DS1.tex", "w") as f:
    f.write(content)
