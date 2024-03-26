#include "push_swap.h"

void	swap(t_element **head, char c)
{
	int			size;

	size = ft_lst_dc_size(*head);
	if (!(*head) || !(*head)->next)
		return;
	*head = (*head)->next;
	if (size > 2)
	{
		(*head)->next->previous = (*head)->previous;//1 
		(*head)->previous->next = (*head)->next;//2 
		(*head)->previous = (*head)->previous->previous;//3
		(*head)->previous->next->previous = (*head);//4
		(*head)->next = (*head)->previous->next;//5
		(*head)->previous->next = (*head);//6
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
		return;
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
		return;
	*head = (*head)->next;
	if (c == 'a')
		ft_printf("ra\n");
	if (c == 'b')
		ft_printf("rb\n");
}

void	reverse_rotate(t_element **head, char c)
{
	if (!*head || !(*head)->next)
		return;
	*head = (*head)->previous;
	if (c == 'a')
		ft_printf("rra\n");
	if (c == 'b')
		ft_printf("rrb\n");
}

void	double_swap(t_element **head_a, t_element **head_b)
{
	swap(head_a, 0);
	swap(head_b, 0);
	ft_printf("ss\n");
}

void	double_rotate(t_element **head_a, t_element **head_b)
{
	rotate(head_a, 0);
	rotate(head_b, 0);
	ft_printf("rr\n");
}

void	double_reverse_rotate(t_element **head_a, t_element **head_b)
{
	reverse_rotate(head_a, 0);
	reverse_rotate(head_b, 0);
	ft_printf("rrr\n");
}
