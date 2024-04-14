/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:48:23 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/14 19:47:39 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execution(t_main_struct *main_struct, char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (pipe(fd) == -1)
	{
		perror("create pipe failed");
		error_handling(main_struct);
	}
	pid1 = fork();
	if (pid1 == -1)
	{
		perror("create fork failed");
		error_handling(main_struct);
	}
	if (pid1 == 0)
		exec_child1(main_struct, fd, envp);
	else
		exec_parent(main_struct, fd, envp);
}

void	exec_child1(t_main_struct *main_struct, int *fd, char **envp)
{
	char	**cmd1;

	close(fd[0]);
	close(main_struct->fd_output);
	dup2(main_struct->fd_input, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	cmd1 = main_struct->cmd1_arr;
	close(main_struct->fd_input);
	close(fd[1]);
	if (main_struct->cmd1_arr && main_struct->cmd1_arr[0] \
	&& main_struct->fd_input != -1)
	{
		if (execve(cmd1[0], cmd1, envp) == -1)
		{
			perror("execve failed");
			error_handling(main_struct);
		}
	}
}

void	exec_parent(t_main_struct *main_struct, int *fd, char **envp)
{
	pid_t	pid2;

	pid2 = fork();
	if (pid2 == -1)
	{
		perror("create fork failed");
		error_handling(main_struct);
	}
	if (pid2 == 0)
		exec_child2(main_struct, fd, envp);
	else
	{
		close(fd[0]);
		close(fd[1]);
		while (waitpid(-1, NULL, 0) != -1)
			continue ;
	}
}

void	exec_child2(t_main_struct *main_struct, int *fd, char **envp)
{
	char	**cmd2;

	close(fd[1]);
	close(main_struct->fd_input);
	dup2(fd[0], STDIN_FILENO);
	dup2(main_struct->fd_output, STDOUT_FILENO);
	cmd2 = main_struct->cmd2_arr;
	close(main_struct->fd_output);
	close(fd[0]);
	if (main_struct->cmd2_arr && main_struct->cmd2_arr[0])
	{
		if (execve(cmd2[0], cmd2, envp) == -1)
		{
			perror("execve failed");
			error_handling(main_struct);
		}
	}
}
