#include "so_long.h"

/*void	destroy_all(void **mlx, void **win)
{
	t_destroy *d_vars;

	d_vars = malloc(sizeof(t_destroy));
	if (!d_vars)
		return ;
	d_vars->mlx = &mlx;
	d_vars->win = &win;
		
	//free(d_vars);
}*/

void	destroy_all(t_list_image *t_list, t_window *t_win)
{
	mlx_destroy_image(t_win->mlx, t_list->img_0);
	mlx_destroy_image(t_win->mlx, t_list->img_1);
	mlx_destroy_image(t_win->mlx, t_list->img_2);
	mlx_destroy_image(t_win->mlx, t_list->img_e);
	mlx_destroy_image(t_win->mlx, t_list->img_c);
	mlx_destroy_image(t_win->mlx, t_list->img_p);
	mlx_destroy_window(t_win->mlx, t_win->win);
	mlx_destroy_display(t_win->mlx);
}

void free_tab(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}
