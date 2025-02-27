/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:19:53 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/26 14:45:40 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verify_extern_wall_2(t_window *t_win)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (t_win->tab[j])
	{
		if (t_win->tab[j][i] == '1')
			j++;
		else
			free_t_win(t_win, "Error\nExtern wall isn't complete\n");
	}
	i = t_win->nb_columns - 1;
	j = 0;
	while (t_win->tab[j])
	{
		if (t_win->tab[j][i] == '1')
			j++;
		else
			free_t_win(t_win, "Error\nExtern wall isn't complete\n");
	}
}

void	verify_nb_collectibles(t_window *t_win)
{
	int		i;
	int		j;

	j = 0;
	while (t_win->tab[j])
	{
		i = 0;
		while (t_win->tab[j][i])
		{
			if (t_win->tab[j][i] == 'C')
				t_win->nb_collect_tot += 1;
			i++;
		}
		j++;
	}
	if (t_win->nb_collect_tot == 0)
		free_t_win(t_win, "Error\nCollectibles are missing\n");
}

void	verify_nb_exit(t_window *t_win)
{
	int		i;
	int		j;
	int		nb_exit;

	j = 0;
	nb_exit = 0;
	while (t_win->tab[j])
	{
		i = 0;
		while (t_win->tab[j][i])
		{
			if (t_win->tab[j][i] == 'E')
				nb_exit++;
			i++;
		}
		j++;
	}
	if (nb_exit != 1)
	{
		if (nb_exit == 0)
			free_t_win(t_win, "Error\nExit is missing\n");
		if (nb_exit > 1)
			free_t_win(t_win, "Error\nThere are too many exits\n");
	}
}
