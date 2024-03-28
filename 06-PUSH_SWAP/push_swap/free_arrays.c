/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arrays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:57:29 by ppuivif           #+#    #+#             */
/*   Updated: 2024/03/27 11:39:36 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(char **str_arr)
{
	int	i;

	i = 0;
	while ((str_arr)[i])
	{
		free(str_arr[i]);
		i++;
	}
	if (str_arr)
		free(str_arr);
	str_arr = NULL;
}

void	free_arr(char **str_arr, int *int_arr)
{
	free_tab(str_arr);
	free(int_arr);
}
