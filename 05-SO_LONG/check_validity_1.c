/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:19:43 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/23 17:52:54 by ppuivif          ###   ########.fr       */
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
	t_win->tab_cpy = ft_tab_cpy(t_win);
	build_tab(t_win);
	free_tab(t_win->tab);
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

size_t	ft_strlen_nl(char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len] && str[len] != '\n')
		len++;
	return (len);
}

void	verify_columns_and_lines(t_window *t_win)
{
	int		j;

	j = 0;
	while (t_win->tab_cpy[j])
	{
		if (ft_strlen_nl(t_win->tab_cpy[j]) == t_win->nb_columns)
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
	while (t_win->tab_cpy[j])
	{
		i = 0;
		while (t_win->tab_cpy[j][i])
		{
			if (t_win->tab_cpy[j][i] != '0' && t_win->tab_cpy[j][i] != '1'
				&& t_win->tab_cpy[j][i] != '2' && t_win->tab_cpy[j][i] != 'C'
				&& t_win->tab_cpy[j][i] != 'E' && t_win->tab_cpy[j][i] != 'P'
				&& t_win->tab_cpy[j][i] != '\n')
				free_t_win(t_win, "Error\nThere is an invalid character \
					in the map\n");
			i++;
		}
		j++;
	}
}
