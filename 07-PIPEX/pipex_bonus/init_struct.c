/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:51:48 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/15 19:49:22 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_main_struct(t_main_struct **main_struct)
{
	*main_struct = ft_calloc(1, sizeof(t_main_struct));
	if (!*main_struct)
	{
		ft_putstr_fd("error\nstructure allocation failed\n", 2);
		exit (EXIT_FAILURE);
	}
	(*main_struct)->nb_arg = 0;
	(*main_struct)->fd_input = 0;
	(*main_struct)->fd_output = 0;
	(*main_struct)->fd_output = 0;
	(*main_struct)->head = NULL;
	(*main_struct)->cursor = NULL;
}
