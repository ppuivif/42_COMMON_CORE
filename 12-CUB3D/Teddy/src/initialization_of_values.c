/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_of_values.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:25:34 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/01 03:06:14 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initialization_of_values(t_game *game)
{
	game->player->angle = 0.0;
	game->player->pitch = 0.0;
	game->player->player_pos_x = 1;// 6 si map plus petite ?
	game->player->player_pos_y = 1;// 4 si map plus petite ?
	game->player->dir_x = -1.0; //non utilisé ?
	game->player->dir_y = 0.0; //non utilisé ?
	game->player->fov = 1.221;
	game->data->height = 300;//pourquoi 300 ?
	
	game->data->nb_lines = 0;
	game->data->nb_columns = 0;
}
