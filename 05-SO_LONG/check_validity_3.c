/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:20:51 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/23 17:20:55 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	flood_fill(t_window *t_win)
{
	int	x;	
	int	y;

	x = t_win->x0_image_p;
	y = t_win->y0_image_p;
	if (t_win->tab_cpy[y - 1][x] != '1' && t_win->tab_cpy[y - 1][x] != '2')
	{
		t_win->tab_cpy[y - 1][x] = '1';
		t_win->y0_image_p -= 1;
		flood_fill(t_win);
		t_win->y0_image_p += 1;
	}
	if (t_win->tab_cpy[y][x - 1] != '1' && t_win->tab_cpy[y][x - 1] != '2')
	{
		t_win->tab_cpy[y][x - 1] = '1';
		t_win->x0_image_p -= 1;
		flood_fill(t_win);
		t_win->x0_image_p += 1;
	}
	if (t_win->tab_cpy[y + 1][x] != '1' && t_win->tab_cpy[y + 1][x] != '2')
	{
		t_win->tab_cpy[y + 1][x] = '1';
		t_win->y0_image_p += 1;
		flood_fill(t_win);
		t_win->y0_image_p -= 1;
	}
	if (t_win->tab_cpy[y][x + 1] != '1' && t_win->tab_cpy[y][x + 1] != '2')
	{
		t_win->tab_cpy[y][x + 1] = '1';
		t_win->x0_image_p += 1;
		flood_fill(t_win);
		t_win->x0_image_p -= 1;
	}
}

void	verify_way_validity(t_window *t_win)
{
	flood_fill(t_win);
	if (find_image(t_win, 'E') == 1 || find_image(t_win, 'C') == 1)
		free_t_win(t_win, "Error\nExit not reachable\n");
}
