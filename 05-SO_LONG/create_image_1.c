/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:21:07 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/26 13:31:33 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_img_0(t_position_image *t_pos)
{
	int	width;
	int	height;
	int	fd;

	width = SIZE;
	height = SIZE;
	fd = open("Images/img0.png", O_RDONLY);
	if (fd >= 0)
		t_pos->t_list1->img_0 = mlx_png_file_to_image(t_pos->t_win1->mlx,
				"Images/img0.png", &width, &height);
	else
		free_t_pos(t_pos, "Error\nImage img_0 " \
			"didn't could be created\n");
	close(fd);
}

void	create_img_1(t_position_image *t_pos)
{
	int	width;
	int	height;
	int	fd;

	width = SIZE;
	height = SIZE;
	fd = open("Images/img1.png", O_RDONLY);
	if (fd >= 0)
		t_pos->t_list1->img_1 = mlx_png_file_to_image(t_pos->t_win1->mlx,
				"Images/img1.png", &width, &height);
	else
		free_t_pos(t_pos, "Error\nImage img_1 " \
			"didn't could be created\n");
	close(fd);
}

void	create_img_2(t_position_image *t_pos)
{
	int	width;
	int	height;
	int	fd;

	width = SIZE;
	height = SIZE;
	fd = open("Images/img2.png", O_RDONLY);
	if (fd >= 0)
		t_pos->t_list1->img_2 = mlx_png_file_to_image(t_pos->t_win1->mlx,
				"Images/img2.png", &width, &height);
	else
		free_t_pos(t_pos, "Error\nImage img_2 " \
			"didn't could be created\n");
	close(fd);
}

void	create_img_c(t_position_image *t_pos)
{
	int	width;
	int	height;
	int	fd;

	width = SIZE;
	height = SIZE;
	fd = open("Images/imgC.png", O_RDONLY);
	if (fd >= 0)
		t_pos->t_list1->img_c = mlx_png_file_to_image(t_pos->t_win1->mlx,
				"Images/imgC.png", &width, &height);
	else
		free_t_pos(t_pos, "Error\nImage img_c " \
			"didn't could be created\n");
	close(fd);
}

void	create_img_e(t_position_image *t_pos)
{
	int	width;
	int	height;
	int	fd;

	width = SIZE;
	height = SIZE;
	fd = open("Images/imgE.png", O_RDONLY);
	if (fd >= 0)
		t_pos->t_list1->img_e = mlx_png_file_to_image(t_pos->t_win1->mlx,
				"Images/imgE.png", &width, &height);
	else
		free_t_pos(t_pos, "Error\nImage img_e " \
			"didn't could be created\n");
	close(fd);
}
