/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:23:21 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/23 17:23:24 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_image_up(t_position_image *t_pos)
{
	t_pos->image = "Pup";
	t_pos->x1_image_p = t_pos->x0_image_p;
	t_pos->y1_image_p = t_pos->y0_image_p - 1;
	move_image_1(t_pos);
}

void	move_image_down(t_position_image *t_pos)
{
	t_pos->image = "Pdown";
	t_pos->x1_image_p = t_pos->x0_image_p;
	t_pos->y1_image_p = t_pos->y0_image_p + 1;
	move_image_1(t_pos);
}

void	move_image_left(t_position_image *t_pos)
{
	t_pos->image = "Pleft";
	t_pos->x1_image_p = t_pos->x0_image_p - 1;
	t_pos->y1_image_p = t_pos->y0_image_p;
	move_image_1(t_pos);
}

void	move_image_right(t_position_image *t_pos)
{
	t_pos->image = "Pright";
	t_pos->x1_image_p = t_pos->x0_image_p + 1;
	t_pos->y1_image_p = t_pos->y0_image_p;
	move_image_1(t_pos);
}
