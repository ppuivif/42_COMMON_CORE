/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:48:23 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/19 18:17:45 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execution(t_main_struct *main_struct, char **envp)
{
	int		i;
	int		fd[2];
	pid_t	pid_1;
	int 	fd_in;
	int		fd_out;
	
	main_struct->cursor = main_struct->head;
	i = 1;
	fd_in = main_struct->fd_input;
	while (i < main_struct->nb_arg - 1)
	{
		if (main_struct->cursor == ft_lst_dc_last(main_struct->head))
			fd_out = main_struct->fd_output;
		else
		{
			if (pipe(fd) == -1)
			{
				perror("error\ncreate pipe failed");
				error_handling(main_struct);
			}
			fd_out = fd[1];
		}
		pid_1 = fork();
		if (pid_1 == -1)
		{
			perror("error\ncreate fork failed");
			error_handling(main_struct);
		}
		if (pid_1 == 0)
		{
			exec_child(main_struct, fd_in, fd_out, envp);
			//return ?
		}	
		main_struct->cursor = main_struct->cursor->next;
		close_fd(fd_in);
		close_fd(fd_out);
		fd_in = fd[0];
		i++;
	}
	while(waitpid(-1, NULL, 0) != -1)
		continue;
}

void	exec_child(t_main_struct *main_struct, int fd_in, int fd_out, char **envp)
{
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close_fd(fd_in);
	close_fd(fd_out);
	close_fd(main_struct->fd_output);
	close_fd(main_struct->fd_input);
	if (main_struct->cursor->path && main_struct->cursor->cmd_arr \
	&& main_struct->cursor->cmd_arr[0])
	{
		if (execve(main_struct->cursor->path, main_struct->cursor->cmd_arr, envp) == -1)
			perror("error\nexecve cmd failed");
	}
	error_handling(main_struct);
}
