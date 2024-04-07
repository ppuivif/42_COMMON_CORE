-----------------------------------------------------------------------------------------------------

push_swap

1-vérification du nombre d'arguments dans la ligne de commande :
  - si aucun argument saisi (hors a.out, soit argc == 1): EXIT_FAILURE


2-lecture des arguments, première vérification des arguments et concatenation en string :
  - check_parameters_validity_and_join
  
    a-vérification de l'absence d'argument vide type ""
      et de l'absence d'argument constitué de whitspaces (entre doubles quotes) type " "
          - check_parameters_are_valid_1
  
    b-vérification de l'absence de caractères autres que digits, autres que + et -, autres que
      whitespaces
          - check_parameters_are_valid_2

    c-constitution d'une string avec les arguments séparés par un espace
          - ft_strjoin_freed


3-constitution d'un tableau de strings en splitant sur les espaces
          - ft_split


4-vérification que les paramètres (strings) sont bien des entiers
    - check_parameters_are_integers
      
      a-un atoi_long permet de :
          - skip les whitespaces en début de string,
          - vérifier le signe,
          - retourne 1 si le '\0' est trouvé (pas de digits),
#         - retourne 1 si un 0 est trouvé en début de string (avant les digits),
          - retourne 1 si nb < INT_MIN ou > INT_MAX,
          - retourne 0 si le nombre est un entier valide.

5-construction d'un tableau d'entiers à partir du tableau de strings et du nombre de paramètres
    - build_int_arr (utilise un malloc et un atoi).

6-vérification de l'absence de doublons à partir du tableau de int
    - check_no_duplicate (comparaison des entiers les uns par rapport aux autres en double boucle),
    - EXIT_FAILURE si doublons.

7-vérification si la liste est déjà triée à partir du tableau de int :
    - check_if_sorted,
    - EXIT_SUCCESS if sorted.

8-construction et tri des stacks :
    - build_and_sort_stacks :
        - déclaration et initialisation des deux stacks a et b,
              - stack_initialization :
                  - malloc,
                  - initialisation des variables head et size.
        - construction de la stack a sous la forme d'une liste chaînée
              - build_linked_list :
                  - creation des nouveaux éléments à partir des valeurs du tableau de int,
                  - initialisation des variables position, new_position (next_position reste à 1),
                  - ajout des éléments avec ft_lst_dc_add_back.
        - tri des valeurs dans le tabeau de int :
              - ft_sort_int_arr (double boucle et swap).
        - indexation des valeurs de la liste chaînée (stack_a):
              - index_stack :
                  - double boucle avec incrémentation de l'index des éléments si le nombre est
                      supérieur au nombre de l'élément suivant.
        - tri de la stack_a en utilisant la stack_b
              - sort_stack_a :
                  - 4 méthodes de tri :
                      - ft_sort_2 :
                            - simple swap.
                      - ft_sort_3 :
                            3 cas :
                                - 1er élément inférieur aux 2 autres,
                                - 2e élément inférieur aux 2 autres,
                                - 3e élément inférieur aux 2 autres.
                      - ft_sort_5 :
                            - push des deux éléments les plus petits dans la stack_b en cherchant la
                                  méthode la plus efficace (search_best_sort_index),
                            - tri des éléments restants dans la stack_a selon sort_2 ou sort_3,
                            - push_b des deux éléments les plus petits précédemment triés
                                  dans la stack_b.
                      - ft_sort_500 : algo papillon avec 5 tailles différentes de chunk
                            - ft_butterfly :
                                - l'algo papillon consiste à envoyer les n plus petits éléments
                                  (les n plus petits index) de a vers b dans l'ordre croissant,
                                  en les positionnant au dessus ou en dessous des éléments déjà
                                  envoyés.
                                - n dépend du nombre de chunks
                                - Le positionnement dépend de l'index de l'élément, comparé
                                  avec la valeur du range - la moitié du chunk.
                                - Une fois l'opération réalisée avec le premier chunk, on passe au
                                  suivant et ainsi de suite jusqu'à la fin.
                            - ft_sort_back :
                                  - la fonction permet de renvoyer les éléments de la stack_b vers
                                  la stack_a, du plus grand au plus petit,
                                  - une optimisation consiste à rechercher la façon la plus optimale
                                  de push en partant du haut ou du bas de la stack
                                  (search_best_sort_index idem sort_5)
                                  - une deuxième optimisation (optimizing_last_push) consiste
                                  à vérifier si au cours de la recherche de l'élément le plus grand,
                                  l'élément le plus grand - 1 (index_max_minus) est repéré.
                                  Si c'est le cas, il est push avent le plus grand. Un swap dans
                                  la stack_a permet ensuite de rétablir l'ordre.

-----------------------------------------------------------------------------------------------------

checker

Les étapes 1 à 6 sont identiques à celles de push_swap pour constituer la liste chaînée (stack_a).

Pas de vérification concernant l'état de la stack_a (triée ou non). 

7-construction et tri des stacks (idem push_swap):
    - build_stacks_for_checker :
        - déclaration et initialisation des deux stacks a et b,
              - stack_initialization :
                  - malloc,
                  - initialisation des variables head et size.
        - construction de la stack a sous la forme d'une liste chaînée
              - build_linked_list :
                  - creation des nouveaux éléments à partir des valeurs du tableau de int,
                  - initialisation des variables position, new_position (next_position reste à 1),
                  - ajout des éléments avec ft_lst_dc_add_back.
        - tri des valeurs dans le tabeau de int :
              - ft_sort_int_arr (double boucle et swap).
        - la fonction checker lit l'entrée standard via GNL :
              - les chaînes lues sont comparées aux instructions standard et sont exécutées
              grâce à la fonction which_instruction,
              - si l'instruction n'est pas reconnue, la fonction renvoie 1 et un message d'erreur
              s'affiche,
              - la fonction ft_lst_dc_is_sorted vérifie si la stack_a est triée,
              - la taille de la stack_b est vérifiée (elle doit être vide),
              - la fonction affiche OK ou KO.

-----------------------------------------------------------------------------------------------------
