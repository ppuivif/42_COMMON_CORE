/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cmd_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:23:16 by ppuivif           #+#    #+#             */
/*   Updated: 2024/04/19 09:23:17 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_path_cmd_validity(char **path, char ***cmd_arr, \
char **cmd_path, int error_path)
{
	char	*path_with_cmd;

	while (*path)
	{
		path_with_cmd = NULL;
		path_with_cmd = ft_strjoin(*path, "/");
		path_with_cmd = ft_strjoin_freed(path_with_cmd, *cmd_arr[0]);
		if (!path_with_cmd || !path_with_cmd[0])
			ft_putstr_fd("error\none path couldn'be checked in envp\n", 2);
		if (access(path_with_cmd, F_OK) == 0)
		{
			*cmd_path = ft_strdup(path_with_cmd);
			if (!cmd_path)
				ft_putstr_fd("error\none path couldn'be checked in envp\n", 2);
			free (path_with_cmd);
			return (0);
		}
		free (path_with_cmd);
		path ++;
	}
	return (no_path(*cmd_arr, error_path));
}

int	no_path(char **cmd_arr, int error_path)
{
	if (error_path == 1)
		perror(cmd_arr[0]);
	else
	{
		ft_putstr_fd(cmd_arr[0], 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	return (127);
}
