#include "so_long.h"

/*int main()
{
	int fd;
	int i;
	int j;
	void *mlx;
	void *win;
	int	width;
	int	height;
	const char *title;
	int img1_width;
	int img1_height;
	int img2_width;
	int img2_height;
	int img3_width;
	int img3_height;
	void *img1;
	void *img2;
	void *img3;

	fd = open("map.ber", O_RDONLY);
	read_map(fd);
	i = 0;
	j = 0;
	mlx = mlx_init();
	img1_width = 64;
	img1_height = 64;
	img2_width = 64;
	img2_height = 64;
	img3_width = 64;
	img3_height = 64;
	img1 = mlx_png_file_to_image(mlx, "img1.png", &img1_width, &img1_height);
	img2 = mlx_png_file_to_image(mlx, "img2.png", &img2_width, &img2_height);
	img3 = mlx_png_file_to_image(mlx, "img3.png", &img3_width, &img3_height);
	width = 640;
	height = 640;
	title = "have a good game";
	win = mlx_new_window(mlx, width, height, title);
	while (i < 640)
	{
		while (j < 640)
		{
			mlx_put_image_to_window(mlx, win, img2, i, j);
			j += 64;
		}
		i += 64;
		j = 0;
	}
	i = 0;
	j = 0;
	while (i < 640)
	{
		mlx_put_image_to_window(mlx, win, img3, i, j);
		i += 64;
	}
	i = 0;
	j = 640 - 64;
	while (i < 640)
	{
		mlx_put_image_to_window(mlx, win, img3, i, j);
		i += 64;
	}
	mlx_put_image_to_window(mlx, win, img1, 64, 64);
	mlx_loop(mlx);
	mlx_destroy_image(mlx, img1);
	mlx_destroy_image(mlx, img2);
	mlx_destroy_image(mlx, img3);
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(tab);
	return (0);
}*/




