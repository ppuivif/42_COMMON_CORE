/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:43:58 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/07 20:56:13 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#include "LIBFT/libft.h"

typedef struct s_cmd
{
	char *path1;
	char *path2;
	char **cmd1_with_options_arr;
	char **cmd2_with_options_arr;
}t_cmd;

typedef struct s_main
{
	t_cmd cmd;
}t_main;


void	check_files(char **argv);
void	build_full_path_cmd_arr(char **cmd_with_options_arr, char **envp);
char	**build_cmd_arr(char *argv);
int		verify_existing_path_in_cmd(char **cmd_with_options_arr);
int		check_full_path_in_envp(char **cmd_with_options_arr, char **envp);
char	**search_path(char **envp);
int		check_path_cmd_validity(char **path, char **cmd_with_options_arr);


void	free_arr(char **str_arr);



#endif