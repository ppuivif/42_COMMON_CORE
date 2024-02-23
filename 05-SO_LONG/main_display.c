/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:23:06 by ppuivif           #+#    #+#             */
/*   Updated: 2024/02/23 17:57:06 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	main_display(t_window *t_win)
{
	char				*title;
	t_list_image		*t_list1;
	t_position_image	*t_pos1;
	unsigned int		nb_columns;
	unsigned int		nb_lines;

	title = "Get the shortest way to the exit";
	nb_columns = t_win->nb_columns;
	nb_lines = t_win->nb_lines;
	t_win->mlx = mlx_init();
	t_win->win = mlx_new_window(t_win->mlx, (SIZE * nb_columns),
			(SIZE * nb_lines), title);
	init_t_list_image(&t_list1, t_win);
	create_tiles(t_list1);
	display_images(t_list1);
	init_t_position_image(&t_pos1, t_list1, t_win);
	update(t_pos1);
	mlx_loop(t_win->mlx);
	free(t_pos1);
	free_t_list(t_list1, "Succeed in destroy and free\n");
}

void	create_tiles(t_list_image *t_list)
{
	create_img_0(t_list);
	create_img_1(t_list);
	create_img_c(t_list);
	create_img_e(t_list);
	create_img_p(t_list);
}

void	which_image_1(t_image *t_img, t_list_image *t_list)
{
	t_img->image_0 = t_list->img_0;
	if (t_list->t_win1->tab_modified[t_img->y_tab][t_img->x_tab] == '0')
		t_img->image = t_list->img_0;
	if (t_list->t_win1->tab_modified[t_img->y_tab][t_img->x_tab] == '1')
		t_img->image = t_list->img_1;
	if (t_list->t_win1->tab_modified[t_img->y_tab][t_img->x_tab] == '2')
	{
		if (!t_list->img_2)
			create_img_2(t_list);
		t_img->image = t_list->img_2;
	}
	if (t_list->t_win1->tab_modified[t_img->y_tab][t_img->x_tab] == 'C')
		t_img->image = t_list->img_c;
	if (t_list->t_win1->tab_modified[t_img->y_tab][t_img->x_tab] == 'E')
		t_img->image = t_list->img_e;
	if (t_list->t_win1->tab_modified[t_img->y_tab][t_img->x_tab] == 'P')
		t_img->image = t_list->img_p;
}

void	display_images(t_list_image *t_list)
{
	t_image	*t_img1;

	init_t_image(&t_img1);
	while (t_img1->y_tab < t_list->t_win1->nb_lines)
	{
		while (t_img1->x_tab < t_list->t_win1->nb_columns)
		{
			which_image_1(t_img1, t_list);
			t_img1->x_map = t_img1->x_tab * SIZE;
			t_img1->y_map = t_img1->y_tab * SIZE;
			mlx_put_image_to_window(t_list->t_win1->mlx, t_list->t_win1->win,
				t_img1->image_0, t_img1->x_map, t_img1->y_map);
			mlx_put_image_to_window(t_list->t_win1->mlx, t_list->t_win1->win,
				t_img1->image, t_img1->x_map, t_img1->y_map);
			t_img1->x_tab++;
		}
		t_img1->y_tab++;
		t_img1->x_tab = 0;
	}
	free(t_img1);
}
