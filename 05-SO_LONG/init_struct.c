#include "so_long.h"

void	init_t_window(t_window **t_win)
{
	*t_win = ft_calloc(1, sizeof(t_window));
	if (!*t_win)
	{
		printf("Erreur : La structure t_windows *t_win n'a pas ete initialisee.\n");
		exit(EXIT_FAILURE);
	}
	(*t_win)->fd = 0;
	(*t_win)->tab = NULL;
	(*t_win)->tab_modified = NULL;
	(*t_win)->tab_cpy = NULL;
	(*t_win)->nb_lines = 0;
	(*t_win)->nb_columns = 0;
	(*t_win)->nb_collect_tot = 0;
	(*t_win)->mlx = NULL;
	(*t_win)->win = NULL;
	(*t_win)->x0_image_p = 0;
	(*t_win)->y0_image_p = 0;
}

void	init_t_image(t_image **t_img)
{
	*t_img = ft_calloc(1, sizeof(t_image));
	if (!*t_img)
	{
		printf("Erreur : La structure t_image *t_img n'a pas ete initialisee.\n");
		exit(EXIT_FAILURE);
	}
	(*t_img)->x_tab = 0;
	(*t_img)->y_tab = 0;
	(*t_img)->x_map = 0;//(*t_img)->x_tab * SIZE;
	(*t_img)->y_map = 0;//(*t_img)->y_tab * SIZE;
	(*t_img)->image = NULL;
	(*t_img)->image_0 = NULL;
}

void	init_t_list_image(t_list_image **t_list, t_window *t_win)
{
	*t_list = ft_calloc(1, sizeof(t_list_image));
	if (!*t_list)
	{
		printf("Erreur : La structure t_list_image *t_list n'a pas ete initialisee.\n");
		exit(EXIT_FAILURE);
	}
	(*t_list)->t_win1 = t_win;
}

void	init_t_position_image(t_position_image **t_pos, t_list_image *t_list1, t_window *t_win)
{
	*t_pos = ft_calloc(1, sizeof(t_position_image));
	if (!*t_pos)
	{
		printf("Erreur : La structure t_position_image *t_pos n'a pas ete initialisee.\n");
		exit(EXIT_FAILURE);
	}
	(*t_pos)->t_win1 = t_win;
	(*t_pos)->t_list1 = t_list1;
	(*t_pos)->image = 0;
	(*t_pos)->x_tab = 0;
	(*t_pos)->y_tab = 0;
	(*t_pos)->x_map = 0;//(*t_pos)->x_tab * SIZE;
	(*t_pos)->y_map = 0;//(*t_pos)->y_tab * SIZE;
	(*t_pos)->x0_image_p = t_win->x0_image_p;
	(*t_pos)->y0_image_p = t_win->y0_image_p;
	(*t_pos)->x1_image_p = 0;
	(*t_pos)->y1_image_p = 0;
	(*t_pos)->move = 0;
	(*t_pos)->nb_collect = 0;
	(*t_pos)->anim_time = 0;
	(*t_pos)->move_possible = 1;
	
}
