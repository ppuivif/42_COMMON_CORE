#include "push_swap.h"

void	swap(t_element **head, char c)
{
	t_element	*first;
	t_element	*second;
	t_element	*third;
	t_element	*last_element;
	int			size;

	size = ft_lst_dc_size(*head);
	if (!(*head) || !(*head)->next)
		return;
	first = *head;
	second = (*head)->next;
	if (size > 2)
	{
		third = second->next;
		last_element = ft_lst_dc_last(*head);
		last_element->next = second;
		second->previous = last_element;
		first->next = third;
		third->previous = first;
	}
	second->next = first;
	second->new_position = 1;
	first->previous = second;
	first->new_position = 2;
	*head = second;
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
	update_position(head_src);
	update_position(head_dest);
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
	update_position(head);
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
	update_position(head);
}

void	double_swap(t_element **head_a, t_element **head_b)
{
	swap(head_a, 'c');
	swap(head_b, 'c');
	ft_printf("ss\n");
}

void	double_rotate(t_element **head_a, t_element **head_b)
{
	rotate(head_a, 'c');
	rotate(head_b, 'c');
	ft_printf("rr\n");
}

void	double_reverse_rotate(t_element **head_a, t_element **head_b)
{
	reverse_rotate(head_a, 'c');
	reverse_rotate(head_b, 'c');
	ft_printf("rrr\n");
}

