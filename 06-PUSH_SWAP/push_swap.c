#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	*str;
	char	**str_arr;
	int		count;
	int		*int_arr;
	void	*sort_arr;
	int		i;
	t_list	*list;

	count = 0;
	i = 2;
	if (argc < 2)
	{
		ft_putstr_fd("\n", 2);
		exit(EXIT_FAILURE);
	}
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

	printf("count : %d\n", count);
	ft_putstr_fd("\n", 1);

	check_parameters_are_integers(str_arr);

	print_tab_str(str_arr);

	list = malloc(sizeof(t_list));
	if (!list)
		return (1);

	int_arr = build_arr(str_arr, count);

	check_no_duplicate(int_arr, count);
	print_tab_int(int_arr, count);
	
	build_linked_list(int_arr, count, &list->head);

//	ft_lst_dc_print(list->head);
	
	sort_arr = ft_sort(int_arr, count);
	print_tab_int(int_arr, count);

	free_tab(str_arr);
	free(int_arr);
}
