{% set num = 11 %}
{% set niveau = "mp2i_s2"%}

{{ titre_chapitre(num,niveau)}}

{{ citation(" A SQL query walks into a bar and sees two tables. He walks up to them and says ‘Can I join you?","Anonyme")}}

## Cours

{{ affiche_cours(num) }}

## Travaux dirigés

{{ td(num) }}


## Travaux pratiques



{{ exo("Dette et croissance",[],0) }}

<div class="centre"><iframe width="560" height="315" src="https://www.youtube.com/embed/yeX_Zs7zztY" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe></div>

1. Télécharger les données présentées dans la vidéo précédente sous la forme d'une base de données :
    {{ telecharger("Dette et Croissance","files/C11/DettePIB.db")}} et l'ouvrir à l'aide de `sqlitebrowser`. Cette base est composée d'une seule table :
    <table>
    <tr><th colspan="2" align="center"> RR </th></tr>
    <tr><td>^^`Id`^^</td><td>`INTEGER` :material-key:</td></tr>
    <tr><td>`Country`</td><td>`TEXT`</td></tr>
    <tr><td>`Year`</td><td>`INTEGER`</td></tr>
    <tr><td>`DebtToGDP`</td><td>`REAL`</td></tr>
    <tr><td>`Growth`</td><td>`REAL`</td></tr>
    <tr><td>`DebtCategory`</td><td>`INTEGER`</td></tr>
    </table>
    On précise la signification des champs suivants : <br>
    :octicons-triangle-right-16: `DebtToGDP` : la dette en pourcentage du {{ sc("pib") }}.<br>
    :octicons-triangle-right-16: `Growth` : la croissance.<br>
2. Quelques requêtes pour s'échauffer
    1. Vérifier comme indiqué dans la vidéo que les données contiennent bien 20 pays. Les lister.
    2. Vérifier aussi que les années vont de 1946 à 2009 comme indiqué dans la vidéo.
    3. Lister par ordre croissant les dix années où la croissance a été la plus faible en France.
    4. Lister les pays où la croissance a dépassé 15 %
3. Des opérations sur les colonnes
    1. Ecrire une requête {{ sc("sql") }} permettant d'obtenir le pays et l'année où la dette a été la plus importante en utilisant la fonction d'agrégation {{sc("max")}}

        !!! note
            On pourrait aussi écrire une requête de classe par ordre décroissant associée à une clause `LIMIT`
    

4. Retrouver à l'aide de {{ sc("sql") }} les *vraies* valeurs de croissance moyenne en fonction de la catégorie de dette dans laquelle se trouve le pays et qu'on rappelle ci-dessous :
    
    |Catégorie| Croissance moyenne |
    |---------|--------------------|
    | 1       | 4,2 % |
    | 2       | 3,1 % |
    | 3       | 3,2 % |
    | 4       | 2,2 % |

5. Les opérations sur les colonnes sont particulièrement utiles en lien avec la clause `GROUP BY`. Par exemple, si on souhaite obtenir la somme de la croissance pour chacun des 20 pays depuis 1970 : 
    
    ```sql
        SELECT country, SUM(Growth) from RR WHERE Year>=1970 GROUP BY Country
    ```

    On peut même renommer la  colonne `SUM(Growth)` des résultats grâce à `AS` et donc l'utiliser comme critère de classement: 
        
    ```sql
            SELECT country, SUM(Growth) AS moy70 from RR WHERE Year>=1970 GROUP BY Country ORDER BY moy70 DESC
```

    Ecrire une *seule* requête permettant d'obtenir les taux de croissance moyenne pour chacune des catégories de dette.


{{ exo("Prix Nobel",[])}}

1. Télécharger ci-dessous une base de données des Prix Nobel :
{{telecharger("Prix Nobel","files/C11/Nobel.db")}}
2. Ouvrir cette base avec `sqlitebrowser`
3. Dans <span class='encadre'>Parcourir les données</span> prendre note du noms des colonnes et de leur signification. 
4. Ecrire les requêtes {{ sc("sql") }} permettant :
    1. d'obtenir les catégories dans lesquelles sont attribuées les prix Nobel,
    2. de lister par ordre alphabétique les lauréats du prix Nobel nés en France ou travaillant pour une organisation Française,
    3. de lister les années où le "Comité international de la Croix Rouge" a obtenu le prix Nobel,
    4. de connaître le nombre de femmes ayant obtenu un prix Nobel,
    5. de lister par âge décroissant les lauréats du prix Nobel qui sont toujours en vie,
    6. de rechercher les lauréats dont le nom contient "Curie".

{{ exo("Tremblements de terre",[]) }} 
1. Télécharger ci-dessous une base de données des tremblements de terre :
{{telecharger("Tremblements de terre","files/C11/earthquakes.db")}}
2. Ouvrir cette base avec `sqlitebrowser`
3. Dans <span class='encadre'>Parcourir les données</span> prendre note du noms des colonnes et de leur signification. 
4. Ecrire les requêtes {{ sc("sql") }} permettant :
    1. de lister  tremblements de terre qui se sont produits au Japon,
    2. de lister les tremblements de terre qui se sont produits en l'an 2000 classés par magnitude,
        
        !!! Aide 
            Remarquer que le champ `occured_on` qui indique la date est au format texte.

    
5. Utiliser cette base pour répondre aux questions suivantes :
    1. les tremblements de terre sont-ils plus fréquents dans l'hémisphère nord ou l'hémisphère sud ?
    
        !!! Aide
             On rappelle que l'hémisphère nord correspond à une latitude positive et le sud à une latitude négative.

    2. Où étaient effectuées les essais nucléaires français ?
    3. L'un des séisme de cette base de données s'est-il produit à proximité de l'île de la Réunion ?
        
        !!! Aide
             Rechercher la latitude et la longitude de l'île de Réunion et considérer que "à proximité" signifie qu'on s'écarte de moins de 10 degrés de latitude ou de longitude

{{ exo("Exercices en ligne (une seule table)",[])}}

1. Des exercices en lignes de requêtes sur une seule table crées par **N. Reveret**. Ces exercices peuvent être faits à la maison (aucune installation nécessaire) et les réponses sont fournis.

    1. [Les prénoms en France au XX-ème siècle](https://nreveret.forge.apps.education.fr/exercices_bdd/31_prenoms/prenoms/){target=_blank}
    2. [Ramens](https://nreveret.forge.apps.education.fr/exercices_bdd/32_ramens/ramens/){target=_blank}

2. Même principe sur ce site de **Q. Fortier** :

    1. [Métro parisien](https://sql-exercices.github.io/){target=_blank}
    2. [Pays](https://sql-exercices.github.io/){target=_blank}

3. Enfin, un [site](https://sqlbolt.com/){target=_blank} (en anglais) qui vous permettra de réviser l'ensemble de ce chapitre en faisant les tutoriels de 1 à 5:

    1. [Tutoriel 1 : introduction](https://sqlbolt.com/lesson/select_queries_introduction){target=_blank}
    2. [Tutoriel 2 : requêtes avec conditions partie 1](https://sqlbolt.com/lesson/select_queries_with_constraints){target=_blank}
    3. [Tutoriel 3 : requêtes avec conditions partie 2](https://sqlbolt.com/lesson/select_queries_with_constraints_pt_2){target=_blank}
    4. [Tutoriel 4 : filtrage et tri des résultats](https://sqlbolt.com/lesson/filtering_sorting_query_results){target=_blank}
    5. [Tutoriel 5 : exercice de synthèse](https://sqlbolt.com/lesson/select_queries_review){target=_blank}


{{ exo("Une enquête policière avec SQL",[]) }}

Le but de cette activité, proposé sur le site de l'université américaine  [Northwerstern University](https://knightlab.northwestern.edu/){target=_blank} est de résoudre un crime en utilisant des requêtes SQL dans une base de données dont voici le schéma relationnel :
![schemabase](./Images/C11/sqlmm.png){: .imgcentre}

Toutes les requêtes peuvent être exécutées directement sur le site, cependant vous pouvez télécharger ci-dessous la base afin d'exécuter vos requêtes en local :
{{ telecharger("SQL Murder Mystery","files/C11/sql-murder-mystery.db")}}

Cliquer sur l'image ci-dessous pour accéder à l'enquête et trouver le coupable.
[![illustration](./Images/C11/mm.png){: .imgcentre}](https://mystery.knightlab.com/walkthrough.html){target=_blank}

{{ exo("Exercices en ligne de SQL (plusieurs tables)",[])}}

1. Des exercices en lignes de requêtes sur plusieurs tables crées par **N. Reveret**. Ces exercices peuvent être faits à la maison (aucune installation nécessaire) et les réponses sont fournies.

    1. [Autour des films](https://nreveret.forge.apps.education.fr/exercices_bdd/41_films/films/){target=_blank}
    2. [Voitures](https://nreveret.forge.apps.education.fr/exercices_bdd/42_cars/cars/){target=_blank}
    3. [World](https://nreveret.forge.apps.education.fr/exercices_bdd/51_world/world/){target=_blank}
    4. [Netflix](https://nreveret.forge.apps.education.fr/exercices_bdd/52_netflix/netflix/){target=_blank}

2. Même principe sur [ce site](https://sql-exercices.github.io/){target=_blank} de **Q. Fortier** avec  bases de données sur :

    1. Les [concours](https://sql-exercices.github.io/){target=_blank}
    2. Les [Pokémon](https://sql-exercices.github.io/){target=_blank}


{{ exo("SQL Island : un jeu de rôle en SQL",[])}}

Un [jeu de rôle en SQL](https://sql-island.informatik.uni-kl.de/){target="blank"} où vous vous retrouvez seul sur une île après un 
crash d'avion (site d'une université allemande)

!!! aide
    Pour changer la langue (initialement en allemand), cliquer sur le menu (en haut et à gauche de la page du jeu) puis sélectionner le 4eme item.


## Humour d'informaticien

![punition](./Images/C11/injection.png){.imgcentre width=500px}



