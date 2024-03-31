push_swap

1-vérification du nombre d'arguments dans la ligne de commande :
  - si aucun argument saisi (hors a.out soit argc == 1): EXIT_FAILURE


2-lecture des arguments, première vérification des arguments et concatenation en string :
  - check_parameters_validity_and_join
  
    a-vérification de l'absence d'argument vide type ""
      et de l'absence d'argument constitué de whitspaces (entre doubles quotes) 
          - check_parameters_are_valid_1
  
    b-vérification de l'absence de caractères autres que digits et autres que + et -
          - check_parameters_are_valid_2

    c-constitution d'une string avec les arguments séparés par un espace
          - ft_strjoin_freed


3-constitution d'un tableau de strings en splitant sur les espaces
          - ft_split


4-vérification que les paramètres (strings) sont bien des entiers
    - check_parameters_are_integers
      
      a-