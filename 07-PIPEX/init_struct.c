#include "pipex.h"

void	init_struct(t_main_struct **main_struct, int argc)
{
//	t_files	*files;
//	t_cmd	*cmd;

	*main_struct = ft_calloc(1, sizeof(t_main_struct));
	if (!*main_struct)
	{
		ft_putstr_fd("structure allocation failed\n", 2);
		exit (EXIT_FAILURE);
	}
	(*main_struct)-> argv_number = argc - 1;
	(*main_struct)->cmd_with_options_arr = ft_calloc((*main_struct)->argv_number - 1, sizeof(char**));
	if (!(*main_struct)->cmd_with_options_arr)
	{
		ft_putstr_fd("array allocation failed\n", 2);
		error_handling(*main_struct);
	}
	(*main_struct)->full_path_cmd = ft_calloc((*main_struct)->argv_number - 1, sizeof(char*));
	if (!(*main_struct)->full_path_cmd)
	{
		ft_putstr_fd("array allocation failed\n", 2);
		error_handling(*main_struct);
	}
	(*main_struct)->fd_input = 0;
	(*main_struct)->fd_output = 0;

/*	init_t_files(&files);
	(*main_struct)->files = files;
	init_t_cmd(&cmd);
	(*main_struct)->cmd = cmd;*/
}

void	init_t_files(t_files **files)
{
	*files = ft_calloc(1, sizeof(t_files));
	if (!*files)
	{
		ft_putstr_fd("structure allocation failed\n", 2);
		exit (EXIT_FAILURE);
	}
	(*files)->infile = NULL;
	(*files)->outfile = NULL;
	(*files)->fd_input = -1;
	(*files)->fd_output = -1;
}

void	init_t_cmd(t_cmd **cmd)
{
	*cmd = ft_calloc(1, sizeof(t_cmd));
	if (!*cmd)
	{
		ft_putstr_fd("structure allocation failed\n", 2);
		exit (EXIT_FAILURE);
	}
	(*cmd)->full_path_cmd1 = NULL;
	(*cmd)->full_path_cmd2 = NULL;
	(*cmd)->cmd1_with_options_arr = NULL;
	(*cmd)->cmd2_with_options_arr = NULL;
}
