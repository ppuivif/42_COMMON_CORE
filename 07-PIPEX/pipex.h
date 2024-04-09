/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:43:58 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/09 15:51:55 by ppuivif          ###   ########.fr       */
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

typedef struct s_files
{
	char	*infile;// to delete ?
	char	*outfile;// to delete ?
	int		fd_input;
	int		fd_output;
}t_files;

typedef struct s_cmd
{
	char	*full_path_cmd1;
	char	*full_path_cmd2;
	char	**cmd1_with_options_arr;
	char	**cmd2_with_options_arr;
}t_cmd;

typedef struct s_main_struct
{
	t_files	*files;
	t_cmd	*cmd;
}t_main_struct;

void	check_files(char **argv, t_main_struct *main_struct);
void	build_full_path_cmd_arr(char **argv, char **envp,
			t_main_struct *main_struct);
void	build_cmd_arr(char **argv, t_main_struct *main_struct);
int		verify_existing_path_in_cmd(char **cmd_with_options_arr);
int		check_full_path_in_envp(char ***cmd_with_options_arr, char **envp);
char	**search_path(char **envp);
int		check_path_cmd_validity(char **path, char ***cmd_with_options_arr);
void	check_and_skip_simple_cote(t_main_struct *main_struct);
void	ft_skip_chr(char *str, char c);

void	init_struct(t_main_struct **main_struct);
void	init_t_files(t_files **files);
void	init_t_cmd(t_cmd **cmd);

void	create_child1(t_main_struct *main_struct, char **envp);


void	success_handling(t_main_struct *main_struct);
void	error_handling(t_main_struct *main_struct);
void	free_all(t_main_struct *main_struct);
void	free_arr(char **str_arr);

#endif