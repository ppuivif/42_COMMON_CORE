/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:21:28 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/26 13:56:00 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_img_p4(t_position_image *t_pos)
{
	int	width;
	int	height;
	int	fd;

	width = SIZE;
	height = SIZE;
	fd = open("Images/imgP4.png", O_RDONLY);
	if (fd >= 0)
		t_pos->t_list1->img_p4 = mlx_png_file_to_image(t_pos->t_win1->mlx,
				"Images/imgP4.png", &width, &height);
	else
		free_t_pos(t_pos, "Error\nImage img_P4 " \
			"didn't could be created\n");
	close(fd);
}

void	create_img_pup(t_position_image *t_pos)
{
	int	width;
	int	height;
	int	fd;

	width = SIZE;
	height = SIZE;
	fd = open("Images/imgPup.png", O_RDONLY);
	if (fd >= 0)
		t_pos->t_list1->img_pup = mlx_png_file_to_image(t_pos->t_win1->mlx,
				"Images/imgPup.png", &width, &height);
	else
		free_t_pos(t_pos, "Error\nImage img_pup " \
			"didn't could be created\n");
	close(fd);
}

void	create_img_pdown(t_position_image *t_pos)
{
	int	width;
	int	height;
	int	fd;

	width = SIZE;
	height = SIZE;
	fd = open("Images/imgPdown.png", O_RDONLY);
	if (fd >= 0)
		t_pos->t_list1->img_pdown = mlx_png_file_to_image(t_pos->t_win1->mlx,
				"Images/imgPdown.png", &width, &height);
	else
		free_t_pos(t_pos, "Error\nImage img_pdown " \
			"didn't could be created\n");
	close(fd);
}

void	create_img_pright(t_position_image *t_pos)
{
	int	width;
	int	height;
	int	fd;

	width = SIZE;
	height = SIZE;
	fd = open("Images/imgPright.png", O_RDONLY);
	if (fd >= 0)
		t_pos->t_list1->img_pright = mlx_png_file_to_image(t_pos->t_win1->mlx,
				"Images/imgPright.png", &width, &height);
	else
		free_t_pos(t_pos, "Error\nImage img_pright " \
			"didn't could be created\n");
	close(fd);
}

void	create_img_pleft(t_position_image *t_pos)
{
	int	width;
	int	height;
	int	fd;

	width = SIZE;
	height = SIZE;
	fd = open("Images/imgPleft.png", O_RDONLY);
	if (fd >= 0)
		t_pos->t_list1->img_pleft = mlx_png_file_to_image(t_pos->t_win1->mlx,
				"Images/imgPleft.png", &width, &height);
	else
		free_t_pos(t_pos, "Error\nImage img_pleft " \
			"didn't could be created\n");
	close(fd);
}
