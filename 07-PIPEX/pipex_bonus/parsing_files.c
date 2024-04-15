/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:52:14 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/15 17:13:46 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_files(char **argv, t_main_struct *main_struct)
{
	main_struct->fd_output = open(argv[main_struct->nb_arg], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (main_struct->fd_output == -1)
	{
		perror("error\noutfile couldn't be opened");
		error_handling(main_struct);
	}
	if (ft_strncmp(argv[1], "here_doc", 8) != 0)
	{
		main_struct->fd_input = open(argv[1], O_RDONLY);
		if (main_struct->fd_input == -1)
		{
			if (access(argv[1], F_OK) == -1)
				perror("error\ninfile doesn't exist");
			else
				perror("error\ninfile couldn't be opened");
		}
	}
	else
	{
//		read_here_doc(argv)
	}
}
