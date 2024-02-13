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
	create_sprites(t_list1);
	display_images(t_list1);
	init_t_position_image(&t_pos1, t_list1, t_win);
	update(t_pos1);
	mlx_loop(t_win->mlx);
	destroy_all(t_list1);
	free(t_list1);
	free(t_pos1);
}

void	create_tiles(t_list_image *t_list)
{
	int	width;
	int	height;

	width = SIZE;
	height = SIZE;
	t_list->img_0 = mlx_png_file_to_image(t_list->t_win1->mlx,
			"Images/img0.png", &width, &height);
	t_list->img_1 = mlx_png_file_to_image(t_list->t_win1->mlx,
			"Images/img1.png", &width, &height);
	t_list->img_2 = mlx_png_file_to_image(t_list->t_win1->mlx,
			"Images/img2.png", &width, &height);
	t_list->img_e = mlx_png_file_to_image(t_list->t_win1->mlx,
			"Images/imgE.png", &width, &height);
	t_list->img_c = mlx_png_file_to_image(t_list->t_win1->mlx,
			"Images/imgC.png", &width, &height);
	if (t_list->img_0 == NULL || t_list->img_1 == NULL || t_list->img_2 == NULL
		|| t_list->img_e == NULL || t_list->img_c == NULL)
		free_t_list(t_list, "Error\nAn image didn't could be created\n");
}

void	create_sprites(t_list_image *t_list)
{
	int	width;
	int	height;

	width = SIZE;
	height = SIZE;
	t_list->img_p = mlx_png_file_to_image(t_list->t_win1->mlx,
			"Images/imgP.png", &width, &height);
	t_list->img_p1 = mlx_png_file_to_image(t_list->t_win1->mlx,
			"Images/imgP1.png", &width, &height);
	t_list->img_p2 = mlx_png_file_to_image(t_list->t_win1->mlx,
			"Images/imgP2.png", &width, &height);
	t_list->img_p3 = mlx_png_file_to_image(t_list->t_win1->mlx,
			"Images/imgP3.png", &width, &height);
	t_list->img_p4 = mlx_png_file_to_image(t_list->t_win1->mlx,
			"Images/imgP4.png", &width, &height);
	t_list->img_p5 = mlx_png_file_to_image(t_list->t_win1->mlx,
			"Images/imgP5.png", &width, &height);
	if (t_list->img_p == NULL || t_list->img_p1 == NULL
		|| t_list->img_p2 == NULL || t_list->img_p3 == NULL
		|| t_list->img_p4 == NULL || t_list->img_p5 == NULL)
		free_t_list(t_list, "Error\nAn image didn't could be created\n");
}

void	which_image(char **tab, t_image *t_img, t_list_image *t_list)
{
	if (tab[t_img->y_tab][t_img->x_tab] == '0')
		t_img->image = t_list->img_0;
	if (tab[t_img->y_tab][t_img->x_tab] == '1')
		t_img->image = t_list->img_1;
	if (tab[t_img->y_tab][t_img->x_tab] == '2')
		t_img->image = t_list->img_2;
	if (tab[t_img->y_tab][t_img->x_tab] == 'E')
		t_img->image = t_list->img_e;
	if (tab[t_img->y_tab][t_img->x_tab] == 'C')
		t_img->image = t_list->img_c;
	if (tab[t_img->y_tab][t_img->x_tab] == 'P')
		t_img->image = t_list->img_p;
	t_img->image_0 = t_list->img_0;
}

void	display_images(t_list_image *t_list)
{
	t_image	*t_img1;

	init_t_image(&t_img1);
	while (t_img1->y_tab < t_list->t_win1->nb_lines)
	{
		while (t_img1->x_tab < t_list->t_win1->nb_columns)
		{
			which_image(t_list->t_win1->tab, t_img1, t_list);
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
