#include "minishell.h"

/*t_element parse_command_line(char *str)
{
	t_element	command_line;
	char		*remaining_line;	
	
	init_element_struct(&command_line);
	if (!str)
		return (command_line);
	remaining_line = skip_first_spaces(str);
	if (ft_strlen(remaining_line) == 0)
		return (command_line);
	parse_between_pipes(remaining_line);
	command_line.line = remaining_line;	
//	printf("%s\n", command_line.line);
	return (command_line);
}

t_element parse_between_pipes(char *str)
{
	t_element	command;
	char		*remaining_line;	

	init_element_struct(&command);
	if (!str)
		return (command);
	remaining_line = skip_first_spaces(str);
	if (ft_strlen(remaining_line) == 0)
		return (command);
	command.line = extract_substring(remaining_line, '|');
	printf ("substring : %s\n", command.line);
	free(command.line);
	remaining_line = ft_strdup(ft_strchr(remaining_line, '|'));
	printf ("remaining_line : %s\n", remaining_line);
	free(remaining_line);
	return (command);
}*/


t_command_line	parse_command_line(char *str)
{
	t_command_line	command_line;
	char			*remaining_line;

	init_command_line_struct(command_line);
	if (!str)
	{
		command_line.flag = false;
		return (command_line);
	}
	remaining_line = skip_first_spaces(str);
	if (ft_strlen(remaining_line) == 0)
	{
		command_line.flag = false;
		return (command_line);
	}
	command_line = parse_substrings(remaining_line);
/*	while(ft_strlen(remaining_line))
	{
		command_line = parse_command(&remaining_line);
		remaining_line++;
	}*/
	return (command_line);


}

t_command_line	parse_substrings(char *str)
{
	t_command_line	command_line;
	char			*remaining_line;
	size_t			len;
	char			*tmp1;
	char			*tmp2;

	init_command_line_struct(command_line);
	if (!str)
	{
		command_line.flag = false;
		return (command_line);
	}
	remaining_line = skip_first_spaces(str);
	if (ft_strlen(remaining_line) == 0)
	{
		command_line.flag = false;
		return (command_line);
	}
	while (remaining_line[0] && remaining_line[0] != '|')
	{
		if (remaining_line[0] == '<' || remaining_line[0] == '>')
		{
			remaining_line++;
			remaining_line = skip_first_spaces(remaining_line);
			len = strcspn(remaining_line, " \n\t");
			printf ("len : %ld\n", len);
			tmp1 = ft_substr(remaining_line, 0, len);
			remaining_line += len;
			printf ("remaining_line : %s\n", remaining_line);
			printf ("redirection : %s\n", tmp1);
		}
		else
		{
			remaining_line = skip_first_spaces(remaining_line);
			len = strcspn(remaining_line, " \n\t");
			printf ("len : %ld\n", len);
			tmp2 = ft_substr(remaining_line, 0, len);
			remaining_line += len;
			printf ("remaining_line : %s\n", remaining_line);
			printf ("argument : %s\n", tmp2);
		}
		remaining_line++;
	}
	return (command_line);
}

