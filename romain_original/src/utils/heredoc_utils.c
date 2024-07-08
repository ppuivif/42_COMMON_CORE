/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:59:39 by rgobet            #+#    #+#             */
/*   Updated: 2024/07/01 11:40:59 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_redirection_to_expand	*is_last(t_redirection_to_expand *tmp)
{
	t_redirection_to_expand	*result;

	result = NULL;
	while (tmp)
	{
		if (tmp->e_type == REDIRECTION_HEREDOC)
			result = tmp;
		tmp = tmp->next;
	}
	return (result);
}

void	where_are_heredoc(t_redirection **list, t_bool exist)
{
	t_redirection	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (exist == FALSE && tmp)
			tmp->e_position = NONE;
		else if (exist == TRUE && tmp && tmp->e_position != HERE)
			tmp->e_position = COMING;
		tmp = tmp->next;
	}
}

void	prepare_heredoc(t_redirection *redirection,
	t_redirection_to_expand *tmp_redirection)
{
	redirection->nb_heredoc++;
	redirection->e_position = HERE;
	redirection->limiter = copy(tmp_redirection->arg);
	redirection->file_heredoc = ft_itoa(
			redirection->nb_heredoc);
	redirection->file_heredoc = ft_strjoin_free_s2(
			"/tmp/.heredoc", redirection->file_heredoc);
	if (access(redirection->file_heredoc, F_OK) == 0)
		unlink(redirection->file_heredoc);
	redirection->infile_fd = open(redirection->file_heredoc,
			O_WRONLY | O_TRUNC | O_CREAT, 0644);
}

void	heredoc_setup(t_redirection *redirection,
	t_command_to_expand *tmp_command, t_env *env, t_vars *vars)
{
	pid_t	child;
	int		wstatus;

	child = fork();
	if (child == 0)
	{
		signal(SIGINT, quit);
		ft_heredoc(redirection,
			tmp_command->redirections, env, vars);
		ft_lstclear_env(&env);
		ft_lstclear_arguments(&tmp_command->arguments);
		ft_lstclear_redirections(&tmp_command->redirections);
		ft_lstclear_commands(&tmp_command);
		ft_lstclear_final_redirection(&redirection);
		ft_free(vars->path);
		free(vars);
		exit(0);
	}
	else
	{
		wait(&wstatus);
		if (WIFSIGNALED(wstatus))
			vars->exit_code = WTERMSIG(wstatus) + 128;
		else
			vars->exit_code = WEXITSTATUS(wstatus);
		if (vars->exit_code == 130)
			g_sig = SIGINT;
	}
	close(redirection->infile_fd);
	redirection->infile_fd = -1;
	redirection->infile_fd = open(
			redirection->file_heredoc, O_RDONLY, 0644);
}
