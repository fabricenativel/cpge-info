hide: - navigation  in index.md

{{dm(3,"Des histoires de dates")}} 

!!! danger "Récupération du devoir"
    * La totalité du devoir est à rendre sous la forme d'un seul et unique fichier `dm3.c` que vous compléterez au fil des questions. Ce fichier vous a déjà été distribué et se trouve dans *votre répertoire personnel* du lycée. Vous pouvez y  accéder depuis un ordinateur du lycée ou depuis l'{{sc("ent")}} grâce à  l'application Nextcloud.
    * Votre fichier `dm3.c` complété devra être enregistré dans votre répertoire personnel du lycée et sera automatiquement ramassé à la date convenue.

Vous disposez d'un fichier de **5000** dates au format `JJ/MM/AAAA` à télécharger ci-dessous :
{{ telecharger("dates.txt","./dates.txt") }}


## Partie I : dates valides

Le fichier de dates contient de nombreuses dates *non valides* (avec jour et mois inversés ou mois qui dépasse 12 ou encore un numéro de jour qui dépasse celui du mois). Le but de cette première partie est de comptabiliser le nombre de dates valides dans le fichier `dates.txt`.

1. Créer le type structuré `date` permettant de représenter une date (donc avec trois champs `jour`, `mois` et `annee`)
2. Ecrire une fonction `affiche` qui prend en argument une variable de type `date` et affiche cette date dans le terminale sous le format `JJ\MM\AAAA`
3. Ecrire une fonction `est_bissextile` qui prend en argument un entier `annee` et renvoie `true` si `annee` est bissextile et `false` sinon.

    !!! aide
        Une année est bissextile si elle est divisible par 4 mais pas par 100 ou s'il est divisible par 400.

3. Ecrire une fonction `est_valide` qui prend en argument une variable de type `date` et renvoie `true` si cette date est valide et `False` sinon.

    !!! aide
        On pourra utiliser un tableau d'entiers `max_jour` tel que `max_jour[i]` donne le nombre maximal de jours du mois de numéro `i` (sans oublier de traiter le cas des années bissextiles).

4. Ecrire une fonction `compte_valide` qui ne prend par d'argument et renvoie le nombre de dates valides du fichiers `dates.txt`.
    Vous pouvez tester votre réponse  : {{ check_reponse("4268")}}

    !!! note
        A la fin de cette partie, on connaît donc le nombre de dates valides du fichiers `dates.txt`. On notera ce nombre `n_dates` dans la suite de l'énoncé.

## Partie II : trier les dates valides

1. Ecrire une fonction `recuperer_dates` qui ne prend pas d'arguments et renvoie un tableau de variables de type date de taille `n_dates` contenant les dates *valides* du fichiers `dates.txt`.

2. Ecrire une fonction `compare_date` qui prend en argument deux variables dates `d1` et `d2` et renvoie `true` si `d1` est antérieure à `d2` et `false` sinon.

3. En utilisant l'algorithme de tri de votre choix, trier *en place* le tableau des dates valides.

4. Quel est la date valide la plus ancienne de ce fichier de dates ?  
    Vous pouvez tester votre réponse (en la donnant au format `JJ/MM/AAA`) {{ check_reponse("25/01/1942")}}

5. Ecrire une fonction `ecrit_dates` qui prend en argument le tableau de dates triées et sa taille et crée un fichier `dates_triees.txt` dans lequel sont écrites les dates au format `JJ/MM/AAAA` et dans l'ordre chronologique.




