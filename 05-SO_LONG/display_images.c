#include "so_long.h"

void create_images(t_list_image *t_list)//to create images
{
	int width;
	int height;
	
	width = SIZE;
	height = SIZE;
	t_list->img_0 = mlx_png_file_to_image(t_list->t_win1->mlx, "Images/img0.png", &width, &height);
	t_list->img_1 = mlx_png_file_to_image(t_list->t_win1->mlx, "Images/img1.png", &width, &height);
	t_list->img_2 = mlx_png_file_to_image(t_list->t_win1->mlx, "Images/img2.png", &width, &height);
	t_list->img_e = mlx_png_file_to_image(t_list->t_win1->mlx, "Images/imgE.png", &width, &height);
	t_list->img_c = mlx_png_file_to_image(t_list->t_win1->mlx, "Images/imgC.png", &width, &height);
	t_list->img_p = mlx_png_file_to_image(t_list->t_win1->mlx, "Images/imgP.png", &width, &height);
	t_list->img_p2 = mlx_png_file_to_image(t_list->t_win1->mlx, "Images/imgP2.png", &width, &height);
}

void which_image(char **tab, t_image *t_img, t_list_image *t_list)//to affect images
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

void display_images(t_list_image *t_list)// to display images in the window
{
	t_image *t_img1;
	
	init_t_image(&t_img1);

	t_list->t_win1->tab = read_map(t_list->t_win1->fd, t_list->t_win1->nb_columns, t_list->t_win1->nb_lines);
	while (t_img1->y_tab < t_list->t_win1->nb_lines)
	{
		while (t_img1->x_tab < t_list->t_win1->nb_columns)
		{
			which_image(t_list->t_win1->tab, t_img1, t_list);
			t_img1->x_map = t_img1->x_tab * SIZE;
			t_img1->y_map = t_img1->y_tab * SIZE;
			mlx_put_image_to_window(t_list->t_win1->mlx, t_list->t_win1->win, t_img1->image_0, t_img1->x_map, t_img1->y_map);
			mlx_put_image_to_window(t_list->t_win1->mlx, t_list->t_win1->win, t_img1->image, t_img1->x_map, t_img1->y_map);
			t_img1->x_tab++;
		}
		t_img1->y_tab++;
		t_img1->x_tab = 0;
	}
	free(t_img1);
}

/*char **stock_image(t_window *w_vars, char *img)//to build a table containing lists of images
{
	char **tab_box;
	unsigned int len;
	unsigned int nb_box;
	unsigned int y;
	unsigned int i;

	len = 0;
	nb_box = w_vars->nb_lines * w_vars->nb_columns;
	y = 0;
	i = 0;
	tab_box = ft_calloc((nb_box + 1), sizeof(char*));
	if (!*tab_box)
		return (NULL);
	while (y < nb_box && img)
	{
		len = ft_strlen(img);
		tab_box[y] = ft_calloc(len, sizeof(char));
		if(!tab_box[y])
			return (NULL);
		while (i < nb_box)
		{
			if (img == tab_box[i])
				i++;
			ft_strcpy(tab_box[y], img);
		}
		y++;
	}
	return (tab_box);
}*/

/*int sort_tab(char **tab_box)
{
	char **sort_tab_box;
	unsigned int	y;
	unsigned int	i;
	int				flag;

	i = 0;
	y = 0;
	flag = 0;
	while (y < 10)
	{
		while (i <= y)
		{
			if (tab_box[i] == tab_box[y])
				i++;
			flag++;
		}
		y++;
		i = 0;
	}
	return (flag);
}*/

