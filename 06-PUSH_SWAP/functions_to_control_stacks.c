#include "push_swap.h"

void	swap(t_element **head, char c)
{
	t_element	*first;
	t_element	*second;
	t_element	*third;
	t_element	*last_element;

	if (!*head || !(*head)->next)
		return;
	first = *head;
	second = (*head)->next;
	third = second->next;
	last_element = ft_lst_dc_last(*head);
	last_element->next = second;
	second->previous = last_element;
	first->next = third;
	third->previous = first;
	second->next = first;
	first->previous = second;
	(*head) = second;
	if (c == 'a')
		ft_printf("sa\n");
	if (c == 'b')
		ft_printf("sb\n");
}

void	push(t_element **head_src, t_element **head_dest, char c)
{
	t_element	*new_element;

	if (!*head_src)
		return;
	new_element = ft_lst_dc_new((*head_src)->number);
	ft_lst_dc_add_front(head_dest, new_element);
	ft_lst_dc_delone(head_src, *head_src);
	if (c == 'a')
		ft_printf("pa\n");
	if (c == 'b')
		ft_printf("pb\n");

}

void	rotate(t_element **head, char c)
{
	if (!*head)
		return;
	*head = (*head)->next;
	if (c == 'a')
		ft_printf("ra\n");
	if (c == 'b')
		ft_printf("rb\n");
}

void	reverse_rotate(t_element **head, char c)
{
	if (!*head)
		return;
	*head = (*head)->previous;
	if (c == 'a')
		ft_printf("rra\n");
	if (c == 'b')
		ft_printf("rrb\n");
}