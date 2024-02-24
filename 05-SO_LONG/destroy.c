/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:21:46 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/24 18:06:07 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_all(t_list_image *t_list)
{
	destroy_image_1(t_list);
	destroy_image_2(t_list);
	if (t_list->t_win1->win)
		mlx_destroy_window(t_list->t_win1->mlx, t_list->t_win1->win);
	if (t_list->t_win1->mlx)
		mlx_destroy_display(t_list->t_win1->mlx);
}

void	destroy_image_1(t_list_image *t_list)
{
	if (t_list->img_0)
		mlx_destroy_image(t_list->t_win1->mlx, t_list->img_0);
	if (t_list->img_1)
		mlx_destroy_image(t_list->t_win1->mlx, t_list->img_1);
	if (t_list->img_2)
		mlx_destroy_image(t_list->t_win1->mlx, t_list->img_2);
	if (t_list->img_e)
		mlx_destroy_image(t_list->t_win1->mlx, t_list->img_e);
	if (t_list->img_c)
		mlx_destroy_image(t_list->t_win1->mlx, t_list->img_c);
	if (t_list->img_p)
		mlx_destroy_image(t_list->t_win1->mlx, t_list->img_p);
}

void	destroy_image_2(t_list_image *t_list)
{
	if (t_list->img_p1)
		mlx_destroy_image(t_list->t_win1->mlx, t_list->img_p1);
	if (t_list->img_p2)
		mlx_destroy_image(t_list->t_win1->mlx, t_list->img_p2);
	if (t_list->img_p3)
		mlx_destroy_image(t_list->t_win1->mlx, t_list->img_p3);
	if (t_list->img_p4)
		mlx_destroy_image(t_list->t_win1->mlx, t_list->img_p4);
	if (t_list->img_pup)
		mlx_destroy_image(t_list->t_win1->mlx, t_list->img_pup);
	if (t_list->img_pdown)
		mlx_destroy_image(t_list->t_win1->mlx, t_list->img_pdown);
	if (t_list->img_pright)
		mlx_destroy_image(t_list->t_win1->mlx, t_list->img_pright);
	if (t_list->img_pleft)
		mlx_destroy_image(t_list->t_win1->mlx, t_list->img_pleft);
}
