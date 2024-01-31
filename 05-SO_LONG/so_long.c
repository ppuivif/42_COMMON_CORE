#include "so_long.h"

void	complete_display(t_window *t_win)
{
	void *mlx;
	void *win;
	char *title;
	t_list_image *t_list1;


	
	title = "Have a good game";
	
	mlx = mlx_init();
	t_win->mlx = mlx;

	win = mlx_new_window(mlx, (SIZE * t_win->nb_columns), (SIZE * t_win->nb_lines), title);
	t_win->win = win;

	init_t_list_image(&t_list1, t_win);

	create_images(t_list1);
	display_images(t_list1);//t_win);

	mlx_loop_hook(mlx, update, t_win);
	mlx_loop(mlx);
	//mlx_clear_window(mlx, t_win);
	destroy_all(t_list1, t_win);
	free(t_list1);
}
