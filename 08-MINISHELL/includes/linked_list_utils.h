#ifndef LINKED_LIST_UTILS_H
# define LINKED_LIST_UTILS_H

# include <stdlib.h>

# include "libft_utils.h"

typedef struct s_element t_element;
typedef struct s_element
{
	char		*line;
	char		**arr;
	char		*path;
	t_element	*next;
	t_element	*previous;
}	t_element;

typedef struct s_list
{
	int			size;
	t_element	*head;
}	t_list;

int			list_initialization(t_list	**stack, int size);
t_element	*ft_lst_dc_new(char *line, char **arr, char *path);
void		ft_lst_dc_add_back(t_element **head, t_element *new_element);
void		ft_lst_dc_add_front(t_element **head, t_element *new_element);
t_element	*ft_lst_dc_last(t_element *head);
size_t		ft_lst_dc_size(t_element *head);
void		ft_lst_dc_delone(t_element **head, t_element *element_to_del);
void		ft_lst_dc_print(t_element *head);

#endif