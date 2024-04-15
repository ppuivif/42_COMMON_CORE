/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:48:23 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/15 19:41:18 by ppuivif          ###   ########.fr       */
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
			exec_first_child(main_struct, fd, envp);
	else
	{
		main_struct->cursor = main_struct->head->next;
//		printf ("cmd2%s\n", main_struct->cursor->cmd_arr[0]);
		exec_parent(main_struct, fd, envp);
	}
}

void	exec_first_child(t_main_struct *main_struct, int *fd, char **envp)
{
	close(fd[0]);
	if (main_struct->fd_output && main_struct->fd_output != -1)
		close(main_struct->fd_output);
	dup2(main_struct->fd_input, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	if (main_struct->fd_input && main_struct->fd_input != -1)
		close(main_struct->fd_input);
	close(fd[1]);
	if (main_struct->head->path && main_struct->head->cmd_arr \
	&& main_struct->head->cmd_arr[0] && main_struct->fd_input != -1)
	{
		if (execve(main_struct->head->path, main_struct->head->cmd_arr, envp) == -1)
			perror("error\nexecve cmd1 failed");
	}
	error_handling(main_struct);
}

/*void	exec_child_next(t_main_struct *main_struct, int *fd, char **envp)
{
	close(fd[0]);
	if (main_struct->fd_output && main_struct->fd_output != -1)
		close(main_struct->fd_output);
	dup2(main_struct->fd_input, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	if (main_struct->fd_input && main_struct->fd_input != -1)
		close(main_struct->fd_input);
	close(fd[1]);
	if (main_struct->head->path && main_struct->head->cmd_arr \
	&& main_struct->head->cmd_arr[0] && main_struct->fd_input != -1)
	{
		if (execve(main_struct->head->path, main_struct->head->cmd_arr, envp) == -1)
			perror("error\nexecve cmd1 failed");
	}
	error_handling(main_struct);
}*/

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
		exec_last_child(main_struct, fd, envp);
	else
	{
		close(fd[0]);
		close(fd[1]);
		while (waitpid(-1, NULL, 0) != -1)
			continue ;
	}
}

void	exec_last_child(t_main_struct *main_struct, int *fd, char **envp)
{
	close(fd[1]);
	if (main_struct->fd_input && main_struct->fd_input != -1)
		close(main_struct->fd_input);
	dup2(fd[0], STDIN_FILENO);
	dup2(main_struct->fd_output, STDOUT_FILENO);
	if (main_struct->fd_output && main_struct->fd_output != -1)
		close(main_struct->fd_output);
	close(fd[0]);
	if (main_struct->cursor->path && main_struct->cursor->cmd_arr && main_struct->cursor->cmd_arr[0])
	{
		if (execve(main_struct->cursor->path, main_struct->cursor->cmd_arr, envp) == -1)
			perror("error\nexecve cmd2 failed");
	}
	error_handling(main_struct);
}
