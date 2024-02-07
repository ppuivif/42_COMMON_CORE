#include "ft_list.h" 

int	ft_lstsize(t_list *lst)
{
	int nb_elements;
	t_list	*last_element;
	
	nb_elements = 0;
	while (lst)
	{
		lst = lst->next;
		nb_elements++;
	}
	return (nb_elements);
}