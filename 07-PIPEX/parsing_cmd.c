/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:52:14 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/14 17:55:55 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	build_full_path_cmd_arr(char **argv, char **envp,
		t_main_struct *main_struct)
{
	build_cmd_arr(argv[2], &main_struct->cmd1_arr);
	if (main_struct->cmd1_arr && main_struct->cmd1_arr[0])
	{
		if (access(main_struct->cmd1_arr[0], F_OK) != 0)
			check_full_path_in_envp(&main_struct->cmd1_arr, envp);
	}
	build_cmd_arr(argv[3], &main_struct->cmd2_arr);
	if (main_struct->cmd2_arr && main_struct->cmd2_arr[0])
	{
		if (access(main_struct->cmd2_arr[0], F_OK) != 0)
			check_full_path_in_envp(&main_struct->cmd2_arr, envp);
	}
}

void	build_cmd_arr(char *argv, char ***cmd_arr)
{
	*cmd_arr = ft_split(argv, ' ');
	if (!**cmd_arr || !*cmd_arr[0])
		ft_putstr_fd("command not found\n", 2);
}

int	check_full_path_in_envp(char ***cmd_arr, char **envp)
{
	char	**path;

	path = search_path(envp);
	if (!path)
	{
		ft_putstr_fd("path doesn't exist in envp\n", 2);
		return (1);
	}
	if (check_path_cmd_validity(path, cmd_arr) == 0)
	{
		free_arr(path);
		return (0);
	}
	free_arr(path);
	return (-1);
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

int	check_path_cmd_validity(char **path, char ***cmd_arr)
{
	char	*path_with_cmd;

	while (*path)
	{
		path_with_cmd = ft_strjoin(*path, "/");
		path_with_cmd = ft_strjoin_freed(path_with_cmd, *cmd_arr[0]);
		if (access(path_with_cmd, F_OK) == 0)
		{
			free(*cmd_arr[0]);
			*cmd_arr[0] = NULL;
			*cmd_arr[0] = ft_strdup(path_with_cmd);
			free (path_with_cmd);
			path_with_cmd = NULL;
			return (0);
		}
		free (path_with_cmd);
		path_with_cmd = NULL;
		path ++;
	}
	free (path_with_cmd);
	path_with_cmd = NULL;
	ft_putstr_fd("command not found\n", 2);
	return (-1);
}
