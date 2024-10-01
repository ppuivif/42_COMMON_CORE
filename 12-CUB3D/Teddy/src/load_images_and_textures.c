/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_and_textures.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:30:15 by tebandam          #+#    #+#             */
/*   Updated: 2024/10/01 01:38:03 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	load_north_south_textures(t_map_data *map_data, t_texture *texture, int i)
{
	char	**tab;

	tab = ft_split(map_data->map[i], ' ');
	if (tab[1] != NULL)
	{
		if (ft_strncmp(map_data->map[i], "NO ", 3) == 0)
		{
			texture->north_texture = mlx_load_png(tab[1]);//est-ce que tab[1] fait référence à une texture valide ?
			if (!texture->north_texture)
				return (free_tab_return_1(tab));
		}
		else if (ft_strncmp(map_data->map[i], "SO ", 3) == 0)
		{
			texture->south_texture = mlx_load_png(tab[1]);
			if (!texture->south_texture)
				return (free_tab_return_1(tab));
		}
		ft_free(tab);
	}
	return (0);
}

int	load_west_east_textures(t_map_data *map_data, t_texture *texture, int i)
{
	char	**tab;

	tab = ft_split(map_data->map[i], ' ');
	if (tab[1] != NULL)
	{
		if (ft_strncmp(map_data->map[i], "WE ", 3) == 0)
		{
			texture->west_texture = mlx_load_png(tab[1]);
			if (!texture->west_texture)
				return (free_tab_return_1(tab));
		}
		else if (ft_strncmp(map_data->map[i], "EA ", 3) == 0)
		{
			texture->east_texture = mlx_load_png(tab[1]);
			if (!texture->east_texture)
				return (free_tab_return_1(tab));
		}
		ft_free(tab);
	}
	return (0);
}

void	load_image(t_game *game)
{
	game->texture->east_texture = mlx_load_png("textures/wall_ea.png");
	game->texture->west_texture = mlx_load_png("textures/wall_we.png");
	game->texture->south_texture = mlx_load_png("textures/wall_so.png");
	game->texture->north_texture = mlx_load_png("textures/wall_no.png");
	if (!game->texture->east_texture || !game->texture->west_texture
		|| !game->texture->south_texture || !game->texture->north_texture)
	{
		ft_putstr_fd("Error loading texture\n", 2);//free des allocations à prévoir
		exit(1);
	}

	game->texture->player_image_N = mlx_load_png("textures/player_N.png");
	game->texture->player_image_E = mlx_load_png("textures/player_E.png");
	game->texture->player_image_S = mlx_load_png("textures/player_S.png");
	game->texture->player_image_W = mlx_load_png("textures/player_W.png");
	if(!game->texture->player_image_N || !game->texture->player_image_E
		|| !game->texture->player_image_S ||!game->texture->player_image_W)
	{
		ft_putstr_fd("Error loading texture\n", 2);//free des allocations à prévoir
		exit(EXIT_FAILURE);
	}
}
