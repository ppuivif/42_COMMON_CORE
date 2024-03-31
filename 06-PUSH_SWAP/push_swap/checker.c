/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:59:23 by ppuivif           #+#    #+#             */
/*   Updated: 2024/03/30 14:57:44 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	*str;
	char	**str_arr;
	int		*int_arr;
	int		i;

	if (argc < 2)
		exit(EXIT_FAILURE);
	str = NULL;
	i = 1;
	while (argv[i])
	{
		check_parameters_validity_and_join(&argv[i], &str);
		i++;
	}
	str_arr = ft_split(str, ' ');
	free(str);
	check_parameters_are_integers(str_arr);
	int_arr = build_int_arr(str_arr, count_parameters(str_arr));
	check_no_duplicate(int_arr, count_parameters(str_arr), str_arr);
	build_stacks_for_checker(str_arr, int_arr, count_parameters(str_arr));
	free_arr(str_arr, int_arr);
}

void	build_stacks_for_checker(char **str_arr, int *int_arr,
	int parameters_number)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (stack_initialization(&stack_a, parameters_number) == 1)
	{
		ft_putstr_fd("Error\nAt least one allocation for stack failed\n", 2);
		free_arr(str_arr, int_arr);
		exit (EXIT_FAILURE);
	}
	if (stack_initialization(&stack_b, parameters_number) == 1)
	{
		ft_putstr_fd("Error\nAt least one allocation for stack failed\n", 2);
		free_arr(str_arr, int_arr);
		free_linked_list(&stack_a);
		exit (EXIT_FAILURE);
	}
	build_linked_list(int_arr, &stack_a);
	ft_sort_int_arr(int_arr, parameters_number);
	if (checker(&stack_a, &stack_b) == 1)
		ft_error(&stack_a, &stack_b, str_arr, int_arr);
	free_linked_list(&stack_a);
	free_linked_list(&stack_b);
}

int	checker(t_list **stack_a, t_list **stack_b)
{
	char	*tmp;

	tmp = get_next_line(0);
	while (tmp)
	{
		if (which_instruction(&(*stack_a), &(*stack_b), tmp) == 1)
		{
			free(tmp);
			return (1);
		}
		free(tmp);
		tmp = NULL;
		tmp = get_next_line(0);
	}
	if ((ft_lst_dc_is_sorted((*stack_a)->head) == 0 \
	&& ft_lst_dc_size((*stack_b)->head) == 0))
		ft_printf("OK\n");
	else
		ft_printf("K0\n");
	return (0);
}

int	which_instruction(t_list **stack_a, t_list **stack_b, char *tmp)
{
	if (ft_strcmp(tmp, "sa\n") == 0)
		swap(&(*stack_a)->head, 0);
	else if (ft_strcmp(tmp, "sb\n") == 0)
		swap(&(*stack_b)->head, 0);
	else if (ft_strcmp(tmp, "ss\n") == 0)
		double_swap(&(*stack_a)->head, &(*stack_b)->head);
	else if (ft_strcmp(tmp, "pa\n") == 0)
		push(&(*stack_b)->head, &(*stack_a)->head, 0);
	else if (ft_strcmp(tmp, "pb\n") == 0)
		push(&(*stack_a)->head, &(*stack_b)->head, 0);
	else if (ft_strcmp(tmp, "ra\n") == 0)
		rotate(&(*stack_a)->head, 0);
	else if (ft_strcmp(tmp, "rb\n") == 0)
		rotate(&(*stack_b)->head, 0);
	else if (ft_strcmp(tmp, "rr\n") == 0)
		double_rotate(&(*stack_a)->head, &(*stack_b)->head);
	else if (ft_strcmp(tmp, "rra\n") == 0)
		reverse_rotate(&(*stack_a)->head, 0);
	else if (ft_strcmp(tmp, "rrb\n") == 0)
		reverse_rotate(&(*stack_b)->head, 0);
	else if (ft_strcmp(tmp, "rrr\n") == 0)
		double_reverse_rotate(&(*stack_a)->head, &(*stack_b)->head);
	else
		return (1);
	return (0);
}

void	ft_error(t_list **stack_a, t_list **stack_b,
		char **str_arr, int *int_arr)
{
	ft_putstr_fd("Error1\n", 2);
	free_arr(str_arr, int_arr);
	free_linked_list(stack_a);
	free_linked_list(stack_b);
	exit (EXIT_FAILURE);
}
