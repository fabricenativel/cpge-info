--8<-- [start:Q8]
SELECT DISTINCT auteur FROM corpus;
--8<-- [end:Q8]

--8<-- [start:Q9a]
SELECT SUM(nombreCaracteres) 
FROM corpus
WHERE langue='Français';
--8<-- [end:Q9a]

--8<-- [start:Q9b]
SELECT symbole, SUM(nombreOccurrences)/(SELECT SUM(nombreCaracteres) FROM corpus WHERE langue='Français')
FROM caractere 
JOIN corpus 
JOIN occurrences
ON caractere.idCar = occurrences.idCar
AND corpus.idLivre = occurrences.idLivre
WHERE langue = 'Français'
GROUP BY symbole;
--8<-- [end:Q9b]
