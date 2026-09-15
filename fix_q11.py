with open("docs/annales/CCMP2025/CCMP2025.md", "r") as f:
    content = f.read()

import re

new_q11 = r"""### Q11
L'algorithme glouton va sélectionner les objets par ratio décroissant : d'abord l'objet d'indice 1 (ratio 4), puis l'objet d'indice 0 (ratio 1.5). Le poids total est alors de $1+2=3 \leqslant 5$, et le profit obtenu est de $4+3=7$. Il ne peut plus ajouter l'objet d'indice 2.

Cependant, en sélectionnant les objets d'indices 1 et 2, le poids total est de $1+4=5 \leqslant 5$ et on obtient un profit de $4+4=8$. On vérifie aisément que c'est le choix optimal. La solution fournie par l'algorithme glouton (profit 7) n'est donc pas optimale sur cet exemple, ce qui illustre le fait qu'une stratégie gloutonne ne garantit pas toujours la solution exacte au problème du sac à dos."""

content = re.sub(r'### Q11\nEn sélectionnant les objets 1 et 2.*?optimal sur cet exemple\.', lambda _: new_q11, content, flags=re.DOTALL)

with open("docs/annales/CCMP2025/CCMP2025.md", "w") as f:
    f.write(content)
