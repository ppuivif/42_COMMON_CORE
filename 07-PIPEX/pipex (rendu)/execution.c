/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:48:23 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/15 16:10:11 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execution(t_main_struct *main_struct, char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (pipe(fd) == -1)
	{
		perror("error\ncreate pipe failed");
		error_handling(main_struct);
	}
	pid1 = fork();
	if (pid1 == -1)
	{
		perror("error\ncreate fork failed");
		error_handling(main_struct);
	}
	if (pid1 == 0)
		exec_child1(main_struct, fd, envp);
	else
		exec_parent(main_struct, fd, envp);
}

void	exec_child1(t_main_struct *main_struct, int *fd, char **envp)
{
	close(fd[0]);
	if (main_struct->fd_output && main_struct->fd_output != -1)
		close(main_struct->fd_output);
	dup2(main_struct->fd_input, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	if (main_struct->fd_input && main_struct->fd_input != -1)
		close(main_struct->fd_input);
	close(fd[1]);
	if (main_struct->path1 && main_struct->cmd1_arr && main_struct->cmd1_arr[0] \
	&& main_struct->fd_input != -1)
	{
		if (execve(main_struct->path1, main_struct->cmd1_arr, envp) == -1)
			perror("error\nexecve cmd1 failed");
	}
	error_handling(main_struct);
}

void	exec_parent(t_main_struct *main_struct, int *fd, char **envp)
{
	pid_t	pid2;

	pid2 = fork();
	if (pid2 == -1)
	{
		perror("error\ncreate fork failed");
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
	close(fd[1]);
	if (main_struct->fd_input && main_struct->fd_input != -1)
		close(main_struct->fd_input);
	dup2(fd[0], STDIN_FILENO);
	dup2(main_struct->fd_output, STDOUT_FILENO);
	if (main_struct->fd_output && main_struct->fd_output != -1)
		close(main_struct->fd_output);
	close(fd[0]);
	if (main_struct->path2 && main_struct->cmd2_arr && main_struct->cmd2_arr[0])
	{
		if (execve(main_struct->path2, main_struct->cmd2_arr, envp) == -1)
			perror("error\nexecve cmd2 failed");
	}
	error_handling(main_struct);
}
