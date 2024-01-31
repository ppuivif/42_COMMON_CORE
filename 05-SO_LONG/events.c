#include "so_long.h"

int key_hook(int key, void *param)
{
	t_window *t_win3;
	t_position_image *t_pos1;
	
	t_win3 = (t_window *)param;
	
	init_t_position_image(&t_pos1);
	t_pos1->image = "P";
//	t_pos1->t_list1 = t_list1;
	
	if(key == 41) // 41 is the key code for escape
		mlx_loop_end(t_win3->mlx);
    //printf("%d", key);
	if(key == 26 || key == 82) //  is the key code for W (up) and top arrow
    {
		if (find_image(t_win3, t_pos1) == 1)
		{
			printf("x %d\n", t_pos1->x_tab);
			printf("y %d\n", t_pos1->y_tab);
			printf("y %d\n", t_win3->tab[t_pos1->y_tab][t_pos1->x_tab]);
			move_image_up(t_win3, t_pos1);
		}
		else
		{
			printf("Erreur : Il n'y a pas de personnage sur la map.\n");
			exit(EXIT_FAILURE);
		}
	}
	/*if(key == 22 || key == 81) //  is the key code for S (down) and down arrow
    	mlx_loop_end(mlx);
	if(key == 6 || key == 80) //  is the key code for A (left) and left arrow
    	mlx_loop_end(mlx);
	if(key == 7 || key == 79) //  is the key code for D (right) and right arrow
    	mlx_loop_end(mlx);*/
		
		
		
		
		
	
    //free(w_vars3);
	return (0);
}

int window_hook(int event, void* mlx)
{
	if(event == 0) // 0 is when we trigger the close of the window (by clicking the cross for example)
	 	mlx_loop_end(mlx);
	return (0);
}

int find_image(t_window *t_win, t_position_image *t_pos)
{
	while ((t_pos->y_tab < t_win->nb_lines) && (t_win->tab[t_pos->y_tab][t_pos->x_tab]))
	{
		while ((t_pos->x_tab < t_win->nb_columns) && (t_win->tab[t_pos->y_tab][t_pos->x_tab]))
		{
			if (t_win->tab[t_pos->y_tab][t_pos->x_tab] == *t_pos->image)
				return (1);
			t_pos->x_tab++;
		}
		t_pos->x_tab = 0;
		t_pos->y_tab++;
	}
	return (0);
}

void	move_image_up(t_window *t_win, t_position_image *t_pos)
{
	if ((t_win->tab[t_pos->y_tab - 1][t_pos->x_tab]) != 49)
	{
		t_pos->x_map = t_pos->x_tab * SIZE;
		t_pos->y_map = t_pos->y_tab * SIZE;
		mlx_put_image_to_window(t_win->mlx, t_win->win, t_pos->t_list1->img_0, t_pos->x_map, t_pos->y_map);
		mlx_put_image_to_window(t_win->mlx, t_win->win, t_pos->t_list1->img_0, t_pos->x_map, (t_pos->y_map - SIZE));
		mlx_put_image_to_window(t_win->mlx, t_win->win, t_pos->t_list1->img_p, t_pos->x_map, (t_pos->y_map - SIZE));
	}
	else
	{
		printf("Erreur : Le personnage n'a pas pu etre deplace.\n");
		exit(EXIT_FAILURE);
	}
}





