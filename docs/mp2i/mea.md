{% set num = 18 %}
{% set niveau = "mp2i_s2"%}

{{ titre_chapitre(num,niveau)}}

{{ citation("The entity-relationship model adopts the more natural view that the real world consists of entities and relationships
","P. Chen","[The Entity-Relationship Model](https://dl.acm.org/doi/pdf/10.1145/320434.320440)") }}

## Cours

{{ affiche_cours(num) }}

## Travaux dirigés

{{ td(num) }}


## Travaux pratiques


!!! important
    On pourra commencer par (re)faire les exercices de TP du [chapitre sur l'introduction aux bases de données](https://fabricenativel.github.io/cpge-info/mp2i/introbd/#travaux-pratiques) afin de réactiver les connaissances en {{sc("sql")}}

{{exo("Revoir le SQL",[],0)}}

Pour revoir les bases de {{sc("sql")}}, utiliser les tutoriels du site [SQL Zoo](https://sqlzoo.net/wiki/SQL_Tutorial){target=_blank} :

1. Avec une seule table :
    * Sur une base de données des [pays du monde](https://sqlzoo.net/wiki/SELECT_from_WORLD_Tutorial){target=_blank}
    * Sur une base de données des [prix Nobel](https://sqlzoo.net/wiki/SELECT_from_Nobel_Tutorial){target=_blank}

2. Avec plusieurs tables (pour maîtriser le {{sc("join")}}) :
    * Sur une base de données sur le [football](https://sqlzoo.net/wiki/The_JOIN_operation){target=_blank}
    * Sur une base de données de films [films](https://sqlzoo.net/wiki/More_JOIN_operations){target=_blank}
    * Sur une base de données de [bus](https://sqlzoo.net/wiki/More_JOIN_operations){target=_blank}

3. Pour reviser les fonctions d'agrégations
    * Sur une base de données d'[étudiants](https://sqlzoo.net/wiki/NSS_Tutorial){target=_blank}

## Humour d'informaticien

![tree](./Images/C18/ERM.jpg){.imgcentre width=500px}
