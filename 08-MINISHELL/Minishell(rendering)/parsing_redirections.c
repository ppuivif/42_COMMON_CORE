/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 06:36:23 by drabarza          #+#    #+#             */
/*   Updated: 2024/09/05 08:58:55 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_redirection_type(char **str, \
t_native_redirection *n_redirection)
{
	if (count_angled_bracket(*str) > 2)
		(*n_redirection).t_redirection = REDIRECTION_INDEFINED;
	else if (count_angled_bracket(*str) == 2)
	{
		if (str[0][0] == '<' && str[0][1] == '<')
			(*n_redirection).t_redirection = REDIRECTION_HEREDOC;
		else if (str[0][0] == '>' && str[0][1] == '>')
			(*n_redirection).t_redirection = REDIRECTION_APPEND;
		else
			(*n_redirection).t_redirection = REDIRECTION_INDEFINED;
		*str += 2;
	}
	else
	{
		if (str[0][0] == '<')
			(*n_redirection).t_redirection = REDIRECTION_INFILE;
		else if (str[0][0] == '>')
			(*n_redirection).t_redirection = REDIRECTION_OUTFILE;
		else
			(*n_redirection).t_redirection = REDIRECTION_INDEFINED;
		*str += 1;
	}
	return ((*n_redirection).t_redirection);
}

static void	check_and_add_redirection(t_substring **substring, \
t_command_line **command_line, t_native_redirection **n_redirection)
{
	if (!(*n_redirection)->content)
	{
		(*n_redirection) = free_and_null(*n_redirection);
		error_allocation_command_line_and_exit(command_line);
	}
	ft_lst_add_back2(&(*substring)->n_redirections, *n_redirection);
}

int	get_redirections(char **remaining_line, t_substring *substring, \
t_command_line **command_line)
{
	int						len;
	t_native_redirection	*n_redirection;

	len = 0;
	n_redirection = NULL;
	init_native_redirection_struct(&n_redirection, command_line);
	if (get_redirection_type(remaining_line, n_redirection) == \
	REDIRECTION_INDEFINED)
	{
		n_redirection = free_and_null(n_redirection);
		return (2);
	}
	*remaining_line = skip_first_whitespaces(*remaining_line);
	len = count_len_to_cut(*remaining_line);
	if (len == -1 || len == 0)
	{
		n_redirection = free_and_null(n_redirection);
		return (2);
	}
	n_redirection->content = ft_substr(*remaining_line, 0, len);
	check_and_add_redirection(&substring, command_line, &n_redirection);
	*remaining_line += len;
	return (0);
}
