/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:44:03 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/19 09:23:33 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_main_struct	*main_struct;
	int				exit_status;

	exit_status = 0;
	if (!envp || !envp[0])
	{
		ft_putstr_fd("error\nenvp doesn't exists or is empty\n", 2);
		exit(EXIT_FAILURE);
	}
	if (argc != 5)
	{
		ft_putstr_fd("error\nnumber of arguments isn't valid\n", 2);
		exit(EXIT_FAILURE);
	}
	init_struct(&main_struct);
	check_files(argv, main_struct);
	build_full_path_cmd_arr(argv, envp, main_struct);
	execution(main_struct, envp);
	exit_status = main_struct->exit_status;
	free_all(main_struct);
	return (exit_status);
}
