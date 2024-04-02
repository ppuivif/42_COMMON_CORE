-----------------------------------------------------------------------------------------------

1-déclaration des variables
	- char *tmp pour stocker le read,
	- static char *buf pour récupérer les tmp successifs
		(en static pour conserver les lectures d'un appel à GNL à l'autre),
	- char *line pour cumuler les buf jusqu'au '\n' et return,
	- int nb_read_bytes pour stocker le retour de la fonction read.

2-check les valeurs données en paramètres
	- le fd qui doit être supérieur ou égal à 0 (erreur si égal à -1),
	- le BUFFER_SIZE doit être supérieur ou égal à 1.

3-initialiser les variables :
	- nb_read_bytes à 0,
	- line à NULL.

4-créer une boucle infinie dont on sort avec des return

5-allocation de mémoire pour tmp et vérification de l'allocation

6-exécuter la fonction read

7-analyser le retour de read (valeur de nb_read_bytes)
	- si nb_read_bytes == -1 : erreur de lecture
		- free tmp (et initialisation à NULL),
		- free buf (et initialisation à NULL),
		- return (NULL).
	- si nb_read_bytes == 0 : fin de fichier (rien a été lu)
		- static void end_of_file(char **buf, char **line)
		- free tmp (et initialisation à NULL),
		- return (line).
	- si nb_read_bytes > 0 : tmp contient des données
		- insertion du contenu de tmp dans buf (char *ft_get_strjoin(char *buf, char *tmp)),
		- free tmp (et initialisation à NULL),
		- recherche d'un '\n' dans buf (static int get_lines(char **buf, char **line))
			- si présence d'un '\n' : return (line),
			- si absence d'un '\n', la boucle se poursuit.

* la fonction end_of_file : static void end_of_file(char **buf, char **line)
	- buf est déjà à NULL :
		- NULL sera retourné via line.
	- buf peut contenir les dernières données du texte (!buf),
		- les données contiennent un ou plusieurs '\n'
			- line est constituée,
			- buf est conservé pour l'appel (ou les appels) suivant à GNL.
		- les données ne contiennent pas de '\n' (on est arrivé à la toute fin du fichier)
			- line est constituée,
			- buf est free et initialisé à NULL.
	- line est retournée dans la fonction GNL car complète.

Pour construire le code :
	- le pointeur buf est-il à NULL ?
		- si oui :
			- free buf (et initialisation à NULL),
			- line initialisée à NULL,
			- return.
		- si non, contient-il un '\n' (si la fonction get_lines return 1) ?
			- si oui :
				- la fonction get_lines s'est appliquée,
				- return.
			- si non :
				- join line et buf,
				- free buf (et initialisation à NULL),
				- return.

* la fonction get_lines : static int get_lines(char **buf, char **line)
La fonction permet de rechercher un '\n', de constituer la line qui sera retournée
et de récupérer le reste de la lecture pour l'appel suivant à GNL   
	- le pointeur buf est-il à NULL ?
		- si oui :
			- line est initialisée à NULL,
			- la valeur 1 est retournée.
			- line est retournée dans la fonction GNL car complète.
		- si non :
			- la variable int start prend le retour de la recherche du '\n', ie sa position,
			- si la fonction détecte la présence d'un '\n' :
				- une variable temporaire prend le début de la chaîne, 
					jusqu'au '\n' inclus (fonction ft_substr sans free avec len = start + 1),
				- line prend la concatenation de line et de tmp2 (fonction ft_get_strjoin),
				- free tmp2 (et initialisation à NULL),
				- buf prend la reste de la lecture
					(fonction ft_get_substr start + 1 et len = ft_strlen(buf) - (start - 1))
				- si buf ne contient plus qu'un '\0' :
					- free buf (et initialisation à NULL),
				- la valeur 1 est retournée.
				- line est retournée dans la fonction GNL car complète.
			- si la fonction ne détecte pas de '\n' :
				- la valeur 0 est retournée,
				- line n'est pas retournée dans la fonction GNL car incomplète.

-----------------------------------------------------------------------------------------------