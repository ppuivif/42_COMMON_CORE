#include "so_long.h"

void create_images(t_list_image *li_vars, t_window *w_vars)//to create images
{
	if (!li_vars)
	{
		printf("Erreur : La structure est vide.\n");
		exit(EXIT_FAILURE);
	}
	
	int width;
	int height;
	
 	/*if (!li_vars->w_vars || !li_vars->w_vars->mlx)
	{
		printf("Erreur : Les structures ne sont pas correctement initialisées.\n");
		exit(EXIT_FAILURE);
	}*/
	width = SIZE;
	height = SIZE;
	li_vars->img0 = mlx_png_file_to_image(w_vars->mlx, "Images/img0.png", &width, &height);
	li_vars->img1 = mlx_png_file_to_image(w_vars->mlx, "Images/img1.png", &width, &height);
	//li_vars->img2 = mlx_png_file_to_image(li_vars->w_vars->mlx, "Images/img0.png", &width, &height);
	//li_vars->imgE = mlx_png_file_to_image(li_vars->w_vars->mlx, "Images/img0.png", &width, &height);
	//li_vars->imgC = mlx_png_file_to_image(li_vars->w_vars->mlx, "Images/img0.png", &width, &height);
	li_vars->imgP = mlx_png_file_to_image(w_vars->mlx, "Images/imgP.png", &width, &height);
	if (!li_vars->img0 || !li_vars->img1 || !li_vars->imgP)
	{
		printf("Erreur : Les images n'ont pas été correctement chargées.\n");
		exit(EXIT_FAILURE);
	}
}


void which_image(char **tab, t_image *i_vars, t_list_image *li_vars)//to affect images
{
	if (tab[i_vars->y][i_vars->x] == '0')
		i_vars->img = li_vars->img0;
	if (tab[i_vars->y][i_vars->x] == '1')
		i_vars->img = li_vars->img1;
	/*if (tab[i_vars->y][i_vars->x] == '2')
		i_vars->img = li_vars->img2;
	if (tab[i_vars->y][i_vars->x] == 'E')
		i_vars->img = li_vars->imgE;
	if (tab[i_vars->y][i_vars->x] == 'C')
		i_vars->img = li_vars->imgC;*/
	if (tab[i_vars->y][i_vars->x] == 'P')
		i_vars->img = li_vars->imgP;
	i_vars->img0 = li_vars->img0;
}

void display_images(t_window *w_vars, t_list_image *li_vars)// to display images in the window
{
	t_image *i_vars;
//	char **tab_box;
	
	i_vars = malloc(sizeof(t_image));
	if (!i_vars)
		exit (1);
	i_vars->x = 0;
	i_vars->y = 0;
	w_vars->tab = read_map(w_vars->fd, w_vars->nb_columns, w_vars->nb_lines);
	while (i_vars->y < w_vars->nb_lines)
	{
		while (i_vars->x < w_vars->nb_columns)
		{
			which_image(w_vars->tab, i_vars, li_vars);
			mlx_put_image_to_window(w_vars->mlx, w_vars->win, i_vars->img0, i_vars->x * SIZE, i_vars->y * SIZE);
			mlx_put_image_to_window(w_vars->mlx, w_vars->win, i_vars->img, i_vars->x * SIZE, i_vars->y * SIZE);
			i_vars->x++;
		}
		i_vars->y++;
		i_vars->x = 0;
	}
	free(i_vars);
//	return (tab_box);
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

