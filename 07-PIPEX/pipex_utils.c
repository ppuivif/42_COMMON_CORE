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

void 	build_full_path_cmd_arr(char **argv, char **envp, t_main_struct *main_struct)
{
	char **cmd1;
	char **cmd2;

	cmd1 = main_struct->cmd->cmd1_with_options_arr;
	cmd2 = main_struct->cmd->cmd2_with_options_arr;
	cmd2 = build_cmd_arr(argv[3]);
	if (cmd2 == NULL)
		error_handling(main_struct);
	cmd1 = build_cmd_arr(argv[2]);
	if (cmd1 != NULL)
	{
		if (verify_existing_path_in_cmd(cmd1) == 1)
			check_full_path_in_envp(&cmd1, envp);
	}
	if (verify_existing_path_in_cmd(cmd2) == -1)
		error_handling(main_struct);
	if (verify_existing_path_in_cmd(cmd2) == 1)
	{
		if (check_full_path_in_envp(&cmd2, envp) == -1)
			error_handling(main_struct);
	}
	int i = 0;
	while (cmd1 && cmd1[i])
	{
		printf("%s\n", cmd1[i]);
		i++;
	}
	printf("cmd2 : %s\n", cmd2[0]);
	printf("cmd2 1st option : %s\n", cmd2[1]);
}

char	**build_cmd_arr(char *arg)
{
	char **cmd_with_options_arr;
	int i;
	
	i = 0;
	cmd_with_options_arr = ft_split(arg, ' ');
	if (!cmd_with_options_arr || !cmd_with_options_arr[0])
	{
		ft_putstr_fd("command not found\n", 2);
		return(NULL);		
	}
	while (cmd_with_options_arr && cmd_with_options_arr[i])
	{
		cmd_with_options_arr[i] = ft_strdup(ft_skip_chr(cmd_with_options_arr[i], 39));
		i++;
	}
	return(cmd_with_options_arr);
}

char *ft_skip_chr(char *str, char c)
{
	size_t	len;
	char	*s;

	len = ft_strlen(str);
	if (str[0] == c && str[len - 1] == c)
	{
		s = ft_substr_freed(str, 1, len - 2);
		return (s);
	}
	return (str);
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

int	check_path_cmd_validity(char **path, char ***cmd_with_options_arr)
{
	int 	i;
	char	*cmd;

	i = 0;
	while (path[i])
	{
		cmd = ft_strjoin(path[i], "/");
		cmd = ft_strjoin_freed(cmd, *cmd_with_options_arr[0]);
		if (access(cmd, F_OK) == 0)
		{
			*cmd_with_options_arr[0] = ft_strdup(cmd);
			free(cmd);
			if (!*cmd_with_options_arr[0])
			{
				ft_putstr_fd("array allocation failed\n", 2);
				return (-1);
			}
			return (0);
		}
		free(cmd);
		cmd = NULL;
		i++;			
	}
	ft_putstr_fd("command not found\n", 2);
	return (-1);
}

/*void	create_child1(char *file_input, char *path, char **cmd1_with_options_arr, char **envp)
{
	int	fd[2];
	pid_t pid;
	
	if (pipe(fd) == -1)
	{
		perror("create pipe failed");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (!pid)
	{
		perror("create fork failed");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		int fd_input;
		fd_input = open(file_input, O_RDONLY);

//		free;
//		close;
		execve(path, cmd1_with_options_arr, envp);
	}



}*/
