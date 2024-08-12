{% set num = 3 %}
{% set niveau = "itc_s3"%}

{{ titre_chapitre(num,niveau)}}

## Cours

{{ affiche_cours(num) }}



## Travaux pratiques




{{ exo("Une enquête policière avec SQL",[],0) }}

Le but de cette activité, proposé sur le site de l'université américaine  [Northwerstern University](https://knightlab.northwestern.edu/){target=_blank} est de résoudre un crime en utilisant des requêtes SQL dans une base de données dont voici le schéma relationnel :
![schemabase](./Images/C3/sqlmm.png){: .imgcentre}

Toutes les requêtes peuvent être exécutées directement sur le site, cependant vous pouvez télécharger ci-dessous la base afin d'exécuter vos requêtes en local :
{{ telecharger("SQL Murder Mystery","files/C3/sql-murder-mystery.db")}}

Cliquer sur l'image ci-dessous pour accéder à l'enquête et trouver le coupable.
[![illustration](./Images/C3/mm.png){: .imgcentre}](https://mystery.knightlab.com/walkthrough.html){target=_blank}

{{ exo("Exercices en ligne de SQL",[])}}

1. Des exercices en lignes de requêtes sur plusieurs tables crées par **N. Reveret**. Ces exercices peuvent être faits à la maison (aucune installation nécessaire) et les réponses sont fournies.

    1. [Autour des films](https://e-nsi.forge.aeif.fr/exercices_bdd/41_films/films/){target=_blank}
    2. [Voitures](https://e-nsi.forge.aeif.fr/exercices_bdd/42_cars/cars/){target=_blank}
    3. [World](https://e-nsi.forge.aeif.fr/exercices_bdd/51_world/world/){target=_blank}
    4. [Netflix](https://e-nsi.forge.aeif.fr/exercices_bdd/52_netflix/netflix/){target=_blank}

2. Même principe sur [ce site](https://sql-exercices.github.io/){target=_blank} de **Q. Fortier** avec  bases de données sur :

    1. Les [concours](https://sql-exercices.github.io/){target=_blank}
    2. Les [Pokémon](https://sql-exercices.github.io/){target=_blank}


{{ exo("SQL Island : un jeu de rôle en SQL",[])}}

Un [jeu de rôle en SQL](https://sql-island.informatik.uni-kl.de/){target="blank"} où vous vous retrouvez seul sur une île après un 
crash d'avion (site d'une université allemande)

!!! aide
    Pour changer la langue (initialement en allemand), cliquer sur le menu (en haut et à gauche de la page du jeu) puis sélectionner le 4eme item.
