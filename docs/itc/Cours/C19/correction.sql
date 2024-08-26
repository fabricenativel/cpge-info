SELECT matiere, SUM(coefficient) * 100 / (SELECT SUM(coefficient) 
FROM epreuve 
JOIN concours ON concours_id=concours.id 
JOIN epreuve_matiere ON epreuve_id=epreuve.id 
WHERE concours.nom='ccinp' AND filiere='mp') as 'poids en pourcentage' FROM epreuve 
JOIN concours ON concours_id=concours.id 
JOIN epreuve_matiere ON epreuve_id=epreuve.id WHERE concours.nom='ccinp' AND filiere='mp' GROUP BY matiere;