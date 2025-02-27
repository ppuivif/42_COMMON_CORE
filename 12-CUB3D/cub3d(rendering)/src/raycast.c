/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:07:21 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/17 13:32:51 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	raycast(void *param)
{
	t_game			*game;
	float			angle_step;
	int				rays;
	int				i;

	game = (t_game *)param;
	rays = WINDOWS_WIDTH - 1;
	angle_step = game->player->fov / rays;
	i = 0;
	while (i < rays)
	{
		game->ray_result.ray_angle = game->player->angle - \
		(game->player->fov / 2.0f) + i * angle_step;
		game->ray_result = ray_hit_detection(game->ray_result.ray_angle, game);
		texture_choice(game);
		pos_texture(game);
		draw_elements(game->texture->image, i, game, \
			game->ray_result.wall_height);
		i++;
	}
}
