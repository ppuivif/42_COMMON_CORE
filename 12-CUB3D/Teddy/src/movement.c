/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:53:45 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/01 00:49:58 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	colision(t_game *game, float orientation)
{
	float	new_pos_x;
	float	new_pos_y;

	new_pos_x = game->player->player_pos_x
		+ cos(game->player->angle + orientation) * 0.1;
	new_pos_y = game->player->player_pos_y
		+ sin(game->player->angle + orientation) * 0.1;
	if (game->data->map[(int)new_pos_y][(int)new_pos_x] == '0')
	{
		game->player->player_pos_x = game->player->player_pos_x
			+ cos(game->player->angle + orientation) * 0.05;
		game->player->player_pos_y = game->player->player_pos_y
			+ sin(game->player->angle + orientation) * 0.05;
	}
}

void	ft_key_mouv(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_LEFT)
		colision(game, -1 * (M_PI / 2));
	if (keydata.key == MLX_KEY_RIGHT)
		colision(game, (M_PI / 2));
	if (keydata.key == MLX_KEY_UP)
		colision(game, 0);
	if (keydata.key == MLX_KEY_DOWN)
		colision(game, M_PI);
	if (keydata.key == MLX_KEY_A)
		game->player->angle = clamp(game->player->angle - 0.05, 0, M_PI * 2.0);
	if (keydata.key == MLX_KEY_D)
		game->player->angle = clamp(game->player->angle + 0.05, 0, M_PI * 2.0);
	if (keydata.key == MLX_KEY_W && game->player->pitch < 0.5)
		game->player->pitch += 0.04;
	if (keydata.key == MLX_KEY_S && game->player->pitch > -0.5)
		game->player->pitch -= 0.04;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
}
