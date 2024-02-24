/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:20:51 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/24 16:37:50 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verify_nb_character(t_window *t_win)
{
	int		i;
	int		j;
	int		nb_char;

	j = 0;
	nb_char = 0;
	while (t_win->tab_cpy[j])
	{
		i = 0;
		while (t_win->tab_cpy[j][i])
		{
			if (t_win->tab_cpy[j][i] == 'P')
				nb_char++;
			i++;
		}
		j++;
	}
	if (nb_char != 1)
	{
		if (nb_char == 0)
			free_t_win(t_win, "Error\nCharacter is missing\n");
		else if (nb_char > 1)
			free_t_win(t_win, "Error\nThere are too many characters\n");
	}
}

void	find_image_p(t_window *t_win)
{
	int		i;
	int		j;

	j = 0;
	while (t_win->tab_cpy[j])
	{
		i = 0;
		while (t_win->tab_cpy[j][i])
		{
			if (t_win->tab_cpy[j][i] == 'P')
			{
				t_win->x0_image_p = i;
				t_win->y0_image_p = j;
				return ;
			}
			i++;
		}
		j++;
	}
}

int	find_image(t_window *t_win, char c)
{
	int		i;
	int		j;

	j = 0;
	while (t_win->tab_cpy[j])
	{
		i = 0;
		while (t_win->tab_cpy[j][i])
		{
			if (t_win->tab_cpy[j][i] == c)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

void	flood_fill(char **tab, unsigned int x, unsigned int y)
{
	tab[y][x] = '1';
	if (tab[y - 1][x] != '1' && tab[y - 1][x] != '2')
		flood_fill(tab, x, y - 1);
	if (tab[y][x - 1] != '1' && tab[y][x - 1] != '2')
		flood_fill(tab, x - 1, y);
	if (tab[y + 1][x] != '1' && tab[y + 1][x] != '2')
		flood_fill(tab, x, y + 1);
	if (tab[y][x + 1] != '1' && tab[y][x + 1] != '2')
		flood_fill(tab, x + 1, y);
}

void	verify_way_validity(t_window *t_win)
{
	flood_fill(t_win->tab_cpy, t_win->x0_begin, t_win->y0_begin);
	if (find_image(t_win, 'E') == 1 || find_image(t_win, 'C') == 1)
		free_t_win(t_win, "Error\nExit not reachable\n");
}
