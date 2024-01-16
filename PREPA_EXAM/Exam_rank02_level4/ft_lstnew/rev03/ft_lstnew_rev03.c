#include "ft_list_rev03.h"

t_list	*ft_lstnew(int content)
{
	t_list *list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

#include <stdio.h>

int	main()
{
	t_list *list;
	int	content1 = 70;

	list = ft_lstnew(content1);
	printf("premier element %d\n", list->content);
}
