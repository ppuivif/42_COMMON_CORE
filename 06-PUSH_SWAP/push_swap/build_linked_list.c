/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_linked_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:41:16 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/01 15:14:28 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	build_and_sort_stacks(char **str_arr, int *int_arr,
	int parameters_number)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (stack_initialization(&stack_a, parameters_number) == 1)
	{
		ft_putstr_fd("error\nAt least one allocation for stack failed\n", 2);
		free_arr(str_arr, int_arr);
		exit (EXIT_FAILURE);
	}
	if (stack_initialization(&stack_b, parameters_number) == 1)
	{
		ft_putstr_fd("error\nAt least one allocation for stack failed\n", 2);
		free_arr(str_arr, int_arr);
		free_linked_list(&stack_a);
		exit (EXIT_FAILURE);
	}
	build_linked_list(int_arr, &stack_a);
	ft_sort_int_arr(int_arr, parameters_number);
	index_stack(&stack_a->head);
	sort_stack_a(&stack_a, &stack_b);
	free_linked_list(&stack_a);
	free_linked_list(&stack_b);
}

int	stack_initialization(t_list	**stack, int size)
{
	*stack = malloc(sizeof(t_list));
	if (!stack)
		return (1);
	(*stack)->head = NULL;
	(*stack)->size = size;
	return (0);
}

void	build_linked_list(int *int_arr, t_list	**list)
{
	int			i;
	t_element	*new_element;

	i = 0;
	while (i < (*list)->size)
	{
		new_element = ft_lst_dc_new(int_arr[i], 1, 1);
		new_element->initial_position = i + 1;
		new_element->new_position = new_element->initial_position;
		ft_lst_dc_add_back(&(*list)->head, new_element);
		i++;
	}
}

void	index_stack(t_element **head)
{
	int			i;
	int			size;
	t_element	*element_to_examinate;
	t_element	*increased_element;

	i = 0;
	size = ft_lst_dc_size(*head);
	element_to_examinate = *head;
	while (i < size)
	{
		increased_element = element_to_examinate->next;
		while (increased_element != (*head))
		{
			if (element_to_examinate->number > increased_element->number)
				element_to_examinate->index += 1;
			else
				increased_element->index += 1;
			increased_element = increased_element->next;
		}
		i++;
		element_to_examinate = element_to_examinate->next;
	}
}

void	update_new_position(t_element **head)
{
	int			i;
	int			size;
	t_element	*tmp_element;

	i = 0;
	size = ft_lst_dc_size(*head);
	tmp_element = *head;
	while (i < size)
	{
		tmp_element->new_position = i + 1;
		tmp_element = tmp_element->next;
		i++;
	}
}
