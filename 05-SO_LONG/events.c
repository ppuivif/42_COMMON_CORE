/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:22:06 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/26 16:51:15 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update(t_position_image *t_pos)
{
	mlx_on_event(t_pos->t_win1->mlx, t_pos->t_win1->win,
		MLX_KEYDOWN, key_hook, t_pos);
	mlx_on_event(t_pos->t_win1->mlx, t_pos->t_win1->win,
		MLX_WINDOW_EVENT, window_hook, t_pos);
}

int	key_hook(int key, void *param)
{
	t_position_image	*t_pos2;

	t_pos2 = (t_position_image *)param;
	if (key == 41)
		mlx_loop_end(t_pos2->t_win1->mlx);
	if ((key == 26 || key == 82) && t_pos2->move_possible == 1)
		move_image_up(t_pos2);
	if ((key == 22 || key == 81) && t_pos2->move_possible == 1)
		move_image_down(t_pos2);
	if ((key == 6 || key == 80) && t_pos2->move_possible == 1)
		move_image_left(t_pos2);
	if ((key == 7 || key == 79) && t_pos2->move_possible == 1)
		move_image_right(t_pos2);
	return (0);
}

int	window_hook(int event, void *param)
{
	t_position_image	*t_pos3;

	t_pos3 = (t_position_image *)param;
	if (event == 0)
		mlx_loop_end(t_pos3->t_win1->mlx);
	return (0);
}
