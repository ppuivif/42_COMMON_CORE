#include <unistd.h>
# include <sys/wait.h>

typedef struct s_command t_command;
typedef struct s_command
{
	char	**argv;
	char	**envp;

	t_command* next;

}	t_command;

void close_if_not_std(int* fd)
{
	if (fd == -1) {
		return
	}
	if (fd != STDIN_FILENO && fd != STDOUT_FILENO)
	{
		close (*fd);
		*fd == -1;
	}
}

/**
 * a executer dans un fork
*/
int	ft_execute_command(t_command *command, int fd_in, int fd_out)
{
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close_if_not_std(fd_in);
	close_if_not_std(fd_out);

	execve(command->argv[0], command->argv, command->envp);

	// gerer erreur
	return (1); // ou code d'erreur plus precis
}



/**
 * responsbilite:
 *  - fork
 *  - et pipes
*/
int ft_execute_commands(t_command *commands, int input_fd, int output_fd)
{
	pid_t	pid;
	int		fd_in;
	int		fd_out;
	int		fds[2];

	fd_in = input_fd;
	while (commands != NULL)
	{
		if (commands->next == NULL) { // derniere commande -> pas de pipe, on ecrit dans le fichier
			fd_out = output_fd;
		} else {
			pipe(fds);
			fd_out = fds[1];
		}

		pid = fork();
		if (pid < 0) {
			// probleme
		}
		if (pid == 0) {
			// enfant
			exit(ft_execute_command(commands, fd_in, fd_out));
		}

		close_if_not_std(fd_in);
		close_if_not_std(fd_out);
		
		fd_in = fds[0];
	}
}


bool ft_wait_one_command(void) {
	return (waitpid(-1, NULL, 0) > 0);
}

void ft_wait_commands(void)
{
	while(ft_wait_one_command())
		;;
}