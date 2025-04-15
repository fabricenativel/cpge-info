SELECT population, pib 
FROM pays 
WHERE nom = "France";

SELECT nom 
FROM pays 
WHERE cotes=0 AND (region="Europe de l'est" or region = "Europe de l'ouest");

SELECT nom 
FROM pays 
WHERE region="Amérique latine" 
ORDER BY nom;

SELECT nom
FROM pays
ORDER BY population DESC
LIMIT 5;

SELECT nom, MAX(pib)
FROM pays
WHERE region="Proche orient";

SELECT nom, population/surface AS densite
FROM pays 
WHERE region="Afrique du nord" 
ORDER BY densite DESC;

SELECT region, SUM(pib) as total_pib 
FROM pays 
GROUP BY region 
ORDER BY total_pib DESC;