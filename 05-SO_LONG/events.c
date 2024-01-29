#include "so_long.h"

int key_hook(int key, void *param)
{
	t_window *w_vars;
	w_vars = malloc(sizeof(t_window));
	if (!w_vars)
		return (1);
	w_vars = (t_window *)param;
	if(key == 41) // 41 is the key code for escape
		mlx_loop_end(w_vars->mlx);
/*    printf("%d", key)
	if(key == 26 || key == ) //  is the key code for W (up)
        mlx_loop_end(mlx);*/
    free(w_vars);
	return (0);
}

int window_hook(int event, void* mlx)
{
	if(event == 0) // 0 is when we trigger the close of the window (by clicking the cross for example)
	 	mlx_loop_end(mlx);
	return (0);
}




