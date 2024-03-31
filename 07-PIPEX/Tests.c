
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> // to delete
//#include <sys/types.h>
#include <sys/stat.h>

/*int	main()
{
	int	fd;

	fd = open("outfile.txt", O_WRONLY);// | O_APPEND) to add;//O_TRUNC to delete all content//O_CREATE 0644 to create with permissions if file doesn't exists
	dup2(fd, STDOUT_FILENO);
	close (fd);
	printf("test\n");
}*/

/*int main()
{
	chmod("outfile.txt", 0644);
	if (access("outfile.txt", R_OK) != -1)
		printf("I have permission to read\n");
	if (access("outfile.txt", R_OK) == -1)
		printf("I don't have permission to read\n");

 	if (access("outfile.txt", W_OK) != -1)
		printf("I have permission to write\n");
 	if (access("outfile.txt", W_OK) == -1)
		printf("I don't have permission to write\n");

 	if (access("outfile.txt", X_OK) != -1)
		printf("I have permission to execute\n");
 	if (access("outfile.txt", X_OK) == -1)
		printf("I don't have permission to execute\n");
 
	return (0);
}*/

/*int main()
{
	char *args[3];
 
	args[0] = "ls";
	args[1] = "-l";
	args[2] = NULL;
	execve("/bin/ls", args, NULL);
	printf("This line will not be executed.\n");
 
	return (0);
}*/

/*int main()
{
	pid_t pid;
 
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		printf("This is the child process. (pid: %d)\n", getpid());
	else
		printf("This is the parent process. (pid: %d)\n", getpid());
 
	return (0);
}*/

 
/*int main()
{
	int fd[2];
	pid_t pid;
	char buffer[13];
 
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
 
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
 
	if (pid == 0)
	{
		close(fd[0]); // close the read end of the pipe
		write(fd[1], "Hello parent!", 13);
		close(fd[1]); // close the write end of the pipe
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(fd[1]); // close the write end of the pipe
		read(fd[0], buffer, 13);
		close(fd[0]); // close the read end of the pipe
		printf("Message from child: '%s'\n", buffer);
		exit(EXIT_SUCCESS);
	}
}*/

/*int main()
{
	if (unlink("example.txt") == 0)
		printf("File successfully deleted");
	else
		printf("Error deleting file");
 
	return (0);
}*/

 
int main(int argc, char *argv[])
{
	pid_t pid;
 
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		printf("I am the child process.\n");
		sleep(2);
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("I am the parent process.\n");
		wait(NULL);
		printf("Child process terminated after a 2s delay.\n");
	}
 
	return (EXIT_SUCCESS);
}
