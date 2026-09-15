import re

with open("docs/annales/CCMP2025/CCMP2025.md", "r") as f:
    content = f.read()

new_q9 = r"""### Q9
La fonction `construitLi` correspond à un algorithme de **tri par insertion** (ici dans l'ordre décroissant).

* **Meilleur cas :** Il se produit lorsque la condition de la boucle `while` (`Lqi[j-1] < x`) est immédiatement fausse à chaque itération. Cela signifie que la liste est initialement **déjà triée dans l'ordre décroissant**. Dans ce cas, le corps de la boucle `while` n'est jamais exécuté. La complexité est alors **linéaire** en $\mathcal{O}(n)$, car la boucle `for` principale effectue simplement $n-1$ itérations à coût constant.
* **Pire cas :** Il se produit lorsque la condition de la boucle `while` est vraie jusqu'à ce que $j=0$. Cela signifie que chaque nouvel élément doit être inséré tout au début, c'est-à-dire lorsque la liste est initialement **triée dans l'ordre croissant**. La boucle `while` effectue alors $i$ itérations pour décaler les éléments. Le nombre total de décalages est proportionnel à $\sum_{i=1}^{n-1} i = \frac{n(n-1)}{2}$. La complexité est alors **quadratique** en $\mathcal{O}(n^2)$."""

# Use a lambda for repl to avoid processing escapes in the replacement string
content = re.sub(r'### Q9.*', lambda _: new_q9, content, flags=re.DOTALL)

with open("docs/annales/CCMP2025/CCMP2025.md", "w") as f:
    f.write(content)
