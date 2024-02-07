#include "so_long.h"

int key_hook(int key, void *param)
{
	t_position_image *t_pos3;
	
	t_pos3 = (t_position_image*)param;
	
	t_pos3->image = "P";
	
	if(key == 41) // 41 is the key code for escape
	{
//		free_tab(t_pos3->t_win1->tab);
//		free(t_pos3);
		mlx_loop_end(t_pos3->t_win1->mlx);
	//	destroy_all(t_pos3->t_list1);
	}
	//printf("%d", key);
	if(key == 26 || key == 82) //  is the key code for W (up) and top arrow
	{
		if (t_pos3->x_image_p == 0 && t_pos3->y_image_p == 0)
			find_image_p(t_pos3);
		move_image_up(t_pos3);
	}
	if(key == 22 || key == 81) //  is the key code for S (down) and down arrow
	{
		if (t_pos3->x_image_p == 0 && t_pos3->y_image_p == 0)
			find_image_p(t_pos3);
		move_image_down(t_pos3);
	}
	if(key == 6 || key == 80) //  is the key code for A (left) and left arrow
	{
		if (t_pos3->x_image_p == 0 && t_pos3->y_image_p == 0)
			find_image_p(t_pos3);
		move_image_left(t_pos3);
	}
	if(key == 7 || key == 79) //  is the key code for D (right) and right arrow
		{
		if (t_pos3->x_image_p == 0 && t_pos3->y_image_p == 0)
			find_image_p(t_pos3);
		move_image_right(t_pos3);
	}	
		
		
		
		
	
    //free(w_vars3);
	return (0);
}

int window_hook(int event, void *param)
{
	t_position_image *t_pos4;

	t_pos4 = (t_position_image *)param;
	if(event == 0) // 0 is when we trigger the close of the window (by clicking the cross for example)
	{
//		free_tab(t_pos4->t_win1->tab);
//		free(t_pos4);
		mlx_loop_end(t_pos4->t_win1->mlx);
	//	destroy_all(t_pos4->t_list1);

	}
	return (0);
}

int find_image_p(t_position_image *t_pos)
{
	while ((t_pos->y_tab < t_pos->t_win1->nb_lines)) // && (t_pos->t_win1->tab[t_pos->y_tab][t_pos->x_tab]))
	{
		while ((t_pos->x_tab < t_pos->t_win1->nb_columns))// && (t_pos->t_win1->tab[t_pos->y_tab][t_pos->x_tab]))
		{
			if (t_pos->t_win1->tab[t_pos->y_tab][t_pos->x_tab] == *t_pos->image)
			{
				t_pos->x_image_p = t_pos->x_tab;
				t_pos->y_image_p = t_pos->y_tab;
				return (1);
			}
			t_pos->x_tab++;
		}
		t_pos->x_tab = 0;
		t_pos->y_tab++;
	}
	return (0);
}

void	move_image_up(t_position_image *t_pos)
{
	int i;

	i = 0;
	if ((t_pos->t_win1->tab[t_pos->y_image_p - 1][t_pos->x_image_p]) != 49)
	{
/*		if ((t_pos->t_win1->tab[t_pos->y_image_p - 1][t_pos->x_image_p]) == 67)
		{
			t_pos->nb_collect++;
			mlx_put_image_to_window(t_pos->t_win1->mlx, t_pos->t_win1->win, t_pos->t_list1->img_0, t_pos->x_image_p * SIZE, ((t_pos->y_image_p) * SIZE));
			mlx_put_image_to_window(t_pos->t_win1->mlx, t_pos->t_win1->win, t_pos->t_list1->img_p2, t_pos->x_image_p * SIZE, ((t_pos->y_image_p) * SIZE));
			delay(10000);
		}*/
		mlx_put_image_to_window(t_pos->t_win1->mlx, t_pos->t_win1->win, t_pos->t_list1->img_0, t_pos->x_image_p * SIZE, t_pos->y_image_p * SIZE);
		mlx_put_image_to_window(t_pos->t_win1->mlx, t_pos->t_win1->win, t_pos->t_list1->img_0, t_pos->x_image_p * SIZE, ((t_pos->y_image_p - 1) * SIZE));
		mlx_put_image_to_window(t_pos->t_win1->mlx, t_pos->t_win1->win, t_pos->t_list1->img_p, t_pos->x_image_p * SIZE, ((t_pos->y_image_p - 1) * SIZE));
		t_pos->y_image_p -= 1;
		t_pos->move++;
		printf("%d\n", t_pos->move);
	}
}

void	move_image_down(t_position_image *t_pos)
{
	if ((t_pos->t_win1->tab[t_pos->y_image_p + 1][t_pos->x_image_p]) != 49)
	{
		mlx_put_image_to_window(t_pos->t_win1->mlx, t_pos->t_win1->win, t_pos->t_list1->img_0, t_pos->x_image_p * SIZE, t_pos->y_image_p * SIZE);
		mlx_put_image_to_window(t_pos->t_win1->mlx, t_pos->t_win1->win, t_pos->t_list1->img_0, t_pos->x_image_p * SIZE, (t_pos->y_image_p + 1) * SIZE);
		mlx_put_image_to_window(t_pos->t_win1->mlx, t_pos->t_win1->win, t_pos->t_list1->img_p, t_pos->x_image_p * SIZE, (t_pos->y_image_p + 1) * SIZE);
		t_pos->y_image_p += 1;
		t_pos->move++;
		printf("%d\n", t_pos->move);
	}
}

void	move_image_left(t_position_image *t_pos)
{
	if ((t_pos->t_win1->tab[t_pos->y_image_p][t_pos->x_image_p - 1]) != 49)
	{
		mlx_put_image_to_window(t_pos->t_win1->mlx, t_pos->t_win1->win, t_pos->t_list1->img_0, t_pos->x_image_p * SIZE, t_pos->y_image_p * SIZE);
		mlx_put_image_to_window(t_pos->t_win1->mlx, t_pos->t_win1->win, t_pos->t_list1->img_0, (t_pos->x_image_p - 1) * SIZE, t_pos->y_image_p * SIZE);
		mlx_put_image_to_window(t_pos->t_win1->mlx, t_pos->t_win1->win, t_pos->t_list1->img_p, (t_pos->x_image_p - 1) * SIZE, t_pos->y_image_p * SIZE);
		t_pos->x_image_p -= 1;
		t_pos->move++;
		printf("%d\n", t_pos->move);
	}
}

void	move_image_right(t_position_image *t_pos)
{
	if ((t_pos->t_win1->tab[t_pos->y_image_p][t_pos->x_image_p + 1]) != 49)
	{
		mlx_put_image_to_window(t_pos->t_win1->mlx, t_pos->t_win1->win, t_pos->t_list1->img_0, t_pos->x_image_p * SIZE, t_pos->y_image_p * SIZE);
		mlx_put_image_to_window(t_pos->t_win1->mlx, t_pos->t_win1->win, t_pos->t_list1->img_0, (t_pos->x_image_p + 1) * SIZE, t_pos->y_image_p * SIZE);
		mlx_put_image_to_window(t_pos->t_win1->mlx, t_pos->t_win1->win, t_pos->t_list1->img_p, (t_pos->x_image_p + 1) * SIZE, t_pos->y_image_p * SIZE);
		t_pos->x_image_p += 1;
		t_pos->move++;
		printf("%d\n", t_pos->move);
	}
}




