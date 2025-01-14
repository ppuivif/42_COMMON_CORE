/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cmd_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:52:14 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/19 10:02:06 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	build_full_path_cmd_arr(char **argv, char **envp,
		t_main_struct *main_struct)
{
	if (main_struct->error_infile == 0)
		main_struct->exit_status = build_cmd_arr(argv[2], \
		&main_struct->cmd1_arr, &main_struct->path1, envp);
	if (main_struct->error_outfile == 0)
		main_struct->exit_status = build_cmd_arr(argv[3], \
		&main_struct->cmd2_arr, &main_struct->path2, envp);
	else
		main_struct->exit_status = 1;
}

int	build_cmd_arr(char *argv, char ***cmd_arr, char	**cmd_path, char **envp)
{
	int	error_path;

	error_path = 0;
	*cmd_arr = ft_split(argv, ' ');
	if (!**cmd_arr || !*cmd_arr[0])
	{
		ft_putstr_fd(*cmd_arr[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		return (127);
	}
	if (access(*cmd_arr[0], F_OK) == 0)
	{
		*cmd_path = ft_strdup(*cmd_arr[0]);
		if (!*cmd_path)
		{
			ft_putstr_fd("error\npath couldn't be created\n", 2);
			return (1);
		}
		return (0);
	}
	if (ft_strchr(*cmd_arr[0], '/') != 0)
		error_path = 1;
	return (check_full_path_in_envp(cmd_arr, cmd_path, envp, error_path));
}

int	check_full_path_in_envp(char ***cmd_arr, char **cmd_path, \
char **envp, int error_path)
{
	int		exit_status;
	char	**path_envp;

	exit_status = 0;
	path_envp = search_path(envp);
	if (!path_envp || !path_envp[0])
	{
		perror(*cmd_arr[0]);
		return (127);
	}
	exit_status = check_path_cmd_validity(path_envp, cmd_arr, \
		cmd_path, error_path);
	free_arr(path_envp);
	return (exit_status);
}

char	**search_path(char **envp)
{
	int		i;
	char	**path;

	path = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			path = ft_split(ft_strchr(envp[i], '/'), ':');
			return (path);
		}
		else
			i++;
	}
	return (path);
}
