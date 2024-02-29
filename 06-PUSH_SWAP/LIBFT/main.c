#include "libft.h"

#include "stdio.h"

int main()
{
	t_list	*list;
	/*list = malloc(sizeof(t_list));
	ne pas malloc et faire un addback ou add front
	pour ajouter un element*/

	t_list	*new_element1;
	t_list	*new_element2;
	t_list	*new_element3;
	t_list	*new_element4;
	t_list	*new_element5;
//	t_list	*last_element;
	
	int content1 = 10;
	int content2 = 100;
	int content3 = 1000;
	int content4 = 10000;
	int content5 = 100000;

//	printf("%p\n", list);

	new_element1 = ft_lst_dc_new(&content1, NULL);
	new_element2 = ft_lst_dc_new(&content2, NULL);
	new_element3 = ft_lst_dc_new(&content3, NULL);
	new_element4 = ft_lst_dc_new(&content4, NULL);
	new_element5 = ft_lst_dc_new(&content5, NULL);

	list = new_element1;
	printf("first element %d\n", *(int*)list->content);
	printf("lenght : %ld\n",ft_lst_dc_size(list));
	ft_lst_dc_add_back(&list, new_element2);
	printf("second element %d\n", *(int*)list->next->content);
	printf("lenght : %ld\n",ft_lst_dc_size(list));
	ft_lst_dc_add_back(&list, new_element3);
	printf("third element %d\n", *(int*)list->next->next->content);
	printf("lenght : %ld\n",ft_lst_dc_size(list));
	ft_lst_dc_add_front(&list, new_element4);
	printf("first element %d\n", *(int*)list->content);
	printf("lenght : %ld\n",ft_lst_dc_size(list));
	ft_lst_dc_add_back(&list, new_element5);
	printf("fourth element %d\n", *(int*)list->next->next->next->next->content);
	printf("lenght : %ld\n",ft_lst_dc_size(list));
	//printf("third element %d\n", *(int*)list->next->next->next->next->content);


}
