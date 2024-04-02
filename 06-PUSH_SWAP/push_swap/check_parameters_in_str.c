/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters_in_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:11:22 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/01 14:45:47 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_parameters_validity_and_join(char **arg, char **str)
{
	check_parameters_are_valid_1(*arg, *str);
	check_parameters_are_valid_2(*arg, *str);
	*str = ft_strjoin_freed(*str, *arg);
	*str = ft_strjoin_freed(*str, " ");
}

void	check_parameters_are_valid_1(char *arg, char *str)
{
	size_t	i;

	i = 0;
	if (ft_strlen(arg) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		free (str);
		exit (EXIT_FAILURE);
	}
	while (ft_isspace(arg[i]) == 0 && arg[i] != 0)
		i++;
	if (i == ft_strlen(arg))
	{
		ft_putstr_fd("Error\n", 2);
		free(str);
		exit (EXIT_FAILURE);
	}
}

void	check_parameters_are_valid_2(char *arg, char *str)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if ((ft_isdigit(arg[i]) == 0 || ft_isspace(arg[i]) == 1)
			&& arg[i] == 43 && arg[i] == 45)
		{
			ft_putstr_fd("Error\n", 2);
			free(str);
			exit (EXIT_FAILURE);
		}
		i++;
	}
}
