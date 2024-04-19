/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:51:48 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/19 18:03:40 by ppuivif          ###   ########.fr       */
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
	(*main_struct)->head = NULL;
	(*main_struct)->cursor = NULL;
}

void	init_cmd_struct(t_cmd **cmd)
{
	*cmd = ft_calloc(1, sizeof(t_cmd));
	if (!*cmd)
	{
		ft_putstr_fd("error\nstructure allocation failed\n", 2);
		exit (EXIT_FAILURE);
	}
	(*cmd)->cmd_arr = NULL;
	(*cmd)->path = NULL;
	(*cmd)->next = NULL;
	(*cmd)->previous = NULL;
}
