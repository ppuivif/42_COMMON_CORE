#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "includes/libft_utils.h"
# include "includes/linked_list_utils.h"

# include <stdio.h>//to delete

typedef struct s_native_argument t_native_argument;
typedef struct s_native_argument
{
	char					*content;
	t_native_argument	*next;
	t_native_argument	*head;
}	t_native_argument;

typedef struct s_native_redirection t_native_redirection;
typedef struct s_native_redirection
{
	char				*content;
	enum
	{
		REDIRECTION_OUTFILE,
		REDIRECTION_INFILE,
		REDIRECTION_APPEND,
		REDIRECTION_HEREDOC,
		REDIRECTION_INDEFINED,
	} e_redirection;
	t_native_redirection	*next;
	t_native_redirection	*head;
}	t_native_redirection;

typedef struct s_substring t_substring;
typedef struct s_substring
{
	t_native_argument		*n_arguments;
	t_native_redirection	*n_redirections;
	t_substring				*next;
	t_substring				*head;
}	t_substring;


typedef struct s_command_line t_command_line;
typedef struct s_command_line
{
	bool				flag;
	t_substring			*substrings;
	t_command_line		*next;
	t_command_line		*head;
}	t_command_line;












//arr_utils.c
void			print_arr(char **arr);
t_command_line 	parse_command_line(char *str);
//t_element 	parse_between_pipes(char *str);
t_command_line	parse_substrings(char *str);


#endif