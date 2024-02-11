#include "so_long.h"

void	complete_display(t_window *t_win)
{
	void				*mlx;
	void				*win;
	char				*title;
	t_list_image		*t_list1;
	t_position_image	*t_pos1;
	unsigned int		nb_columns;
	unsigned int		nb_lines;
	
	title = "Get the shortest way to the exit";
	nb_columns = t_win->nb_columns;
	nb_lines = t_win->nb_lines;
	mlx = mlx_init();
	t_win->mlx = mlx;
	win = mlx_new_window(mlx, (SIZE * nb_columns), (SIZE * nb_lines), title);
	t_win->win = win;
	init_t_list_image(&t_list1, t_win);


	create_tiles(t_list1);
	create_sprites(t_list1);
	display_images(t_list1);
	printf("%d\n", t_win->x0_image_p);
	printf("%d\n", t_win->y0_image_p);
	
	init_t_position_image(&t_pos1, t_list1, t_win);
	update(t_pos1);
	mlx_loop(mlx);
	destroy_all(t_list1);
	free(t_list1);
	free(t_pos1);
}
