/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:20:34 by tebandam          #+#    #+#             */
/*   Updated: 2024/07/08 11:04:51 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	*process_successful_command(t_command_line_parsing
*parsing_result, t_env **env, char *command_line, t_vars *vars)
{
	ft_cmd_manager(env, parsing_result, vars);
	if (parsing_result->commands
		&& parsing_result->commands->redirections)
		ft_lstclear_redirections(&parsing_result->commands->redirections);
	if (parsing_result->commands
		&& parsing_result->commands->arguments)
		ft_lstclear_arguments(&parsing_result->commands->arguments);
	if (parsing_result->commands)
		ft_lstclear_commands(&parsing_result->commands);
	if (parsing_result)
		free(parsing_result);
	if (command_line)
		free(command_line);
	command_line = NULL;
	return (command_line);
}

static char	*verif_command_line(char *command_line
	, t_env **env, t_vars *vars)
{
	t_command_line_parsing	*parsing_result;

	if (command_line != NULL && command_line[0] != '\0')
	{
		add_history_and_parse(command_line, &parsing_result);
		if (check_spaces_and_tabs(command_line, parsing_result, vars) == 1)
			return (NULL);
		if (handle_parsing_errors(parsing_result, command_line, vars) == 1)
			return (NULL);
		if (check_pipe_position(command_line, vars) == 1)
			return (NULL);
		if (check_empty_quotes(command_line, parsing_result, vars) == 1)
			return (NULL);
		command_line = process_successful_command(parsing_result,
				env, command_line, vars);
		return (command_line);
	}
	return (command_line);
}

int	ft_readline(t_env **env, t_vars *vars)
{
	char							*command_line;

	command_line = NULL;
	while (1)
	{
		if (vars->exit == TRUE)
		{
			ft_lstclear_env(env);
			free(vars);
			exit(vars->exit_code);
		}
		if (command_line)
		{
			free(command_line);
			command_line = NULL;
		}
		set_interactive_mode(1);
		command_line = readline("minishell ~ ");
		set_interactive_mode(2);
		if (!command_line)
		{
			ft_putstr_fd("exit\n", 2);
			break ;
		}
		command_line = verif_command_line(command_line, env, vars);
	}
	return (0);
}

