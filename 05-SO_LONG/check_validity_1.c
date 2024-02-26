/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:19:43 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/26 14:47:06 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_file(char *str)
{
	char	*st;
	int		fd;

	fd = 0;
	st = ft_strrchr(str, '.');
	if (ft_strcmp(st, ".ber") != 0)
	{
		ft_putstr_fd("Error\nType of map file is not correct\n", 1);
		exit(EXIT_FAILURE);
	}
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nMap file couldn't be opened\n", 1);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

void	check_map_validity(t_window *t_win, char *argv)
{
	t_win->fd = open(argv, O_RDONLY);
	size_of_map(t_win);
	close(t_win->fd);
	t_win->fd = open(argv, O_RDONLY);
	read_map(t_win);
	close(t_win->fd);
	build_tab(t_win);
	verify_columns_and_lines(t_win);
	verify_invalid_z(t_win);
	verify_extern_wall_1(t_win);
	verify_extern_wall_2(t_win);
	verify_nb_collectibles(t_win);
	verify_nb_exit(t_win);
	verify_nb_character(t_win);
	find_image_p(t_win);
	verify_way_validity(t_win);
}

void	verify_columns_and_lines(t_window *t_win)
{
	int		j;

	j = 0;
	while (t_win->tab[j])
	{
		if (ft_strlen(t_win->tab[j]) == t_win->nb_columns)
			j++;
		else
			free_t_win(t_win, "Error\nMap is not rectangular\n");
	}
}

void	verify_invalid_z(t_window *t_win)
{
	int		i;
	int		j;

	j = 0;
	while (t_win->tab[j])
	{
		i = 0;
		while (t_win->tab[j][i])
		{
			if (t_win->tab[j][i] != '0' && t_win->tab[j][i] != '1'
				&& t_win->tab[j][i] != '2' && t_win->tab[j][i] != 'C'
				&& t_win->tab[j][i] != 'E' && t_win->tab[j][i] != 'P')
				free_t_win(t_win, "Error\nThere is an invalid character \
					in the map\n");
			i++;
		}
		j++;
	}
}

void	verify_extern_wall_1(t_window *t_win)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (t_win->tab[j][i] && t_win->tab[j][i] != '\n')
	{
		if (t_win->tab[j][i] == '1')
			i++;
		else
			free_t_win(t_win, "Error\nExtern wall isn't complete\n");
	}
	i = 0;
	j = t_win->nb_lines - 1;
	while (t_win->tab[j][i] && t_win->tab[j][i] != '\n')
	{
		if (t_win->tab[j][i] == '1')
			i++;
		else
			free_t_win(t_win, "Error\nExtern wall isn't complete\n");
	}
}
