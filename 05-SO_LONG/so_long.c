#include "so_long.h"

void	complete_display(t_window *w_vars, t_list_image *li_vars)
{
	void *mlx;
	void *win;
	char *title;
	//char **tab_box;
	
	title = "Have a good game";
	mlx = mlx_init();
	w_vars->mlx = mlx;
	win = mlx_new_window(mlx, (SIZE * w_vars->nb_columns), (SIZE * w_vars->nb_lines), title);
	w_vars->win = win;
	display_images(w_vars, li_vars);
	mlx_loop_hook(mlx, update, w_vars);
	mlx_loop(mlx);
	destroy_all(li_vars);

}





