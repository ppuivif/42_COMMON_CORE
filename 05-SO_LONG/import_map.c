#include "so_long.h"
#include <stdio.h>

void size_of_map(int fd, unsigned int *nb_columns, unsigned int *nb_lines)
{
	*nb_columns = ft_strlen(get_next_line(fd)) - 1;
	*nb_lines = 1;
	while (get_next_line(fd))
		*nb_lines += 1;
}


char **read_map(int fd, unsigned int nb_columns, unsigned int nb_lines)
{
	unsigned int	i;
	unsigned int j;
	char **tab;

	i = 0;
	j = 0;
	tab = ft_calloc((nb_lines + 1), sizeof (char*));
	if (!tab)
		return (NULL);
	while (i < nb_lines)
	{
		tab[i] = ft_calloc((nb_columns + 1), sizeof (char));
		if(!tab[i])
			return (NULL);
		ft_strcpy(tab[i], get_next_line(fd));
		i++;
	}
	close (fd);
	return (tab);
}

void which_image(char **tab, void *mlx, t_image *i_vars)
{
	int width;
	int height;
	
	width = SIZE;
	height = SIZE;
	if (tab[i_vars->y][i_vars->x] == '0')
		*i_vars->img = mlx_png_file_to_image(mlx, "Images/img0.png", &width, &height);
	if (tab[i_vars->y][i_vars->x] == '1')
		*i_vars->img = mlx_png_file_to_image(mlx, "Images/img1.png", &width, &height);
	if (tab[i_vars->y][i_vars->x] == '2')
		*i_vars->img = "img2";
	if (tab[i_vars->y][i_vars->x] == 'C')
		*i_vars->img = "imgC";
	if (tab[i_vars->y][i_vars->x] == 'E')
		*i_vars->img = "imgE";
	if (tab[i_vars->y][i_vars->x] == 'P')
		*i_vars->img = mlx_png_file_to_image(mlx, "Images/imgP.png", &width, &height);
	*i_vars->img0 = mlx_png_file_to_image(mlx, "Images/img0.png", &width, &height);
}

void	display_images(t_window *w_vars, void *mlx, void *win)
{
	unsigned int x;
	unsigned int y;
	void *img;
	void *img0;

	i_vars = malloc(sizeof(t_image));
	if (!i_vars)
		return ;

	x = 0;
	y = 0;
	int img0_width;
	int img0_height;
	img0_width = SIZE;
	img0_height = SIZE;
	
	img0 = mlx_png_file_to_image(mlx, "Images/img0.png", &img0_width, &img0_width);
	w_vars->tab = read_map(w_vars->fd, w_vars->nb_columns, w_vars->nb_lines);
	while (y < w_vars->nb_lines)
	{
		while (x < w_vars->nb_columns)
		{
			which_image(w_vars->tab, mlx, i_vars->x, i_vars->y, &i_vars->img, &i_vars->img0);
			mlx_put_image_to_window(mlx, win, img0, x * SIZE, y * SIZE);
			mlx_put_image_to_window(mlx, win, img, x * SIZE, y * SIZE);
			x++;
		}
		y++;
		x = 0;
	}
}
