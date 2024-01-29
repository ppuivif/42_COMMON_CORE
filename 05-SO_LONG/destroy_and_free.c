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

void	destroy_all(t_list_image *li_vars)
{
	mlx_destroy_image(li_vars->w_vars->mlx, li_vars->img0);
	mlx_destroy_image(li_vars->w_vars->mlx, li_vars->img1);
	//mlx_destroy_image(li_vars->w_vars->mlx, li_vars->img2);
	//mlx_destroy_image(li_vars->w_vars->mlx, li_vars->imgE);
	//mlx_destroy_image(li_vars->w_vars->mlx, li_vars->imgC);
	mlx_destroy_image(li_vars->w_vars->mlx, li_vars->imgP);
	mlx_destroy_window(li_vars->w_vars->mlx, li_vars->w_vars->win);
	mlx_destroy_display(li_vars->w_vars->mlx);
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
