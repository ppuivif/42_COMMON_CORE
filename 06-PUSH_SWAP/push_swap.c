#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	*str;
	char	**str_arr;
	int		count;
	int		*int_arr;
//		void	*sort_arr;
	int		i;
	t_list	*list_a;
	t_list	*list_b;

	count = 0;
	i = 2;
	if (argc < 2)
		exit(EXIT_FAILURE);
	str = ft_strjoin(argv[1], " ");
	while (argv[i])
	{
		str = ft_strjoin_freed(str, argv[i]);
		str = ft_strjoin_freed(str, " ");
		i++;
	}
	str_arr = ft_split(str, ' ');
	free(str);
	count = count_parameters(str_arr);

	ft_putstr_fd("count number of elements :\n" ,1);
	printf("count : %d\n", count);
	ft_putstr_fd("\n", 1);

	check_parameters_are_integers(str_arr);

	ft_putstr_fd("str_array_a :\n" ,1);
	print_tab_str(str_arr);

	list_a = malloc(sizeof(t_list));
	if (!list_a)
		return (1);
	list_a->head = NULL;
	list_b = malloc(sizeof(t_list));
	if (!list_b)
		return (1);
	list_b->head = NULL;
	
	int_arr = build_arr(str_arr, count);

	check_no_duplicate(int_arr, count);
	
//	print_tab_int(int_arr, count);

	build_linked_list(int_arr, count, &list_a->head);
	ft_putstr_fd("stack_a :\n" ,1);
	ft_lst_dc_print(list_a->head);
	
	ft_sort(int_arr, count);
	ft_putstr_fd("int_array_a after sort :\n" ,1);
	print_tab_int(int_arr, count);

	swap(&list_a->head, 'a');
	ft_putstr_fd("stack_a after swap_a (sa):\n" ,1);
	ft_lst_dc_print(list_a->head);

	ft_putstr_fd("stack_b before push a to b (pb) :\n" ,1);
	ft_lst_dc_print(list_b->head);

	push(&list_a->head, &list_b->head, 'b');
	ft_putstr_fd("stack_a after first push a to b (pb) :\n" ,1);
	ft_lst_dc_print(list_a->head);
	ft_putstr_fd("stack_b after first push a to b (pb) :\n" ,1);
	ft_lst_dc_print(list_b->head);
	
	push(&list_a->head, &list_b->head, 'b');
	ft_putstr_fd("stack_a after second push a to b (pb) :\n" ,1);
	ft_lst_dc_print(list_a->head);
	ft_putstr_fd("stack_b after second push a to b (pb) :\n" ,1);
	ft_lst_dc_print(list_b->head);

	rotate(&list_a->head, 'a');
	ft_putstr_fd("stack_a after rotate (ra):\n" ,1);
	ft_lst_dc_print(list_a->head);

	reverse_rotate(&list_a->head, 'a');
	ft_putstr_fd("stack_a after reverse_rotate (rra) :\n" ,1);
	ft_lst_dc_print(list_a->head);


	free_tab(str_arr);
	free(int_arr);
	free_linked_list(&list_a);
	free_linked_list(&list_b);
}
