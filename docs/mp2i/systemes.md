
{% set num = 0 %}
{% set niveau = "mp2i_s1"%}

{{ titre_chapitre(num,niveau)}}

{{ citation("I'm doing a (free) operating system (just a hobby, won't be big and
  professional like gnu) (...)","Linus Torvalds","[comp.os.minix newsgroup 1991](https://groups.google.com/group/comp.os.minix/msg/b813d52cbc5a044b)")}}
## Cours

{{ cours(num) }}

## Travaux dirigés

{{ td(num) }}

## Travaux pratiques

{{ exo("Les bases de la ligne de commande",[],0) }}
1. En utilisant uniquement la  ligne de commande, créer l'arborescence suivante dans votre répertoire personnel :
        ```mermaid
            graph TD
            A[MP2I] --> B[C1-Systèmes]
            A[MP2I] --> G[C2-OCaml]
            A[MP2I] --> F[C3-Arithmétique]
            B --> C[Cours]
            B --> D[TD]
            B --> E[TP]
        ```
2. Renommer le dossier `C2-OCaml` en `C2-LangageC`
3. Aller dans le dossier `MP2I`
4. Taper la commande `tree`, quel est l'effet de cette commande ?
5. Quelle option de la commande `tree` permet de limiter le niveau d’arborescence souhaité ?

{{exo("Calendrier",[])}}

1. Ouvrir un terminal et y tester la commande `cal`
2. Lire la documentation de cette commande
3. Quel était le jour de la semaine le 26 juin 1815 ?
4. Quel commande faut-il écrire pour afficher le calendrier du mois de mai 1970 ?

{{ exo("Chercher des fichiers",[] )}}

1. Lire les premières lignes de la documentation de la commande `find`. A quoi sert cette commande ?
2. Tester la commande `find ~ -name .*`. Expliquer le résultat obtenu et l'effet de la commande.

    !!! Aide 
        On rappelle que `~` désigne votre répertoire personnel.
         

3. Sachant que les commandes du système se trouvent dans le repertoire `/usr/bin`, lister toutes les commandes dont le nom se terminent par  `dir` (`rmdir` et `mkdir` devraient donc apparaître).

4. Alice est certaine d'avoir un fichier nommé `bob.txt` dans son répertoire personnel mais elle n'arrive plus à le retrouver. Quelle commande devrait-elle taper ?

5. Expliquer le but de la commande `find ~ -mtime 5 -name *.txt`

{{ exo("Gameshell",[]) }}

[Gameshell](https://github.com/phyver/GameShell){target=_blank} est un mini-jeu d'aventure dans le terminal dans lequel les commandes servent à accomplir des missions. Il a été developpé par [Pierre Hyvernat](http://www.lama.univ-smb.fr/~hyvernat){target=_blank} et [Rodolphe Lepigre](https://lepigre.fr/){target=_blank}.

0. Lancer un terminal (le raccourci clavier est ++ctrl+alt+t++)
1. Créer un dossier `gameshell` dans votre répertoire personnel
2. Aller dans le répertoire `gameshell`
3. Y copier le fichier `gameshell.sh` téléchargeable ci-dessous :
    [Télécharger gameshell :fontawesome-solid-download:](./files/C0/gameshell.sh){.md-button}

    !!! note
        Depuis la ligne de commande, en l'absence de proxy (ce qui n'est pas le cas au lycée), on peut aussi taper :
        ```shell
        wget https://github.com/phyver/GameShell/releases/download/latest/gameshell.sh
        ```

4. Ajouter le droit d'exécution pour l'utilisateur sur le fichier `gameshell.sh`.
5. Dans le terminal taper  `./gameshell.sh` 

    !!! retenir "A retenir"
        On retiendra que pour lancer un exécutable  depuis le terminal, on donne son chemin. Ici puisqu'il se trouve dans le répertoire courant (c'est à dire <code><mark>.</mark></code>) on tape donc <code><mark>./</mark>gameshell</code>


    !!! aide "Aide"
        Voici les principales commandes du jeu :

        * `gsh goal` : affiche l'objectif de la mission
        * `gsh check` : vérifie que l'objectif est atteint et le cas échéant passe à la mission suivante
        * `gsh reset` : réinitialise la mission en cours 
        * `gsh exit` : quitter le jeu

        Pour relancer le jeu à partir de la dernière sauvegarde taper `./gameshell-save.sh`

{{exo("The command line murders",[])}}

Dans ce [mini jeu](https://github.com/veltman/clmystery){target=_blank} (crée par [Noah Veltman](http://noahveltman.com/){target=_blank}), vous devez résoudre une enquête policière en utilisant uniquement la ligne de commande. Pour jouer :

1. Commencer par [télécharger l'archive zip du jeu](./files/C0/clmystery-master.zip) 
2. Décompresser cette archive dans le répertoire de votre choix, et aller dans le répertoire `clmystery-master`
3. Taper `cat instructions` pour demarrer

!!! aide
    Toutes les commandes utiles pour résoudre l'enquête sont expliquées dans le fichier `cheatsheet.pdf` 


!!! lien
    En ligne (donc sans aucune installation sur son ordinateur personnel), on peut aussi jouer à [Terminus](http://luffah.xyz/bidules/Terminus/){target=_blank} pour découvrir la ligne de commande

## Humour d'informaticien

![Sudo](./Images/C0/sandwich.png){.imgcentre width=500px}