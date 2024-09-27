
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>//to delete


void fatal_error_handling()
{
	write(2, "error: fatal\n", 12);
	exit(EXIT_FAILURE);
}

void execve_error_handling(char *str)
{
	write(2, "error: cannot execute ", 22);
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	close_fd(int fd)
{
	if (fd && fd > 2)
	{
		if (close(fd) == -1)
			fatal_error_handling();
	}
}

void	child_execution(char **argv, int i, int *fd, int has_pipe, char **envp)
{
	argv[i] = NULL;
	if (has_pipe)
	{
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			fatal_error_handling();
		close_fd(fd[0]);
		close_fd(fd[1]);
	}
	if (!strcmp(argv[0], "cd"))
	{
//		buitin_cd(argv);
		return;
	}
	execve(argv[0], argv, envp);
	execve_error_handling(argv[0]);
}

void	execution(char **argv, int i, int has_pipe, char **envp)
{
	int	fd[2];
	int pid;

	if (!strcmp(argv[0], "cd"))
	{
//		buitin_cd(argv);
		return;
	}
	if (has_pipe && pipe(fd) == -1)
		fatal_error_handling();
	pid = fork();
	if (pid == -1)
		fatal_error_handling();
	if (!pid)
		child_execution(argv, i, fd, has_pipe, envp);
	while (waitpid(-1, NULL, 0) != -1)
		continue ;
//	write(2, "here\n", 5);
	if (has_pipe)
	{
		if (dup2(fd[0], STDIN_FILENO) == -1)
			fatal_error_handling();
		close_fd(fd[0]);
		close_fd(fd[1]);
	}
}

int main(int argc, char **argv, char **envp)
{
    int i;
	int has_pipe;

    (void)argc;
	i = 0;
	has_pipe = 0;
    while (argv[i])
    {
		argv += i + 1;
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (argv[i] && !strcmp(argv[i], "|"))
			has_pipe = 1;
		if (i)
			execution(argv, i, has_pipe, envp);
    }
    return (0);
}