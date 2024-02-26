#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "LIBFT/libft.h"
# include <stdlib.h>
# include <limits.h> 


# include <stdio.h> //ATTENTION


int		count_parameters(char **tab);
void	check_parameters_are_integers(char **tab_str);
int		*build_tab(char **tab_str, int count);
void	free_tab(char **tab);
int		ft_atoi_long(char *str);
char	*ft_strjoin_freed(char *s1, char *s2);


void	print_tab_str(char **tab_str);
void	print_tab_int(int *tab_int, int count);


#endif