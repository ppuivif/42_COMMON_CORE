/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_to_control_stacks_1.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:56:03 by ppuivif           #+#    #+#             */
/*   Updated: 2024/03/27 10:58:09 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_element **head, char c)
{
	int			size;

	size = ft_lst_dc_size(*head);
	if (!(*head) || !(*head)->next)
		return ;
	*head = (*head)->next;
	if (size > 2)
	{
		(*head)->next->previous = (*head)->previous;
		(*head)->previous->next = (*head)->next;
		(*head)->previous = (*head)->previous->previous;
		(*head)->previous->next->previous = (*head);
		(*head)->next = (*head)->previous->next;
		(*head)->previous->next = (*head);
	}
	if (c == 'a')
		ft_printf("sa\n");
	if (c == 'b')
		ft_printf("sb\n");
}

void	push(t_element **head_src, t_element **head_dest, char c)
{
	t_element	*new_element;
	int			size_src;

	size_src = ft_lst_dc_size(*head_src);
	if (!*head_src)
		return ;
	new_element = ft_lst_dc_new((*head_src)->number, (*head_src)->index,
			(*head_src)->initial_position);
	ft_lst_dc_add_front(head_dest, new_element);
	ft_lst_dc_delone(head_src, *head_src);
	if (c == 'a')
		ft_printf("pa\n");
	if (c == 'b')
		ft_printf("pb\n");
}

void	rotate(t_element **head, char c)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	if (c == 'a')
		ft_printf("ra\n");
	if (c == 'b')
		ft_printf("rb\n");
}

void	reverse_rotate(t_element **head, char c)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->previous;
	if (c == 'a')
		ft_printf("rra\n");
	if (c == 'b')
		ft_printf("rrb\n");
}
