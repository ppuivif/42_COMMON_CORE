#include "pipex.h"

void	check_files(char **argv, t_main_struct *main_struct)
{
	main_struct->fd_output = open(argv[4], O_WRONLY | O_CREAT, 0644);
	if (main_struct->fd_output == -1)
	{
		perror("outfile couldn't be opened");
		exit (EXIT_FAILURE);
	}
	main_struct->fd_input = open(argv[1], O_RDONLY);
	if (main_struct->fd_input == -1)
	{
		if (access(argv[1], F_OK) == -1)
			perror("infile doesn't exist");
		else
			perror("infile couldn't be opened");
	}
}

void	build_full_path_cmd_arr(char **argv, char **envp,
		t_main_struct *main_struct)
{
	int	i;
	int	last;

	i = 0;
	last = main_struct->argv_number - 1;
 	build_cmd_arr(argv, main_struct);
//	if (main_struct->cmd_with_options_arr[last - 1] == NULL)
//			error_handling(main_struct);
	while (i < last)
	{
		if (main_struct->cmd_with_options_arr[i])
		{
			if (verify_existing_path_in_cmd(&main_struct->cmd_with_options_arr[i], \
			&main_struct->full_path_cmd[i]) == 1)
			{
				check_full_path_in_envp(&main_struct->cmd_with_options_arr[i], \
				&main_struct->full_path_cmd[i], envp);

			}
		}		

		i++;
	}
/*	int flag2 = verify_existing_path_in_cmd(&main_struct->cmd_with_options_arr[last - 1], \
		&main_struct->full_path_cmd[last - 1]);
	if (flag2 == -1)
		error_handling(main_struct);
	if (flag2 == 1)
	{
		if (check_full_path_in_envp(&main_struct->cmd_with_options_arr[last - 1], \
		&main_struct->full_path_cmd[last], envp) == -1)
			error_handling(main_struct);
	}*/

	//to delete
	i = 0;
	int	j;
	while (main_struct->cmd_with_options_arr
		&& main_struct->cmd_with_options_arr[i])
	{
		j = 0;
		while (main_struct->cmd_with_options_arr[i][j])
		{
			printf("cmd%d : %s\n", i, main_struct->cmd_with_options_arr[i][j]);
			j++;
		}
		i++;
	}
}

void	build_cmd_arr(char **argv, t_main_struct *main_struct)
{
	int	i;

	i = 0;
	while (i < main_struct->argv_number - 2)
	{
		main_struct->cmd_with_options_arr[i] = ft_split(argv[i + 2], ' ');
		i++;
	}
	main_struct->cmd_with_options_arr[i] = NULL;
	i = 0;
	while (i < main_struct->argv_number - 2)
	{
		if (!main_struct->cmd_with_options_arr[i] \
		|| !main_struct->cmd_with_options_arr[i][0])
			ft_putstr_fd("command not found\n", 2);
		else
		{
			check_and_skip_simple_quote(main_struct->cmd_with_options_arr[i], main_struct);

//			printf("argv : %s\n", argv[i + 2]);
		}
		i++;
	}
}

void	check_and_skip_simple_quote(char **str_array, t_main_struct *main_struct)
{
	int	i;

	i = 0;
	while (str_array[i])
	{
		ft_skip_chr(str_array[i], '\'');
		if (!str_array[i])
			error_handling(main_struct);
//		printf("str_arr : %s\n", str_array[i]);
		i++;
	}
}

void	ft_skip_chr(char *str, char c)
{
	size_t	len;

	len = ft_strlen(str);
	if (str[0] == c && str[len - 1] == c)
		str = ft_substr_freed(str, 1, len - 2);
	if (!str)
		ft_putstr_fd("memory allocation failed\n", 2);
}

int	verify_existing_path_in_cmd(char ***cmd_with_options_arr, char **full_path_cmd)
{
	char *cmd;

	if (ft_strchr(*cmd_with_options_arr[0], '/') != 0)
	{
		if (access(*cmd_with_options_arr[0], F_OK) == 0)
		{
			*full_path_cmd = *cmd_with_options_arr[0];
			while (ft_strchr(*cmd_with_options_arr[0], '/') != 0)
			{
				cmd = *cmd_with_options_arr[0];
				free (*cmd_with_options_arr[0]);
				*cmd_with_options_arr[0] = NULL;
				*cmd_with_options_arr[0] = ft_strdup(ft_strchr(cmd, '/') + 1);
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
}

int	check_full_path_in_envp(char ***cmd_with_options_arr, char **full_path_cmd, char **envp)
{
	char	**path;
	
	path = search_path(envp);
	if (!path)
	{
		ft_putstr_fd("path doesn't exist in envp\n", 2);
		free_arr(path);
		return (1);
	}
	if (check_path_cmd_validity(path, full_path_cmd, cmd_with_options_arr) == 0)
	{
		free_arr(path);
		return (0);
	}
	free_arr(path);
	return (-1);
}

char	**search_path(char **envp)
{
	int		i;
	char	**path;

	path = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			path = ft_split(ft_strchr(envp[i], '/'), ':');
			return (path);
		}
		else
			i++;
	}
	return (path);
}

int	check_path_cmd_validity(char **path, char **full_path_cmd, char ***cmd_with_options_arr)
{
	char	*path_with_cmd;

	while (*path)
	{
		path_with_cmd = ft_strjoin(*path, "/");
		path_with_cmd = ft_strjoin_freed(path_with_cmd, *cmd_with_options_arr[0]);
		if (access(path_with_cmd, F_OK) == 0)
		{
			*full_path_cmd = ft_strdup(path_with_cmd);
			free(path_with_cmd);
			path_with_cmd = NULL;

//			free(path);
//			path = NULL;
//			free(*cmd_with_options_arr[0]);
//			*cmd_with_options_arr[0] = NULL;
//			*cmd_with_options_arr[0] = ft_strdup(cmd);
//			free(cmd);
//			if (!*cmd_with_options_arr[0])
//			{
//				ft_putstr_fd("array allocation failed\n", 2);
//				return (-1);
//			}
			return (0);
		}

		free(path_with_cmd);
		path_with_cmd = NULL;
		path ++;
	}
//	free(path);
	ft_putstr_fd("command not found\n", 2);
	return (-1);
}

