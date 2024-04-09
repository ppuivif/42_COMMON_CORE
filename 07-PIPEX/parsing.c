#include "pipex.h"

void	check_files(char **argv, t_main_struct *main_struct)
{
	main_struct->files->fd_output = open(argv[4], O_WRONLY | O_CREAT, 0644);
	if (main_struct->files->fd_output == -1)
	{
		perror("outfile couldn't be opened");
		exit (EXIT_FAILURE);
	}
	main_struct->files->fd_input = open(argv[1], O_RDONLY);
	if (main_struct->files->fd_input == -1)
	{
		if (access(argv[1], F_OK) == -1)
			perror("infile doesn't exist");
		else
			perror("infile couldn't be opened");
	}
	if (main_struct->files->fd_output != -1)
		close(main_struct->files->fd_output);
	if (main_struct->files->fd_input != -1)
		close(main_struct->files->fd_input);
}

void	build_full_path_cmd_arr(char **argv, char **envp,
		t_main_struct *main_struct)
{
	char	**cmd1;
	char	**cmd2;
	char	*full_path_cmd1;
	char	*full_path_cmd2;
	


	build_cmd_arr(argv, main_struct);
	cmd1 = main_struct->cmd->cmd1_with_options_arr;
	cmd2 = main_struct->cmd->cmd2_with_options_arr;
	if (cmd2 == NULL)
		error_handling(main_struct);
	full_path_cmd1 = main_struct->cmd->full_path_cmd1;
	full_path_cmd2 = main_struct->cmd->full_path_cmd2;
	if (cmd1 != NULL)
	{
		if (verify_existing_path_in_cmd(&cmd1, &full_path_cmd1) == 1)
			check_full_path_in_envp(&cmd1, &full_path_cmd1, envp);
	}
	int flag2 = verify_existing_path_in_cmd(&cmd2. &full_path_cmd2))
	if (flag2 == -1)
		error_handling(main_struct);
	if (flag2 == 1)
	{
		if (check_full_path_in_envp(&cmd2, &full_path_cmd2, envp) == -1)
			error_handling(main_struct);
	}

	//to delete
	int	i = 0;
	while (cmd1 && cmd1[i])
	{
		printf("cmd1 : %s\n", cmd1[i]);
		i++;
	}
	i = 0;
	while (cmd2	&& cmd2[i])
	{
		printf("cmd2 : %s\n", cmd2[i]);
		i++;
	}
}

void	build_cmd_arr(char **argv, t_main_struct *main_struct)
{
	main_struct->cmd->cmd1_with_options_arr = ft_split(argv[2], ' ');
	main_struct->cmd->cmd2_with_options_arr = ft_split(argv[3], ' ');
	if (!main_struct->cmd->cmd1_with_options_arr
		|| !main_struct->cmd->cmd1_with_options_arr[0]
		|| !main_struct->cmd->cmd2_with_options_arr
		|| !main_struct->cmd->cmd2_with_options_arr[0])
		ft_putstr_fd("command not found\n", 2);
	else
		check_and_skip_simple_cote(main_struct);
}

void	check_and_skip_simple_cote(t_main_struct *main_struct)
{
	int	i;

	i = 0;
	while (main_struct->cmd->cmd1_with_options_arr
		&& main_struct->cmd->cmd1_with_options_arr[i])
	{
		ft_skip_chr(main_struct->cmd->cmd1_with_options_arr[i], 39);
		if (!main_struct->cmd->cmd1_with_options_arr[i])
			error_handling(main_struct);
		i++;
	}
	i = 0;
	while (main_struct->cmd->cmd2_with_options_arr
		&& main_struct->cmd->cmd2_with_options_arr[i])
	{
		ft_skip_chr(main_struct->cmd->cmd2_with_options_arr[i], 39);
		if (!main_struct->cmd->cmd2_with_options_arr[i])
			error_handling(main_struct);
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

int	verify_existing_path_in_cmd(char **cmd_with_options_arr)
{
	char	*cmd;

	if (ft_strchr(cmd_with_options_arr[0], '/') != 0)
	{
		cmd = cmd_with_options_arr[0];
		if (access(cmd, F_OK) == 0)
			return (0);
		else
		{
			ft_putstr_fd("given path isn't valid for the command\n", 2);
			return (-1);
		}
	}
	return (1);
}

int	check_full_path_in_envp(char ***cmd_with_options_arr, char **envp)
{
	char	**path;

	path = search_path(envp);
	if (!path)
	{
		ft_putstr_fd("path doesn't exist in envp\n", 2);
		free_arr(path);
		return (1);
	}
	if (check_path_cmd_validity(path, cmd_with_options_arr) == 0)
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

int	check_path_cmd_validity(char **path, char ***cmd_with_options_arr)
{
	char	*cmd;

	while (*path)
	{
		cmd = ft_strjoin(*path, "/");
		cmd = ft_strjoin_freed(cmd, *cmd_with_options_arr[0]);
		if (access(cmd, F_OK) == 0)
		{
			main_struct->cmd->full_path_cmd1 = ft_strdup(cmd);
			free(cmd);
			cmd = NULL;
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
		free(cmd);
		cmd = NULL;
		path ++;
	}
	ft_putstr_fd("command not found\n", 2);
	return (-1);
}

