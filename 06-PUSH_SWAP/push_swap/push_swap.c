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
	check_if_sorted(int_arr, size_stack_a, str_arr);

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

	index_stack(&stack_a->head);
//	ft_putstr_fd("\nstack_a with index :\n" ,1);
//	ft_lst_dc_print(stack_a->head);

	if (stack_a->size == 2)
		ft_sort_2(&stack_a);

	else if (stack_a->size <= 3)
		ft_sort_3(&stack_a, &stack_b);

	else if (stack_a->size <= 5)
		ft_sort_5(&stack_a, &stack_b);

	else if (stack_a->size <= 100)
		ft_sort_500(&stack_a, &stack_b, 3);

	else if (stack_a->size <= 200)
		ft_sort_500(&stack_a, &stack_b, 3);// to modify

	else if (stack_a->size <= 300)
		ft_sort_500(&stack_a, &stack_b, 3);// to modify
	
	else if (stack_a->size <= 400)
		ft_sort_500(&stack_a, &stack_b, 3);// to modify
		
	else if (stack_a->size > 400)
		ft_sort_500(&stack_a, &stack_b, 8);
	

	free_tab(str_arr);
	free(int_arr);
	free_linked_list(&stack_a);
	free_linked_list(&stack_b);
}*/

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
	
	checker(&stack_a, &stack_b);
}