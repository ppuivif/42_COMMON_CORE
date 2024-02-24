/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:22:15 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/24 10:10:38 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_t_list(t_list_image *t_list, char *error_message)
{
	if (t_list->t_win1->tab_cpy)
		free_tab(t_list->t_win1->tab_cpy);
	if (t_list->t_win1->tab_modified)
		free_tab(t_list->t_win1->tab_modified);
	destroy_all(t_list);
	if (t_list->t_win1)
		free(t_list->t_win1);
	if (t_list)
		free(t_list);
	ft_putstr_fd(error_message, 1);
	exit (EXIT_FAILURE);
}

void	free_t_win(t_window *t_win, char *error_message)
{
	if (t_win->tab_cpy)
		free_tab(t_win->tab_cpy);
	if (t_win->tab_modified)
		free_tab(t_win->tab_modified);
	if (t_win->win)
		mlx_destroy_window(t_win->mlx, t_win->win);
	if (t_win->mlx)
		mlx_destroy_display(t_win->mlx);
	if (t_win)
		free(t_win);
	ft_putstr_fd(error_message, 1);
	exit (EXIT_FAILURE);
}

void	free_t_pos(t_position_image *t_pos, char *error_message)
{
	if (t_pos->t_win1->tab_cpy)
		free_tab(t_pos->t_win1->tab_cpy);
	if (t_pos->t_win1->tab_modified)
		free_tab(t_pos->t_win1->tab_modified);
	destroy_all(t_pos->t_list1);
	if (t_pos->t_win1)
		free(t_pos->t_win1);
	if (t_pos->t_list1)
		free(t_pos->t_list1);
	if (t_pos)
		free(t_pos);
	ft_putstr_fd(error_message, 1);
	exit (EXIT_FAILURE);
}

void	free_tab(char **tab)
{
	unsigned int	i;

	i = 0;
	while ((tab)[i])
	{
		free((tab)[i]);
		i++;
	}
	if (tab)
		free(tab);
	tab = NULL;
}
