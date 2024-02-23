/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:21:20 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/23 17:21:23 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_img_p(t_list_image *t_list)
{
	int	width;
	int	height;
	int	fd;

	width = SIZE;
	height = SIZE;
	fd = open("Images/imgP.png", O_RDONLY);
	if (fd >= 0)
		t_list->img_p = mlx_png_file_to_image(t_list->t_win1->mlx,
				"Images/imgP.png", &width, &height);
	else
		free_t_list(t_list, "Error\nImage img_P didn't could be created\n");
	close(fd);
}

void	create_img_p1(t_list_image *t_list)
{
	int	width;
	int	height;
	int	fd;

	width = SIZE;
	height = SIZE;
	fd = open("Images/imgP1.png", O_RDONLY);
	if (fd >= 0)
		t_list->img_p1 = mlx_png_file_to_image(t_list->t_win1->mlx,
				"Images/imgP1.png", &width, &height);
	else
		free_t_list(t_list, "Error\nImage img_P1 didn't could be created\n");
	close(fd);
}

void	create_img_p2(t_list_image *t_list)
{
	int	width;
	int	height;
	int	fd;

	width = SIZE;
	height = SIZE;
	fd = open("Images/imgP2.png", O_RDONLY);
	if (fd >= 0)
		t_list->img_p2 = mlx_png_file_to_image(t_list->t_win1->mlx,
				"Images/imgP2.png", &width, &height);
	else
		free_t_list(t_list, "Error\nImage img_P2 didn't could be created\n");
	close(fd);
}

void	create_img_p3(t_list_image *t_list)
{
	int	width;
	int	height;
	int	fd;

	width = SIZE;
	height = SIZE;
	fd = open("Images/imgP3.png", O_RDONLY);
	if (fd >= 0)
		t_list->img_p3 = mlx_png_file_to_image(t_list->t_win1->mlx,
				"Images/imgP3.png", &width, &height);
	else
		free_t_list(t_list, "Error\nImage img_P3 didn't could be created\n");
	close(fd);
}

/*void	create_img_p4(t_list_image *t_list)
{
	int	width;
	int	height;
	int	fd;

	width = SIZE;
	height = SIZE;
	
	fd = open("Images/imgP4.png", O_RDONLY);
	if (fd >= 1)
		t_list->img_p4 = mlx_png_file_to_image(t_list->t_win1->mlx,
			"Images/imgP4.png", &width, &height);
	else
		free_t_list(t_list, "Error\nImage img_P4 didn't could be created\n");
	close(fd);
}*/
