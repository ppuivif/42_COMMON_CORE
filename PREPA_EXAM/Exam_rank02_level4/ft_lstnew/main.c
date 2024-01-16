#include "ft_list.h"

int	main()
{
	t_list *list;

	list = ft_lstnew(50);
	ft_lstadd_back(&list, ft_lstnew(70));
	printf("premier %d\n", list->content);
	printf("deuxieme %d\n", list->next->content);
}