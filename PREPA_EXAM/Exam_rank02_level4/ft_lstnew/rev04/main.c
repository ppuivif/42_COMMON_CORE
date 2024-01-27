#include "ft_list.h"
#include <stdio.h>

int main()
{
	int content;
	t_list *list;
	t_list *last_element;

	content = 1;
	list = ft_lstnew(content);
	ft_lstadd_back(&list, ft_lstnew(2));
	last_element = ft_lstlast(list);
	printf("premier element %d\n", list->content);
	printf("deuxieme element %d\n", list->next->content);
	printf("dernier element %d\n", last_element->content);
	return (0);
}