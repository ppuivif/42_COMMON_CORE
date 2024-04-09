#include "pipex.h"


void	create_child1(t_main_struct *main_struct, char **envp)
{
	int	fd[2];
	pid_t pid1;
	char **cmd1;
	
	if (pipe(fd) == -1)
	{
		perror("create pipe failed");
		error_handling(main_struct);
	}

	pid1 = fork();
	if (pid1 == -1)
	{
		perror("create fork failed");
		error_handling(main_struct);
	}
	if (pid1 == 0)//child1 process
	{
		close(fd[0]);
		close(main_struct->files->fd_output);
		dup2(main_struct->files->fd_input, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		cmd1 = main_struct->cmd->cmd1_with_options_arr;
		execve(cmd1[0], cmd1, envp);
		close(main_struct->files->fd_input);
		close(fd[1]);
		success_handling(main_struct);
	}
	else //parent process
	{
		char *buf;
		buf = NULL;
		waitpid(pid1, NULL, 0);
		read(fd[0], buf, 100);
		printf("%s\n", buf);
		close(fd[0]);
		success_handling(main_struct);


	}	
}