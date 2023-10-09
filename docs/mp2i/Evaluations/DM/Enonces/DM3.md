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
2. Ecrire une fonction `affiche` qui prend en argument une variable de type `date` et affiche cette date dans le terminale sous le format `JJ/MM/AAAA`
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

5. 4. Quel est la date valide la plus récente de ce fichier de dates ?  
    Vous pouvez tester votre réponse (en la donnant au format `JJ/MM/AAA`) {{ check_reponse("17/12/2022")}}


## Partie III : nombre de jours entre deux dates

Dans cette partie on cherche à déterminer le nombre de jours séparant deux dates données `d1` et `d2` en faisant l'hypothèse que `d1` est avant `d2`. Pour tester, on prendra pour `d1` la plus ancienne date valide du fichier et pour `d2` la plus récente (voir partie précédente)

1. Implémenter l'algorithme qui consiste à incrémenter la date `d1` de un jour en un jour jusqu'à atteindre la date `d2`.  
Vous pouvez tester votre réponse : {{check_reponse("29546")}}

    !!! aide
        * Commencer par écrire une fonction `lendemain` qui incrémente de un jour la date passée en argument.
        * En C, on ne peut pas directement tester l'égalité entre deux `struct`, il faut donc écrire une fonction testant si deux dates sont égales

2. Implémenter l'algorithme qui consiste à effectuer les étapes suivantes où on note `a1` l'année de la date `d1` et `a2` l'année de la date `d2` et où on suppose que `a2>a1`:

    1. Calculer "directement" (c'est à dire sans incrémenter de jour en jour) le nombre de jour noté `n1` séparant `d1` de la fin de l'année  `a1` (c'est à dire du `31/12/a1`).
    2. Calculer la somme du nombre de jour noté `n2` des années `a1+1` jusqu'à `a2-1`.
    3. Calculer le nombre de jour noté `n3` séparant le `01\01\a1` de la date `d2`
    4. En déduire la réponse au problème.

## Partie IV : Création d'un nouveau fichier de dates

Le but de cette partie est de créer un nouveau fichier de dates, on ne conserve que les dates valides rangées dans l'ordre chronologique et en plus on  fait figurer devant chaque date le jour de la semaine correspondant. 

1. Ecrire une fonction `jour_semaine` qui prend en argument un struct `date` et renvoie le jour de la semaine correspondant.

    !!! aide
        * L'année la plus ancienne du fichier de dates est 1942
        * Le 01/01/1942 était un jeudi

