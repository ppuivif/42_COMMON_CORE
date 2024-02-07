#include "so_long.h"

void	complete_display(t_window *t_win)
{
	void *mlx;
	void *win;
	char *title;
	t_list_image *t_list1;
	t_position_image *t_pos1;
	
	title = "Have a good game";
	
	mlx = mlx_init();
	t_win->mlx = mlx;

	win = mlx_new_window(mlx, (SIZE * t_win->nb_columns), (SIZE * t_win->nb_lines), title);
	t_win->win = win;

	init_t_list_image(&t_list1, t_win);

	create_images(t_list1);
	display_images(t_list1);

	init_t_position_image(&t_pos1, t_list1, t_win);

	update(t_pos1);
	//mlx_loop_hook(mlx, update, t_pos1);
	mlx_loop(mlx);
	//mlx_clear_window(mlx, t_win);
	destroy_all(t_list1);
//	mlx_destroy_window(t_list1->t_win1->mlx, t_list1->t_win1->win);
//	mlx_destroy_display(t_list1->t_win1->mlx);
	free(t_list1);
	free(t_pos1);
}
