#include "so_long.h"

int update(void *param)// to update on events
{
	t_position_image *t_pos2;

	t_pos2 = (t_position_image *)param;
	mlx_on_event(t_pos2->t_win1->mlx, t_pos2->t_win1->win, MLX_KEYDOWN, key_hook, t_pos2);
	mlx_on_event(t_pos2->t_win1->mlx, t_pos2->t_win1->win, MLX_WINDOW_EVENT, window_hook, t_pos2);
//	free(t_win2);
	return (0);
}