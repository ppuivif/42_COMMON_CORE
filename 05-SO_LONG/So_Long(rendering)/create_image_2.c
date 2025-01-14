/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:21:20 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/26 20:15:40 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_img_p(t_position_image *t_pos)
{
	int	width;
	int	height;
	int	fd;

	width = SIZE;
	height = SIZE;
	fd = open("Images/imgP.png", O_RDONLY);
	if (fd >= 0)
		t_pos->t_list1->img_p = mlx_png_file_to_image(t_pos->t_win1->mlx,
				"Images/imgP.png", &width, &height);
	if (fd < 0 || !t_pos->t_list1->img_p)
		free_t_pos(t_pos, "Error\nImage img_P " \
			"didn't could be created\n");
	close(fd);
}

void	create_img_p1(t_position_image *t_pos)
{
	int	width;
	int	height;
	int	fd;

	width = SIZE;
	height = SIZE;
	fd = open("Images/imgP1.png", O_RDONLY);
	if (fd >= 0)
		t_pos->t_list1->img_p1 = mlx_png_file_to_image(t_pos->t_win1->mlx,
				"Images/imgP1.png", &width, &height);
	if (fd < 0 || !t_pos->t_list1->img_p1)
		free_t_pos(t_pos, "Error\nImage img_P1 " \
			"didn't could be created\n");
	close(fd);
}

void	create_img_p2(t_position_image *t_pos)
{
	int	width;
	int	height;
	int	fd;

	width = SIZE;
	height = SIZE;
	fd = open("Images/imgP2.png", O_RDONLY);
	if (fd >= 0)
		t_pos->t_list1->img_p2 = mlx_png_file_to_image(t_pos->t_win1->mlx,
				"Images/imgP2.png", &width, &height);
	if (fd < 0 || !t_pos->t_list1->img_p2)
		free_t_pos(t_pos, "Error\nImage img_P2 " \
			"didn't could be created\n");
	close(fd);
}

void	create_img_p3(t_position_image *t_pos)
{
	int	width;
	int	height;
	int	fd;

	width = SIZE;
	height = SIZE;
	fd = open("Images/imgP3.png", O_RDONLY);
	if (fd >= 0)
		t_pos->t_list1->img_p3 = mlx_png_file_to_image(t_pos->t_win1->mlx,
				"Images/imgP3.png", &width, &height);
	if (fd < 0 || !t_pos->t_list1->img_p3)
		free_t_pos(t_pos, "Error\nImage img_P3 " \
			"didn't could be created\n");
	close(fd);
}
