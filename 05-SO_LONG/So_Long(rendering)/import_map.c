/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:22:26 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/26 14:32:50 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	size_of_map(t_window *t_win)
{
	char	*tmp;

	tmp = get_next_line(t_win->fd);
	if (!tmp)
	{
		free_t_win(t_win, "Error\nMap couldn't be read\n");
		exit (EXIT_FAILURE);
	}
	t_win->nb_columns = ft_strlen(tmp) - 1;
	free(tmp);
	tmp = NULL;
	t_win->nb_lines = 1;
	tmp = get_next_line(t_win->fd);
	while (tmp)
	{
		free(tmp);
		tmp = NULL;
		tmp = get_next_line(t_win->fd);
		t_win->nb_lines += 1;
	}
	free(tmp);
	tmp = NULL;
}

void	read_map(t_window *t_win)
{
	unsigned int	j;

	j = 0;
	t_win->tab = ft_calloc((t_win->nb_lines + 1), sizeof (char *));
	if (!t_win->tab)
	{
		free_t_win(t_win, "Error\nArray tab couldn't be created\n");
		exit (EXIT_FAILURE);
	}
	while (j < t_win->nb_lines)
	{
		t_win->tab[j] = ft_strtrim(get_next_line(t_win->fd), "\n");
		j++;
	}
	close (t_win->fd);
}

void	build_tab(t_window *t_win)
{
	unsigned int		i;
	unsigned int		j;

	t_win->tab_modified = ft_tab_cpy(t_win);
	j = 1;
	while (t_win->tab_modified[j])
	{
		i = 1;
		while (t_win->tab_modified[j][i])
		{
			if (j != (t_win->nb_lines - 1) && i != (t_win->nb_columns - 1) && \
			t_win->tab_modified[j][i] == '1')
				t_win->tab_modified[j][i] = '2';
			i++;
		}
		j++;
	}
}

char	**ft_tab_cpy(t_window *t_win)
{
	unsigned int	j;
	char			**new_tab;

	j = 0;
	new_tab = ft_calloc(t_win->nb_lines + 1, sizeof(char *));
	if (!new_tab)
	{
		free_t_win(t_win, "Error\nArray new_tab couldn't be created\n");
		exit (EXIT_FAILURE);
	}
	while (j < t_win->nb_lines && t_win->tab[j])
	{
		new_tab[j] = ft_strdup(t_win->tab[j]);
		j++;
	}
	return (new_tab);
}
