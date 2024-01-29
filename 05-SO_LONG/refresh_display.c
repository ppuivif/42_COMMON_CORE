#include "so_long.h"

int update(void *param)// to update on events
{
	t_window *w_vars;
	/*w_vars = malloc(sizeof(t_window));
	if (!w_vars)
		exit (1);*/
	w_vars = (t_window *)param;
//	mlx_on_event((w_vars->mlx, w_vars->win, MLX_KEYDOWN, key_hook, w_vars);
//	display_images(w_vars);
	mlx_on_event(w_vars->mlx, w_vars->win, MLX_KEYDOWN, key_hook, w_vars);
	mlx_on_event(w_vars->mlx, w_vars->win, MLX_WINDOW_EVENT, window_hook, w_vars->mlx);
//	free(w_vars);
	return (0);
}