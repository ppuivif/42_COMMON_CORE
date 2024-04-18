/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:52:14 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/18 18:33:02 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	build_full_path_cmd_arr(char **argv, char **envp,
		t_main_struct *main_struct)
{
	if (main_struct->error_infile == 0)
		main_struct->exit_status = build_cmd_arr(argv[2], &main_struct->cmd1_arr, \
			&main_struct->path1, envp);
	if (main_struct->error_outfile == 0)
		main_struct->exit_status = build_cmd_arr(argv[3], &main_struct->cmd2_arr, \
			&main_struct->path2, envp);
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
	else
	{
		if (access(*cmd_arr[0], F_OK) == 0)
		{
			*cmd_path = ft_strdup(*cmd_arr[0]);
			if (!*cmd_path)
				ft_putstr_fd("error\npath couldn't be created\n", 2);
			return (1);
		}
		else
		{
			error_path = 1;
			return (check_full_path_in_envp(cmd_arr, cmd_path, envp, error_path));
		}
	}
}

int	check_full_path_in_envp(char ***cmd_arr, char **cmd_path, char **envp, int error_path)
{
	int		exit_status;
	char	**path_envp;

	exit_status = 0;
	path_envp = search_path(envp);
	if (!path_envp || !path_envp[0])
	{
		ft_putstr_fd("error\npath doesn't exist in envp\n", 2);
		return (1);
	}
	exit_status = check_path_cmd_validity(path_envp, cmd_arr, cmd_path, error_path);
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

int	check_path_cmd_validity(char **path, char ***cmd_arr, char **cmd_path, int error_path)
{
	char	*path_with_cmd;

	while (*path)
	{
		path_with_cmd = NULL;
		path_with_cmd = ft_strjoin(*path, "/");
		path_with_cmd = ft_strjoin_freed(path_with_cmd, *cmd_arr[0]);
		if (!path_with_cmd || !path_with_cmd[0])
			ft_putstr_fd("error\nat least one path couldn'be checked \
			in envp\n", 2);
		if (access(path_with_cmd, F_OK) == 0)
		{
			*cmd_path = ft_strdup(path_with_cmd);
			if (!cmd_path)
				ft_putstr_fd("error\nat least one path couldn'be checked\
				in envp\n", 2);
			free (path_with_cmd);
			return (0);
		}
		free (path_with_cmd);
		path ++;
	}
	if (error_path == 1)//to check if nexcessary
	{
		ft_putstr_fd(*cmd_arr[0], 2);
		ft_putstr_fd(": command not found\n", 2);
//		perror(*cmd_arr[0]);
	}
	else
	{
		ft_putstr_fd(*cmd_arr[0], 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	return (127);
}
