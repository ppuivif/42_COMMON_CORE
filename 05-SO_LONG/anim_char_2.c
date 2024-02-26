/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_char_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:19:16 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/26 17:59:52 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fifth_anim_char(t_position_image *t_pos)
{
	int		x1;
	int		y1;

	if (!t_pos->t_list1->img_p)
		create_img_p(t_pos);
	x1 = t_pos->x1_image_p;
	y1 = t_pos->y1_image_p;
	mlx_put_image_to_window(t_pos->t_win1->mlx, t_pos->t_win1->win,
		t_pos->t_list1->img_0, x1 * SIZE, y1 * SIZE);
	mlx_put_image_to_window(t_pos->t_win1->mlx, t_pos->t_win1->win,
		t_pos->t_list1->img_p, x1 * SIZE, y1 * SIZE);
	t_pos->x0_image_p = t_pos->x1_image_p;
	t_pos->y0_image_p = t_pos->y1_image_p;
}
