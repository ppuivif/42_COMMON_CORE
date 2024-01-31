#include "so_long.h"

int update(void *param)// to update on events
{
	t_window *t_win2;

	t_win2 = (t_window *)param;
	mlx_on_event(t_win2->mlx, t_win2->win, MLX_KEYDOWN, key_hook, t_win2);
	mlx_on_event(t_win2->mlx, t_win2->win, MLX_WINDOW_EVENT, window_hook, t_win2->mlx);
//	free(t_win2);
	return (0);
}