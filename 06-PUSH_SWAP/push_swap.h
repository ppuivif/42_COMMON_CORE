#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "LIBFT/libft.h"
# include <stdlib.h>
# include <limits.h> 


# include <stdio.h> //ATTENTION

t_list	*ft_lstnew(void *content, void *position);
t_list	*ft_lstlast(t_list *list);
void	ft_lstadd_front(t_list **list, t_list *new_element);
void	ft_lstadd_back(t_list **list, t_list *new_element);
size_t	ft_lstsize(t_list *list);
void	ft_lstdelone(t_list *list, void (*del)(void *));
void	del(void *element_to_del);

int		count_parameters(char **arr);
void	check_parameters_are_integers(char **str_arr);
void	check_no_duplicate(int *int_arr, int count);
int		*build_arr(char **str_arr, int count);
void	free_tab(char **arr);
int		ft_atoi_long(char *str);
char	*ft_strjoin_freed(char *s1, char *s2);

void	ft_swap_int(int *a, int *b);
void	*ft_sort(int *arr, int count);


void	print_tab_str(char **str_arr);
void	print_tab_int(int *int_arr, int count);

void	build_linked_list(int *int_arr, int count, t_element **head);


#endif