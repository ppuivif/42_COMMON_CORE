#include "pipex.h"

void	free_arr(char **str_arr)
{
	int	i;

	i = 0;
	while ((str_arr)[i])
	{
		free(str_arr[i]);
		i++;
	}
	if (str_arr)
		free(str_arr);
	str_arr = NULL;
}

void	success_handling(t_main_struct *main_struct)
{
	free_all(main_struct);
	exit (EXIT_SUCCESS);
}

void	error_handling(t_main_struct *main_struct)
{
	free_all(main_struct);
	exit (EXIT_FAILURE);
}

void	free_all(t_main_struct *main_struct)
{
	int	i;

	i = 0;
	if (main_struct->fd_input)
		close(main_struct->fd_input);
	if (main_struct->fd_output)
		close(main_struct->fd_output);
	while (i < main_struct->argv_number - 1)
	{
		if (main_struct->cmd_with_options_arr[i])
			free_arr(main_struct->cmd_with_options_arr[i]);
		if (main_struct->full_path_cmd[i])
			free(main_struct->full_path_cmd[i]);
		i++;
	}	
	if (main_struct->cmd_with_options_arr)
		free(main_struct->cmd_with_options_arr);
	if (main_struct->full_path_cmd)
		free(main_struct->full_path_cmd);
	if (main_struct)
		free(main_struct);
}

/*	if (main_struct->files->fd_output != -1)
		close(main_struct->files->fd_output);
	if (main_struct->files->fd_input != -1)
		close(main_struct->files->fd_input);*/
