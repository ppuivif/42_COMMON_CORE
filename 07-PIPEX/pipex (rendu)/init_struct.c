/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:51:48 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/18 18:02:02 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_struct(t_main_struct **main_struct)
{
	*main_struct = ft_calloc(1, sizeof(t_main_struct));
	if (!*main_struct)
	{
		ft_putstr_fd("error\nstructure allocation failed\n", 2);
		exit (EXIT_FAILURE);
	}
	(*main_struct)->fd_input = 0;
	(*main_struct)->fd_output = 0;
	(*main_struct)->cmd1_arr = NULL;
	(*main_struct)->path1 = NULL;
	(*main_struct)->cmd2_arr = NULL;
	(*main_struct)->path2 = NULL;
	(*main_struct)->error_infile = 0;
	(*main_struct)->error_outfile = 0;
	(*main_struct)->exit_status = 0;
}
