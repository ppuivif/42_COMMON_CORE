#include "pipex.h"

void	init_struct(t_main_struct **main_struct)
{
	t_files	*files;
	t_cmd	*cmd;

	*main_struct = ft_calloc(1, sizeof(t_main_struct));
	if (!*main_struct)
	{
		ft_putstr_fd("structure allocation failed\n", 2);
		exit (EXIT_FAILURE);
	}
	init_t_files(&files);
	(*main_struct)->files = files;
	init_t_cmd(&cmd);
	(*main_struct)->cmd = cmd;
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
