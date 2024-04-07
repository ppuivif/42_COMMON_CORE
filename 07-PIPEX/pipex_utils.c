#include "pipex.h"

void	check_files(char **argv)
{
	int	fd_input;
	int	fd_output;

	fd_output = open(argv[4], O_WRONLY | O_CREAT, 0644);
	if (fd_output == -1)
	{
		perror("outfile couldn't be opened");
		exit(EXIT_FAILURE);
	}
	fd_input = open(argv[1], O_RDONLY);
	if (fd_input == -1)
	{
		if (access(argv[1], F_OK) == -1)
			perror("infile doesn't exist");
		else
			perror("infile couldn't be opened");
	}
	if (fd_output != -1)
		close(fd_output);
	if (fd_input != -1)
		close(fd_input);
}

void 	build_full_path_cmd_arr(char **argv, char **envp)
{
	char **cmd1_with_options_arr;
	char **cmd2_with_options_arr;



	cmd1_with_options_arr = build_cmd_arr(argv[2]);
	if (cmd1_with_options_arr == NULL)
		ft_putstr_fd("cmd1 couldn't be read", 2);
	cmd2_with_options_arr = build_cmd_arr(argv[3]);
	if (cmd2_with_options_arr == NULL)
		perror("cmd2 couldn't be read");

	if (verify_existing_path_in_cmd(cmd1_with_options_arr) == 1)
		check_full_path_in_envp(cmd1_with_options_arr, envp);
	if (verify_existing_path_in_cmd(cmd2_with_options_arr) == -1)
			exit(EXIT_FAILURE);
	if (verify_existing_path_in_cmd(cmd2_with_options_arr) == 1)
	{
		if (check_full_path_in_envp(cmd2_with_options_arr, envp) == -1)
			exit (EXIT_FAILURE);
	}

	printf("cmd1 : %s\n", cmd1_with_options_arr[0]);
	printf("cmd1 1st option : %s\n", cmd1_with_options_arr[1]);
	printf("cmd2 : %s\n", cmd2_with_options_arr[0]);
	printf("cmd2 1st option : %s\n", cmd2_with_options_arr[1]);
}

char	**build_cmd_arr(char *argv)
{
	char **cmd_with_options_arr;
	int i;
	size_t	len;
	
	i = 0;
	cmd_with_options_arr = ft_split(argv, ' ');
	while (cmd_with_options_arr && cmd_with_options_arr[i])
	{
		if (cmd_with_options_arr[i][0] == 39)
		{
			len = ft_strlen((cmd_with_options_arr[i] + 1)) \
				- ft_strlen(ft_strrchr(cmd_with_options_arr[i], 39));
			cmd_with_options_arr[i] = ft_substr_freed(cmd_with_options_arr[i], 1, len);//to free
		}
		i++;
	}
	return(cmd_with_options_arr);			
}

int	verify_existing_path_in_cmd(char **cmd_with_options_arr)
{
	char	*cmd;

	if (cmd_with_options_arr[0][0] == '/')
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

int	check_full_path_in_envp(char **cmd_with_options_arr, char **envp)	
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
	int i;
	char **path;
	
	path = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			path = ft_split(ft_strchr(envp[i], '/'), ':');//to free
			return (path);
		}
		else
			i++;
	}
	return (path);
}

int	check_path_cmd_validity(char **path, char **cmd_with_options_arr)
{
	int 	i;
	char	*cmd;

	i = 0;
	while (path[i])
	{
		cmd = ft_strjoin(path[i], "/");
		cmd = ft_strjoin_freed(cmd, cmd_with_options_arr[0]);
		if (access(cmd, F_OK) == 0)
		{
			free(cmd);
			return (0);
		}
		free(cmd);
		cmd = NULL;
		i++;			
	}
	ft_putstr_fd("no valid path for the command or invalid command\n", 2);
	return (-1);
}