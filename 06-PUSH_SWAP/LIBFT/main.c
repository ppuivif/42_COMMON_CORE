/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:02:20 by ppuivif           #+#    #+#             */
/*   Updated: 2024/03/01 12:03:57 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "stdio.h"

int main()
{
	t_list	*list;
	list = malloc(sizeof(t_list));
	if (!list)
		return (1);// malloc necessaire sinon erreur list pas initilisee

	/*ne pas malloc et faire un addback ou add front
	pour ajouter un element*/

//	t_element	*new_element1;
	t_element	*new_element2;
	t_element	*new_element3;
	t_element	*new_element4;
	t_element	*new_element5;
//	t_element	*last_element;
	
//	int content1 = 10;
	int content2 = 100;
	int content3 = 1000;
	int content4 = 10000;
	int content5 = 100000;

//	int position1 = 1;
	int position2 = 2;
	int position3 = 3;
	int position4 = 4;
	int position5 = 5;

//	printf("%p\n", list);

//	new_element1 = ft_lst_dc_new(content1, position1);
	new_element2 = ft_lst_dc_new(&content2, &position2);
	new_element3 = ft_lst_dc_new(&content3, &position3);
	new_element4 = ft_lst_dc_new(&content4, &position4);
	new_element5 = ft_lst_dc_new(&content5, &position5);

//	list->head = new_element1;
//	printf("first element %d\n", list->head->number);
	printf("lenght : %ld\n",ft_lst_dc_size(list->head));
	ft_lst_dc_add_back(&list->head, new_element2);
	printf("second element %d\n", *(int*)list->head->number);
	printf("lenght : %ld\n",ft_lst_dc_size(list->head));
	ft_lst_dc_add_back(&list->head, new_element3);
	printf("third element %d\n", *(int*)list->head->next->number);
	printf("lenght : %ld\n",ft_lst_dc_size(list->head));
	ft_lst_dc_add_front(&list->head, new_element4);
	printf("first element %d\n", *(int*)list->head->next->next->number);
	printf("lenght : %ld\n",ft_lst_dc_size(list->head));
	ft_lst_dc_add_back(&list->head, new_element5);
	printf("fourth element %d\n", *(int*)list->head->next->next->next->number);
	printf("lenght : %ld\n",ft_lst_dc_size(list->head));
	//printf("third element %d\n", *(int*)list->next->next->next->next->number);*/


}
