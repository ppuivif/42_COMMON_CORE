#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "LIBFT/libft.h"
# include "FT_PRINTF/libftprintf.h"
# include "GNL/get_next_line.h"
# include <stdlib.h>
# include <limits.h> 


# include <stdio.h> //ATTENTION

int		count_parameters(char **arr);
void	check_parameters_are_integers(char **str_arr);
void	check_no_duplicate(int *int_arr, int count, char **str_arr);
void	check_if_sorted(int *int_arr, int count, char **str_arr);
int		*build_arr(char **str_arr, int count);
void	free_tab(char **arr);
int		ft_atoi_long(char *str);
char	*ft_strjoin_freed(char *s1, char *s2);

void	ft_swap_int(int *a, int *b);
void	ft_sort(int *arr, int count);


void	print_tab_str(char **str_arr);
void	print_tab_int(int *int_arr, int count);

void	build_linked_list(int *int_arr, t_list **list);
void	index_stack(t_element **head);
void	update_new_position(t_element **head);

void	swap(t_element	**head, char c);
void	push(t_element	**head_src, t_element **head_dest, char c);
void	rotate(t_element **head, char c);
void	reverse_rotate(t_element **head, char c);
void	double_swap(t_element **head_a, t_element **head_b);
void	double_rotate(t_element **head_a, t_element **head_b);
void	double_reverse_rotate(t_element **head_a, t_element **head_b);

int		search_new_position_element_with_index(t_list	*list, int index);
int		search_best_sort_index(t_list **src, t_list **dest, char s, char d, int index);
int		ft_butterfly(t_list	**src, t_list **dest, int chunk);

void	ft_sort_2(t_list **src);
void	ft_sort_3(t_list **src, t_list **dest);
void	ft_sort_5(t_list **src, t_list **dest);
void	ft_sort_500(t_list **src, t_list **dest, int chunk);
int		ft_sort_back(t_list **src, t_list **dest);
int		optimizing_last_push(t_list **dest, int index_max, int index_max_minus_1);

void	free_linked_list(t_list **list);

void	checker(t_list **stack_a, t_list **stack_b);
void	which_instruction_1(t_list **stack_a, t_list **stack_b, char *tmp);

#endif