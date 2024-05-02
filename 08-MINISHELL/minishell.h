#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "includes/libft_utils.h"
# include "includes/linked_list_utils.h"

# include <stdio.h>//to delete

//arr_utils.c
void	print_arr(char **arr);
char	*skip_first_spaces(char *str);
t_element parse_command_line(char *str);
t_element parse_between_pipes(char *str);


#endif