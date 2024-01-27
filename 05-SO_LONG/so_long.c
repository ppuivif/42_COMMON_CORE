#include "so_long.h"
#include <stdio.h>

void	complete_display(t_window *w_vars)
{
	void *mlx;
	void *win;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, (SIZE * w_vars->nb_columns), (SIZE * w_vars->nb_lines), "Have a good game !");
	display_images(w_vars, mlx, win);
	mlx_loop(mlx);
	//mlx_destroy_image(mlx, img);
	//mlx_destroy_image(mlx, img1);
	//mlx_destroy_image(mlx, img2);
	//mlx_destroy_image(mlx, imgE);
	//mlx_destroy_image(mlx, imgC);
	//mlx_destroy_image(mlx, imgP);
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(w_vars->tab);
}





