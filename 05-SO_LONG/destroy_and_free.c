#include "so_long.h"

void	destroy_all(t_list_image *t_list)
{
	mlx_destroy_image(t_list->t_win1->mlx, t_list->img_0);
	mlx_destroy_image(t_list->t_win1->mlx, t_list->img_1);
	mlx_destroy_image(t_list->t_win1->mlx, t_list->img_2);
	mlx_destroy_image(t_list->t_win1->mlx, t_list->img_e);
	mlx_destroy_image(t_list->t_win1->mlx, t_list->img_c);
	mlx_destroy_image(t_list->t_win1->mlx, t_list->img_p);
	mlx_destroy_image(t_list->t_win1->mlx, t_list->img_p2);
	mlx_destroy_image(t_list->t_win1->mlx, t_list->img_p3);
	mlx_destroy_window(t_list->t_win1->mlx, t_list->t_win1->win);
	mlx_destroy_display(t_list->t_win1->mlx);
}

void	free_all_struct(void *structure)
{
	if (structure)
		free(structure);
	//structure = NULL;
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
