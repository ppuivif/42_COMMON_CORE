1-comment se comporte bash avec une ligne de commande telle que < infile cmd1 | cmd2 > outfile ?
	- la commande cmd1 s'execute
	- si un parametre est requis pour l'execution de la commande cmd1, le fichier infile est pris en parametre
	- le resultat de l'execution de la commande cmd1 est transmis a la commande cmd2 via le pipe
	- la commande cmd2 s'execute
	- le resultat de l'execution est envoye dans le fichier outfile
	- l'execution de la ligne de commande peut etre verifiee par une lecture du contenu du fichier outfile

2-check quels sont les lignes de commandes invalides ?
	- nombre d'arguments different de 4
	- arguments correspondants aux commandes vides ou ne comportant que des whitespaces
	- 

3-check les fichiers infile et outfile :
	- infile = argv[1] et outfile = arg[4]
	- le fichier infile existe-il (OPEN peut-il l'ouvrir avec l'option O_RDONLY) ? Sinon EXIT_FAILURE
	- le user a-t-il les droits de lecture (OPEN peut-il l'ouvrir avec l'option O_RDONLY) ? Sinon EXIT_FAILURE
	- le fichier outfile existe-il ?
	- si le fichier outfile n'existe pas, le creer avec les droits d'ecriture avec OPEN
	- s'il existe, le user a-t-il les droits d'ecriture (OPEN peut-il l'ouvrir avec l'option O_WRONLY) ? Sinon EXIT_FAILURE
	- 

4-check les commandes :
	- commande et/ou options valides
		- les commandes valides sont stockees dans des fichiers dont les chemins d'acces sont contenus dans l'environnement de la facon suivante :
				PATH=/nfs/homes/ppuivif/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
			les chemins d'acces (paths) etant separes par ":"
		- NB : utiliser la commande "printenv" dans le terminal pour lire le contenu
		- l'environnement est le dernier argument de la fonction main (char **envp)
		- parcourir envp a la recherche de la ligne contenant le mot path
		- si le mot n'est pas trouve : EXIT_FAILURE
		- si le mot est trouve : skip le mot et recuperer le reste de la sring
		- construire un tableau de chaines de caracteres (les paths) en splitant sur les ":"

	-	
		- extraire les commandes cmd1 et cmd2 et leurs options depuis la ligne de commande (argv[2] et argv[3]) en splitant sur les espaces pour chacune d'elle
		- construire deux tableau de chaines de caracteres
		- compter le nombre d'options pour chaque commande
		- verifier la validite de la commande avec la fonction ACCESS

	-
		- pour chaque commande, associer successivement les paths stockes, avec la commande et verifier si la concatenation est valide grace a la fonction ACCESS
		- si l'une des deux recherche echoue, close, free et EXIT_FAILURE
		- si la recherche est fructueuse, conserver la concatenation

//		- sinon recuperer chacun des deux paths, puis concatener de nouveau avec chacune des deux commandes et leurs options pas vu dans le code ??

//6-le parsing des fichiers

//7-le parsing des commandes

6-la gestion des cas d'erreur

7-quitter proprement le programme :
	- close les fd
	- free

8-l'execution (la fonction PIPE)
	- executer la fonction

9-creer un fork
	- un processus parent
	- un processus enfant 1
	- un processus enfant 2

10-execution des commandes

11-total free
