#include "push_swap.h"

int	main(int argc, char **argv)
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

	ft_printf("count number of elements : %d\n\n", size_stack_a);

	check_parameters_are_integers(str_arr);

//	ft_putstr_fd("str_array_a :\n" ,1);
//	print_tab_str(str_arr);

	int_arr = build_arr(str_arr, size_stack_a);

	check_no_duplicate(int_arr, size_stack_a, str_arr);
//	check_if_sorted(int_arr, size_stack_a, str_arr);
//	print_tab_int(int_arr, count);

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
//	ft_putstr_fd("stack_a before sort :\n" ,1);
//	ft_lst_dc_print(stack_a->head);
	
/*	ft_putstr_fd("int_array_a after sort :\n" ,1);
	print_tab_int(int_arr, stack_a->size);*/

	index_stack(&stack_a->head);
	ft_putstr_fd("\nstack_a with index :\n" ,1);
	ft_lst_dc_print(stack_a->head);

	if (stack_a->size == 2)
		ft_sort_2(&stack_a);

	else if (stack_a->size <= 3)
		ft_sort_3(&stack_a, &stack_b);

	else if (stack_a->size <= 5)
		ft_sort_5(&stack_a, &stack_b);
	
	else if (stack_a->size <= 100)
		ft_sort_100(&stack_a, &stack_b);

/*	ft_putstr_fd("\nstack_a after sort :\n" ,1);
	ft_lst_dc_print(stack_a->head);*/

	ft_putstr_fd("\nstack_a after sort :\n" ,1);
	ft_lst_dc_print(stack_a->head);



















/*	swap(&stack_a, 'a');
	ft_putstr_fd("stack_a after swap_a (sa):\n" ,1);
	ft_lst_dc_print(stack_a->head);

	ft_putstr_fd("stack_b before push a to b (pb) :\n" ,1);
	ft_lst_dc_print(stack_b->head);

	push(&stack_a->head, &stack_b->head, 'b');
	ft_putstr_fd("stack_a after first push a to b (pb) :\n" ,1);
	ft_lst_dc_print(stack_a->head);
	ft_putstr_fd("stack_b after first push a to b (pb) :\n" ,1);
	ft_lst_dc_print(stack_b->head);
	
	push(&stack_a->head, &stack_b->head, 'b');
	ft_putstr_fd("stack_a after second push a to b (pb) :\n" ,1);
	ft_lst_dc_print(stack_a->head);
	ft_putstr_fd("stack_b after second push a to b (pb) :\n" ,1);
	ft_lst_dc_print(stack_b->head);

	rotate(&stack_a->head, 'a');
	ft_putstr_fd("stack_a after rotate (ra):\n" ,1);
	ft_lst_dc_print(stack_a->head);

	reverse_rotate(&stack_a->head, 'a');
	ft_putstr_fd("stack_a after reverse_rotate (rra) :\n" ,1);
	ft_lst_dc_print(stack_a->head);*/


	free_tab(str_arr);
	free(int_arr);
	free_linked_list(&stack_a);
	free_linked_list(&stack_b);
}
