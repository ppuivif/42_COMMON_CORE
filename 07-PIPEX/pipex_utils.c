#include "includes/pipex.h"

void	check_files(char **argv)
{
	int	fd_input;
	int	fd_output;

	if (access(argv[1], F_OK) == -1)
		perror("Infile doesn't exist");
	fd_input = open(argv[1], O_RDONLY);
	if (fd_input == -1)
	{
		perror("Infile couldn't be opened");
		exit(EXIT_FAILURE);
	}
	fd_output = open(argv[4], O_WRONLY | O_CREAT, 0644);
	if (fd_output == -1)
	{
		perror("Outfile couldn't be opened");
		exit(EXIT_FAILURE);//util ?
	}

}