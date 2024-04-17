/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:48:23 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/17 17:40:58 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execution(t_main_struct *main_struct, char **envp)
{
	int		fd[2];
	pid_t	pid_1;

	if (pipe(fd) == -1)
	{
		perror("error\ncreate pipe failed");
		error_handling(main_struct);
	}
	pid_1 = fork();
	if (pid_1 == -1)
	{
		perror("error\ncreate fork failed");
		error_handling(main_struct);
	}
	if (pid_1 == 0)
			exec_first_child(main_struct, fd, envp);
	else
	{
//		main_struct->cursor = main_struct->head->next;
//		printf ("cmd2%s\n", main_struct->cursor->cmd_arr[0]);
		exec_parent(main_struct, fd, envp);
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

void	exec_parent(t_main_struct *main_struct, int *fd, char **envp)
{
	int	i;
	pid_t	pid_n[main_struct->nb_arg];
	pid_t	pid_last;

	if (main_struct->fd_input)
	{
		close(main_struct->fd_input);
		main_struct->fd_input = -1;
	}
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	i = 2;
	while (i < main_struct->nb_arg - 2)
	{
		pid_n[i] = fork();
		if (pid_n[i] == -1)
		{
			perror("error\ncreate fork failed");
			error_handling(main_struct);
		}
		if (pid_n[i] == 0)
			exec_current_child(main_struct, fd, envp);
//		else
//			main_struct->cursor = main_struct->cursor->next;
		i++;
	}
	pid_last = fork();
	if (pid_last == -1)
	{
		perror("error\ncreate fork failed");
		error_handling(main_struct);
	}
	if (pid_last == 0)
		exec_last_child(main_struct, fd, envp);
	else
	{
		close(fd[1]);
		while (waitpid(-1, NULL, 0) != -1)
			continue ;
		if (main_struct->fd_output)
			close(main_struct->fd_output);
	}
}

void	exec_current_child(t_main_struct *main_struct, int *fd, char **envp)
{
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	if (main_struct->fd_output)
		close(main_struct->fd_output);
//	if (main_struct->cursor->path && main_struct->cursor->cmd_arr && main_struct->cursor->cmd_arr[0])
	if (main_struct->head->next->path && main_struct->head->next->cmd_arr && main_struct->head->next->cmd_arr[0])
	{
		write (2, "here\n", 5);
//		if (execve(main_struct->cursor->path, main_struct->cursor->cmd_arr, envp) == -1)
		if (execve(main_struct->head->next->path, main_struct->head->next->cmd_arr, envp) == -1)
			perror("error\nexecve cmd failed");
	}
	error_handling(main_struct);
}

void	exec_last_child(t_main_struct *main_struct, int *fd, char **envp)
{
	close(fd[1]);
	dup2(main_struct->fd_output, STDOUT_FILENO);
	if (main_struct->fd_output)
		close(main_struct->fd_output);
//	if (main_struct->cursor->path && main_struct->cursor->cmd_arr && main_struct->cursor->cmd_arr[0])
	if (main_struct->head->previous->path && main_struct->head->previous->cmd_arr && main_struct->head->previous->cmd_arr[0])
	{
//		if (execve(main_struct->cursor->path, main_struct->cursor->cmd_arr, envp) == -1)
		if (execve(main_struct->head->previous->path, main_struct->head->previous->cmd_arr, envp) == -1)
			perror("error\nexecve cmd failed");
	}
	error_handling(main_struct);
}
