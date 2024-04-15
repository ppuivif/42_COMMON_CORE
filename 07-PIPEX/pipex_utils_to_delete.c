
void	check_and_skip_simple_quote(char ***str_array, t_main_struct *main_struct)
{
	int	i;

	i = 0;
	while ((*str_array)[i])
	{
		ft_skip_chr(&((*str_array)[i]), '\'');
		if (!(*str_array)[i])
			error_handling(main_struct);
		i++;
	}
}

void	ft_skip_chr(char **str, char c)
{
	size_t	len;

	len = ft_strlen(*str);
	if ((*str)[0] == c && (*str)[len - 1] == c)
		*str = ft_substr_freed(*str, 1, len - 2);
	if (!*str)
		ft_putstr_fd("memory allocation failed\n", 2);
}

/*int	check_existing_path_in_cmd(char ***cmd_with_options_arr, char **full_path_cmd)
{
	char *cmd;

	if (ft_strchr(*cmd_with_options_arr[0], '/') != 0)
	{
		if (access(*cmd_with_options_arr[0], F_OK) == 0)
		{
			*full_path_cmd = *cmd_with_options_arr[0];
			while (ft_strchr(*cmd_with_options_arr[0], '/') != 0)
			{
				cmd = ft_strdup(*cmd_with_options_arr[0]);
				free (cmd_with_options_arr[0][0]);
			//	*cmd_with_options_arr[0] = NULL;
				printf ("%s\n", cmd);
				cmd_with_options_arr[0][0] = ft_strdup(ft_strchr(cmd, '/') + 1);
				free (cmd);
				cmd = NULL;
			}
			return (0);
		}
		else
		{
			ft_putstr_fd("given path isn't valid for the command\n", 2);
			return (-1);
		}
	}
	return (1);
}*/