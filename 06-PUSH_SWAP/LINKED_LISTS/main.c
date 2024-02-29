#include <stdio.h>
#include "ft_list.h"

int	main()
{
	t_list *list;
	t_list *new_element1;
	t_list *new_element2;
	t_list *last_element;
	size_t	len;
	t_list *element_to_del;

	list = ft_lstnew("les");
	new_element1 = ft_lstnew("salut");
	new_element2 = ft_lstnew("amis");
	
	printf("first element before add :%s\n", (char *)list->content);
	
	ft_lstadd_front(&list, new_element1);
	printf("first element after add_front : %s\n", (char *)list->content);
	printf("second element after add : %s\n", (char *)list->next->content);
	
	last_element = ft_lstlast(list); 
	printf("last element before add_back : %s\n", (char *)last_element->content);
	
	ft_lstadd_back(&list, new_element2);
	last_element = ft_lstlast(list); 
	printf("last element after add_back : %s\n", (char *)last_element->content);
	
	printf("final_sentence : %s %s %s\n", (char *)list->content, 
		(char *)list->next->content, (char *)last_element->content);

	len = ft_lstsize(list);
	printf("number of element : %ld\n", len);

	element_to_del = ft_lstlast(list);
	ft_lstdelone(element_to_del, del);
//	last_element = ft_lstlast(list); 
//	printf("last element after del last element :%s\n", (char *)last_element->content);
	
	ft_lstdelone(list->next, del);
	ft_lstdelone(list, del);
	

	return (0);
}