#include "includes/pipex.h"

void	check_files(char **argv)
{
	int	fd_input;
	int	fd_output;

	fd_output = open(argv[4], O_WRONLY | O_CREAT, 0644);
	if (fd_output == -1)
	{
		perror("Outfile couldn't be opened");
		exit(EXIT_FAILURE);
	}
	fd_input = open(argv[1], O_RDONLY);
	if (fd_input == -1)
	{
		if (access(argv[1], F_OK) == -1)
			perror("Infile doesn't exist");
		else
			perror("Infile couldn't be opened");
	}
	if (fd_output != -1)
		close(fd_output);
	if (fd_input != -1)
		close(fd_input);
}

void	check_cmd(char **argv, char **envp)
{
	char *path;

	path = search_path(envp);
	if (!path)
		printf("path not found\n");//to delete
	else
		printf("%s\n", path);//to delete


}

char	*search_path(char **envp)
{
	int i;
	char *path;
	
	path = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			path = ft_strchr(envp[i], '/');
			return (path);
		}
		else
			i++;
	}
	return (path);
}
