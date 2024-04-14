/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:43:58 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/14 11:54:33 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

# include "LIBFT/libft.h"

typedef struct s_main_struct
{
	int		fd_input;
	int		fd_output;
	char	**cmd1_arr;
	char	**cmd2_arr;
}t_main_struct;

void	check_files(char **argv, t_main_struct *main_struct);
void	build_full_path_cmd_arr(char **argv, char **envp,
			t_main_struct *main_struct);
void	build_cmd_arr(char *argv, char ***cmd_arr);
int		check_full_path_in_envp(char ***cmd_arr, char **envp);
char	**search_path(char **envp);
int		check_path_cmd_validity(char **path, char ***cmd_arr);

void	init_struct(t_main_struct **main_struct);
void	execution(t_main_struct *main_struct, char **envp);
void	exec_child1(t_main_struct *main_struct, int *fd, char **envp);
void	exec_parent(t_main_struct *main_struct, int *fd, char **envp);
void	exec_child2(t_main_struct *main_struct, int *fd, char **envp);

void	success_handling(t_main_struct *main_struct);
void	error_handling(t_main_struct *main_struct);
void	free_all(t_main_struct *main_struct);
void	free_arr(char **str_arr);

#endif