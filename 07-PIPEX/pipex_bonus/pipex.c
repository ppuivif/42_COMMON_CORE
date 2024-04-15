/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:44:03 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/15 19:29:48 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_main_struct	*main_struct;

	if (!envp || !envp[0])
	{
		ft_putstr_fd("error\nenvp doesn't exists or is empty\n", 2);
		exit(EXIT_FAILURE);
	}
	if (argc < 5)
	{
		ft_putstr_fd("error\nnumber of arguments isn't valid\n", 2);
		exit(EXIT_FAILURE);
	}
	init_main_struct(&main_struct);
	main_struct->nb_arg = argc - 1;
	check_files(argv, main_struct);
	build_full_path_cmd_arr(argv, envp, main_struct);
	execution(main_struct, envp);
	success_handling(main_struct);
}
