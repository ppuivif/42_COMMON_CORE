/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:51:24 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/15 19:20:22 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_cmd(t_cmd **cmd)
{
	if((*cmd)->cmd_arr)
		free_arr((*cmd)->cmd_arr);
	if((*cmd)->path)
		free((*cmd)->path);
	free(*cmd);	
}

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

void	success_handling(t_main_struct *main_struct)
{
	free_all(main_struct);
	exit (EXIT_SUCCESS);
}

void	error_handling(t_main_struct *main_struct)
{
	free_all(main_struct);
	exit (EXIT_FAILURE);
}

void	free_all(t_main_struct *main_struct)
{
	if (main_struct->fd_input && main_struct->fd_input != -1)
		close(main_struct->fd_input);
	if (main_struct->fd_output && main_struct->fd_output != -1)
		close(main_struct->fd_output);
	while (main_struct->head != NULL)
		ft_lst_dc_delone(&main_struct->head, main_struct->head);
	if (main_struct)
		free(main_struct);
}
