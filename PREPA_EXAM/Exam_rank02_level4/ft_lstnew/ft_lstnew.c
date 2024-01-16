/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:12:43 by ppuivif           #+#    #+#             */
/*   Updated: 2024/01/11 17:57:20 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr_last_element;

	if (!lst)
		return (NULL);
	ptr_last_element = lst;
	while (ptr_last_element->next != NULL)
	{
		ptr_last_element = ptr_last_element->next;
	}
	return (ptr_last_element);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr_last_element;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ptr_last_element = ft_lstlast(*lst);
	ptr_last_element->next = new;
}

t_list  *ft_lstnew(int content)
{
    t_list  *tmp;

    tmp = malloc(sizeof(t_list));
    if (!tmp)
        return (NULL);
    tmp->content = content;
    tmp->next = NULL;
    return (tmp);
}

#include <stdio.h>

int	main()
{
	
	t_list *list;

	list = ft_lstnew(5);
	ft_lstadd_back(&list, ft_lstnew(7));
	
	printf("premier %d\n", list->content);
	printf("deuxieme %d\n", list->next->content);

	
}
