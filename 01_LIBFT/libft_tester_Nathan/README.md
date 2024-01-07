le SupraTester pour la libft de l'école 42 (Linux ~~Mac Os~~)

# REQUIS
    ``vala est un compileur C (clang ou gcc)``

	vous pouvez esquiver la dépendance à vala avec ``make bootstrap``

    UNE REGLE `so elle doit créer libft.so !
    
    par exemple dans votre Makefile
    ```make
        so:
            gcc *.o --shared -o libft.so
  
    ```
    autrement il tentera de créer un libft.so de lui même , mais ça lui rajoute des tâches inutiles.
# INSTALLATION

    cloner le repo dans votre libft ou à sa racine.
    executer `make run`

# SupraTester

Il permet de charger vos fonctions et de les tester
de manière asynchrone et rapide sur plusieurs processeurs.

Il teste la mémoire avec SupraLeak pour un gain de vitesse :)

Une idée ? Autre chose ? Faites une issue !
