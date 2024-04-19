/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:52:14 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/19 08:22:06 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_files(char **argv, t_main_struct *main_struct)
{
	main_struct->fd_input = open(argv[1], O_RDONLY);
	if (main_struct->fd_input == -1)
	{
		if (access(argv[1], F_OK) == -1)
		{
			perror(argv[1]);
			main_struct->error_infile = 1;
		}
		else
		{
			perror(argv[1]);
			main_struct->error_infile = 2;
		}
	}
	main_struct->fd_output = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (main_struct->fd_output == -1)
	{
		perror(argv[4]);
		main_struct->error_outfile = 1;
	}
}
