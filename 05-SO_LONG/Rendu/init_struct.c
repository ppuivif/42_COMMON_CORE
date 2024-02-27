/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:22:37 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/26 20:37:29 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_t_window(t_window **t_win)
{
	*t_win = ft_calloc(1, sizeof(t_window));
	if (!*t_win)
	{
		ft_putstr_fd("Erreur : La structure t_windows *t_win \
			n'a pas ete initialisee.\n", 2);
		exit(EXIT_FAILURE);
	}
	(*t_win)->fd = 0;
	(*t_win)->tab = NULL;
	(*t_win)->tab_modified = NULL;
	(*t_win)->nb_lines = 0;
	(*t_win)->nb_columns = 0;
	(*t_win)->nb_collect_tot = 0;
	(*t_win)->mlx = NULL;
	(*t_win)->win = NULL;
	(*t_win)->x0_image_p = 0;
	(*t_win)->y0_image_p = 0;
}

void	init_t_list_image(t_list_image **t_list, t_window *t_win)
{
	*t_list = ft_calloc(1, sizeof(t_list_image));
	if (!*t_list)
	{
		ft_putstr_fd("Erreur : La structure t_list_image *t_list \
			n'a pas ete initialisee.\n", 2);
		exit(EXIT_FAILURE);
	}
	(*t_list)->t_win1 = t_win;
	(*t_list)->img = NULL;
	(*t_list)->img_0 = NULL;
	(*t_list)->img_1 = NULL;
	(*t_list)->img_2 = NULL;
	(*t_list)->img_e = NULL;
	(*t_list)->img_c = NULL;
	(*t_list)->img_p = NULL;
	(*t_list)->img_p1 = NULL;
	(*t_list)->img_p2 = NULL;
	(*t_list)->img_p3 = NULL;
	(*t_list)->img_p4 = NULL;
	(*t_list)->img_pup = NULL;
	(*t_list)->img_pdown = NULL;
	(*t_list)->img_pright = NULL;
	(*t_list)->img_pleft = NULL;
}

void	init_t_position_image(t_position_image **t_pos,
	t_list_image *t_list, t_window *t_win)
{
	*t_pos = ft_calloc(1, sizeof(t_position_image));
	if (!*t_pos)
	{
		ft_putstr_fd("Erreur : La structure t_position_image *t_pos \
			n'a pas ete initialisee.\n", 2);
		exit(EXIT_FAILURE);
	}
	(*t_pos)->t_win1 = t_win;
	(*t_pos)->t_list1 = t_list;
	(*t_pos)->image = NULL;
	(*t_pos)->image_0 = NULL;
	(*t_pos)->x_tab = 0;
	(*t_pos)->y_tab = 0;
	(*t_pos)->x_map = 0;
	(*t_pos)->y_map = 0;
	(*t_pos)->x0_image_p = t_win->x0_image_p;
	(*t_pos)->y0_image_p = t_win->y0_image_p;
	(*t_pos)->x1_image_p = 0;
	(*t_pos)->y1_image_p = 0;
	(*t_pos)->move = 0;
	(*t_pos)->nb_collect = 0;
	(*t_pos)->move_possible = 1;
}
