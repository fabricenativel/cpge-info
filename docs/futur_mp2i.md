hide: - navigation  in futur_mp2i.md

# Se préparer à l'informatique en MP2I

Le premier conseil est d'arrivé **reposé** et **motivé**  ! Le rythme en classe préparatoire est bien plus soutenu que dans le secondaire et prendre de l'avance mais arrivé épuisé ne sera pas productif. Même si vous n'avez pas fait {{sc("nsi")}} au lycée, tout sera repris depuis le début, inutile de vous inquiéter ! Ceci dit, voici quelques conseils pour consolider ou vérifier que vous avez les bases normalement acquises au lycée :

## Des bases en programmation

Bien que  Python ne soit **pas** au programme de la MP2I, une connaissance élémentaire de ce langage est attendue à l'entrée en MP2I  et notamment des concepts suivants :

* expressions et opérateurs arithmétique
* variables et affectations
* booléens, opérateurs `and`, `or` et `not`
* instructions conditionnelles et boucles
* fonctions

Pour vérifier votre niveau en Python, voici quelques ressources :

1. [Futurecoder](https://fr.futurecoder.io/) propose un cours en ligne adapté aux débutants
2. Le site [France-IOI](https://www.france-ioi.org/algo/chapters.php){target=_blank} propose une initiation accompagnée d'exercices
3. Ce [site d'un collectif d'enseignants de NSI](https://codex.forge.apps.education.fr/) propose aussi de nombreux exercices à faire directement dans le navigateur sans aucune installation. Les exercices sont classés par niveau de difficulté, les plus faciles sont abordables même sans avoir fait {{sc("nsi")}}.

## Sans oublier les mathématiques !

L'informatique c'est *aussi* des mathématiques, à votre arrivée en MP2I des notions comme  les calculs sur les puissances ou le raisonnement par récurrence seront supposées connues.

## Environnement de travail

Une pratique régulière de la programmation est indispensable pour progresser cette année, aussi il vous faudra disposer d'un ordinateur personnel avec un environnement de travail adapté à la MP2I. Deux langages sont au programme en {{sc("mp2i")}} : Le [C](https://fr.wikipedia.org/wiki/C_(langage)) et le  [OCaml](https://ocaml.org/){target=_blank}. L'"écosystème" naturel de ces deux langages est le système d'exploitation Linux. Au lycée, la distribution Linux installé est [Debian](https://www.debian.org). En début d'année, une "*install party*" sera organisée mais vous pouvez prendre un peu d'avance :

### Installer Linux

Trois options sont possibles :

1. L'installer en parallèle de windows et utiliser un *dual-boot*, c'est sans doute la meilleure option. Voici en détail la procédure à suivre :

    1. Télécharger la [dernière version stable de Debian](https://www.debian.org/distrib/) sous la forme d'un fichier `.iso` (prendre l'image d'installation de taille réduite pour PC 64 bits).
    2. Télecharger et installer [balena etcher](https://etcher.balena.io/) un logiciel permettant de *flasher* des clés usb
    3. Lancer *balena etcher* et flasher sur une clé usb (vide) l'iso récupéré à l'étape **a.**
    4. Insérer la clé usb et redémarrer votre ordinateur, s'il démarre sur la clé usb et vous propose d'installer Ubuntu c'est gagné, aller directement à l'étape **f.** 
    5. Si l'ordinateur ne redémarre pas directement sur la clé usb c'est qu'il est configuré pour démarrer directement sur le disque dur. Pour modifier ce comportement, lors de la phase de démarrage une touche (généralement il s'agit de ++f2++ ou ++del++ ou ++f8++) vous permet d'accéder à un menu et de sélectionner la clé usb comme périphérique de démarrage.
    6. Suiver simplement les instructions d'installation.

        !!! danger
            Debian détectera que Windows est déjà installé sur votre ordinateur et vous proposera de s'installer "à côté" et de partitionner votre disque dur. Attention à bien sélectionner cette option (vous risquez de perdre l'installation de windows dans le cas contraire)


2. Utiliser une [machine virtuelle](https://www.virtualbox.org/)
3. Utiliser [https://learn.microsoft.com/fr-fr/windows/wsl/install](WSL)

