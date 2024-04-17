/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:48:23 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/17 10:09:39 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execution(t_main_struct *main_struct, char **envp)
{
	int		fd[2];

	main_struct->cursor = main_struct->head;
	if (pipe(fd) == -1)
	{
		perror("error\ncreate pipe failed");
		error_handling(main_struct);
	}
	exec_child(main_struct, fd, envp);
	close(fd[0]);
	close(fd[1]);
	close(main_struct->fd_tmp);
	if (main_struct->fd_input)
		close(main_struct->fd_input);
	if (main_struct->fd_output)
		close(main_struct->fd_output);
	while (waitpid(-1, NULL, 0) != -1)
		continue ;
//		printf ("cmd2%s\n", main_struct->cursor->cmd_arr[0]);
}


void	exec_child(t_main_struct *main_struct, int *fd, char **envp)
{
	int	i;
	pid_t	pid_n[main_struct->nb_arg];
	
	i = 1;
	while (i < main_struct->nb_arg - 1)
		{
			pid_n[i] = fork();
			if (pid_n[i] == -1)
			{
				perror("error\ncreate fork failed");
				error_handling(main_struct);
			}
			if (pid_n[i] == 0)
			{
				if (main_struct->cursor == main_struct->head)
					exec_first_child(main_struct, fd, envp);
				else if (main_struct->cursor == ft_lst_dc_last(main_struct->head))
					exec_last_child(main_struct, fd, envp);
				else
					exec_current_child(main_struct, fd, envp);
			}
			else
			{
				dup2(main_struct->fd_tmp, fd[1]);
				main_struct->cursor = main_struct->cursor->next;
			}
			i++;
		}
}

void	exec_first_child(t_main_struct *main_struct, int *fd, char **envp)
{
	close(fd[0]);
	if (main_struct->fd_output)
		close(main_struct->fd_output);
	dup2(main_struct->fd_input, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	if (main_struct->fd_input)
		close(main_struct->fd_input);
	close(fd[1]);
	if (main_struct->head->path && main_struct->head->cmd_arr \
	&& main_struct->head->cmd_arr[0] && main_struct->fd_input)
	{
		if (execve(main_struct->head->path, main_struct->head->cmd_arr, envp) == -1)
			perror("error\nexecve cmd failed");
	}
	error_handling(main_struct);
}

void	exec_current_child(t_main_struct *main_struct, int *fd, char **envp)
{
	if (main_struct->fd_input)
		close(main_struct->fd_input);
//	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(main_struct->fd_tmp, STDIN_FILENO);
	close(main_struct->fd_tmp);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	if (main_struct->fd_output)
		close(main_struct->fd_output);
	if (main_struct->cursor->path && main_struct->cursor->cmd_arr && main_struct->cursor->cmd_arr[0])
	{
//		ft_putstr_fd("here", 2);
		if (execve(main_struct->cursor->path, main_struct->cursor->cmd_arr, envp) == -1)
			perror("error\nexecve cmd failed");
	}
	error_handling(main_struct);
}

void	exec_last_child(t_main_struct *main_struct, int *fd, char **envp)
{
	if (main_struct->fd_input)
		close(main_struct->fd_input);
	close(fd[1]);
//	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(main_struct->fd_tmp, STDIN_FILENO);
	close(main_struct->fd_tmp);
	dup2(main_struct->fd_output, STDOUT_FILENO);
	if (main_struct->fd_output)
		close(main_struct->fd_output);
	if (main_struct->cursor->path && main_struct->cursor->cmd_arr && main_struct->cursor->cmd_arr[0])
	{
		if (execve(main_struct->cursor->path, main_struct->cursor->cmd_arr, envp) == -1)
			perror("error\nexecve cmd failed");
	}
	error_handling(main_struct);
}


