
#include "push_swap.h"

/*int	main(int argc, char **argv)
{
	char	*str;
	char	**str_arr;
	int		*int_arr;
	int		i;
	int		size_stack_a;
	t_list	*stack_a;
	t_list	*stack_b;

	size_stack_a = 0;
	if (argc < 2)
		exit(EXIT_FAILURE);
	str = ft_strjoin(argv[1], " ");
	i = 2;

	while (argv[i])
	{
		str = ft_strjoin_freed(str, argv[i]);
		str = ft_strjoin_freed(str, " ");
		i++;
	}
	str_arr = ft_split(str, ' ');
	free(str);
	size_stack_a = count_parameters(str_arr);

//	ft_printf("count number of elements : %d\n\n", size_stack_a);

	check_parameters_are_integers(str_arr);


	int_arr = build_arr(str_arr, size_stack_a);

	check_no_duplicate(int_arr, size_stack_a, str_arr);
	stack_a = malloc(sizeof(t_list));
	if (!stack_a)
		return (1);
	stack_a->head = NULL;
	stack_a->size = size_stack_a;

	stack_b = malloc(sizeof(t_list));
	if (!stack_b)
		return (1);
	stack_b->head = NULL;
	stack_b->size = 0;
	

	build_linked_list(int_arr, &stack_a);
	ft_sort(int_arr, size_stack_a);
	
	checker(stack_a, stack_b);
}*/

void checker(t_list **stack_a, t_list **stack_b)
{
	char *tmp;
//	int	nb_read;
//	read(fd, tmp, BUFFER_SIZE);
	tmp = get_next_line(1);
	if (tmp)
		return;
	ft_printf("tmp : %s\n", tmp);
	which_instruction_1(&(*stack_a), &(*stack_b), tmp);
	while (tmp)
	{
		free(tmp);
		tmp = NULL;
		tmp = get_next_line(1);
		ft_printf("tmp : %s\n", tmp);
		which_instruction_1(&(*stack_a), &(*stack_b), tmp);
	}
	free(tmp);
	tmp = NULL;
	if (ft_lst_dc_is_sorted((*stack_a)->head) == 1)
		ft_printf("OK\n");
	else	
		ft_printf("K0\n");

}

void	which_instruction_1(t_list **stack_a, t_list **stack_b, char *tmp)
{
	if (ft_strcmp(tmp, "sa") == 0)
		swap(&(*stack_a)->head, 0);
	else if (ft_strcmp(tmp, "sb") == 0)
		swap(&(*stack_b)->head, 0);
	else if (ft_strcmp(tmp, "ss") == 0)
	{
		swap(&(*stack_a)->head, 0);
		swap(&(*stack_b)->head, 0);
	}
	else if (ft_strcmp(tmp, "pa") == 0)
		push(&(*stack_a)->head, &(*stack_b)->head, 0);
	else if (ft_strcmp(tmp, "pb") == 0)
		push(&(*stack_a)->head, &(*stack_b)->head, 0);
	else if (ft_strcmp(tmp, "ra") == 0)
		rotate(&(*stack_a)->head, 0);
	else if (ft_strcmp(tmp, "rb") == 0)
		rotate(&(*stack_b)->head, 0);
	else if (ft_strcmp(tmp, "rr") == 0)
	{
		rotate(&(*stack_a)->head, 0);
		rotate(&(*stack_b)->head, 0);
	}
	else if (ft_strcmp(tmp, "rra") == 0)
		reverse_rotate(&(*stack_a)->head, 0);
	else if (ft_strcmp(tmp, "rrb") == 0)
		reverse_rotate(&(*stack_b)->head, 0);
	else if (ft_strcmp(tmp, "rrr") == 0)
	{
		reverse_rotate(&(*stack_a)->head, 0);
		reverse_rotate(&(*stack_b)->head, 0);
	}
}

