#include "push_swap.h"

/*void	swap(t_element **head, char c)
{
	int			size;

	size = ft_lst_dc_size(*head);
	if (!(*head) || !(*head)->next)
		return;
	if (size > 2)
	{
		(*head)->previous->next = (*head)->next;//1 
		(*head)->next->previous = (*head)->previous;//2
		(*head)->next->next->previous = (*head);//3
		(*head)->next = (*head)->next->next;//4
		(*head)->previous->next->next = (*head);//5
		(*head)->previous = (*head)->previous->next;//6
		*head = (*head)->previous;
	}
	else
		*head = (*head)->next;
	(*head)->new_position = 1;
	(*head)->next->new_position = 2;
	if (c == 'a')
		ft_printf("sa\n");
	if (c == 'b')
		ft_printf("sb\n");
}*/

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
	(*head)->new_position = 1;
	(*head)->next->new_position = 2;
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
	update_new_position(head_src);
	update_new_position(head_dest);
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
	update_new_position(head);
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
	update_new_position(head);
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

