#include "ft_list.h"
#include <stdio.h>

int main()
{
	void *content;
	char *str = "salut";
	content = str; 
	t_list *list;
	t_list *last_element;

	list = ft_lstnew(content);
	printf("premier element avant ajout :%s\n", (char *)list->content);
	ft_lstadd_front(&list, ft_lstnew("les"));
	ft_lstadd_back(&list, ft_lstnew("amis"));
	last_element = ft_lstlast(list);
	printf("premier element apres ajout :%s\n", (char *)list->content);
	printf("deuxieme element :%s\n", (char *)list->next->content);
	printf("dernier element :%s\n", (char *)last_element->content);
	printf("nbre d'elements :%d\n", ft_lstsize(list));
	return (0);
}