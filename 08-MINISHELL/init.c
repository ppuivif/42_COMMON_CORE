#include "minishell.h"

void	init_argument_struct(t_native_argument *n_argument)
{
	n_argument->content = NULL;
	n_argument->next = NULL;
	n_argument->head = NULL;
}

void	init_redirection_struct(t_native_redirection *n_redirection)
{
	n_redirection->content = NULL;
	n_redirection->next = NULL;
	n_redirection->head = NULL;
}

void	init_substring_struct(t_substring *substring)
{
	substring->n_arguments = NULL;
	substring->n_redirections = NULL;
	substring->next = NULL;
	substring->head = NULL;
}

void	init_command_line_struct(t_command_line *command_line)
{
	command_line->flag = true;
	command_line->substrings = NULL;
	command_line->next = NULL;
	command_line->head = NULL;
}