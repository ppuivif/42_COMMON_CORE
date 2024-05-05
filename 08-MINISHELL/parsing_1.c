#include "minishell.h"

t_command_line	*parse_command_line(char *str)
{
	t_command_line	*command_line;
	char			*remaining_line;

	command_line = NULL;
	if (init_command_line_struct(&command_line) == 1)
	{
		command_line->flag = false;
		return (command_line);
	}
	remaining_line = skip_first_spaces(str);
	if (ft_strlen(remaining_line) == 0)
	{
		command_line->flag = false;
		return (command_line);
	}
	while(ft_strlen(remaining_line))
	{
		parse_substrings(&remaining_line, command_line);
		if (command_line->flag == false)
			return (command_line);
		remaining_line = skip_first_spaces(remaining_line);
		if (remaining_line[0] == '|')
		{
			remaining_line++;
			remaining_line = skip_first_spaces(remaining_line);
			if (ft_strlen(remaining_line) == 0)
			{
				command_line->flag = false;
				return (command_line);
			}	
		}
	}
	ft_lst_print(command_line);
	return (command_line);
}

void	parse_substrings(char **remaining_line, t_command_line *command_line)
{
	t_substring		*substring;

	substring = NULL;
	if (init_substring_struct(&substring) == 1)
	{
		command_line->flag = false;
		return ;//to confirm
	}
	if (!*remaining_line)
	{
		command_line->flag = false;
		return ;//to confirm
	}
	*remaining_line = skip_first_spaces(*remaining_line);
	if (ft_strlen(*remaining_line) == 0)
	{
		command_line->flag = false;
		return ;// to confirm
	}
	while (*remaining_line[0] && *remaining_line[0] != '|')
	{
		if (*remaining_line[0] == '<' || *remaining_line[0] == '>')
			get_redirections(remaining_line, substring);
		else
			get_arguments(remaining_line, substring);
		*remaining_line = skip_first_spaces(*remaining_line);
	}
	ft_lst_add_back1(&command_line->substrings, substring);
}


static void get_redirection_type(char **str, t_native_redirection *n_redirection)
{
	if (str[0][0] == '<' && str[0][1] == '<')
	{
		(*n_redirection).e_redirection = REDIRECTION_HEREDOC;
		*str += 2;
	}
	else if (str[0][0] == '>' && str[0][1] == '>')
	{
		(*n_redirection).e_redirection = REDIRECTION_APPEND;
		*str += 2;
	}
	else if (str[0][0] == '<')
	{
		(*n_redirection).e_redirection = REDIRECTION_INFILE;
		*str += 1;
	}
	else if (str[0][0] == '>')

	{
		(*n_redirection).e_redirection = REDIRECTION_OUTFILE;
		*str += 1;
	}
	else
	{
		(*n_redirection).e_redirection = REDIRECTION_INDEFINED;
		*str += 1;	
	}
}

void	get_redirections(char **remaining_line, t_substring *substring)
{
	size_t					len;
	t_native_redirection	*n_redirection;

	len = 0;
	n_redirection = NULL;
	if (init_redirection_struct(&n_redirection) == 1)
	{
		return ;//to confirm
	}
	get_redirection_type(remaining_line, n_redirection);
	*remaining_line = skip_first_spaces(*remaining_line);
	len = strcspn(*remaining_line, " \n\t\0");
	if (strcspn(*remaining_line, "<>") < len)
		substring->flag = false;//to complete
	else
	{
		n_redirection->content = ft_substr(*remaining_line, 0, len);
		*remaining_line += len;
		ft_lst_add_back2(&substring->n_redirections, n_redirection);
	}
}

void get_arguments(char **remaining_line, t_substring *substring)
{
	size_t				len;
	t_native_argument	*n_argument;

	len = 0;
	n_argument = NULL;
	if (init_argument_struct(&n_argument) == 1)
	{
		return ;//to confirm
	}
	*remaining_line = skip_first_spaces(*remaining_line);
	len = strcspn(*remaining_line, " \n\t\0");
	if (strcspn(*remaining_line, "<>|") < len)
		substring->flag = false;//to complete
	else
	{
		n_argument->content = ft_substr(*remaining_line, 0, len);
		*remaining_line += len;
		ft_lst_add_back3(&substring->n_arguments, n_argument);
	}
}

