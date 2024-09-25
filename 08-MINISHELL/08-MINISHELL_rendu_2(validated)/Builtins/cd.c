/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:23:16 by drabarza          #+#    #+#             */
/*   Updated: 2024/09/10 15:44:02 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*search_home(t_exec_struct *exec_struct)
{
	t_envp_struct	*env;

	env = exec_struct->envp_struct;
	while (env)
	{
		if (!ft_strncmp(env->name, "HOME", 4))
		{
			return (env->value);
		}
		env = env->next;
	}
	return (NULL);
}

static char	*search_or_replace_oldpwd(t_exec_struct *exec_struct, char *str)
{
	t_envp_struct	*env;

	env = exec_struct->envp_struct;
	while (env)
	{
		if (!ft_strncmp(env->name, "OLDPWD", 6))
		{
			if (!str)
				return (env->value);
			free(env->value);
			env->value = ft_strdup(str);
			return (NULL);
		}
		env = env->next;
	}
	if (!str)
	{
		exec_struct->command_line->current_exit_code = 1;
		return ("bash: cd: OLDPWD not set");
	}
	return (NULL);
}

static void	check_error(t_exec_struct *exec_struct, char *argument)
{
	if (errno == EACCES)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(argument, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	else if (access(argument, F_OK) == 0)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(argument, 2);
		ft_putstr_fd(": Not a directory\n", 2);
	}
	else
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(argument, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	exec_struct->command_line->current_exit_code = 1;
}

static int	cd_option(t_exec_struct *exec_struct, \
t_exec_argument *exec_arguments, size_t size, char *home)
{
	if (size == 1 || !ft_strcmp(exec_arguments->next->argument, "--")
		|| !ft_strcmp(exec_arguments->next->argument, "~"))
	{
		home = ft_strdup(search_home(exec_struct));
		if (!home)
		{
			ft_putstr_fd("cd: HOME not set\n", 2);
			exec_struct->command_line->current_exit_code = 1;
		}
		else if (chdir(home) == -1)
			check_error(exec_struct, home);
		free(home);
		return (1);
	}
	if (!ft_strcmp(exec_arguments->next->argument, "-"))
	{
		ft_putstr_fd(search_or_replace_oldpwd(exec_struct, NULL), 2);
		ft_putstr_fd("\n", 2);
		if (chdir(search_or_replace_oldpwd(exec_struct, NULL)) == -1)
			check_error(exec_struct, search_or_replace_oldpwd \
				(exec_struct, NULL));
		return (1);
	}
	return (0);
}

void	cd(t_exec_struct *exec_struct, t_exec_argument *exec_arguments)
{
	char	*old;
	size_t	size;
	char	*home;

	size = ft_lst_size9(exec_arguments);
	home = NULL;
	if (size > 2)
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		exec_struct->command_line->current_exit_code = 1;
		return ;
	}
	if (error_option(exec_struct, exec_arguments, "cd"))
		return ;
	if (cd_option(exec_struct, exec_arguments, size, home))
		return ;
	old = getcwd(NULL, 0);
	if (chdir(exec_arguments->next->argument) == -1)
	{
		check_error(exec_struct, exec_arguments->next->argument);
		free(old);
		return ;
	}
	search_or_replace_oldpwd(exec_struct, old);
	free(old);
}
