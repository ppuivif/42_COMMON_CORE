/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:14:48 by ppuivif           #+#    #+#             */
/*   Updated: 2024/03/26 20:52:05 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	*str;
	char	**str_arr;
	int		*int_arr;
	int		i;
	int		parameters_number;

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
	parameters_number = count_parameters(str_arr);
	check_parameters_are_integers(str_arr);
	int_arr = build_arr(str_arr, parameters_number);
	check_no_duplicate(int_arr, parameters_number, str_arr);
	check_if_sorted(int_arr, parameters_number, str_arr);
	build_and_sort_stacks(str_arr, int_arr, parameters_number);
	free_arr(str_arr, int_arr);
}
