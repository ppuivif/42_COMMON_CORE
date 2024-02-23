/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:21:28 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/23 17:30:17 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_img_pup(t_list_image *t_list)
{
	int	width;
	int	height;
	int	fd;

	width = SIZE;
	height = SIZE;
	fd = open("Images/imgPup.png", O_RDONLY);
	if (fd >= 0)
		t_list->img_pup = mlx_png_file_to_image(t_list->t_win1->mlx,
				"Images/imgPup.png", &width, &height);
	else
		free_t_list(t_list, "Error\nImage img_pup didn't could be created\n");
	close(fd);
}

void	create_img_pdown(t_list_image *t_list)
{
	int	width;
	int	height;
	int	fd;

	width = SIZE;
	height = SIZE;
	fd = open("Images/imgPdown.png", O_RDONLY);
	if (fd >= 0)
		t_list->img_pdown = mlx_png_file_to_image(t_list->t_win1->mlx,
				"Images/imgPdown.png", &width, &height);
	else
		free_t_list(t_list, "Error\nImage img_pdown didn't could be created\n");
	close(fd);
}

void	create_img_pright(t_list_image *t_list)
{
	int	width;
	int	height;
	int	fd;

	width = SIZE;
	height = SIZE;
	fd = open("Images/imgPright.png", O_RDONLY);
	if (fd >= 0)
		t_list->img_pright = mlx_png_file_to_image(t_list->t_win1->mlx,
				"Images/imgPright.png", &width, &height);
	else
		free_t_list(t_list, "Error\nImage img_pright \
			didn't could be created\n");
	close(fd);
}

void	create_img_pleft(t_list_image *t_list)
{
	int	width;
	int	height;
	int	fd;

	width = SIZE;
	height = SIZE;
	fd = open("Images/imgPleft.png", O_RDONLY);
	if (fd >= 0)
		t_list->img_pleft = mlx_png_file_to_image(t_list->t_win1->mlx,
				"Images/imgPleft.png", &width, &height);
	else
		free_t_list(t_list, "Error\nImage img_pleft didn't could be created\n");
	close(fd);
}
