#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "LIBFT/libft.h"
# include "FT_PRINTF/libftprintf.h"
# include <stdlib.h>
# include <limits.h> 


# include <stdio.h> //ATTENTION

int		count_parameters(char **arr);
void	check_parameters_are_integers(char **str_arr);
void	check_no_duplicate(int *int_arr, int count);
int		*build_arr(char **str_arr, int count);
void	free_tab(char **arr);
int		ft_atoi_long(char *str);
char	*ft_strjoin_freed(char *s1, char *s2);

void	ft_swap_int(int *a, int *b);
void	ft_sort(int *arr, int count);


void	print_tab_str(char **str_arr);
void	print_tab_int(int *int_arr, int count);

void	build_linked_list(int *int_arr, int count, t_element **head);

void	swap(t_element	**head, char c);
void	push(t_element	**head_src, t_element **head_dest, char c);
void	rotate(t_element **head, char c);
void	reverse_rotate(t_element **head, char c);

void	free_linked_list(t_list **list);

#endif