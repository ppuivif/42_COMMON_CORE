#include "so_long.h"

void	destroy_all(t_list_image *t_list)
{
	destroy_image(t_list);
	if (t_list->t_win1->win)
		mlx_destroy_window(t_list->t_win1->mlx, t_list->t_win1->win);
	if (t_list->t_win1->mlx)
		mlx_destroy_display(t_list->t_win1->mlx);
}

void	destroy_image(t_list_image *t_list)
{
	if (t_list->img_0)
		mlx_destroy_image(t_list->t_win1->mlx, t_list->img_0);
	if (t_list->img_1)
		mlx_destroy_image(t_list->t_win1->mlx, t_list->img_1);
	if (t_list->img_2)
		mlx_destroy_image(t_list->t_win1->mlx, t_list->img_2);
	if (t_list->img_e)
		mlx_destroy_image(t_list->t_win1->mlx, t_list->img_e);
	if (t_list->img_c)
		mlx_destroy_image(t_list->t_win1->mlx, t_list->img_c);
	if (t_list->img_p)
		mlx_destroy_image(t_list->t_win1->mlx, t_list->img_p);
	if (t_list->img_p1)
		mlx_destroy_image(t_list->t_win1->mlx, t_list->img_p1);
	if (t_list->img_p2)
		mlx_destroy_image(t_list->t_win1->mlx, t_list->img_p2);
	if (t_list->img_p3)
		mlx_destroy_image(t_list->t_win1->mlx, t_list->img_p3);
	if (t_list->img_p4)
		mlx_destroy_image(t_list->t_win1->mlx, t_list->img_p4);
	if (t_list->img_p5)
		mlx_destroy_image(t_list->t_win1->mlx, t_list->img_p5);
}

void	free_t_list(t_list_image *t_list, char *error_message) 
{
	perror(error_message);
	free_tab(t_list->t_win1->tab);
	destroy_all(t_list);
	if (t_list->t_win1)
		free(t_list->t_win1);
	if (t_list)
		free(t_list);
	exit (EXIT_FAILURE);
}

void	free_t_win(t_window *t_win, char *error_message)
{
	perror(error_message);
	free_tab(t_win->tab);
	if (t_win)
		free(t_win);
	if (t_win)
		free(t_win);
	exit (EXIT_FAILURE);
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
	if (tab)
		free(tab);
	tab = NULL;
}
