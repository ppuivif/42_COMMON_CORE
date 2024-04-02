/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:14:48 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/01 18:59:13 by ppuivif          ###   ########.fr       */
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
	check_if_sorted(int_arr, count_parameters(str_arr), str_arr);
	build_and_sort_stacks(str_arr, int_arr, count_parameters(str_arr));
	free_arr(str_arr, int_arr);
	return (0);
}
