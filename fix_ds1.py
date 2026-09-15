import re

with open('docs/mp2i/Evaluations/DS/DS1/DS1.tex', 'r', encoding='utf-8') as f:
    content = f.read()

# L24
content = content.replace("librairies standards usuelles", "bibliothèques standard usuelles")
content = content.replace("<stdassert.h>", "<assert.h>")

# L69-82 Variant
variant_old = r"""	\tcor{Un \textit{variant de boucle} est une quantité qui dépend des variables du programmes et est :
		\begin{enumerate}
			\item entière,
			\item positive,
			\item strictement décroissante.
		\end{enumerate}.
		Dans l'algorithme ci-dessus, la quantité $m$ est un variant de boucle, en effet :
		\begin{enumerate}
			\item $m \in \N$ par précondition.
			\item $m \in \N$ par précondition puis $m$ reste  positif car par condition d'entrée dans la boucle $m\geqslant 1$ et dans la boucle on décrémente $m$ donc après un passage dans la boucle $m$ reste positif ou nul.
			\item $m$ décroit strictement car $m$ est diminué de 1  lors de chaque passage dans la boucle.
		\end{enumerate}
		L'algorithme termine car on a trouvé un variant de boucle.
	}"""
variant_new = r"""	\tcor{Un \textit{variant de boucle} est une quantité qui dépend des variables du programme et qui est :
		\begin{enumerate}
			\item entière,
			\item positive,
			\item strictement décroissante.
		\end{enumerate}
		Dans l'algorithme ci-dessus, la quantité $m$ est un variant de boucle, en effet :
		\begin{enumerate}
			\item $m \in \N$ (par précondition).
			\item $m$ reste positif ou nul : par condition d'entrée dans la boucle $m \geqslant 1$, et comme on décrémente $m$ de 1, $m$ reste $\geqslant 0$ après le tour de boucle.
			\item $m$ décroît strictement car il est diminué de 1 lors de chaque passage dans la boucle.
		\end{enumerate}
		L'algorithme termine car on a trouvé un variant de boucle.
	}"""
content = content.replace(variant_old, variant_new)

# L84-99 Invariant
invariant_old = r"""	\tcor{Un \textit{invariant de boucle} est une propriété qui dépend des variables du programme et qui est :
		\begin{enumerate}
			\item vraie avant d'entrer dans la boucle (initialisation)
			\item reste vraie après un tour de boucle si elle l'était au tour précédent (conservation)
		\end{enumerate}
		En sortie de boucle, la validité d'un invariant permet de prouver la correction de l'algorithme.\\
		On note, $m_0$ la valeur initiale de $m$, montrons que la propriété $I$ : \og{} $r = (m - m_0)n$ \fg est un invariant de boucle.
		\begin{enumerate}
			\item Avant d'entrée dans la boucle $ m = m_0$ donc $(m - m_0)n = 0$ et comme $r$ est initialisé à $0$ la propriété $I$ est vérifiée.
			\item On suppose $I$ vérifié à l'entrée de la boucle et on note $r'$ (resp. $m'$) les valeurs prises par $r$ (resp. $m$) au tour de boucle suivant, alors : \\
			      $(m' - m_0) n = (m + 1 - m_0) n$, or $I$ étant vérifié à l'entrée de boucle $(m-m_0) n = r$ donc \\
			      $(m' - m_0) n = r + n$ et comme $r' = r +n $ \\
			      $(m' - m_0) n = r'$ et donc $I$ est vérifiée.
		\end{enumerate}
		En sortie de boucle, puisque $m=0$, cette invariant prouve que $r = m_0n$ et donc l'algorithme est correcte.
	}"""
invariant_new = r"""	\tcor{Un \textit{invariant de boucle} est une propriété qui dépend des variables du programme et qui :
		\begin{enumerate}
			\item est vraie avant d'entrer dans la boucle (initialisation),
			\item reste vraie après un tour de boucle si elle l'était au début du tour (conservation).
		\end{enumerate}
		En sortie de boucle, la validité d'un invariant permet de prouver la correction de l'algorithme.\\
		En notant $m_0$ la valeur initiale de $m$, montrons que la propriété $I$ : \og{} $r = (m_0 - m)n$ \fg{} est un invariant de boucle.
		\begin{enumerate}
			\item Avant d'entrer dans la boucle, $m = m_0$ donc $(m_0 - m)n = 0$. Comme $r$ est initialisé à $0$, la propriété $I$ est vérifiée.
			\item On suppose $I$ vérifiée au début d'un tour de boucle et on note $r'$ (resp. $m'$) les valeurs prises par $r$ (resp. $m$) à la fin de ce tour. On a $m' = m - 1$ et $r' = r + n$.
			      Calculons : $(m_0 - m')n = (m_0 - (m - 1))n = (m_0 - m + 1)n = (m_0 - m)n + n$. 
			      Or, par hypothèse de récurrence ($I$ vraie), $(m_0 - m)n = r$. 
			      Donc $(m_0 - m')n = r + n = r'$. La propriété $I$ est donc conservée.
		\end{enumerate}
		En sortie de boucle, la condition $m > 0$ est fausse, donc $m = 0$. L'invariant nous assure alors que $r = (m_0 - 0)n = m_0 n$. L'algorithme calcule bien le produit attendu et est donc correct.
	}"""
content = content.replace(invariant_old, invariant_new)

content = content.replace("c'est à dire que par exemple", "c'est-à-dire que, par exemple")
content = content.replace("c'est à dire", "c'est-à-dire")
content = content.replace("l'avant dernier", "l'avant-dernier")

# I and I' in Retourner tableau
content = content.replace("Avant d'entrer dans la boucle $i = 0$ et $j=n-1$ et donc  $I$ est vrai.", "Avant d'entrer dans la boucle $i = 0$ et $j=n-1$, donc $I$ est vraie.")
content = content.replace("On suppose $I$ vraie en entrant dans la boucle, montrant qu'alors $I$ est conservé lors d'un passage dans cette boucle, $i' = i+1$ et $j' = j-1$ sont après ce passage les nouvelles valeurs de $i$ et $j$, on a donc $i'+j' = i +j$ or par hypothèse $i+j = n-1$ donc $I$ est conservée.", "On suppose $I$ vraie au début d'un tour de boucle. Montrons qu'alors $I$ est conservée à la fin de ce passage. En notant $i' = i+1$ et $j' = j-1$ les nouvelles valeurs, on a $i'+j' = i+1+j-1 = i+j$. Or, par hypothèse $i+j = n-1$, donc $i'+j' = n-1$ et $I$ est conservée.")
content = content.replace("On vérifie que l'invariant proposé est vraie :", "On vérifie que l'invariant proposé est vrai :")
content = content.replace("et donc $I'$ est vraie par vacuité.", "et donc $I'$ est vrai par vacuité.")
content = content.replace("Conservé par un passage dans la boucle. Si $I'$ est vrai en entrant dans la boucle, alors on échange $t[i]$ avec $t[j]$ et comme d'après l'invariant $I$ démontré à la question précédente $j = n-1-i$, on echange $t[i]$ avec $t[n-1-i]$. Comme par hypothèse les éléments situés avant $i$ et après $j$ sont déjà correctement échangé ($I'$ supposé vraie) dans le nouveau tableau obtenu $I'$ est vrai.", "Conservé lors d'un passage dans la boucle : si $I'$ est vrai en entrant dans la boucle, alors on échange $t[i]$ avec $t[j]$. D'après l'invariant $I$ démontré à la question précédente, $j = n-1-i$. On échange donc $t[i]$ avec $t[n-1-i]$. Comme, par hypothèse, les éléments situés avant $i$ et après $j$ sont déjà correctement échangés ($I'$ supposé vrai), la propriété $I'$ reste vraie pour les indices s'étendant jusqu'à $i$ et $j$.")

# string typos
content = content.replace("chaine de caractères", "chaîne de caractères")
content = content.replace("chaines de caractères", "chaînes de caractères")
content = content.replace("la chaine", "la chaîne")
content = content.replace("On peut pas en C affecter directement un tableau", "On ne peut pas affecter directement un tableau en C")
content = content.replace("dirrectement", "directement")
content = content.replace("Quelle est la valeurs renvoyée", "Quelle est la valeur renvoyée")
content = content.replace("On peut propose la spécification suivante", "On peut proposer la spécification suivante")
content = content.replace("car $n$ et $d$ sont des entiers", "car $n$ et $d$ sont entiers")
content = content.replace("car comme $n$ divise $n$, par condition d'entrée dans la boucle $d < n$.", "car, tout entier admettant au moins lui-même comme diviseur, la condition $n \bmod d \\neq 0$ implique $d < n$.")
content = content.replace("succintement", "succinctement")
content = content.replace("Si {\\tt min1<=v<min2}", "Si {\\tt min1 <= tab[i] < min2}")
content = content.replace("sont appeles", "sont appelés")
content = content.replace("Ecrire la fonction", "Écrire la fonction")
content = content.replace("la librairie", "la bibliothèque")

with open('docs/mp2i/Evaluations/DS/DS1/DS1.tex', 'w', encoding='utf-8') as f:
    f.write(content)

