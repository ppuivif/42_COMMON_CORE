#include "so_long.h"

int update(t_position_image *t_pos)// to update on events
{
	mlx_on_event(t_pos->t_win1->mlx, t_pos->t_win1->win, MLX_KEYDOWN, key_hook, t_pos);
	mlx_on_event(t_pos->t_win1->mlx, t_pos->t_win1->win, MLX_WINDOW_EVENT, window_hook, t_pos);
	return (0);
}