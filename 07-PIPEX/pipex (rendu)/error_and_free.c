/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:51:24 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/18 17:45:11 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_arr(char **str_arr)
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

void	error_handling(t_main_struct *main_struct)
{
	free_all(main_struct);
	exit (EXIT_FAILURE);
}

void	free_all(t_main_struct *main_struct)
{
	if (main_struct->fd_input)
		close(main_struct->fd_input);
	if (main_struct->fd_output)
		close(main_struct->fd_output);
	if (main_struct->cmd1_arr)
		free_arr(main_struct->cmd1_arr);
	if (main_struct->path1)
		free(main_struct->path1);
	if (main_struct->cmd2_arr)
		free_arr(main_struct->cmd2_arr);
	if (main_struct->path2)
		free(main_struct->path2);
	if (main_struct)
		free(main_struct);
}
